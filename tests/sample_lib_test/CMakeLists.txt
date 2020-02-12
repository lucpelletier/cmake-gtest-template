project(sample_lib_test)

set(SOURCE_FILES src/cpp/sample_lib_test.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sample_lib gtest gmock gmock_main)

gtest_discover_tests(${PROJECT_NAME})
