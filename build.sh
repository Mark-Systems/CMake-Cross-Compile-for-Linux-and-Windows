#!/bin/bash

echo "Start cross compile for Linux and Windows "
if [ ! -d Build_Linux ]; then
    # "Create dir and run cmake cmd .."
    cmake -E make_directory Build_Linux
    cmake -E chdir Build_Linux cmake ..
fi
cmake --build Build_Linux

if [ ! -d Build_Win ]; then
    # "Create dir and run cmake cmd .."
    cmake -E make_directory Build_Win
    cmake -E chdir Build_Win cmake -DCMAKE_TOOLCHAIN_FILE=${PWD}/win32_toolchain/win32_toolchain.cmake ..
fi
cmake --build Build_Win

echo "Run test ... "
${PWD}/run_test.sh

