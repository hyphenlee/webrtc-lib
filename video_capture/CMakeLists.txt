SET(VIDEO_CAPTURE_SRC
  "device_info_impl.cc"
  "device_info_impl.h"
  "include/video_capture.h"
  "include/video_capture_defines.h"
  "include/video_capture_factory.h"
  "video_capture_config.h"
  "video_capture_delay.h"
  "video_capture_factory.cc"
  "video_capture_impl.cc"
  "video_capture_impl.h"
  # "external/device_info_external.cc"
  # "external/video_capture_external.cc"

  )
SET(LIBS  "")
if(APPLE)
  if(IOS)
    message(STATUS "start build base for ios")
    set(LIBS ${LIBS}
      "AVFoundation"
      "CoreMedia"
      "CoreVideo"
      )
    
    SET(VIDEO_CAPTURE_SRC
      ${VIDEO_CAPTURE_SRC}
      "ios/device_info_ios.h"
      "ios/device_info_ios.mm"
      "ios/device_info_ios_objc.h"
      "ios/device_info_ios_objc.mm"
      "ios/rtc_video_capture_ios_objc.h"
      "ios/rtc_video_capture_ios_objc.mm"
      "ios/video_capture_ios.h"
      "ios/video_capture_ios.mm"
      )
  else()
    # LINK_DIRECTORIES( "/usr/local/Cellar/openssl/1.0.2d_1/lib/")
    message("start build for darwin system")
    Set(LIBS ${LIBS}
      "CoreVideo"
      "QTKit"
      )
    # set(LIBRARYS ${LIBRARYS} ${ssl_library} ${ssl_library2})
    message(librarys: "${LIBRARYS}")
    SET(VIDEO_CAPTURE_SRC
      ${VIDEO_CAPTURE_SRC}
      "mac/qtkit/video_capture_qtkit.h"
      "mac/qtkit/video_capture_qtkit.mm"
      "mac/qtkit/video_capture_qtkit_info.h"
      "mac/qtkit/video_capture_qtkit_info.mm"
      "mac/qtkit/video_capture_qtkit_info_objc.h"
      "mac/qtkit/video_capture_qtkit_info_objc.mm"
      "mac/qtkit/video_capture_qtkit_objc.h"
      "mac/qtkit/video_capture_qtkit_objc.mm"
      "mac/qtkit/video_capture_qtkit_utility.h"
      "mac/video_capture_mac.mm"
      )
    ADD_DEFINITIONS(-DWEBRTC_POSIX)
    ADD_DEFINITIONS(-DWEBRTC_MAC)
  endif()
elseif(ANDROID)
  message("build for android")
  SET(VIDEO_CAPTURE_SRC
    ${VIDEO_CAPTURE_SRC}
    "android/device_info_android.cc"
    "android/device_info_android.h"
    "android/video_capture_android.cc"
    "android/video_capture_android.h"
    )
  ADD_DEFINITIONS(-DWEBRTC_ANDROID)
  ADD_DEFINITIONS(-DWEBRTC_POSIX)
  ADD_DEFINITIONS(-DWEBRTC_LINUX)
endif()
ADD_DEFINITIONS(-DSSL_USE_OPENSSL)
ADD_DEFINITIONS(-DHAVE_OPENSSL_SSL_H)
set(LIBRARYS "")
message(${LIBS})
foreach(var ${LIBS})
  message(item:${var})
  FIND_LIBRARY(find${var} ${var})
  message(full path:${find${var}})
  if(${lib2} MATCHES "NOTFOUND")
    message(SEND_ERROR "library not not found:${var}")
  else()
    set(LIBRARYS ${LIBRARYS} ${find${var}})
  endif()
endforeach()
    set(LIBRARYS ${LIBRARYS} SystemWrapper CommonVideo)

ADD_LIBRARY(VideoCapture  STATIC ${VIDEO_CAPTURE_SRC})

TARGET_LINK_LIBRARIES(VideoCapture ${LIBRARYS})
