cmake_minimum_required(VERSION 3.10)
project(stack)

set(CMAKE_CXX_STANDARD 11)

add_executable(stack main.cpp Stack.h arrStack.h linkStack.h)