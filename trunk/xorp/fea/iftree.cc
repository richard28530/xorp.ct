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

#ident "$XORP: xorp/fea/iftree.cc,v 1.2 2003/03/10 23:20:16 hodson Exp $"

#include "config.h"
#include "iftree.hh"

#include "libxorp/c_format.hh"

/* ------------------------------------------------------------------------- */
/* Misc */

static inline const char* true_false(bool b)
{
    return b ? "true" : "false";
}

/* ------------------------------------------------------------------------- */
/* IfTreeItem code */

string
IfTreeItem::str() const
{
    struct {
	State st;
	const char* desc;
    } t[] = { { CREATED,  "CREATED"  },
	      { DELETED,  "DELETED"  },
	      { CHANGED, "CHANGED" }
    };

    string r;
    for (size_t i = 0; i < sizeof(t) / sizeof(t[0]); i++) {
	if ((_st & t[i].st) == 0) continue;
	if (r.empty() == false) r += ",";
	r += t[i].desc;
    }
    return r;
}

/* ------------------------------------------------------------------------- */
/* IfTree code */

bool
IfTree::add_if(const string& ifname)
{
    IfMap::iterator ii = get_if(ifname);
    if (ii != ifs().end()) {
	ii->second.mark(CREATED);
	return false;
    }
    _ifs.insert(IfMap::value_type(ifname, IfTreeInterface(ifname)));
    return true;
}

bool
IfTree::remove_if(const string& ifname)
{
    IfMap::iterator ii = get_if(ifname);
    if (ii == ifs().end())
	return false;

    ii->second.mark(DELETED);
    return true;
}

void
IfTree::finalize_state()
{
    IfMap::iterator ii = _ifs.begin();
    while (ii != _ifs.end()) {
	//
	// If interface is marked as deleted, delete it.
	//
	if (ii->second.is_marked(DELETED)) {
	    _ifs.erase(ii++);
	    continue;
	}
	//
	// Call finalize_state on interfaces that remain
	//
	ii->second.finalize_state();
	++ii;
    }
    set_state(NO_CHANGE);
}

string
IfTree::str() const
{
    string r;
    for (IfMap::const_iterator ii = ifs().begin(); ii != ifs().end(); ++ii) {
	const IfTreeInterface& fi = ii->second;
	r += fi.str() + string("\n");
	for (IfTreeInterface::VifMap::const_iterator vi = fi.vifs().begin();
	     vi != fi.vifs().end(); ++vi) {
	    const IfTreeVif& fv = vi->second;
	    r += string("  ") + fv.str() + string("\n");
	    for (IfTreeVif::V4Map::const_iterator ai = fv.v4addrs().begin();
		 ai != fv.v4addrs().end(); ++ai) {
		const IfTreeAddr4& a = ai->second;
		r += string("    ") + a.str() + string("\n");
	    }
	    for (IfTreeVif::V6Map::const_iterator ai = fv.v6addrs().begin();
		 ai != fv.v6addrs().end(); ++ai) {
		const IfTreeAddr6& a = ai->second;
		r += string("    ") + a.str() + string("\n");
	    }
	}
    }

    return r;
}

IfTree&
IfTree::align_with(const IfTree& o)
{
    // Walk interfaces, vifs, and addresses deleting anything that does
    // occur in 'o' and aligning state variable to those present in 'o'
    
    IfTree::IfMap::iterator ii;
    for (ii = ifs().begin(); ii != ifs().end(); ++ii) {
	const string& ifname = ii->second.ifname();
	IfTree::IfMap::const_iterator oi = o.get_if(ifname);
	if (oi == o.ifs().end()) {
	    // Mark local interface for deletion, not present in other
	    ii->second.mark(DELETED);
	    continue;
	} else {
	    ii->second.copy_state(oi->second);
	}

	IfTreeInterface::VifMap::iterator vi;
	for (vi = ii->second.vifs().begin();
	     vi != ii->second.vifs().end(); ++vi) {
	    const string& vifname = vi->second.vifname();
	    IfTreeInterface::VifMap::const_iterator ov =
		oi->second.get_vif(vifname);
	    if (ov == oi->second.vifs().end()) {
		vi->second.mark(DELETED);
		continue;
	    } else {
		vi->second.copy_state(ov->second);
	    }

	    IfTreeVif::V4Map::iterator ai4;
	    for (ai4 = vi->second.v4addrs().begin();
		 ai4 != vi->second.v4addrs().end(); ++ai4) {
		IfTreeVif::V4Map::const_iterator oa4 =
		    ov->second.get_addr(ai4->second.addr());
		if (oa4 == ov->second.v4addrs().end()) {
		    ai4->second.mark(DELETED);
		} else {
		    ai4->second = oa4->second;
		}
	    }

	    IfTreeVif::V6Map::iterator ai6;
	    for (ai6 = vi->second.v6addrs().begin();
		 ai6 != vi->second.v6addrs().end(); ++ai6) {
		IfTreeVif::V6Map::const_iterator oa6 =
		    ov->second.get_addr(ai6->second.addr());
		if (oa6 == ov->second.v6addrs().end()) {
		    ai6->second.mark(DELETED);
		} else {
		    ai6->second = oa6->second;
		}
	    }
	}
    }

    // Pass over and remove items marked for deletion
    finalize_state();
    
    return *this;
}

