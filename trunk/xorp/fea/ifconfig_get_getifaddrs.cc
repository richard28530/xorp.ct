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

#ident "$XORP: xorp/fea/ifconfig_rtsock.cc,v 1.5 2003/03/10 23:20:15 hodson Exp $"


#include "fea_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"

#ifdef HAVE_IFADDRS_H
#include <ifaddrs.h>
#endif

#include "ifconfig.hh"
#include "ifconfig_get.hh"


//
// Get information about the network interfaces from the underlying system.
//
// The mechanism to obtain the information is getifaddrs(3).
//


IfConfigGetGetifaddrs::IfConfigGetGetifaddrs(IfConfig& ifc)
    : IfConfigGet(ifc)
{
#ifdef HAVE_GETIFADDRS
    register_ifc();
#endif
}

IfConfigGetGetifaddrs::~IfConfigGetGetifaddrs()
{
    
}

int
IfConfigGetGetifaddrs::start()
{
    return (XORP_OK);
}

int
IfConfigGetGetifaddrs::stop()
{
    return (XORP_OK);
}

void
IfConfigGetGetifaddrs::receive_data(const uint8_t* data, size_t n_bytes)
{
    //
    // XXX: we don't receive the data asynchronously, hence we pull-out
    // everything.
    //
    if (pull_config(ifc().live_config()) < 0)
	return;
    
    debug_msg("Start configuration read:\n");
    debug_msg_indent(4);
    debug_msg("%s\n", ifc().live_config().str().c_str());
    debug_msg_indent(0);
    debug_msg("\nEnd configuration read.\n");
    
    ifc().report_updates(ifc().live_config());
    ifc().live_config().finalize_state();
    
    UNUSED(data);
    UNUSED(n_bytes);
}

int
IfConfigGetGetifaddrs::pull_config(IfTree& iftree)
{
    return read_config(iftree);
}

#ifndef HAVE_GETIFADDRS
int
IfConfigGetGetifaddrs::read_config(IfTree& )
{
    return (XORP_ERROR);
}

#else // HAVE_GETIFADDRS
int
IfConfigGetGetifaddrs::read_config(IfTree& it)
{
    struct ifaddrs *ifap;
    
    if (getifaddrs(&ifap) != 0) {
	XLOG_ERROR("getifaddrs() failed: %s", strerror(errno));
	return (XORP_ERROR);
    }
    
    parse_buffer_ifaddrs(it, (const ifaddrs **)&ifap);
    freeifaddrs(ifap);
    
    return (XORP_OK);
}

#endif // HAVE_GETIFADDRS
