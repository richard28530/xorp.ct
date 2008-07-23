/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP$"


#include "rtrmgr_base.hh"


XrlRtrmgrTargetBase::XrlRtrmgrTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlRtrmgrTargetBase::~XrlRtrmgrTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlRtrmgrTargetBase::set_command_map(XrlCmdMap* cmds)
{
    if (_cmds == 0 && cmds) {
        _cmds = cmds;
        add_handlers();
        return true;
    }
    if (_cmds && cmds == 0) {
	remove_handlers();
        _cmds = cmds;
        return true;
    }
    return false;
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_common_0_1_get_target_name(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_target_name");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string name;
    try {
	XrlCmdError e = common_0_1_get_target_name(
	    name);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_target_name", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("name", name);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_common_0_1_get_version(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_version");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string version;
    try {
	XrlCmdError e = common_0_1_get_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_version", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_common_0_1_get_status(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_status");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t status;
    string reason;
    try {
	XrlCmdError e = common_0_1_get_status(
	    status,
	    reason);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_status", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("status", status);
	pxa_outputs->add("reason", reason);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_common_0_1_shutdown(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/shutdown");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = common_0_1_shutdown();
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/shutdown", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_get_pid(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/get_pid");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t pid;
    try {
	XrlCmdError e = rtrmgr_0_1_get_pid(
	    pid);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/get_pid", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("pid", pid);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_register_client(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/register_client");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string filename;
    uint32_t pid;
    uint32_t clientid;
    try {
	XrlCmdError e = rtrmgr_0_1_register_client(
	    xa_inputs.get_uint32("userid"),
	    xa_inputs.get_string("clientname"),
	    filename,
	    pid,
	    clientid);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/register_client", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("filename", filename);
	pxa_outputs->add("pid", pid);
	pxa_outputs->add("clientid", clientid);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_unregister_client(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/unregister_client");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_unregister_client(
	    xa_inputs.get_string("token"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/unregister_client", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_authenticate_client(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(3), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/authenticate_client");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_authenticate_client(
	    xa_inputs.get_uint32("userid"),
	    xa_inputs.get_string("clientname"),
	    xa_inputs.get_string("token"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/authenticate_client", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_enter_config_mode(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/enter_config_mode");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_enter_config_mode(
	    xa_inputs.get_string("token"),
	    xa_inputs.get_bool("exclusive"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/enter_config_mode", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_leave_config_mode(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/leave_config_mode");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_leave_config_mode(
	    xa_inputs.get_string("token"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/leave_config_mode", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_get_config_users(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/get_config_users");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    XrlAtomList users;
    try {
	XrlCmdError e = rtrmgr_0_1_get_config_users(
	    xa_inputs.get_string("token"),
	    users);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/get_config_users", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("users", users);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_get_running_config(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/get_running_config");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    bool ready;
    string config;
    try {
	XrlCmdError e = rtrmgr_0_1_get_running_config(
	    xa_inputs.get_string("token"),
	    ready,
	    config);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/get_running_config", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("ready", ready);
	pxa_outputs->add("config", config);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_apply_config_change(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 4) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(4), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/apply_config_change");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_apply_config_change(
	    xa_inputs.get_string("token"),
	    xa_inputs.get_string("target"),
	    xa_inputs.get_string("deltas"),
	    xa_inputs.get_string("deletions"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/apply_config_change", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_lock_config(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/lock_config");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    bool success;
    uint32_t holder;
    try {
	XrlCmdError e = rtrmgr_0_1_lock_config(
	    xa_inputs.get_string("token"),
	    xa_inputs.get_uint32("timeout"),
	    success,
	    holder);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/lock_config", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("success", success);
	pxa_outputs->add("holder", holder);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_unlock_config(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/unlock_config");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_unlock_config(
	    xa_inputs.get_string("token"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/unlock_config", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_lock_node(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(3), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/lock_node");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    bool success;
    uint32_t holder;
    try {
	XrlCmdError e = rtrmgr_0_1_lock_node(
	    xa_inputs.get_string("token"),
	    xa_inputs.get_string("node"),
	    xa_inputs.get_uint32("timeout"),
	    success,
	    holder);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/lock_node", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("success", success);
	pxa_outputs->add("holder", holder);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_unlock_node(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/unlock_node");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_unlock_node(
	    xa_inputs.get_string("token"),
	    xa_inputs.get_string("node"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/unlock_node", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_save_config(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(3), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/save_config");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_save_config(
	    xa_inputs.get_string("token"),
	    xa_inputs.get_string("target"),
	    xa_inputs.get_string("filename"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/save_config", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_load_config(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(3), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/load_config");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_load_config(
	    xa_inputs.get_string("token"),
	    xa_inputs.get_string("target"),
	    xa_inputs.get_string("filename"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/load_config", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_rtrmgr_0_1_set_config_directory(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr/0.1/set_config_directory");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_0_1_set_config_directory(
	    xa_inputs.get_string("config_directory"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr/0.1/set_config_directory", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "finder_event_observer/0.1/xrl_target_birth");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_event_observer_0_1_xrl_target_birth(
	    xa_inputs.get_string("target_class"),
	    xa_inputs.get_string("target_instance"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_event_observer/0.1/xrl_target_birth", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRtrmgrTargetBase::handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "finder_event_observer/0.1/xrl_target_death");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_event_observer_0_1_xrl_target_death(
	    xa_inputs.get_string("target_class"),
	    xa_inputs.get_string("target_instance"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_event_observer/0.1/xrl_target_death", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

void
XrlRtrmgrTargetBase::add_handlers()
{
	if (_cmds->add_handler("common/0.1/get_target_name",
	    callback(this, &XrlRtrmgrTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version",
	    callback(this, &XrlRtrmgrTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "common/0.1/get_version");
	}
	if (_cmds->add_handler("common/0.1/get_status",
	    callback(this, &XrlRtrmgrTargetBase::handle_common_0_1_get_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "common/0.1/get_status");
	}
	if (_cmds->add_handler("common/0.1/shutdown",
	    callback(this, &XrlRtrmgrTargetBase::handle_common_0_1_shutdown)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "common/0.1/shutdown");
	}
	if (_cmds->add_handler("rtrmgr/0.1/get_pid",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_get_pid)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/get_pid");
	}
	if (_cmds->add_handler("rtrmgr/0.1/register_client",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_register_client)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/register_client");
	}
	if (_cmds->add_handler("rtrmgr/0.1/unregister_client",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_unregister_client)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/unregister_client");
	}
	if (_cmds->add_handler("rtrmgr/0.1/authenticate_client",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_authenticate_client)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/authenticate_client");
	}
	if (_cmds->add_handler("rtrmgr/0.1/enter_config_mode",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_enter_config_mode)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/enter_config_mode");
	}
	if (_cmds->add_handler("rtrmgr/0.1/leave_config_mode",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_leave_config_mode)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/leave_config_mode");
	}
	if (_cmds->add_handler("rtrmgr/0.1/get_config_users",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_get_config_users)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/get_config_users");
	}
	if (_cmds->add_handler("rtrmgr/0.1/get_running_config",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_get_running_config)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/get_running_config");
	}
	if (_cmds->add_handler("rtrmgr/0.1/apply_config_change",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_apply_config_change)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/apply_config_change");
	}
	if (_cmds->add_handler("rtrmgr/0.1/lock_config",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_lock_config)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/lock_config");
	}
	if (_cmds->add_handler("rtrmgr/0.1/unlock_config",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_unlock_config)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/unlock_config");
	}
	if (_cmds->add_handler("rtrmgr/0.1/lock_node",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_lock_node)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/lock_node");
	}
	if (_cmds->add_handler("rtrmgr/0.1/unlock_node",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_unlock_node)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/unlock_node");
	}
	if (_cmds->add_handler("rtrmgr/0.1/save_config",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_save_config)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/save_config");
	}
	if (_cmds->add_handler("rtrmgr/0.1/load_config",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_load_config)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/load_config");
	}
	if (_cmds->add_handler("rtrmgr/0.1/set_config_directory",
	    callback(this, &XrlRtrmgrTargetBase::handle_rtrmgr_0_1_set_config_directory)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "rtrmgr/0.1/set_config_directory");
	}
	if (_cmds->add_handler("finder_event_observer/0.1/xrl_target_birth",
	    callback(this, &XrlRtrmgrTargetBase::handle_finder_event_observer_0_1_xrl_target_birth)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "finder_event_observer/0.1/xrl_target_birth");
	}
	if (_cmds->add_handler("finder_event_observer/0.1/xrl_target_death",
	    callback(this, &XrlRtrmgrTargetBase::handle_finder_event_observer_0_1_xrl_target_death)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "rtrmgr", "finder_event_observer/0.1/xrl_target_death");
	}
	_cmds->finalize();
}

void
XrlRtrmgrTargetBase::remove_handlers()
{
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("common/0.1/get_status");
	_cmds->remove_handler("common/0.1/shutdown");
	_cmds->remove_handler("rtrmgr/0.1/get_pid");
	_cmds->remove_handler("rtrmgr/0.1/register_client");
	_cmds->remove_handler("rtrmgr/0.1/unregister_client");
	_cmds->remove_handler("rtrmgr/0.1/authenticate_client");
	_cmds->remove_handler("rtrmgr/0.1/enter_config_mode");
	_cmds->remove_handler("rtrmgr/0.1/leave_config_mode");
	_cmds->remove_handler("rtrmgr/0.1/get_config_users");
	_cmds->remove_handler("rtrmgr/0.1/get_running_config");
	_cmds->remove_handler("rtrmgr/0.1/apply_config_change");
	_cmds->remove_handler("rtrmgr/0.1/lock_config");
	_cmds->remove_handler("rtrmgr/0.1/unlock_config");
	_cmds->remove_handler("rtrmgr/0.1/lock_node");
	_cmds->remove_handler("rtrmgr/0.1/unlock_node");
	_cmds->remove_handler("rtrmgr/0.1/save_config");
	_cmds->remove_handler("rtrmgr/0.1/load_config");
	_cmds->remove_handler("rtrmgr/0.1/set_config_directory");
	_cmds->remove_handler("finder_event_observer/0.1/xrl_target_birth");
	_cmds->remove_handler("finder_event_observer/0.1/xrl_target_death");
}