/* ------------------------------------------------------------------------- */
/* IfTreeInterface code */

IfTreeInterface::IfTreeInterface(const string& ifname)
    : IfTreeItem(), _ifname(ifname), _enabled(false), _if_flags(0), _mtu(0)
{}

bool
IfTreeInterface::add_vif(const string& vifname)
{
    VifMap::iterator vi = get_vif(vifname);
    if (vi != _vifs.end()) {
	vi->second.mark(CREATED);
	return false;
    }
    _vifs.insert(VifMap::value_type(vifname, IfTreeVif(name(), vifname)));
    return true;
}

bool
IfTreeInterface::remove_vif(const string& vifname)
{
    VifMap::iterator vi = get_vif(vifname);
    if (vi == _vifs.end())
	return false;
    vi->second.mark(DELETED);
    return true;
}

void
IfTreeInterface::finalize_state()
{
    VifMap::iterator vi = _vifs.begin();
    while (vi != _vifs.end()) {
	//
	// If interface is marked as deleted, delete it.
	//
	if (vi->second.is_marked(DELETED)) {
	    _vifs.erase(vi++);
	    continue;
	}
	//
	// Call finalize_state on vifs that remain
	//
	vi->second.finalize_state();
	++vi;
    }
    set_state(NO_CHANGE);
}

string
IfTreeInterface::str() const
{
    return c_format("Interface %s { enabled := %s } { flags := 0x%02x } "
		    "{ mtu := %d } { mac := %s }",
		    _ifname.c_str(), true_false(_enabled), _if_flags, _mtu,
		    _mac.str().c_str()) + string(" ") + IfTreeItem::str();
}

/* ------------------------------------------------------------------------- */
/* IfTreeVif code */

IfTreeVif::IfTreeVif(const string& ifname, const string& vifname)
    : IfTreeItem(), _ifname(ifname), _vifname(vifname), _enabled(false),
      _broadcast(false), _loopback(false), _point_to_point(false),
      _multicast(false), _vif_flags(0)
{}

bool
IfTreeVif::add_addr(const IPv4& v4addr)
{
    V4Map::iterator ai = get_addr(v4addr);
    if (ai != v4addrs().end()) {
	ai->second.mark(CREATED);
	return false;
    }
    _v4addrs.insert(V4Map::value_type(v4addr, IfTreeAddr4(v4addr)));
    return true;
}

bool
IfTreeVif::remove_addr(const IPv4& v4addr)
{
    V4Map::iterator ai = get_addr(v4addr);
    if (ai == v4addrs().end())
	return false;
    ai->second.mark(DELETED);
    return true;
}

bool
IfTreeVif::add_addr(const IPv6& v6addr)
{
    V6Map::iterator ai = get_addr(v6addr);
    if (ai != v6addrs().end()) {
	ai->second.mark(CREATED);
	return false;
    }
    _v6addrs.insert(V6Map::value_type(v6addr, IfTreeAddr6(v6addr)));
    return true;
}

bool
IfTreeVif::remove_addr(const IPv6& v6addr)
{
    V6Map::iterator ai = get_addr(v6addr);
    if (ai == v6addrs().end())
	return false;
    ai->second.mark(DELETED);
    return true;
}

