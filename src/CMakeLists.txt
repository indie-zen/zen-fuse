set(SERVER_SOURCES
  Server.cpp
  FUSE_api.cpp
  ZenFuse.cpp
)

find_package(Boost REQUIRED program_options)
find_package(fuse REQUIRED)
find_package(ZMQ REQUIRED)
find_package(ZeroMQPP REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIRS} ${ZeroMQPP_INCLUDE_DIR}
  ${ZMQ_INCLUDE_DIR} ${FUSE_INCLUDE_DIRS})

add_definitions(${FUSE_DEFINITIONS})
add_executable(zenfused ${SERVER_SOURCES})

target_link_libraries(zenfused ${Boost_LIBRARIES} ${ZeroMQPP_LIBRARY}
  ${ZMQ_LIBRARY} ${FUSE_LIBRARIES} pthread)

install (TARGETS zenfused DESTINATION bin)
