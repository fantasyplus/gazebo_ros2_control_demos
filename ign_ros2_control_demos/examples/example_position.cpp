// Copyright 2021 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Shim to redirect "ign_ros2_control_demos example_position" call
// to "gz_ros2_control_demos example_position"

#include <stdlib.h>

#include <sstream>
#include <iostream>

#include <ament_index_cpp/get_package_prefix.hpp>


int main(int argc, char * argv[])
{
  std::stringstream cli_call;

  cli_call << ament_index_cpp::get_package_prefix("gz_ros2_control_demos")
           << "/lib/gz_ros2_control_demos/example_position";

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      cli_call << " " << argv[i];
    }
  }

  std::cerr << "[ign_ros2_control_demos] is deprecated! "
            << "Redirecting to use [gz_ros2_control_demos] instead!"
            << std::endl << std::endl;
  system(cli_call.str().c_str());

  return 0;
}
