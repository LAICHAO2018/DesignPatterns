cmake_minimum_required(VERSION 3.22)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(DesignPatterns include/ObserverPattern.h
        main.cpp)
