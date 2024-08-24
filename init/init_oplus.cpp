/*
 * Copyright (C) 2022-2023 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;
#include "init_oplus.h"

/*
 * SetProperty does not allow updating read only properties and as a result
 * does not work for our use case. Write "OverrideProperty" to do practically
 * the same thing as "SetProperty" without this restriction.
 */
void OverrideProperty(char const prop[], char const value[]) {
    prop_info* pi = (prop_info*)__system_property_find(prop);
    if (pi != nullptr)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void load_props(int i, int j) {
    const auto OverrideRoProperty = [](const char* source, const char* prop, const char* value,
                                       bool product) {
        std::string PropertyName = "ro.";

        if (product) PropertyName += "product.";
        if (source != nullptr) PropertyName += source;
        if (!product) PropertyName += "build.";
        PropertyName += prop;

        OverrideProperty(PropertyName.c_str(), value);
    };

    for (const auto& source : RO_PROP_SOURCES) {
        OverrideRoProperty(source, "device", DEVICES[j], true);
        OverrideRoProperty(source, "model", MODELS[i], true);
        OverrideRoProperty(source, "name", MODELS[i], true);
        OverrideRoProperty(source, "fingerprint", BUILD_FINGERPRINT[i], false);
    }
    OverrideRoProperty(nullptr, "product", MODELS[i], false);
}

/*
 * Only for read-only properties. Properties that can be wrote to more
 * than once should be set in a typical init script (e.g. init.oplus.hw.rc)
 * after the original property has been set.
 */
void vendor_load_properties() {
    auto prjname = std::stoi(GetProperty("ro.boot.prjname", "0"));
    auto region = std::stoi(GetProperty("ro.boot.hw_region_id", "0"));

    switch (prjname) {
        // udon
        case 22881:  // IN
            OverrideProperty("ro.product.product.model", "CPH2487");
            break;
        // ovaltine
        case 21841:  // CN - ACE Pro
            load_props(4, 0);
            break;
        case 21842:  // IN / EEA / NA - 10T
            switch (region) {
                case 1:  // IN
                    load_props(0, 1);
                    break;
                case 2:  // EEA
                    load_props(1, 1);
                    break;
                case 3:  // NA
                    load_props(2, 1);
                    break;
                default:
                    LOG(ERROR) << "Unexpected project name: " << prjname;
            }
            break;
        default:
            LOG(ERROR) << "Unexpected project name: " << prjname;
    }
}
