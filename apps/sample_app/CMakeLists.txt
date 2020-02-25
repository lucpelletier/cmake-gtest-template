project(sample_app)

set(LIB_SOURCE_FILES src/main_lib/cpp/app_main.cpp)
set(LIB_HEADER_FILES src/main_lib/include/sample_app/app_main.h)
set(LIB_NAME ${PROJECT_NAME}_lib)
add_library(${LIB_NAME} ${LIB_SOURCE_FILES} ${LIB_HEADER_FILES})
target_link_libraries(${LIB_NAME} sample_lib)
target_include_directories(${LIB_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/main_lib/include>)

set(SOURCE_FILES src/main/cpp/main.cpp)
set(EXE_NAME ${PROJECT_NAME}_exe)
add_executable(${EXE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXE_NAME} ${LIB_NAME})
