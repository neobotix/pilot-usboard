#!/bin/bash

VNX_INTERFACE_DIR=${VNX_INTERFACE_DIR:-/usr/interface}

BASE_INCLUDE=$1
VNX_INCLUDE=$2

if [ -z "$BASE_INCLUDE" ]; then
	BASE_INCLUDE=${VNX_INTERFACE_DIR}/pilot/base/
fi

if [ -z "$VNX_INCLUDE" ]; then
	VNX_INCLUDE=${VNX_INTERFACE_DIR}/vnx/
fi

cd $(dirname "$0")

vnxcppcodegen --cleanup generated/ pilot.usboard interface/ modules/ $BASE_INCLUDE $VNX_INCLUDE

