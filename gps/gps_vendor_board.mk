# Any TARGET_BOARD_PLATFORM being built that does
# not want vendor location modules built should be
# added to this exclude list to prevent building
LOC_BOARD_PLATFORM_EXCLUDE_LIST :=

# Define BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE if:
# EXCLUDE_LOCATION_FEATURES is not true AND
# TARGET_BOARD_PLATFORM is not in LOC_BOARD_PLATFORM_EXCLUDE_LIST AND
# (TARRGET_USES_QMMA is not true OR
#  TARGET_USES_QMAA_OVERRIDE_GPS is not false
ifneq ($(EXCLUDE_LOCATION_FEATURES),true)
  ifeq (,$(filter $(LOC_BOARD_PLATFORM_EXCLUDE_LIST),$(TARGET_BOARD_PLATFORM)))
    ifneq ($(TARGET_USES_QMAA),true)
      BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := default
    else ifneq ($(TARGET_USES_QMAA_OVERRIDE_GPS),false)
      BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := default
    endif
  endif #LOC_BOARD_PLATFORM_EXCLUDE_LIST check
endif #EXCLUDE_LOCATION_FEATURES check
