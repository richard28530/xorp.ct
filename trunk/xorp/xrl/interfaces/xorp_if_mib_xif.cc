/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "xorp_if_mib_xif.hh"

bool
XrlXorpIfMibV0p1Client::send_load_mib(
	const char*	dst_xrl_target_name,
	const string&	mod_name,
	const string&	abs_path,
	const LoadMibCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "xorp_if_mib/0.1/load_mib");
    x.args().add("mod_name", mod_name);
    x.args().add("abs_path", abs_path);
    return _sender->send(x, callback(this, &XrlXorpIfMibV0p1Client::unmarshall_load_mib, cb));
}


/* Unmarshall load_mib */
void
XrlXorpIfMibV0p1Client::unmarshall_load_mib(
	const XrlError&	e,
	XrlArgs*	a,
	LoadMibCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t mib_index;
    try {
	a->get("mib_index", mib_index);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &mib_index);
}

bool
XrlXorpIfMibV0p1Client::send_unload_mib(
	const char*	dst_xrl_target_name,
	const uint32_t&	mib_index,
	const UnloadMibCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "xorp_if_mib/0.1/unload_mib");
    x.args().add("mib_index", mib_index);
    return _sender->send(x, callback(this, &XrlXorpIfMibV0p1Client::unmarshall_unload_mib, cb));
}


/* Unmarshall unload_mib */
void
XrlXorpIfMibV0p1Client::unmarshall_unload_mib(
	const XrlError&	e,
	XrlArgs*	a,
	UnloadMibCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool unloaded;
    try {
	a->get("unloaded", unloaded);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &unloaded);
}
