set(AUDIO_DEVICE_SRC
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
  "include/audio_device_defines.h"
  "audio_device_impl.cc"
  "audio_device_impl.h"

  # "android/audio_device_template.h"
  # "android/audio_manager.cc"
  # "android/audio_manager.h"
  # "android/audio_record_jni.cc"
  # "android/audio_record_jni.h"
  # "android/audio_track_jni.cc"
  # "android/audio_track_jni.h"
  # "android/opensles_common.cc"
  # "android/opensles_common.h"
  # "android/opensles_player.cc"
  # "android/opensles_player.h"

  # "linux/alsasymboltable_linux.cc"
  # "linux/alsasymboltable_linux.h"
  # "linux/audio_device_alsa_linux.cc"
  # "linux/audio_device_alsa_linux.h"
  # "linux/audio_mixer_manager_alsa_linux.cc"
  # "linux/audio_mixer_manager_alsa_linux.h"
  # "linux/latebindingsymboltable_linux.cc"
  # "linux/latebindingsymboltable_linux.h"
  
  
  # "win/audio_device_core_win.cc"
  # "win/audio_device_core_win.h"
  # "win/audio_device_wave_win.cc"
  # "win/audio_device_wave_win.h"
  # "win/audio_mixer_manager_win.cc"
  # "win/audio_mixer_manager_win.h"

  "dummy/file_audio_device_factory.cc"
  "dummy/file_audio_device_factory.h"

  )
message("start process audio device")
add_definitions(-DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE)
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  message("darwin system")
  if(IOS)
    message("handle for ios")
    set(AUDIO_DEVICE_SRC
      ${AUDIO_DEVICE_SRC}
      "ios/audio_device_ios.h"
      "ios/audio_device_ios.mm"
      "ios/audio_device_not_implemented_ios.mm"
      "../utility/source/helpers_ios.mm"
      "../utility/interface/helpers_ios.h"
      )
    set(LIBS ${LIBS}
      "AudioToolbox"
      "AVFoundation"
      "Foundation"
      )
    include_directories(${PROJECT_SOURCE_DIR}/audio_device/ios)
    include_directories(${PROJECT_SOURCE_DIR}/utility/interface)
    add_definitions(-DWEBRTC_IOS)
  else()
    set(AUDIO_DEVICE_SRC
      ${AUDIO_DEVICE_SRC}
      "mac/audio_device_mac.cc"
      "mac/audio_device_mac.h"
      "mac/audio_mixer_manager_mac.cc"
      "mac/audio_mixer_manager_mac.h"
      "mac/portaudio/pa_memorybarrier.h"
      "mac/portaudio/pa_ringbuffer.c"
      "mac/portaudio/pa_ringbuffer.h"
      )
    include_directories(${PROJECT_SOURCE_DIR}/audio_device/mac)
    add_definitions(-DWEBRTC_MAC)
    set(LIBS ${LIBS}
      AudioToolbox
      CoreAudio
      )
  endif()
  set(LIBRARYS "")
  foreach(var ${LIBS})
    message(item:${var})
    FIND_LIBRARY(find${var} ${var})
    message(full path:${find${var}})
    if(${lib2} MATCHES "NOTFOUND")
      message(error: "library not not found:${var}")
    else()
      
      set(LIBRARYS ${LIBRARYS} ${find${var}})
    endif()
  endforeach()
  message(audio device librarys: "${LIBRARYS}")
endif()
add_library(AudioDevice STATIC  ${AUDIO_DEVICE_SRC})
TARGET_LINK_LIBRARIES(AudioDevice  ${LIBRARYS} CommonAudio )