void
IfTreeVif::finalize_state()
{
    for (V4Map::iterator ai = _v4addrs.begin(); ai != _v4addrs.end(); ) {
	//
	// If address is marked as deleted, delete it.
	//
	if (ai->second.is_marked(DELETED)) {
	    _v4addrs.erase(ai++);
	    continue;
	}
	//
	// Call finalize_state on addresses that remain
	//
	ai->second.finalize_state();
	++ai;
    }

    for (V6Map::iterator ai = _v6addrs.begin(); ai != _v6addrs.end(); ) {
	//
	// If address is marked as deleted, delete it.
	//
	if (ai->second.is_marked(DELETED)) {
	    _v6addrs.erase(ai++);
	    continue;
	}
	//
	// Call finalize_state on interfaces that remain
	//
	ai->second.finalize_state();
	++ai;
    }
    set_state(NO_CHANGE);
}

string
IfTreeVif::str() const
{
    return c_format("VIF %s { enabled := %s } { broadcast := %s } "
		    "{ loopback := %s } { point_to_point := %s } "
		    "{ multicast := %s } { flags := 0x%02x }",
		    _vifname.c_str(), true_false(_enabled),
		    true_false(_broadcast), true_false(_loopback),
		    true_false(_point_to_point), true_false(_multicast),
		    _vif_flags)
	+ string(" ") + IfTreeItem::str();
}

/* ------------------------------------------------------------------------- */
/* IfTreeAddr4 code */

bool
IfTreeAddr4::set_prefix(uint32_t prefix)
{
    if (prefix > IPv4::addr_bitlen())
	return false;

    _prefix = prefix;
    mark(CHANGED);
    return true;
}

void
IfTreeAddr4::set_bcast(const IPv4& baddr)
{
    set_broadcast(false);
    set_point_to_point(false);
    if (baddr != IPv4::ZERO())
	set_broadcast(true);
    _oaddr = baddr;
    mark(CHANGED);
}

IPv4
IfTreeAddr4::bcast() const
{
    if (broadcast())
	return _oaddr;
    return IPv4::ZERO();
}

void
IfTreeAddr4::set_endpoint(const IPv4& eaddr)
{
    set_broadcast(false);
    set_point_to_point(false);
    if (eaddr != IPv4::ZERO())
	set_point_to_point(true);
    _oaddr = eaddr;
    mark(CHANGED);
}

IPv4
IfTreeAddr4::endpoint() const
{
    if (point_to_point())
	return _oaddr;
    return IPv4::ZERO();
}

void
IfTreeAddr4::finalize_state()
{
    set_state(NO_CHANGE);
}

string
IfTreeAddr4::str() const
{
    string r = c_format("V4Addr %s { enabled := %s } { broadcast := %s } "
			"{ loopback := %s } { point_to_point := %s } "
			"{ multicast := %s } { flags := 0x%02x }"
			"{ prefix := %d }",
			_addr.str().c_str(), true_false(_enabled),
			true_false(_broadcast), true_false(_loopback),
			true_false(_point_to_point), true_false(_multicast),
			_addr_flags, _prefix);
    if (_point_to_point)
	r += c_format(" { endpoint := %s }", _oaddr.str().c_str());
    if (_broadcast)
	r += c_format(" { broadcast := %s }", _oaddr.str().c_str());
    r += string(" ") + IfTreeItem::str();
    return r;
}

/* ------------------------------------------------------------------------- */
/* IfTreeAddr6 code */

bool
IfTreeAddr6::set_prefix(uint32_t prefix)
{

    if (prefix > IPv6::addr_bitlen())
	return false;

    _prefix = prefix;
    mark(CHANGED);
    return true;
}

void
IfTreeAddr6::set_endpoint(const IPv6& eaddr)
{
    set_point_to_point(false);
    if (eaddr != IPv6::ZERO())
	set_point_to_point(true);
    _oaddr = eaddr;
    mark(CHANGED);
}

IPv6
IfTreeAddr6::endpoint() const
{
    if (point_to_point())
	return _oaddr;
    return IPv6::ZERO();
}

void
IfTreeAddr6::finalize_state()
{
    set_state(NO_CHANGE);
}

string
IfTreeAddr6::str() const
{
    string r = c_format("V6Addr %s { enabled := %s } "
			"{ loopback := %s } { point_to_point := %s } "
			"{ multicast := %s } { flags := 0x%02x } "
			"{ prefix := %d }",
			_addr.str().c_str(), true_false(_enabled),
			true_false(_loopback),
			true_false(_point_to_point), true_false(_multicast),
			_addr_flags, _prefix);
    if (_point_to_point)
	r += c_format(" { endpoint := %s }", _oaddr.str().c_str());
    r += string(" ") + IfTreeItem::str();
    return r;
}
