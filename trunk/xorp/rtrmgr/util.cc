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

#ident "$XORP: xorp/rtrmgr/util.cc,v 1.1 2003/09/24 16:16:08 hodson Exp $"

#include <list>
#include <string>

#include "rtrmgr_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "util.hh"

static string s_cfg_root;
static string s_bin_root;
static string s_boot_file;

list<string>
split(const string& s, char ch)
{
    list <string> parts;
    string s2 = s;
    size_t ix;
    ix = s2.find(ch);
    while (ix != string::npos) {
	parts.push_back(s2.substr(0,ix));
	s2 = s2.substr(ix+1, s2.size()-ix);
	ix = s2.find(ch);
    }
    if (!s2.empty())
	parts.push_back(s2);
    return parts;
}

string
find_exec_path_name(const char *progname)
{
    XLOG_ASSERT(strlen(progname) <= MAXPATHLEN);

    //
    // Look for trailing slash in progname
    //
    const char* p = strrchr(progname, '/');
    if (p) {
	return string(progname, p);
    }

    //
    // Go through the PATH environment variable and find the program location
    //
    string slash_progname("/");
    slash_progname += progname;
    const char* s = getenv("PATH");
    while (s != NULL && *s != '\0') {
	const char* e = strchr(s, ':');
	string path;
	if (e) {
	    path = string(s, e);
	    s = e + 1;
	} else {
	    path = string(s);
	    s = NULL;
	}
	string complete_path = path + slash_progname;
	if (access(complete_path.c_str(), X_OK) == 0) {
	    return path;
	}
    }
    return string("");
}

static string
xorp_real_path(const string& path)
{
    char rp[MAXPATHLEN + 1];
    const char* prp = realpath(path.c_str(), rp);
    if (prp) {
	return string(prp);
    }
    XLOG_WARNING("realpath(%s) failed.", path.c_str());
    return path;
}

void
xorp_path_init(const char* argv0)
{
    const char* xr = getenv("XORP_ROOT");
    if (xr != NULL) {
	s_bin_root = xr;
	s_cfg_root = xr;
	s_boot_file = s_cfg_root + "/rtrmgr/config.boot";
	return;
    }

    string current_root = find_exec_path_name(argv0) + "/..";
    current_root = xorp_real_path(current_root);

    string build_root = xorp_real_path(XORP_BUILD_ROOT);
    if (current_root == build_root) {
	s_bin_root = build_root;
	s_cfg_root = xorp_real_path(XORP_SRC_ROOT);
	s_boot_file = s_cfg_root + "/rtrmgr/config.boot";
	return;
    }

    string install_root = xorp_real_path(XORP_INSTALL_ROOT);
    s_bin_root = install_root;
    s_cfg_root = install_root;
    s_boot_file = s_cfg_root + "/config.boot";
}

const string&
xorp_binary_root_dir()
{
    return s_bin_root;
}

const string&
xorp_config_root_dir()
{
    return s_cfg_root;
}

string
xorp_template_dir()
{
    return s_cfg_root + string("/etc/templates");
}

string
xorp_xrl_targets_dir()
{
    return s_cfg_root + string("/xrl/targets");
}

string
xorp_boot_file()
{
    return s_boot_file;
}

const char*
xorp_basename(const char* argv0)
{
    const char* p = strrchr(argv0, '/');
    if (p) {
	return p + 1;
    }
    return argv0;
}
