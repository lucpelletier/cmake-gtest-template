project(sample_app)

set(LIB_SOURCE_FILES src/c/app_main.c)
set(LIB_HEADER_FILES src/include/sample_app/app_main.h)
set(LIB_NAME ${PROJECT_NAME}_lib)
add_library(${LIB_NAME} ${LIB_SOURCE_FILES})
target_link_libraries(${LIB_NAME} sample_lib)
target_include_directories(${LIB_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>)

set(SOURCE_FILES src/c/main.c)
set(EXE_NAME ${PROJECT_NAME}_exe)
add_executable(${EXE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXE_NAME} ${LIB_NAME})
