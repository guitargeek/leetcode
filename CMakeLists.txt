cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

project(leet)

include_directories(include)

set(SOURCE_FILES
    src/twoSum.cpp
    src/addTwoNumbers.cpp
    src/lengthOfLongestSubstring.cpp
    src/romanToInt.cpp
    src/threeSum.cpp
    src/findPeakElement.cpp
    src/climbStairs.cpp
    src/reverseList.cpp
    src/hammingDistance.cpp
    src/isBoomerang.cpp
    src/lastStoneWeight.cpp
    src/rangeSumBST.cpp
    src/sortedSquares.cpp
    src/numIslands.cpp
    src/gardenNoAdj.cpp
    src/MinStack.cpp
)

add_library(leet SHARED ${SOURCE_FILES})
