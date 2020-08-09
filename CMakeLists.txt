cmake_minimum_required(VERSION 3.13)
project(shirose_logger CXX)

cmake_policy(SET CMP0076 NEW)

add_library(shirose_logger)
target_compile_features(shirose_logger
  PUBLIC
    cxx_std_14
  )
target_compile_options(shirose_logger
  PUBLIC
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:Intel>:$<IF:$<PLATFORM_ID:Windows>,/warn:all,-warn all>>
  )
target_include_directories(shirose_logger
  PUBLIC
    include
  )

add_subdirectory(include/shirose)
add_subdirectory(src)

if (SHIROSE_ENABLE_TESTING)
  add_subdirectory(test)
endif ()