/*
 * Copyright (C) 2021 The Android Open Source Project
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

#ifndef HARDWARE_GOOGLE_PIXEL_HEALTH_STATSHELPER_H
#define HARDWARE_GOOGLE_PIXEL_HEALTH_STATSHELPER_H

#include <aidl/android/frameworks/stats/IStats.h>
#include <hardware/google/pixel/pixelstats/pixelatoms.pb.h>

namespace hardware {
namespace google {
namespace pixel {
namespace health {

using aidl::android::frameworks::stats::IStats;
using android::hardware::google::pixel::PixelAtoms::VendorBatteryCausedShutdown;
using android::hardware::google::pixel::PixelAtoms::VendorBatteryHealthSnapshot;

std::shared_ptr<IStats> getStatsService();

void reportBatteryHealthSnapshot(const std::shared_ptr<IStats> &stats_client,
                                 const VendorBatteryHealthSnapshot &batteryHealthSnapshot);

void reportBatteryCausedShutdown(const std::shared_ptr<IStats> &stats_client,
                                 const VendorBatteryCausedShutdown &batteryCausedShutdown);

}  // namespace health
}  // namespace pixel
}  // namespace google
}  // namespace hardware

#endif  // HARDWARE_GOOGLE_PIXEL_HEALTH_STATSHELPER_H
