# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rf24_transceiver_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rf24_transceiver_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rf24_transceiver_FOUND FALSE)
  elseif(NOT rf24_transceiver_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rf24_transceiver_FOUND FALSE)
  endif()
  return()
endif()
set(_rf24_transceiver_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rf24_transceiver_FIND_QUIETLY)
  message(STATUS "Found rf24_transceiver: 1.0.0 (${rf24_transceiver_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rf24_transceiver' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT rf24_transceiver_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rf24_transceiver_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rf24_transceiver_DIR}/${_extra}")
endforeach()
