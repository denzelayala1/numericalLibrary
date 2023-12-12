cmake_minimum_required(VERSION 3.10)
project(numericalLibrary)

set(CMAKE_CXX_STANDARD 11)

# Source files
#file(GLOB SOURCES "src/*.cpp")
set(SOURCES
    src/integrate.cpp
    src/main.cpp
)

# Include directories
include_directories(include)  # Include directory for headers

# Add executable
add_executable(test ${SOURCES})
