// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
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

// $XORP: xorp/fea/ifconfig.hh,v 1.2 2003/03/10 23:20:15 hodson Exp $

#ifndef __FEA_FTICONFIG_ENTRY_GET_HH__
#define __FEA_FTICONFIG_ENTRY_GET_HH__


#include "libxorp/xorp.h"
#include "libxorp/ipvx.hh"

#include "fte.hh"
#include "netlink_socket.hh"
#include "routing_socket.hh"


class IPv4;
class IPv6;
class FtiConfig;

class FtiConfigEntryGet {
public:
    FtiConfigEntryGet(FtiConfig& ftic);
    
    virtual ~FtiConfigEntryGet();
    
    FtiConfig&	ftic() { return _ftic; }
    
    virtual void register_ftic();

    /**
     * Start operation.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int start() = 0;
    
    /**
     * Stop operation.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int stop() = 0;
    
    /**
     * Receive data.
     * 
     * @param data the buffer with the data
     * @param n_bytes the number of bytes in the @param data buffer.
     */
    virtual void receive_data(const uint8_t* data, size_t n_bytes) = 0;
    
    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route4(const IPv4& dst, Fte4& fte) = 0;

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry4(const IPv4Net& dst, Fte4& fte) = 0;

    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route6(const IPv6& dst, Fte6& fte) = 0;

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry6(const IPv6Net& dst, Fte6& fte) = 0;

    int sock(int family);
    
protected:
    int parse_buffer_rtm(FteX& fte, const uint8_t *buf, size_t buf_bytes);
    int parse_buffer_nlm(FteX& fte, const uint8_t *buf, size_t buf_bytes);
    
    int	_s4;
    int _s6;
    
private:
    FtiConfig&	_ftic;
};

class FtiConfigEntryGetRs : public FtiConfigEntryGet,
			    public RoutingSocket,
			    public RoutingSocketObserver {
public:
    FtiConfigEntryGetRs(FtiConfig& ftic);
    virtual ~FtiConfigEntryGetRs();

    /**
     * Start operation.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int start();
    
    /**
     * Stop operation.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int stop();

    /**
     * Data has pop-up.
     * 
     * @param data the buffer with the data.
     * @param n_bytes the number of bytes in the @param data buffer.
     */
    virtual void rtsock_data(const uint8_t* data, size_t n_bytes);
    
    /**
     * Receive data.
     * 
     * @param data the buffer with the data.
     * @param n_bytes the number of bytes in the @param data buffer.
     */
    virtual void receive_data(const uint8_t* data, size_t n_bytes);
    
    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route4(const IPv4& dst, Fte4& fte);

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry4(const IPv4Net& dst, Fte4& fte);

    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route6(const IPv6& dst, Fte6& fte);

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry6(const IPv6Net& dst, Fte6& fte);

private:
    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route(const IPvX& dst, FteX& fte);

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry(const IPvXNet& dst, FteX& fte);

    bool	    _cache_valid;	// Cache data arrived.
    uint32_t	    _cache_seqno;	// Seqno of routing socket data to
					// cache so route lookup via routing
					// socket can appear synchronous.
    vector<uint8_t> _cache_data;	// Cached routing socket data route.
};

class FtiConfigEntryGetNetlink : public FtiConfigEntryGet,
				 public NetlinkSocket,
				 public NetlinkSocketObserver {
public:
    FtiConfigEntryGetNetlink(FtiConfig& ftic);
    virtual ~FtiConfigEntryGetNetlink();

    /**
     * Start operation.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int start();
    
    /**
     * Stop operation.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int stop();

    /**
     * Data has pop-up.
     * 
     * @param data the buffer with the data.
     * @param n_bytes the number of bytes in the @param data buffer.
     */
    virtual void nlsock_data(const uint8_t* data, size_t n_bytes);
    
    /**
     * Receive data.
     * 
     * @param data the buffer with the data.
     * @param n_bytes the number of bytes in the @param data buffer.
     */
    virtual void receive_data(const uint8_t* data, size_t n_bytes);
    
    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route4(const IPv4& dst, Fte4& fte);

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry4(const IPv4Net& dst, Fte4& fte);

    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route6(const IPv6& dst, Fte6& fte);

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry6(const IPv6Net& dst, Fte6& fte);

private:
    /**
     * Lookup a route.
     *
     * @param dst host address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_route(const IPvX& dst, FteX& fte);

    /**
     * Lookup entry.
     *
     * @param dst network address to resolve.
     * @param fte return-by-reference forwarding table entry.
     *
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int lookup_entry(const IPvXNet& dst, FteX& fte);

    bool	    _cache_valid;	// Cache data arrived.
    uint32_t	    _cache_seqno;	// Seqno of netlink socket data to
					// cache so route lookup via netlink
					// socket can appear synchronous.
    vector<uint8_t> _cache_data;	// Cached netlink socket data.
};

#endif // __FEA_FTICONFIG_ENTRY_GET_HH__
