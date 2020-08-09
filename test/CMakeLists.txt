find_package(GTest REQUIRED)
enable_testing()

add_executable(logging_test logging_test.cpp)
target_link_libraries(logging_test
  PRIVATE
    GTest::GTest
    GTest::Main
    shirose_logger
  )
add_test(
    NAME logging_test
    COMMAND $<TARGET_FILE:logging_test>
)