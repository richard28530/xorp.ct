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

#ifndef __XRL_INTERFACES_CLI_PROCESSOR_XIF_HH__
#define __XRL_INTERFACES_CLI_PROCESSOR_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifCliProcessor"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlCliProcessorV0p1Client {
public:
    XrlCliProcessorV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlCliProcessorV0p1Client() {}

    typedef XorpCallback5<void, const XrlError&, const string*, const string*, const uint32_t*, const string*>::RefPtr ProcessCommandCB;
    /**
     *  Send Xrl intended to:
     *
     *  Process a CLI command.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param processor_name the processor name for this command.
     *
     *  @param cli_term_name the terminal name the command was entered from.
     *
     *  @param cli_session_id the CLI session ID the command was entered from.
     *
     *  @param command_name the command name to process.
     *
     *  @param command_args the command arguments to process.
     */
    bool send_process_command(
	const char*	dst_xrl_target_name,
	const string&	processor_name,
	const string&	cli_term_name,
	const uint32_t&	cli_session_id,
	const string&	command_name,
	const string&	command_args,
	const ProcessCommandCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_process_command(
	const XrlError&	e,
	XrlArgs*	a,
	ProcessCommandCB		cb
    );

};

#endif /* __XRL_INTERFACES_CLI_PROCESSOR_XIF_HH__ */
