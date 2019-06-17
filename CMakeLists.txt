cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

project(leet)

include_directories(include)

set(SOURCE_FILES
    src/twoSum.cpp
    src/addTwoNumbers.cpp
    src/lengthOfLongestSubstring.cpp
    src/reverse.cpp
    src/longestCommonPrefix.cpp
    src/romanToInt.cpp
    src/longestConsecutive.cpp
    src/threeSum.cpp
    src/rob.cpp
    src/fib.cpp
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
    src/leastInterval.cpp
    src/diameterOfBinaryTree.cpp
    src/MinStack.cpp
)

add_library(leet SHARED ${SOURCE_FILES})
