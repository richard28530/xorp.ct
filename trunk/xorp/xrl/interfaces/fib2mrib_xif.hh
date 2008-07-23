/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP$
 */

#ifndef __XRL_INTERFACES_FIB2MRIB_XIF_HH__
#define __XRL_INTERFACES_FIB2MRIB_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFib2mrib"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFib2mribV0p1Client {
public:
    XrlFib2mribV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFib2mribV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableFib2MribCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop Fib2mrib.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable Fib2mrib, otherwise disable it.
     */
    bool send_enable_fib2mrib(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableFib2MribCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartFib2MribCB;

    bool send_start_fib2mrib(
	const char*	dst_xrl_target_name,
	const StartFib2MribCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopFib2MribCB;

    bool send_stop_fib2mrib(
	const char*	dst_xrl_target_name,
	const StopFib2MribCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableLogTraceAllCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable the Fib2mrib trace log for all operations.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the trace log, otherwise disable it.
     */
    bool send_enable_log_trace_all(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableLogTraceAllCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_enable_fib2mrib(
	const XrlError&	e,
	XrlArgs*	a,
	EnableFib2MribCB		cb
    );

    void unmarshall_start_fib2mrib(
	const XrlError&	e,
	XrlArgs*	a,
	StartFib2MribCB		cb
    );

    void unmarshall_stop_fib2mrib(
	const XrlError&	e,
	XrlArgs*	a,
	StopFib2MribCB		cb
    );

    void unmarshall_enable_log_trace_all(
	const XrlError&	e,
	XrlArgs*	a,
	EnableLogTraceAllCB		cb
    );

};

#endif /* __XRL_INTERFACES_FIB2MRIB_XIF_HH__ */
