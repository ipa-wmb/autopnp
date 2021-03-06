#
# Copyright (c) 2011-2014, fortiss GmbH.
# Licensed under the Apache License, Version 2.0.
# 
# Use, modification and distribution are subject to the terms specified
# in the accompanying license file LICENSE.txt located at the root directory
# of this software distribution. A copy is available at
# http://chromosome.fortiss.org/.
#
# This file is part of CHROMOSOME.
#
# $Id: CMakeLists.txt 7637 2014-03-03 09:38:45Z kainz $
#         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
#         (fortiss GmbH).

# This is the node-specific CMakeLists.txt for the master node of the
# ROSGateway project. Use it for building the node in a build
# system of its own. This is meaningful if the node uses a different compiler
# toolchain than other nodes of the same project. If all nodes are compiled
# using the same toolchain for the same platform, you may use the top-level
# CMakeLists.txt file located in ../../../ instead to generate a single
# build system for all nodes.

cmake_minimum_required (VERSION 2.8.3)

set (NODE_NAME "master")
project (${NODE_NAME})

# Main project settings
set_property (GLOBAL PROPERTY XME_TARGET_IDENTIFIER "posix")
include ("../../../../CMakeCommon.txt")

# Add project specific include directories
xme_include_directory ("../..")

# PROTECTED REGION ID(APPLICATION_MASTER_CMAKELISTS_TXT_INCLUDES) ENABLED START
add_definitions(-DXME_MULTITHREAD)
# PROTECTED REGION END

# Needed to ensure PRIuXX macros are defined by <inttypes.h>. See Issue #3837.
add_definitions (-D__STDC_FORMAT_MACROS)

# Add component and application definitions
include ("CMakeApplication.txt")
