project(sample_lib)

set(SOURCE_FILES src/cpp/sample.cpp)
set(HEADER_FILES src/include/sample_lib/sample.h)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
)

