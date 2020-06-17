#!/bin/bash

VNX_INTERFACE_DIR=${VNX_INTERFACE_DIR:-/usr/interface}

BASE_INCLUDE=$1

if [ -z "$BASE_INCLUDE" ]; then
	BASE_INCLUDE=${VNX_INTERFACE_DIR}/pilot/base/
fi

cd $(dirname "$0")

vnxcppcodegen --cleanup generated/ pilot.usboard interface/ modules/ ${VNX_INTERFACE_DIR}/vnx/ ${BASE_INCLUDE}

