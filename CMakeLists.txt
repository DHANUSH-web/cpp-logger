cmake_minimum_required(VERSION 3.20)
project(cpp-logger)
# include_directories(logger)
set(CMAKE_CXX_STANDARD 20)
add_executable(cpplogger main.cpp
        logger.h
        manager.h)
