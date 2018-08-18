cmake_minimum_required(VERSION 3.10)
project(single_link)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(single_link
        linklist.h
        main.cpp)
