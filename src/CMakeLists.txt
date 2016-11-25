set(SERVER_SOURCES
  FUSE_api.cpp
  Server.cpp
  ZenFuse.cpp
)

find_package(Boost REQUIRED program_options)
find_package(fuse REQUIRED)
find_package(ZMQ REQUIRED)
find_package(ZeroMQPP REQUIRED)
find_package(IndieZen REQUIRED)

message("Zen Enterprise Library: " ${ZEN_ENTERPRISE_LIBRARY})
message("Zen Fabric Library: " ${ZEN_FABRIC_LIBRARY})
message("ZeroMQPP Library: " ${ZeroMQPP_LIBRARY})
message("ZMQ Library: " ${ZMQ_LIBRARY})

set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${ZeroMQPP_INCLUDE_DIR}
  ${ZMQ_INCLUDE_DIR} ${FUSE_INCLUDE_DIRS})

add_definitions(${FUSE_DEFINITIONS})
add_executable(zenfused ${SERVER_SOURCES})

target_link_libraries(zenfused ${ZEN_FABRIC_LIBRARY} ${ZEN_ENTERPRISE_LIBRARY} 
  ${ZeroMQPP_LIBRARY} ${ZMQ_LIBRARY} ${Boost_LIBRARIES} ${FUSE_LIBRARIES} pthread)

install (TARGETS zenfused DESTINATION bin)
