cmake_minimum_required(VERSION 3.15)
project(my_project_name LANGUAGES C CXX)

# For MSVC, don't add warning level 3, we want to set it to 4 below
cmake_policy(SET CMP0092 NEW)

set(CMAKE_CXX_STANDARD 17)

# enable all warnings
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# check submodules have been cloned
set(GOOGLETEST_PATH ${CMAKE_SOURCE_DIR}/external/github.com/google/googletest)
if (NOT EXISTS ${GOOGLETEST_PATH}/CMakeLists.txt)
    message(FATAL_ERROR "Submodules have not been cloned.\nRun 'git submodule update --init --recursive'")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${GOOGLETEST_PATH} EXCLUDE_FROM_ALL)

# make sure pybind11 uses python3
set(PYBIND11_PYTHON_VERSION 3.6 CACHE STRING "")
add_subdirectory(external/github.com/pybind/pybind11 EXCLUDE_FROM_ALL)

# add top-level projects
enable_testing()
add_subdirectory(apps)
add_subdirectory(libs)
add_subdirectory(tests)
