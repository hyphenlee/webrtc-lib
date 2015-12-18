SET(VIDEO_RENDER_SRC
  "external/video_render_external_impl.cc"
  "external/video_render_external_impl.h"
  "i_video_render.h"
  "include/video_render.h"
  "include/video_render_defines.h"
  "video_render_impl.h"
  "video_render_impl.cc"
  )
SET(LIBS  "")
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
  if(IOS)
    message(STATUS "start build base for ios")
    set(LIBS ${LIBS}
      "OpenGLES"
      "QuartzCore"
      )
    SET(VIDEO_RENDER_SRC
      ${VIDEO_RENDER_SRC}
      "ios/open_gles20.h"
      "ios/open_gles20.mm"
      "ios/video_render_ios_channel.h"
      "ios/video_render_ios_channel.mm"
      "ios/video_render_ios_gles20.h"
      "ios/video_render_ios_gles20.mm"
      "ios/video_render_ios_impl.h"
      "ios/video_render_ios_impl.mm"
      "ios/video_render_ios_view.h"
      "ios/video_render_ios_view.mm"
      )
  else()
    message("start build for darwin system")
    set(LIBS ${LIBS}
      )
    # set(LIBRARYS ${LIBRARYS} ${ssl_library} ${ssl_library2})
    message(librarys: "${LIBRARYS}")
    SET(VIDEO_RENDER_SRC
      ${VIDEO_RENDER_SRC}

      )

  endif()
elseif(ANDROID)
  message("build for android")
  SET(VIDEO_RENDER_SRC
    ${VIDEO_RENDER_SRC}

    )
  set(LIBS ${LIBS}

    )
  include_directories(${PROJECT_SOURCE_DIR}/libs/openssl/include)
  ADD_DEFINITIONS(-DWEBRTC_ANDROID)
  ADD_DEFINITIONS(-DWEBRTC_POSIX)
  ADD_DEFINITIONS(-DWEBRTC_LINUX)
endif()
ADD_DEFINITIONS(-DSSL_USE_OPENSSL)
ADD_DEFINITIONS(-DHAVE_OPENSSL_SSL_H)
set(LIBRARYS "")
# find_library(ssl_lib "ssl")
#message("${ssl_lib}")
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

set(LIBRARYS ${LIBRARYS} CommonVideo SystemWrapper)
ADD_LIBRARY(VideoRender  ${VIDEO_RENDER_SRC} )
TARGET_LINK_LIBRARIES(VideoRender ${LIBRARYS})
