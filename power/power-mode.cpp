/*
 * Copyright (C) 2020-2024 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <aidl/android/hardware/power/BnPower.h>
#include <aidl/vendor/oplus/hardware/touch/IOplusTouch.h>
#include <android-base/file.h>
#include <android-base/logging.h>
#include <linux/input.h>
#include <android/binder_manager.h>

namespace {
using ::aidl::vendor::oplus::hardware::touch::IOplusTouch;

std::shared_ptr<IOplusTouch> mTouchService;
}  // anonymous namespace

namespace aidl {
namespace android {
namespace hardware {
namespace power {
namespace impl {

#define DOUBLE_TAP_INDEP_ENABLED 1 << 1
#define DOUBLE_TAP_INDEP_DISABLED 1 << 16

using ::aidl::android::hardware::power::Mode;

bool isDeviceSpecificModeSupported(Mode type, bool* _aidl_return) {
    switch (type) {
        case Mode::DOUBLE_TAP_TO_WAKE:
            *_aidl_return = true;
            return true;
        default:
            return false;
    }
}

bool setDeviceSpecificMode(Mode type, bool enabled) {
    switch (type) {
        case Mode::DOUBLE_TAP_TO_WAKE: {
            const std::string instance = std::string() + IOplusTouch::descriptor + "/default";
            mTouchService = IOplusTouch::fromBinder(
                    ndk::SpAIBinder(AServiceManager_waitForService(instance.c_str())));
            LOG(INFO) << "Power mode: " << toString(type) << " isDoubleTapEnabled: " << enabled;

            // For normal devices
            int result = 0;
            mTouchService->touchWriteNodeFile(0, 1, enabled ? "1" : "0", &result);
            LOG(DEBUG) << "Power-Touch write double_tap_enable result: " << result;

            // For tcm hbp driver devices
            mTouchService->touchWriteNodeFile(
                    0, 21,
                    std::to_string(enabled ? DOUBLE_TAP_INDEP_ENABLED : DOUBLE_TAP_INDEP_DISABLED),
                    &result);
            LOG(DEBUG) << "Power-Touch write double_tap_enable_indep result: " << result;
            return true;
        }
        default:
            return false;
    }
}

}  // namespace impl
}  // namespace power
}  // namespace hardware
}  // namespace android
}  // namespace aidl
