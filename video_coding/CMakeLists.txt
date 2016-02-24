SET(VIDEO_CODING_SRC
  "main/interface/video_coding.h"
  "main/interface/video_coding_defines.h"
  "main/source/codec_database.cc"
  "main/source/codec_database.h"
  "main/source/codec_timer.cc"
  "main/source/codec_timer.h"
  "main/source/content_metrics_processing.cc"
  "main/source/content_metrics_processing.h"
  "main/source/decoding_state.cc"
  "main/source/decoding_state.h"
  "main/source/encoded_frame.cc"
  "main/source/encoded_frame.h"
  "main/source/fec_tables_xor.h"
  "main/source/frame_buffer.cc"
  "main/source/frame_buffer.h"
  "main/source/generic_decoder.cc"
  "main/source/generic_decoder.h"
  "main/source/generic_encoder.cc"
  "main/source/generic_encoder.h"
  "main/source/inter_frame_delay.cc"
  "main/source/inter_frame_delay.h"
  "main/source/internal_defines.h"
  "main/source/jitter_buffer.cc"
  "main/source/jitter_buffer.h"
  "main/source/jitter_buffer_common.h"
  "main/source/jitter_estimator.cc"
  "main/source/jitter_estimator.h"
  "main/source/media_opt_util.cc"
  "main/source/media_opt_util.h"
  "main/source/media_optimization.cc"
  "main/source/media_optimization.h"
  "main/source/nack_fec_tables.h"
  "main/source/packet.cc"
  "main/source/packet.h"
  "main/source/qm_select.cc"
  "main/source/qm_select.h"
  "main/source/qm_select_data.h"
  "main/source/receiver.cc"
  "main/source/receiver.h"
  "main/source/rtt_filter.cc"
  "main/source/rtt_filter.h"
  "main/source/session_info.cc"
  "main/source/session_info.h"
  "main/source/timestamp_map.cc"
  "main/source/timestamp_map.h"
  "main/source/timing.cc"
  "main/source/timing.h"
  "main/source/video_coding_impl.cc"
  "main/source/video_coding_impl.h"
  "main/source/video_receiver.cc"
  "main/source/video_sender.cc"

  "utility/frame_dropper.cc"
  "utility/include/frame_dropper.h"
  "utility/include/moving_average.h"
  "utility/include/quality_scaler.h"
  "utility/include/vp8_header_parser.h"
  "utility/quality_scaler.cc"
  "utility/vp8_header_parser.cc"
  
  "codecs/i420/main/interface/i420.h"
  "codecs/i420/main/source/i420.cc"

  "codecs/vp8/default_temporal_layers.h"
  "codecs/vp8/include/vp8.h"
  "codecs/vp8/include/vp8_common_types.h"
  "codecs/vp8/realtime_temporal_layers.cc"
  "codecs/vp8/reference_picture_selection.cc"
  "codecs/vp8/reference_picture_selection.h"
  "codecs/vp8/screenshare_layers.cc"
  "codecs/vp8/screenshare_layers.h"
  "codecs/vp8/simulcast_encoder_adapter.cc"
  "codecs/vp8/simulcast_encoder_adapter.h"
  "codecs/vp8/temporal_layers.h"
  "codecs/vp8/vp8_factory.cc"
  "codecs/vp8/vp8_factory.h"
  "codecs/vp8/vp8_impl.cc"
  "codecs/vp8/vp8_impl.h"

  "codecs/vp9/include/vp9.h"
  "codecs/vp9/vp9_frame_buffer_pool.cc"
  "codecs/vp9/vp9_frame_buffer_pool.h"
  "codecs/vp9/vp9_impl.cc"
  "codecs/vp9/vp9_impl.h"

  "codecs/h264/h264.cc"
  "codecs/h264/include/h264.h"

  )
include_directories(
  "${LIB_PATH_PREFIX}/libyuv/include"
  ${CMAKE_SOURCE_DIR}/libs/libvpx
  )
link_directories("${LIB_PATH_PREFIX}/libyuv/")

set(LIBRARYS "")
if(IOS)
  SET(VIDEO_CODING_SRC
    ${VIDEO_CODING_SRC}
    "codecs/h264/h264_video_toolbox_decoder.cc"
    "codecs/h264/h264_video_toolbox_decoder.h"
    "codecs/h264/h264_video_toolbox_encoder.cc"
    "codecs/h264/h264_video_toolbox_encoder.h"
    "codecs/h264/h264_video_toolbox_nalu.cc"
    "codecs/h264/h264_video_toolbox_nalu.h"
    "codecs/h264/h264_objc.mm"
    )
  set(LIBS ${LIBS}
    VideoToolbox
    CoreVideo
    CoreMedia
    CoreFoundation
    )  
elseif(APPLE)
  SET(VIDEO_CODING_SRC
    ${VIDEO_CODING_SRC}
    "codecs/h264/h264_decoder_impl.cc"
    "codecs/h264/h264_decoder_impl.h"
    "codecs/h264/h264_encoder_impl.cc"
    "codecs/h264/h264_encoder_impl.h"
    )
  # find_library(FFMPEG_LIB NAMES libavutil.a )
  # find_library(OPENH264_LIB NAMES libopenh264.a)
  add_definitions(-DWEBRTC_THIRD_PARTY_H264)
  link_directories("${LIB_PATH_PREFIX}/openh264")
  include_directories("${LIB_PATH_PREFIX}/openh264/include")
    link_directories("${LIB_PATH_PREFIX}/ffmpeg/lib")
  include_directories("${LIB_PATH_PREFIX}/ffmpeg/include")
  # find_path( FFMPEG_INCLUDE_DIR libavutil/samplefmt.h )
  # find_path( OPENH264_INCLUDE_DIR wels/codec_api.h)
  # include_directories(
  #   ${FFMPEG_INCLUDE_DIR}
  #   ${OPENH264_INCLUDE_DIR}
  #   )
  # message(openh264: ${OPENH264_INCLUDE_DIR})
  set(LIBRARYS ${LIBRARYS}
    "libavutil.a"
    "libopenh264.a"
    "libavcodec.a"
    "libavformat.a"
    )
endif()


Foreach(var ${LIBS})
  message(item:${var})
  FIND_LIBRARY(find${var} ${var})
  message(full path:${find${var}})
  if(${lib2} MATCHES "NOTFOUND")
    Message(error: "library not not found:${var}")
  else()
    set(LIBRARYS ${LIBRARYS} ${find${var}})
  endif()
Endforeach()

set(LIBRARYS ${LIBRARYS} COMMON_VIDEO SYSTEM_WRAPPER yuv)
add_definitions(
  -DWEBRTC_VIDEO_TOOLBOX_SUPPORTED
  -DWEBRTC_OBJC_H264
  )

ADD_LIBRARY(VideoCoding  ${VIDEO_CODING_SRC})

TARGET_LINK_LIBRARIES(VideoCoding ${LIBRARYS})
