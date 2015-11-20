# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (AudioModule)

SET(CMAKE_SKIP_BUILD_RPATH  TRUE)
# add library
# set(CMAKE_BUILD_TYPE Release)
# aux_source_directory(./testlib SRC_TEST)

# RPATH and library search setting
#cmake_policy(SET CMP0042 OLD)

# SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
# SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
# SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/out")
# SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
if(IOS)
  SET(CMAKE_CXX_FLAGS " -std=c++11 -mfpu=neon  ${CMAKE_CXX_FLAGS} ")
  # set( CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -mfpu=neon")
  SET(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS}")
elseif(ANDROID)
  SET(CMAKE_CXX_FLAGS " -std=c++11 -mfpu=neon -v ${CMAKE_CXX_FLAGS} ")
  # set( CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -mfpu=neon")
  SET(CMAKE_C_FLAGS " -mfpu=neon  ${CMAKE_C_FLAGS}")
else()
  SET(CMAKE_CXX_FLAGS " -std=c++11 -msse2  ${CMAKE_CXX_FLAGS} ")
  SET(CMAKE_C_FLAGS " -msse2 ${CMAKE_C_FLAGS}")
endif()
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
# find_library(ssl_library
#   NAMES ssl
#   HINTS "/usr/local/Cellar/openssl/1.0.2d_1/lib/"
#   )
# message(ssl:${ssl_library})

# INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/base)

SET(COMMON_SRC
  audio_receive_stream.h
  # audio_send_stream.h
  # call.h
  common.h
  common_types.cc
  common_types.h
  config.h
  config.cc
  engine_configurations.h
  frame_callback.h
  stream.h
  transport.h
  typedefs.h
  # video_decoder.h
  # video_encoder.h
  # video_frame.h
  # video_receiver_stream.h
  # video_renderer.h
  # video_send_stream.h
  interface/module.h
  interface/module_common_types.h
  jsoncpp.cpp
  )
add_library(COMMON  ${COMMON_SRC})
ADD_SUBDIRECTORY(base)
ADD_SUBDIRECTORY(system_wrappers)
ADD_SUBDIRECTORY(common_audio)
# ADD_SUBDIRECTORY(audio_coding)
ADD_SUBDIRECTORY(audio_processing)
#ADD_SUBDIRECTORY(audio_device)
# ADD_SUBDIRECTORY(test)

# set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
