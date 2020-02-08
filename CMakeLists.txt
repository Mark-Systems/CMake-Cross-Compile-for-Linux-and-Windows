################################
# CMake Configuration
################################

# Mendetory
cmake_minimum_required(VERSION 3.10.2)
project(CMake_Cross_Compile_Demo)

# Add subdirectories here ...
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

# Or the following folder will be included.
#include_directories("${PROJECT_SOURCE_DIR}/src")

# Set the output folder where your program will be created.
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/BuildOutput)

# We need this if we want cross compile an cpp application for Windows.
if (MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
    set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++ -s")
endif()


set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

###################
# GoogleTest
###################
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
endif()

################################
# Unit Tests
################################
# Add test cpp file
add_executable( runUnitTests ${PROJECT_SOURCE_DIR}/test/example_test.cpp )

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests ${EXECUTABLE_OUTPUT_PATH}/runUnitTests )

################################
# Build binary
################################
set(app_srcs src/main.cpp)
add_executable(Example ${app_srcs})

