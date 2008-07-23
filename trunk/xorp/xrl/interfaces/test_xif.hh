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

#ifndef __XRL_INTERFACES_TEST_XIF_HH__
#define __XRL_INTERFACES_TEST_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifTest"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlTestV1p0Client {
public:
    XrlTestV1p0Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlTestV1p0Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr PrintHelloWorldCB;
    /**
     *  Send Xrl intended to:
     *
     *  Print "hello world".
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_print_hello_world(
	const char*	dst_xrl_target_name,
	const PrintHelloWorldCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr PrintHelloWorldAndMessageCB;
    /**
     *  Send Xrl intended to:
     *
     *  Print "hello world" and a user supplied greeting.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param msg greeting to be printed.
     */
    bool send_print_hello_world_and_message(
	const char*	dst_xrl_target_name,
	const string&	msg,
	const PrintHelloWorldAndMessageCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr GetGreetingCountCB;
    /**
     *  Send Xrl intended to:
     *
     *  Count number of greetings available.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_greeting_count(
	const char*	dst_xrl_target_name,
	const GetGreetingCountCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr GetGreetingCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get greeting.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param greeting_num index of greeting.
     */
    bool send_get_greeting(
	const char*	dst_xrl_target_name,
	const int32_t&	greeting_num,
	const GetGreetingCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ShootFootCB;
    /**
     *  Send Xrl intended to:
     *
     *  Something that always fails.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_shoot_foot(
	const char*	dst_xrl_target_name,
	const ShootFootCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_print_hello_world(
	const XrlError&	e,
	XrlArgs*	a,
	PrintHelloWorldCB		cb
    );

    void unmarshall_print_hello_world_and_message(
	const XrlError&	e,
	XrlArgs*	a,
	PrintHelloWorldAndMessageCB		cb
    );

    void unmarshall_get_greeting_count(
	const XrlError&	e,
	XrlArgs*	a,
	GetGreetingCountCB		cb
    );

    void unmarshall_get_greeting(
	const XrlError&	e,
	XrlArgs*	a,
	GetGreetingCB		cb
    );

    void unmarshall_shoot_foot(
	const XrlError&	e,
	XrlArgs*	a,
	ShootFootCB		cb
    );

};

#endif /* __XRL_INTERFACES_TEST_XIF_HH__ */
