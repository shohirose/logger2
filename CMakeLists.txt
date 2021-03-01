cmake_minimum_required(VERSION 3.13)
project(logger CXX)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

cmake_policy(SET CMP0076 NEW)

add_library(logger)
target_compile_features(logger
  PUBLIC
    cxx_std_14
  )
target_compile_options(logger
  PUBLIC
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:Intel>:$<IF:$<PLATFORM_ID:Windows>,/warn:all,-warn all>>
  )
target_include_directories(logger
  PUBLIC
    include
  )

add_subdirectory(include/shirose)
add_subdirectory(src)

option(BUILD_GMOCK "" OFF)
option(INSTALL_GTEST "" OFF)
option(gtest_force_shared_crt "" ON)

add_subdirectory(third-party/googletest)
add_subdirectory(test)