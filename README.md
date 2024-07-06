# tetrix

A tetris clone with fresh ideas for a revamped gameplay.

### Build Instructions for GNU Linux

This project uses the cmake template from [raylib-game-template](https://github.com/raysan5/raylib-game-template/blob/main/CMakeLists.txt), which will clone the latest raylib version into the build directory. Therefore have an internet connection before you build, install cmake.

#### Install required tools

    sudo apt install build-essential git cmake

#### Install required libraries

##### Debian

    sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

##### [Other distributions](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#install-required-libraries)

#### Build project using cmake

The following will clone raylib and create the make files, and then build those Makefiles.
    cmake -B build/ && cmake --build build/

#### Run the binary

    ./build/tetrix/tetrix

### Build Instructions for other platforms

Although the CMakeLists.txt is supposed to be portable and cross platform, you may find a broader guide on [raylib-wiki](https://github.com/raysan5/raylib/wiki/)
