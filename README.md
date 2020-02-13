# CMake Project Template with GoogleTest

## Getting Started

On Ubuntu, install the latest cmake with:

    sudo snap install cmake
    
## Building and Running Tests

To build the project, run:

    cd <repository root>
    mkdir build
    cmake -GNinja -S . -B build
    cd build
    cmake --build .
    ctest
   
## Test Naming Convention

The google tests use the following naming convention:

    MethodName_StateUnderTest_ExpectedBehavior

For more details, see https://osherove.com/blog/2005/4/3/naming-standards-for-unit-tests.html.

## CMake Best Practices

- https://github.com/onqtam/awesome-cmake
- https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
- https://cliutils.gitlab.io/modern-cmake/
