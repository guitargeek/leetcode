cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

project(leet)

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_library(leet SHARED ${SOURCE_FILES})
