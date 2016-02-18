SET(COMMON_AUDIO_SRC
  "audio_converter.cc"
  "audio_converter.h"
  "audio_ring_buffer.cc"
  "audio_ring_buffer.h"
  "audio_util.cc"
  "blocker.cc"
  "blocker.h"
  "channel_buffer.cc"
  "channel_buffer.h"
  "fft4g.c"
  "fft4g.h"
  "fir_filter.cc"
  "fir_filter.h"
  "fir_filter_neon.h"
  "fir_filter_sse.h"
  "include/audio_util.h"
  "lapped_transform.cc"
  "lapped_transform.h"
  "real_fourier.cc"
  "real_fourier.h"
  "real_fourier_ooura.cc"
  "real_fourier_ooura.h"
  "resampler/include/push_resampler.h"
  "resampler/include/resampler.h"
  "resampler/push_resampler.cc"
  "resampler/push_sinc_resampler.cc"
  "resampler/push_sinc_resampler.h"
  "resampler/resampler.cc"
  "resampler/sinc_resampler.cc"
  "resampler/sinc_resampler.h"
  "ring_buffer.c"
  "ring_buffer.h"
  "signal_processing/auto_corr_to_refl_coef.c"
  "signal_processing/auto_correlation.c"
  "signal_processing/complex_fft_tables.h"
  "signal_processing/copy_set_operations.c"
  "signal_processing/cross_correlation.c"
  "signal_processing/division_operations.c"
  "signal_processing/dot_product_with_scale.c"
  "signal_processing/downsample_fast.c"
  "signal_processing/energy.c"
  "signal_processing/filter_ar.c"
  "signal_processing/filter_ma_fast_q12.c"
  "signal_processing/get_hanning_window.c"
  "signal_processing/get_scaling_square.c"
  "signal_processing/ilbc_specific_functions.c"
  "signal_processing/include/real_fft.h"
  "signal_processing/include/signal_processing_library.h"
  "signal_processing/include/spl_inl.h"
  "signal_processing/levinson_durbin.c"
  "signal_processing/lpc_to_refl_coef.c"
  "signal_processing/min_max_operations.c"
  "signal_processing/randomization_functions.c"
  "signal_processing/real_fft.c"
  "signal_processing/refl_coef_to_lpc.c"
  "signal_processing/resample.c"
  "signal_processing/resample_48khz.c"
  "signal_processing/resample_by_2.c"
  "signal_processing/resample_by_2_internal.c"
  "signal_processing/resample_by_2_internal.h"
  "signal_processing/resample_fractional.c"
  "signal_processing/spl_init.c"
  "signal_processing/spl_sqrt.c"
  "signal_processing/splitting_filter.c"
  "signal_processing/sqrt_of_one_minus_x_squared.c"
  "signal_processing/vector_scaling_operations.c"
  "sparse_fir_filter.cc"
  "sparse_fir_filter.h"
  "vad/include/vad.h"
  "vad/include/webrtc_vad.h"
  "vad/vad.cc"
  "vad/vad_core.c"
  "vad/vad_core.h"
  "vad/vad_filterbank.c"
  "vad/vad_filterbank.h"
  "vad/vad_gmm.c"
  "vad/vad_gmm.h"
  "vad/vad_sp.c"
  "vad/vad_sp.h"
  "vad/webrtc_vad.c"
  "wav_file.cc"
  "wav_file.h"
  "wav_header.cc"
  "wav_header.h"
  "window_generator.cc"
  "window_generator.h"
  "signal_processing/complex_fft.c"

  )
if(APPLE)
  if(IOS)
    # ADD_DEFINITIONS(-DWEBRTC_DETECT_NEON)
    message("handle for ios")
    message(platfrom:${IOS_PLATFORM})
    if(${IOS_PLATFORM} STREQUAL OS)
      message("handle for real device")
      SET(COMMON_AUDIO_SRC
        ${COMMON_AUDIO_SRC}
        "fir_filter_neon.cc"
        "resampler/sinc_resampler_neon.cc"
        "signal_processing/cross_correlation_neon.c"
        "signal_processing/downsample_fast_neon.c"
        "signal_processing/min_max_operations_neon.c"
        "signal_processing/complex_bit_reverse_arm.S"
        "signal_processing/spl_sqrt_floor_arm.S"
        "signal_processing/complex_bit_reverse.c"
        "signal_processing/spl_sqrt_floor.c"
        # "signal_processing/filter_ar_fast_q12_armv7.S"
        "signal_processing/filter_ar_fast_q12.c"
        # "fir_filter_sse.cc"
        # "resampler/sinc_resampler_sse.cc"
        )
      ADD_DEFINITIONS(-DWEBRTC_DETECT_NEON)
    else ()
      SET(COMMON_AUDIO_SRC
        ${COMMON_AUDIO_SRC}
        "signal_processing/complex_bit_reverse.c"
        "signal_processing/spl_sqrt_floor.c"
        "signal_processing/filter_ar_fast_q12.c"
        "fir_filter_sse.cc"
        "resampler/sinc_resampler_sse.cc"
        )
    endif()
  else()
    SET(COMMON_AUDIO_SRC
      ${COMMON_AUDIO_SRC}
      "signal_processing/complex_bit_reverse.c"
      "signal_processing/filter_ar_fast_q12.c"
      "signal_processing/spl_sqrt_floor.c"
      "fir_filter_sse.cc"
      "resampler/sinc_resampler_sse.cc"
      )
  endif()
elseif(ANDROID)
  message("common audio:build for android")
  SET(COMMON_AUDIO_SRC
    ${COMMON_AUDIO_SRC}
    "fir_filter_neon.cc"
    "resampler/sinc_resampler_neon.cc"
    "signal_processing/cross_correlation_neon.c"
    "signal_processing/downsample_fast_neon.c"
    "signal_processing/min_max_operations_neon.c"
    "signal_processing/complex_bit_reverse_arm.S"
    "signal_processing/spl_sqrt_floor_arm.S"
    "signal_processing/complex_bit_reverse.c"
    "signal_processing/spl_sqrt_floor.c"
    "signal_processing/filter_ar_fast_q12_armv7.S"
    )
  ADD_DEFINITIONS(-DWEBRTC_DETECT_NEON)
  # SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=neon")
  # SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfpu=neon")
endif()

ADD_LIBRARY(CommonAudio ${COMMON_AUDIO_SRC})
target_link_libraries(CommonAudio COMMON BASE SystemWrapper)
