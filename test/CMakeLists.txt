set(TEST_SRC
  main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/audio_device/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/audio_device)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
#SET(CMAKE_CXX_FLAGS "-std=c++11")
add_executable(main ${TEST_SRC})
target_link_libraries(main AudioDevice AudioProcessing)
