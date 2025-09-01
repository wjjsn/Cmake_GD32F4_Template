使用`cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="./gcc-arm-none-eabi.cmake" -S . -B./build/Debug -G Ninja`来配置
使用`cmake --build ./build/Debug --`来编译