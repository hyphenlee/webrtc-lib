SET(BASE_SRC
  "atomicops.h"
  "bitbuffer.cc"
  "bitbuffer.h"
  "buffer.cc"
  "buffer.h"
  "bufferqueue.cc"
  "bufferqueue.h"
  "bytebuffer.cc"
  "bytebuffer.h"
  "byteorder.h"
  "checks.cc"
  "checks.h"
  "criticalsection.cc"
  "criticalsection.h"
  "event.cc"
  "event.h"
  "event_tracer.cc"
  "event_tracer.h"
  "exp_filter.cc"
  "exp_filter.h"
  "md5.cc"
  "md5.h"
  "md5digest.cc"
  "md5digest.h"
  "platform_file.cc"
  "platform_file.h"
  "platform_thread.cc"
  "platform_thread.h"
  "safe_conversions.h"
  "safe_conversions_impl.h"
  "scoped_ptr.h"
  "stringencode.cc"
  "stringencode.h"
  "stringutils.cc"
  "stringutils.h"
  "systeminfo.cc"
  "systeminfo.h"
  "template_util.h"
  "thread_annotations.h"
  "thread_checker.h"
  "thread_checker_impl.cc"
  "thread_checker_impl.h"
  "timeutils.cc"
  "timeutils.h"
  "trace_event.h"
  "basictypes.h"
  "constructormagic.h"
  "logging.cc"
  "logging.h"
  
  "arraysize.h"
  "asyncfile.cc"
  "asyncfile.h"
  "asyncinvoker-inl.h"
  "asyncinvoker.cc"
  "asyncinvoker.h"
  "asyncpacketsocket.cc"
  "asyncpacketsocket.h"
  "asyncresolverinterface.cc"
  "asyncresolverinterface.h"
  "asyncsocket.cc"
  "asyncsocket.h"
  "asynctcpsocket.cc"
  "asynctcpsocket.h"
  "asyncudpsocket.cc"
  "asyncudpsocket.h"
  "autodetectproxy.cc"
  "autodetectproxy.h"
  "base64.cc"
  "base64.h"
  "basicdefs.h"
  "common.cc"
  "common.h"
  "crc32.cc"
  "crc32.h"
  "cryptstring.cc"
  "cryptstring.h"
  "diskcache.cc"
  "diskcache.h"
  "filerotatingstream.cc"
  "filerotatingstream.h"
  "fileutils.cc"
  "fileutils.h"
  "firewallsocketserver.cc"
  "firewallsocketserver.h"
  "flags.cc"
  "flags.h"
  "format_macros.h"
  "gunit_prod.h"
  "helpers.cc"
  "helpers.h"
  "httpbase.cc"
  "httpbase.h"
  "httpclient.cc"
  "httpclient.h"
  "httpcommon-inl.h"
  "httpcommon.cc"
  "httpcommon.h"
  "httprequest.cc"
  "httprequest.h"
  "iosfilesystem.mm"
  "ipaddress.cc"
  "ipaddress.h"
  "linked_ptr.h"
  "mathutils.h"
  "messagedigest.cc"
  "messagedigest.h"
  "messagehandler.cc"
  "messagehandler.h"
  "messagequeue.cc"
  "messagequeue.h"
  "nethelpers.cc"
  "nethelpers.h"
  "network.cc"
  "network.h"
  "nullsocketserver.h"
  "pathutils.cc"
  "pathutils.h"
  "physicalsocketserver.cc"
  "physicalsocketserver.h"
  "proxydetect.cc"
  "proxydetect.h"
  "proxyinfo.cc"
  "proxyinfo.h"
  "ratelimiter.cc"
  "ratelimiter.h"
  "ratetracker.cc"
  "ratetracker.h"
  "rtccertificate.cc"
  "rtccertificate.h"
  "scoped_autorelease_pool.h"
  # "scoped_autorelease_pool.mm"
  "sha1.cc"
  "sha1.h"
  "sha1digest.cc"
  "sha1digest.h"
  "signalthread.cc"
  "signalthread.h"
  "sigslot.cc"
  "sigslot.h"
  "sigslotrepeater.h"
  "socket.h"
  "socketadapters.cc"
  "socketadapters.h"
  "socketaddress.cc"
  "socketaddress.h"
  "socketaddresspair.cc"
  "socketaddresspair.h"
  "socketfactory.h"
  "socketpool.cc"
  "socketpool.h"
  "socketserver.h"
  "socketstream.cc"
  "socketstream.h"
  "ssladapter.cc"
  "ssladapter.h"
  "sslfingerprint.cc"
  "sslfingerprint.h"
  "sslidentity.cc"
  "sslidentity.h"
  "sslsocketfactory.cc"
  "sslsocketfactory.h"
  "sslstreamadapter.cc"
  "sslstreamadapter.h"
  "sslstreamadapterhelper.cc"
  "sslstreamadapterhelper.h"
  "stream.cc"
  "stream.h"
  "task.cc"
  "task.h"
  "taskparent.cc"
  "taskparent.h"
  "taskrunner.cc"
  "taskrunner.h"
  "thread.cc"
  "thread.h"
  "timing.cc"
  "timing.h"
  "urlencode.cc"
  "urlencode.h"
  "worker.cc"
  "worker.h"

  
  "unixfilesystem.cc"
  "unixfilesystem.h"

  "bandwidthsmoother.cc"
  "bandwidthsmoother.h"
  "bind.h"
  "bind.h.pump"
  "callback.h"
  "callback.h.pump"
  "fileutils_mock.h"
  # "genericslot.h"
  # "genericslot.h.pump"
  "httpserver.cc"
  "httpserver.h"
  "json.cc"
  "json.h"
  "logsinks.cc"
  "logsinks.h"
  "mathutils.h"
  "multipart.cc"
  "multipart.h"
  "natserver.cc"
  "natserver.h"
  "natsocketfactory.cc"
  "natsocketfactory.h"
  "nattypes.cc"
  "nattypes.h"
  "optionsfile.cc"
  "optionsfile.h"
  "profiler.cc"
  "profiler.h"
  "proxyserver.cc"
  "proxyserver.h"
  "refcount.h"
  "referencecountedsingletonfactory.h"
  "rollingaccumulator.h"
  "scoped_ref_ptr.h"
  "scopedptrcollection.h"
  "sec_buffer.h"
  "sharedexclusivelock.cc"
  "sharedexclusivelock.h"
  "sslconfig.h"
  "sslroots.h"
  "testclient.cc"
  "testclient.h"
  "transformadapter.cc"
  "transformadapter.h"
  "versionparsing.cc"
  "versionparsing.h"
  "virtualsocketserver.cc"
  "virtualsocketserver.h"
  "window.h"
  "windowpicker.h"
  "windowpickerfactory.h"
  "latebindingsymboltable.cc"
  "latebindingsymboltable.cc.def"
  "latebindingsymboltable.h"
  "latebindingsymboltable.h.def"
  "posix.cc"
  "posix.h"
  # "maccocoathreadhelper.h"
  # "maccocoathreadhelper.mm"
  "macconversion.cc"
  "macconversion.h"
  # "macutils.cc"
  # "macutils.h"

  )
