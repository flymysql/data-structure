cmake_minimum_required(VERSION 3.10)
project(queue)

set(CMAKE_CXX_STANDARD 11)

add_executable(queue main.cpp Queue.h arrQueue.h linkQueue.h farmer_wolf.cpp)