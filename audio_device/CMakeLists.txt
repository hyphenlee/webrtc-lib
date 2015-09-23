set(device_src
  "audio_device_buffer.cc"
  "audio_device_buffer.h"
  "audio_device_config.h"
  "audio_device_generic.cc"
  "audio_device_generic.h"
  "dummy/audio_device_dummy.cc"
  "dummy/audio_device_dummy.h"
  "dummy/file_audio_device.cc"
  "dummy/file_audio_device.h"
  "fine_audio_buffer.cc"
  "fine_audio_buffer.h"
  "include/audio_device.h"
  "include/audio_device_defines.h")

add_library(AudioDevice SHARED ${device_src})

if(CMAKE_SYSTEM_NAME EQUAL "Darwin")
  add_subdirectory(mac)
endif()

