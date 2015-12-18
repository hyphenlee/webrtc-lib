SET(COMMON_VIDEO_SRC
  "i420_buffer_pool.cc"
  "incoming_video_stream.cc"
  "interface/i420_buffer_pool.h"
  "interface/incoming_video_stream.h"
  "interface/video_frame_buffer.h"
  "libyuv/include/scaler.h"
  "libyuv/include/webrtc_libyuv.h"
  "libyuv/scaler.cc"
  "libyuv/webrtc_libyuv.cc"
  "video_frame.cc"
  "video_frame_buffer.cc"
  "video_render_frames.cc"
  "video_render_frames.h"
  )
include_directories(
  "include"
  "libyuv/include"
  "../interface"
  "${LIB_PATH_PREFIX}/libyuv/include"
  )
link_directories("${LIB_PATH_PREFIX}/libyuv/")
SET(LIBS  "")
SET(LIBRARYS  "")

if(IOS)
  set(LIBRARYS ${LIBRARYS} yuv)
endif()
ADD_LIBRARY(CommonVideo  ${COMMON_VIDEO_SRC})
TARGET_LINK_LIBRARIES(CommonVideo SYSTEM_WRAPPER ${LIBRARYS})
