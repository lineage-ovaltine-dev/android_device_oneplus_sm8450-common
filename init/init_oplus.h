/*
 * Copyright (C) 2023 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

constexpr const char* RO_PROP_SOURCES[] = {
        nullptr, "product.", "product_services.", "odm.", "vendor.", "system.", "bootimage.",
};

constexpr const char* MODELS[] = {
        "CPH2413", "CPH2415", "CPH2417", "CPH2419", "PGP110",
};

// TO-DO make a map
constexpr const char* DEVICES[] = {
        "OP5551L1",
        "OP5552L1",
};

constexpr const char* BUILD_FINGERPRINT[] = {
        "OnePlus/CPH2413/OP5552L1:13/SKQ1.221119.001/S.123ec2a_6b801_6ff30:user/release-keys",
        "OnePlus/CPH2415/OP5552L1:13/SKQ1.221119.001/S.123ec2a_6b801_6ff30:user/release-keys",
        "OnePlus/CPH2417/OP5552L1:13/SKQ1.221119.001/S.123ec2a_6b801_6ff30:user/release-keys",
        "OnePlus/CPH2419/OP5552L1:13/SKQ1.221119.001/S.123ec2a_6b801_6ff30:user/release-keys",
        "OnePlus/PGP110/OP5551L1:14/UP1A.230620.001/S.1317e36_a82b-2:user/release-keys",
};
