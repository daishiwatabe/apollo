/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file: routing_helper.h
 **/

#ifndef MODULES_PLANNING_COMMON_ROUTING_HELPER_H_
#define MODULES_PLANNING_COMMON_ROUTING_HELPER_H_

#include <memory>
#include <unordered_map>

#include "modules/map/hdmap/hdmap.h"
#include "modules/map/pnc_map/path.h"
#include "modules/map/proto/routing.pb.h"

namespace apollo {
namespace planning {

class RoutingHelper {
 public:
  RoutingHelper() = default;
  RoutingHelper(const hdmap::HDMap *map_ptr);
  void SetMap(const hdmap::HDMap *map_ptr);
  ~RoutingHelper() = default;
  bool CreatePathFromRouting(const hdmap::RoutingResult &routing,
                             const common::PointENU &point,
                             const double backward_length,
                             const double forward_length,
                             hdmap::Path *path) const;

  bool CreatePathFromRouting(const hdmap::RoutingResult &routing,
                             hdmap::Path *path) const;

  bool CreatePathFromRouting(const hdmap::RoutingResult &routing,
                             double start_s, double end_s,
                             hdmap::Path *path) const;

  bool validate_routing(const hdmap::RoutingResult &routing) const;

 private:
  void append_lane_to_points(
      hdmap::LaneInfoConstPtr lane, const double start_s, const double end_s,
      std::vector<hdmap::MapPathPoint> *const points,
      std::vector<hdmap::LaneSegment> *const lane_segments) const;
  const hdmap::HDMap *hdmap_ = nullptr;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_COMMON_ROUTING_HELPER_H_