SET(LIBS  "")
IF(APPLE)
  IF(IOS)
    message(STATUS "start build base for ios")
    set(LIBS ${LIBS}
      "CFNetwork"
      "Foundation"
      "Security"
      "SystemConfiguration"
      "UIKit"
      # "ssl"
      # "crypto"
      )
    SET(BASE_SRC
      ${BASE_SRC}
      "macconversion.cc"
      "macconversion.h"
      )
    link_directories(${PROJECT_SOURCE_DIR}/libs/ios/openssl/lib)
    include_directories(${PROJECT_SOURCE_DIR}/libs/ios/openssl/include)
    set(CMAKE_LIBRARY_PATH "${CMAKE_LIBRARY_PATH} ${PROJECT_SOURCE_DIR}/libs/ios/openssl/include")
    ADD_DEFINITIONS(-DCARBON_DEPRECATED=YES)
    ADD_DEFINITIONS(-DWEBRTC_POSIX)
    ADD_DEFINITIONS(-DWEBRTC_IOS)
    ADD_DEFINITIONS(-DWEBRTC_MAC)
    # ADD_DEFINITIONS(-DBSD)
    

  else()
    # INCLUDE_DIRECTORIES( "/usr/local/Cellar/openssl/1.0.2d_1/include/")
    # INCLUDE_DIRECTORIES( "/usr/local/Cellar/jsoncpp/0.10.5/include/jsoncpp/")
    INCLUDE_DIRECTORIES( "${PROJECT_SOURCE_DIR}/common_audio/signal_processing/include/")
    include_directories("${LIB_PATH_PREFIX}/openssl/include")
    # LINK_DIRECTORIES( "/usr/local/Cellar/openssl/1.0.2d_1/lib/")
    message("start build for darwin system")
    set(LIBS ${LIBS}
      "Cocoa"
      "AppKit"
      "ApplicationServices"
      "Carbon"
      "CoreFoundation"
      "Foundation"
      "IOKit"
      "Security"
      "SystemConfiguration"
      "ssl"
      "crypto"
      # "jsoncpp"
      )
    # set(LIBRARYS ${LIBRARYS} ${ssl_library} ${ssl_library2})
    message(librarys: "${LIBRARYS}")
    SET(BASE_SRC
      ${BASE_SRC}
      "macasyncsocket.cc"
      "macasyncsocket.h"
      "maccocoasocketserver.h"
      "maccocoasocketserver.mm"
      "macsocketserver.cc"
      "macsocketserver.h"
      "macwindowpicker.cc"
      "macwindowpicker.h"
      )
    ADD_DEFINITIONS(-DWEBRTC_POSIX)
    ADD_DEFINITIONS(-DWEBRTC_MAC)
    ADD_DEFINITIONS(-DSSL_USE_OPENSSL=1)
  endif()
elseif(ANDROID)
  message("build for android")
  SET(BASE_SRC
    ${BASE_SRC}
    "ifaddrs-android.cc"
    "ifaddrs-android.h"
    )
  set(LIBS ${LIBS}
    "log"
    "GLESv2"
    "c"
    "dl"
    "m"
    "ssl"
    "crypto"
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

if(IOS)
  set(LIBRARYS ${LIBRARYS} ssl crypto)
endif()

ADD_LIBRARY(BASE  ${BASE_SRC})

TARGET_LINK_LIBRARIES(BASE ${LIBRARYS})
