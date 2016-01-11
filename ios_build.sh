rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=../IOS.cmake -DIOS_PLATFORM=OS -GXcode 
