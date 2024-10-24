#!/bin/bash
#
# SPDX-FileCopyrightText: 2016 The CyanogenMod Project
# SPDX-FileCopyrightText: 2017-2024 The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

set -e

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "${MY_DIR}" ]]; then MY_DIR="${PWD}"; fi

ANDROID_ROOT="${MY_DIR}/../../.."

export TARGET_ENABLE_CHECKELF=true

HELPER="${ANDROID_ROOT}/tools/extract-utils/extract_utils.sh"
if [ ! -f "${HELPER}" ]; then
    echo "Unable to find helper script at ${HELPER}"
    exit 1
fi
source "${HELPER}"

function vendor_imports() {
    cat <<EOF >>"$1"
		"device/oneplus/sm8450-common",
		"hardware/qcom-caf/sm8450",
		"hardware/qcom-caf/wlan",
		"hardware/oplus",
		"vendor/qcom/opensource/commonsys/display",
		"vendor/qcom/opensource/commonsys-intf/display",
		"vendor/qcom/opensource/dataservices",
EOF
}

function lib_to_package_fixup_odm_variants() {
    if [ "$2" != "odm" ]; then
        return 1
    fi

    case "$1" in
        audio.primary.taro | \
            vendor.qti.hardware.pal@1.0-impl)
            echo "$1_odm"
            ;;
        *)
            return 1
            ;;
    esac
}

function lib_to_package_fixup_vendor_variants() {
    if [ "$2" != "vendor" ]; then
        return 1
    fi

    case "$1" in
        com.qualcomm.qti.dpm.api@1.0 | \
            libQnnHtp | \
            libQnnHtpPrepare | \
            libQnnHtpV69Stub | \
            vendor.oplus.hardware.performance-V1-ndk | \
            vendor.qti.diaghal@1.0 | \
            vendor.qti.hardware.dpmservice@1.0 | \
            vendor.qti.hardware.qccsyshal@1.0 | \
            vendor.qti.hardware.qccsyshal@1.1 | \
            vendor.qti.hardware.qccvndhal@1.0 | \
            vendor.qti.hardware.wifidisplaysession@1.0 | \
            vendor.qti.imsrtpservice@3.0)
            echo "$1_vendor"
            ;;
        libagmclient | \
            libpalclient | \
            libwpa_client) ;;
        *)
            return 1
            ;;
    esac
}

function lib_to_package_fixup() {
    lib_to_package_fixup_clang_rt_ubsan_standalone "$1" ||
        lib_to_package_fixup_proto_3_9_1 "$1" ||
        lib_to_package_fixup_odm_variants "$@" ||
        lib_to_package_fixup_vendor_variants "$@"
}

# Initialize the helper for common
setup_vendor "${DEVICE_COMMON}" "${VENDOR_COMMON:-$VENDOR}" "${ANDROID_ROOT}" true

# Warning headers and guards
write_headers "udon ovaltine"

# The standard common blobs
write_makefiles "${MY_DIR}/proprietary-files.txt" true

# Finish
write_footers

if [ -s "${MY_DIR}/../../${VENDOR}/${DEVICE}/proprietary-files.txt" ]; then
    # Reinitialize the helper for device
    setup_vendor "${DEVICE}" "${VENDOR}" "${ANDROID_ROOT}" false

    # Warning headers and guards
    write_headers

    # The standard device blobs
    write_makefiles "${MY_DIR}/../../${VENDOR}/${DEVICE}/proprietary-files.txt" true

    if [ -f "${MY_DIR}/../../${VENDOR}/${DEVICE}/proprietary-firmware.txt" ]; then
        append_firmware_calls_to_makefiles "${MY_DIR}/../../${VENDOR}/${DEVICE}/proprietary-firmware.txt"
    fi

    # Finish
    write_footers
fi
