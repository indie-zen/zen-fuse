cmake_minimum_required (VERSION 3.5)
#set(CMAKE_CXX_FLAGS "-std=c++14 -stdlib=libc++")
#set(CMAKE_CXX_FLAGS "-std=c++1z")
set(CMAKE_CXX_FLAGS "-std=c++14")

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(zenfuse)

#set(CMAKE_DISABLE_SOURCE_CHANGES ON)
#set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

find_program(CLDOC cldoc)

add_subdirectory(src)
