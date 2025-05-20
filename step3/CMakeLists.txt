cmake_minimum_required(VERSION 3.29)
project(stepThree)

set(CMAKE_CXX_STANDARD 20)

add_executable(stepThree main.cpp
        account.cpp
        account.h
        date.cpp
        date.h
        accumulator.h)
