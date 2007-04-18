// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2007 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/libxipc/finder_tcp.cc,v 1.29 2006/03/16 00:04:16 pavlin Exp $"

#include <functional>

#include "finder_module.h"

#include "libxorp/xorp.h"
#include "libxorp/debug.h"
#include "libxorp/xlog.h"

#include "libxorp/asyncio.hh"

#include "libcomm/comm_api.h"

#include "sockutil.hh"
#include "finder_tcp.hh"
#include "permits.hh"

///////////////////////////////////////////////////////////////////////////////
// FinderTcpBase

FinderTcpBase::FinderTcpBase(EventLoop& e, XorpFd sock)
    : _sock(sock),
      _reader(e, sock),
      _writer(e, sock),
      _isize(0), _osize(0)
{
    debug_msg("Constructor for FinderTcpBase object 0x%p\n", this);
    _reader.add_buffer(reinterpret_cast<uint8_t*>(&_isize), sizeof(_isize),
		       callback(this, &FinderTcpBase::read_callback));
    _reader.start();
}

FinderTcpBase::~FinderTcpBase()
{
    debug_msg("Destructor for FinderTcpBase object 0x%p\n", this);
    _writer.stop();
    _reader.stop();
    _writer.flush_buffers();
    _reader.flush_buffers();
    if (!closed())
	close();
}

bool
FinderTcpBase::write_data(const iovec* iov, uint32_t iovcnt)
{
    if (_writer.running()) {
	return false;
    }

    if (closed()) {
	XLOG_WARNING("Attempting to write data on closed socket");
	return false;
    }

    _osize = 0;
    for (uint32_t i = 0; i < iovcnt; i++)
	_osize += iov[i].iov_len;

    // Write 4-byte header containing length
    _osize = htonl(_osize);
    _writer.add_buffer(reinterpret_cast<uint8_t*>(&_osize), sizeof(_osize),
		       callback(this, &FinderTcpBase::write_callback));

    // Write iovec
    for (uint32_t i = 0; i < iovcnt; i++) {
	if (iov[i].iov_len == 0)
	    continue;
	_writer.add_buffer(reinterpret_cast<uint8_t*>(iov[i].iov_base),
			   iov[i].iov_len,
			   callback(this, &FinderTcpBase::write_callback));
    }
    _writer.start();

    return true;
}

bool
FinderTcpBase::write_data(const uint8_t* data, uint32_t data_bytes)
{
    assert(data_bytes != 0);

    if (_writer.running()) {
	return false;
    }

    if (closed()) {
	XLOG_WARNING("Attempting to write data on closed socket");
	return false;
    }

    // Write 4-byte header containing length
    _osize = htonl(data_bytes);
    _writer.add_buffer(reinterpret_cast<uint8_t*>(&_osize), sizeof(_osize),
		       callback(this, &FinderTcpBase::write_callback));

    // Write corresponding length of data
    _writer.add_buffer(data, data_bytes,
		       callback(this, &FinderTcpBase::write_callback));
    _writer.start();

    return true;
}

void
FinderTcpBase::read_callback(AsyncFileOperator::Event	ev,
			     const uint8_t*		buffer,
			     size_t			buffer_bytes,
			     size_t			offset)
{
    switch (ev) {
    case AsyncFileOperator::DATA:
	break;
    case AsyncFileOperator::FLUSHING:
	return;
    case AsyncFileOperator::END_OF_FILE:
	debug_msg("End of file (%d)\n", _reader.error());
	error_event();
	return;
    case AsyncFileOperator::WOULDBLOCK:
	_reader.resume();
	return;
    case AsyncFileOperator::OS_ERROR:
	if (EWOULDBLOCK == _reader.error()) {
	    _reader.resume();
	} else {
	    debug_msg("read_callback error = %d\n", _reader.error());
	    error_event();
	}
	return;
    }

    assert(ev == AsyncFileOperator::DATA);
    if (offset != buffer_bytes) {
	// Not enough data to do anything useful with
	return;
    }

    if (reinterpret_cast<const uint8_t*>(&_isize) == buffer) {
	// Read length of data to follow
	try {
	    _isize = ntohl(_isize);
	    if (0 == _isize || _isize > MAX_XRL_INPUT_SIZE)
		throw std::bad_alloc();
	    _input_buffer.resize(_isize);
	} catch (std::bad_alloc) {
	    XLOG_ERROR("Bad input buffer size (%d bytes) from wire, "
		       "dropping connection", XORP_INT_CAST(_isize));
	    error_event();
	    return;
	}
	_reader.add_buffer(&_input_buffer[0], _input_buffer.size(),
			   callback(this, &FinderTcpBase::read_callback));
	_reader.start();
	return;
    } else {
	// Looks like payload data
	assert(buffer == &_input_buffer[0]);

	// Finished reading data, notify call read_event.
	read_event(0, buffer, buffer_bytes);
	_reader.add_buffer(reinterpret_cast<uint8_t*>(&_isize), sizeof(_isize),
			   callback(this, &FinderTcpBase::read_callback));
	_reader.start();
	return;
    }
}

