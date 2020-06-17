#!/bin/bash

VNX_INTERFACE_DIR=${VNX_INTERFACE_DIR:-/usr/interface}

cd $(dirname "$0")

vnxcppcodegen --cleanup generated/ pilot.usboard interface/ modules/ ${VNX_INTERFACE_DIR}/vnx/ ${VNX_INTERFACE_DIR}/pilot/base/

