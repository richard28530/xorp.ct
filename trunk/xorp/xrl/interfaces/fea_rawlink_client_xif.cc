/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "fea_rawlink_client_xif.hh"

bool
XrlRawLinkClientV0p1Client::send_recv(
	const char*	dst_xrl_target_name,
	const string&	if_name,
	const string&	vif_name,
	const Mac&	src_address,
	const Mac&	dst_address,
	const uint32_t&	ether_type,
	const vector<uint8_t>&	payload,
	const RecvCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "raw_link_client/0.1/recv");
    x.args().add("if_name", if_name);
    x.args().add("vif_name", vif_name);
    x.args().add("src_address", src_address);
    x.args().add("dst_address", dst_address);
    x.args().add("ether_type", ether_type);
    x.args().add("payload", payload);
    return _sender->send(x, callback(this, &XrlRawLinkClientV0p1Client::unmarshall_recv, cb));
}


/* Unmarshall recv */
void
XrlRawLinkClientV0p1Client::unmarshall_recv(
	const XrlError&	e,
	XrlArgs*	a,
	RecvCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
