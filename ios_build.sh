rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../IOS.cmake -DIOS_PLATFORM=SIMULATOR64 -GXcode
