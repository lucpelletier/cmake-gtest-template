cmake_minimum_required(VERSION 3.21)
project(my_project_name LANGUAGES CXX)

# install conan cmake support
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)

# For MSVC, don't add warning level 3, we want to set it to 4 below
cmake_policy(SET CMP0092 NEW)

# set c++ language standard
set(CMAKE_CXX_STANDARD 20)

# install dependencies w/ conan
conan_cmake_configure(REQUIRES
                        gtest/cci.20210126
                        pybind11/2.9.1
                      GENERATORS cmake_find_package)
conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

# find dependencies
find_package(GTest)
find_package(pybind11)

# enable all warnings
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# add top-level projects
enable_testing()
add_subdirectory(apps)
add_subdirectory(libs)
add_subdirectory(tests)
