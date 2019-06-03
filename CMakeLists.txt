cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

project(leet)

include_directories(include)

set(SOURCE_FILES
    src/twoSum.cpp
    src/addTwoNumbers.cpp
    src/reverseList.cpp
    src/hammingDistance.cpp
    src/isBoomerang.cpp
    src/lastStoneWeight.cpp
    src/numIslands.cpp
    src/MinStack.cpp
)

add_library(leet SHARED ${SOURCE_FILES})
