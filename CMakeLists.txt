cmake_minimum_required(VERSION 3.30)
project(ModularCpp)
include_directories(utils)
set(CMAKE_CXX_STANDARD 20)
add_executable(ModularCpp main.cpp
        utils/logger.h)
