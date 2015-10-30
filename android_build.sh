export PATH=~/.ndk:${PATH}
#export PATH=/tmp/my-android-toolchain/bin:$PATH
#export CC="arm-linux-androideabi-gcc"
#export CXX="arm-linux-androideabi-g++"
#export ANDROID_STANDALONE_TOOLCHAIN=/tmp/my-android-toolchain
#export ANDROID_NDK=~/.ndk
rm -rf build
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../android.toolchain.cmake -DANDROID_NDK=~/.ndk -DCMAKE_BUILD_TYPE=Release \
      -DANDROID_ABI="armeabi-v7a with NEON" -DANDROID_NATIVE_API_LEVEL=android-17  ..
cmake --build .
