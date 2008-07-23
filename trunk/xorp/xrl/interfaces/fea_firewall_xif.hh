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

#ifndef __XRL_INTERFACES_FEA_FIREWALL_XIF_HH__
#define __XRL_INTERFACES_FEA_FIREWALL_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaFirewall"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFeaFirewallV0p1Client {
public:
    XrlFeaFirewallV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFeaFirewallV0p1Client() {}

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr StartTransactionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Start firewall configuration transaction.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_start_transaction(
	const char*	dst_xrl_target_name,
	const StartTransactionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CommitTransactionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Commit firewall configuration transaction.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     */
    bool send_commit_transaction(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const CommitTransactionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AbortTransactionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Abort firewall configuration transaction.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     */
    bool send_abort_transaction(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const AbortTransactionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddEntry4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add an IPv4 firewall entry.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param rule_number the rule number for this entry.
     *
     *  @param ifname the name of the interface where this filter is to be
     *  applied.
     *
     *  @param vifname the name of the vif where this filter is to be applied.
     *
     *  @param src_network the source IPv4 network address prefix.
     *
     *  @param dst_network the destination IPv4 network address prefix.
     *
     *  @param ip_protocol the IP protocol number (1-255, or 0 if wildcard).
     *
     *  @param src_port_begin the source TCP/UDP begin port (0-65535).
     *
     *  @param src_port_end the source TCP/UDP end port (0-65535).
     *
     *  @param dst_port_begin the destination TCP/UDP begin port (0-65535).
     *
     *  @param dst_port_end the destination TCP/UDP end port (0-65535).
     *
     *  @param action the action to be taken when this filter is matched. It is
     *  one of the following keywords: "none", "pass", "drop", "reject".
     */
    bool send_add_entry4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src_network,
	const IPv4Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const AddEntry4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ReplaceEntry4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Replace an IPv4 firewall entry.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param rule_number the rule number for this entry.
     *
     *  @param ifname the name of the interface where this filter is to be
     *  applied.
     *
     *  @param vifname the name of the vif where this filter is to be applied.
     *
     *  @param src_network the source IPv4 network address prefix.
     *
     *  @param dst_network the destination IPv4 network address prefix.
     *
     *  @param ip_protocol the IP protocol number (1-255, or 0 if wildcard).
     *
     *  @param src_port_begin the source TCP/UDP begin port (0-65535).
     *
     *  @param src_port_end the source TCP/UDP end port (0-65535).
     *
     *  @param dst_port_begin the destination TCP/UDP begin port (0-65535).
     *
     *  @param dst_port_end the destination TCP/UDP end port (0-65535).
     *
     *  @param action the action to be taken when this filter is matched. It is
     *  one of the following keywords: "none", "pass", "drop", "reject".
     */
    bool send_replace_entry4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src_network,
	const IPv4Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const ReplaceEntry4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteEntry4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete an IPv4 firewall entry.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param rule_number the rule number for this entry.
     *
     *  @param ifname the name of the interface where this filter is to be
     *  deleted.
     *
     *  @param vifname the name of the vif where this filter is to be deleted.
     *
     *  @param src_network the source IPv4 network address prefix.
     *
     *  @param dst_network the destination IPv4 network address prefix.
     *
     *  @param ip_protocol the IP protocol number (1-255, or 0 if wildcard).
     *
     *  @param src_port_begin the source TCP/UDP begin port (0-65535).
     *
     *  @param src_port_end the source TCP/UDP end port (0-65535).
     *
     *  @param dst_port_begin the destination TCP/UDP begin port (0-65535).
     *
     *  @param dst_port_end the destination TCP/UDP end port (0-65535).
     */
    bool send_delete_entry4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src_network,
	const IPv4Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const DeleteEntry4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAllEntries4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete all IPv4 firewall entries.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     */
    bool send_delete_all_entries4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const DeleteAllEntries4CB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const bool*>::RefPtr GetEntryListStart4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Get a token for a list of IPv4 firewall entries.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_entry_list_start4(
	const char*	dst_xrl_target_name,
	const GetEntryListStart4CB&	cb
    );

    typedef XorpCallback13<void, const XrlError&, const uint32_t*, const string*, const string*, const IPv4Net*, const IPv4Net*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const string*, const bool*>::RefPtr GetEntryListNext4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the next item in a list of IPv4 firewall entries.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param token returned by a previous call to get_entry_list_start4.
     */
    bool send_get_entry_list_next4(
	const char*	dst_xrl_target_name,
	const uint32_t&	token,
	const GetEntryListNext4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddEntry6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add an IPv6 firewall entry.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param rule_number the rule number for this entry.
     *
     *  @param ifname the name of the interface where this filter is to be
     *  applied.
     *
     *  @param vifname the name of the vif where this filter is to be applied.
     *
     *  @param src_network the source IPv6 network address prefix.
     *
     *  @param dst_network the destination IPv6 network address prefix.
     *
     *  @param ip_protocol the IP protocol number (1-255, or 0 if wildcard).
     *
     *  @param src_port_begin the source TCP/UDP begin port (0-65535).
     *
     *  @param src_port_end the source TCP/UDP end port (0-65535).
     *
     *  @param dst_port_begin the destination TCP/UDP begin port (0-65535).
     *
     *  @param dst_port_end the destination TCP/UDP end port (0-65535).
     *
     *  @param action the action to be taken when this filter is matched. It is
     *  one of the following keywords: "none", "pass", "drop", "reject".
     */
    bool send_add_entry6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src_network,
	const IPv6Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const AddEntry6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ReplaceEntry6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Replace an IPv6 firewall entry.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param rule_number the rule number for this entry.
     *
     *  @param ifname the name of the interface where this filter is to be
     *  applied.
     *
     *  @param vifname the name of the vif where this filter is to be applied.
     *
     *  @param src_network the source IPv6 network address prefix.
     *
     *  @param dst_network the destination IPv6 network address prefix.
     *
     *  @param ip_protocol the IP protocol number (1-255, or 0 if wildcard).
     *
     *  @param src_port_begin the source TCP/UDP begin port (0-65535).
     *
     *  @param src_port_end the source TCP/UDP end port (0-65535).
     *
     *  @param dst_port_begin the destination TCP/UDP begin port (0-65535).
     *
     *  @param dst_port_end the destination TCP/UDP end port (0-65535).
     *
     *  @param action the action to be taken when this filter is matched. It is
     *  one of the following keywords: "none", "pass", "drop", "reject".
     */
    bool send_replace_entry6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src_network,
	const IPv6Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const ReplaceEntry6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteEntry6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete an IPv6 firewall entry.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param rule_number the rule number for this entry.
     *
     *  @param ifname the name of the interface where this filter is to be
     *  deleted.
     *
     *  @param vifname the name of the vif where this filter is to be deleted.
     *
     *  @param src_network the source IPv6 network address prefix.
     *
     *  @param dst_network the destination IPv6 network address prefix.
     *
     *  @param ip_protocol the IP protocol number (1-255, or 0 if wildcard).
     *
     *  @param src_port_begin the source TCP/UDP begin port (0-65535).
     *
     *  @param src_port_end the source TCP/UDP end port (0-65535).
     *
     *  @param dst_port_begin the destination TCP/UDP begin port (0-65535).
     *
     *  @param dst_port_end the destination TCP/UDP end port (0-65535).
     */
    bool send_delete_entry6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src_network,
	const IPv6Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const DeleteEntry6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAllEntries6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete all IPv6 firewall entries.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param tid the transaction ID for this operation.
     */
    bool send_delete_all_entries6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const DeleteAllEntries6CB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const bool*>::RefPtr GetEntryListStart6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Get a token for a list of IPv6 firewall entries.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_entry_list_start6(
	const char*	dst_xrl_target_name,
	const GetEntryListStart6CB&	cb
    );

    typedef XorpCallback13<void, const XrlError&, const uint32_t*, const string*, const string*, const IPv6Net*, const IPv6Net*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const string*, const bool*>::RefPtr GetEntryListNext6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the next item in a list of IPv6 firewall entries.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param token returned by a previous call to get_entry_list_start6.
     */
    bool send_get_entry_list_next6(
	const char*	dst_xrl_target_name,
	const uint32_t&	token,
	const GetEntryListNext6CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_start_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	StartTransactionCB		cb
    );

    void unmarshall_commit_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	CommitTransactionCB		cb
    );

    void unmarshall_abort_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	AbortTransactionCB		cb
    );

    void unmarshall_add_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	AddEntry4CB		cb
    );

    void unmarshall_replace_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceEntry4CB		cb
    );

    void unmarshall_delete_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEntry4CB		cb
    );

    void unmarshall_delete_all_entries4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllEntries4CB		cb
    );

    void unmarshall_get_entry_list_start4(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListStart4CB		cb
    );

    void unmarshall_get_entry_list_next4(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListNext4CB		cb
    );

    void unmarshall_add_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	AddEntry6CB		cb
    );

    void unmarshall_replace_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceEntry6CB		cb
    );

    void unmarshall_delete_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEntry6CB		cb
    );

    void unmarshall_delete_all_entries6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllEntries6CB		cb
    );

    void unmarshall_get_entry_list_start6(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListStart6CB		cb
    );

    void unmarshall_get_entry_list_next6(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListNext6CB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_FIREWALL_XIF_HH__ */
