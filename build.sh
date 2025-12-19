#!/bin/bash

echo "Building Raylib Scene Management Project..."
echo

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build

# Configure and build
echo "Configuring CMake..."
cmake --preset default ..
if [ $? -ne 0 ]; then
    echo "CMake configuration failed!"
    cd ..
    exit 1
fi

echo
echo "Building project..."
cmake --build . --config Debug
if [ $? -ne 0 ]; then
    echo "Build failed!"
    cd ..
    exit 1
fi

echo
echo "Build completed successfully!"
echo "Executable location: build/src/Game/Game"
cd ..

read -p "Would you like to launch the game? (y/n): " toRun
if [ "$toRun" == "y" ] || [ "$toRun" == "yes" ]; then
    echo "Launching game..."
    "$PWD/build/src/Game/Game"
else
    echo "Game not launched. You can run it later with: ./build/src/Game/Game"
fi