void
FinderTcpBase::write_callback(AsyncFileOperator::Event	ev,
			      const uint8_t*		buffer,
			      size_t			buffer_bytes,
			      size_t			offset)
{
    switch (ev) {
    case AsyncFileOperator::DATA:
	break;
    case AsyncFileOperator::FLUSHING:
	return;
    case AsyncFileOperator::END_OF_FILE:
	return;
    case AsyncFileOperator::WOULDBLOCK:
	_writer.resume();
	return;
    case AsyncFileOperator::OS_ERROR:
	if (EWOULDBLOCK == _writer.error()) {
	    _writer.resume();
	} else {
	    debug_msg("Error encountered (error = %d), shutting down",
		      _writer.error());
	    write_event(_writer.error(), buffer, 0);
	    error_event();
	}
	return;
    }

    assert(ev == AsyncFileOperator::DATA);
    if (offset != buffer_bytes) {
	// Not enough data to do anything useful with
	return;
    }

    if (reinterpret_cast<const uint8_t*>(&_osize) == buffer) {
	// Notified of length information write
	return;
    }

    if (offset == buffer_bytes && _writer.buffers_remaining() == 0) {
	// Reached last byte of last buffer, write completed
	write_event(0, buffer, buffer_bytes);
	//	assert(_writer.running() == false);
	return;
    }
}

void
FinderTcpBase::close_event()
{
}

void
FinderTcpBase::error_event()
{
}

void
FinderTcpBase::set_read_enabled(bool en)
{
    bool running = _reader.running();
    if (false == en && running)
	_reader.stop();
    else if (en && false == running)
	_reader.resume();
}

bool
FinderTcpBase::read_enabled() const
{
    return _reader.running();
}

void
FinderTcpBase::close()
{
    _writer.flush_buffers();
    _writer.stop();
    _reader.flush_buffers();
    _reader.stop();
    comm_close(_sock);
    debug_msg("Closing fd = %s\n", _sock.str().c_str());
    _sock.clear();
    close_event();
}

bool
FinderTcpBase::closed() const
{
    return (!_sock.is_valid());
}

///////////////////////////////////////////////////////////////////////////////
// FinderTcpListenerBase

FinderTcpListenerBase::FinderTcpListenerBase(EventLoop& e,
					     IPv4	interface,
					     uint16_t	port,
					     bool	en)
    throw (InvalidAddress, InvalidPort)
    : _e(e), _en(false), _addr(interface), _port(port)
{
    comm_init();

    in_addr if_ia;
    if_ia.s_addr = interface.addr();

    if (is_ip_configured(if_ia) == false && interface != IPv4::ANY()) {
	xorp_throw(InvalidAddress, "Not a configured IPv4 address");
    }

    _lsock = comm_bind_tcp4(&if_ia, htons(port), COMM_SOCK_NONBLOCKING);
    if (!_lsock.is_valid()) {
	xorp_throw(InvalidPort, comm_get_last_error_str());
    }

    if (en)
	set_enabled(en);
    debug_msg("Created new listener with fd %s\n", _lsock.str().c_str());
}

FinderTcpListenerBase::~FinderTcpListenerBase()
{
    set_enabled(false);
    // XXX: duplicate call; set_enabled() will remove callback
    //_e.remove_ioevent_cb(_lsock, IOT_ACCEPT);
    debug_msg("Destructing Listener with fd = %s\n", _lsock.str().c_str());
    comm_close(_lsock);
}

void
FinderTcpListenerBase::set_enabled(bool en)
{
    if (en == _en)
	return;

    if (en) {
	IoEventCb cb = callback(this, &FinderTcpListenerBase::connect_hook);
	if (false == _e.add_ioevent_cb(_lsock, IOT_ACCEPT, cb)) {
	    XLOG_FATAL("Failed to add io event callback\n");
	}
    } else {
	_e.remove_ioevent_cb(_lsock, IOT_ACCEPT);
    }
    _en = en;
}

bool
FinderTcpListenerBase::enabled() const
{
    return _en;
}

void
FinderTcpListenerBase::connect_hook(XorpFd fd, IoEventType type)
{
    assert(fd == _lsock);
    assert(type == IOT_ACCEPT);

    UNUSED(fd);
    XorpFd sock;

    sock = comm_sock_accept(_lsock);
    if (!sock.is_valid()) {
	XLOG_ERROR("accept(): %s", comm_get_last_error_str());
	return;
    }

    sockaddr_in name;
    socklen_t namelen = sizeof(name);
    if (getpeername(sock, reinterpret_cast<sockaddr*>(&name), &namelen) < 0) {
	XLOG_ERROR("getpeername(): %s",
		   comm_get_last_error_str());
	return;
    }

    IPv4 peer(name);
    if (host_is_permitted(peer)) {
	debug_msg("Created socket %s\n", sock.str().c_str());
	if (comm_sock_set_blocking(sock, COMM_SOCK_NONBLOCKING) != XORP_OK) {
	    XLOG_WARNING("Failed to set socket non-blocking.");
	    return;
	}
	if (connection_event(sock) == true)
	    return;
    } else {
	XLOG_WARNING("Rejected connection attempt from %s",
		     peer.str().c_str());
    }
    comm_close(sock);
}
