cmake_minimum_required(VERSION 3.12)
project(IFT3001_TP2_Q2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IFT3001_TP2_Q2
        couples.txt
        couples_format_windows.txt
        experience.cpp
        tests.cpp
        tri.cpp
        tri.hpp)
