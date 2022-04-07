project(sample_app_test)

set(SOURCE_FILES src/cpp/sample_app_test.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sample_app_lib GTest::gmock GTest::gmock_main)

gtest_discover_tests(${PROJECT_NAME})
