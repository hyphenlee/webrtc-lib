SET(UTILITY_SRC
  "interface/audio_frame_operations.h"
  "interface/file_player.h"
  "interface/file_recorder.h"
  "interface/helpers_android.h"
  "interface/jvm_android.h"
  "interface/process_thread.h"
  "source/audio_frame_operations.cc"
  "source/coder.cc"
  "source/coder.h"
  "source/file_player_impl.cc"
  "source/file_player_impl.h"
  "source/file_recorder_impl.cc"
  "source/file_recorder_impl.h"
  "source/helpers_android.cc"
  "source/jvm_android.cc"
  "source/process_thread_impl.cc"
  "source/process_thread_impl.h"
  "source/helpers_ios.mm"
  )

add_library(UTILITY ${UTILITY_SRC})
target_link_libraries(UTILITY COMMON CommonAudio SyatemWrapper AudioCoding MediaFile)
