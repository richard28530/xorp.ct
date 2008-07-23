/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP$
 */


#ifndef __XRL_TARGETS_FIB2MRIB_BASE_HH__
#define __XRL_TARGETS_FIB2MRIB_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlFib2mribTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlFib2mribTargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlFib2mribTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlFib2mribTargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    const char* version() const { return "fib2mrib/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target birth to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_birth(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target death to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_death(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Notification of a route being added.
     *
     *  @param network the network address prefix of the route to add.
     *
     *  @param nexthop the address of the next-hop router toward the
     *  destination.
     *
     *  @param ifname the name of the physical interface toward the
     *  destination.
     *
     *  @param vifname the name of the virtual interface toward the
     *  destination.
     *
     *  @param metric the routing metric toward the destination.
     *
     *  @param admin_distance the administratively defined distance toward the
     *  destination.
     *
     *  @param protocol_origin the name of the protocol that originated this
     *  route.
     *
     *  @param xorp_route true if this route was installed by XORP.
     */
    virtual XrlCmdError fea_fib_client_0_1_add_route4(
	// Input values,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const bool&	xorp_route) = 0;

    virtual XrlCmdError fea_fib_client_0_1_add_route6(
	// Input values,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const bool&	xorp_route) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Notification of a route being replaced.
     *
     *  @param network the network address prefix of the route to replace.
     *
     *  @param nexthop the address of the next-hop router toward the
     *  destination.
     *
     *  @param ifname the name of the physical interface toward the
     *  destination.
     *
     *  @param vifname the name of the virtual interface toward the
     *  destination.
     *
     *  @param metric the routing metric toward the destination.
     *
     *  @param admin_distance the administratively defined distance toward the
     *  destination.
     *
     *  @param protocol_origin the name of the protocol that originated this
     *  route.
     *
     *  @param xorp_route true if this route was installed by XORP.
     */
    virtual XrlCmdError fea_fib_client_0_1_replace_route4(
	// Input values,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const bool&	xorp_route) = 0;

    virtual XrlCmdError fea_fib_client_0_1_replace_route6(
	// Input values,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const bool&	xorp_route) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Notification of a route being deleted.
     *
     *  @param network the network address prefix of the route to delete.
     *
     *  @param ifname the name of the physical interface toward the
     *  destination.
     *
     *  @param vifname the name of the virtual interface toward the
     *  destination.
     */
    virtual XrlCmdError fea_fib_client_0_1_delete_route4(
	// Input values,
	const IPv4Net&	network,
	const string&	ifname,
	const string&	vifname) = 0;

    virtual XrlCmdError fea_fib_client_0_1_delete_route6(
	// Input values,
	const IPv6Net&	network,
	const string&	ifname,
	const string&	vifname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Notification of a route resolution request. This is issued when the
     *  forwarding plane cannot find any route to a given destination, even a
     *  candidate default.
     *
     *  @param network the address of the destination. forwarding plane
     *  requires a route to be resolved by the upper layer.
     */
    virtual XrlCmdError fea_fib_client_0_1_resolve_route4(
	// Input values,
	const IPv4Net&	network) = 0;

    virtual XrlCmdError fea_fib_client_0_1_resolve_route6(
	// Input values,
	const IPv6Net&	network) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Configure a policy filter.
     *
     *  @param filter the identifier of the filter to configure.
     *
     *  @param conf the configuration of the filter.
     */
    virtual XrlCmdError policy_backend_0_1_configure(
	// Input values,
	const uint32_t&	filter,
	const string&	conf) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Reset a policy filter.
     *
     *  @param filter the identifier of the filter to reset.
     */
    virtual XrlCmdError policy_backend_0_1_reset(
	// Input values,
	const uint32_t&	filter) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Push all available routes through all filters for re-filtering.
     */
    virtual XrlCmdError policy_backend_0_1_push_routes() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable/start/stop Fib2mrib.
     *
     *  @param enable if true, then enable Fib2mrib, otherwise disable it.
     */
    virtual XrlCmdError fib2mrib_0_1_enable_fib2mrib(
	// Input values,
	const bool&	enable) = 0;

    virtual XrlCmdError fib2mrib_0_1_start_fib2mrib() = 0;

    virtual XrlCmdError fib2mrib_0_1_stop_fib2mrib() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable the Fib2mrib trace log for all operations.
     *
     *  @param enable if true, then enable the trace log, otherwise disable it.
     */
    virtual XrlCmdError fib2mrib_0_1_enable_log_trace_all(
	// Input values,
	const bool&	enable) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_add_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_add_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_replace_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_replace_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_delete_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_delete_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_resolve_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_fib_client_0_1_resolve_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_configure(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_reset(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_push_routes(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fib2mrib_0_1_enable_fib2mrib(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fib2mrib_0_1_start_fib2mrib(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fib2mrib_0_1_stop_fib2mrib(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fib2mrib_0_1_enable_log_trace_all(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif // __XRL_TARGETS_FIB2MRIB_BASE_HH__
