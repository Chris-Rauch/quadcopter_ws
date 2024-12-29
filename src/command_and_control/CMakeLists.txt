cmake_minimum_required(VERSION 3.8)
project(command_and_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(interfaces REQUIRED)

# add nodes
add_executable(rf24_transceiver 
  src/rf24_transceiver.cpp
)

target_include_directories(rf24_transceiver PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_link_libraries(rf24_transceiver /usr/local/lib/librf24.so)
target_link_libraries(rf24_transceiver /usr/lib/libwiringPi.so.3.10)

# link dependencies to nodes
ament_target_dependencies(rf24_transceiver rclcpp interfaces)

install(TARGETS
  rf24_transceiver
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
