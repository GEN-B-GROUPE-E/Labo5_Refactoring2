cmake_minimum_required(VERSION 3.12)
project(GEN_Refactor2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(GEN_Refactor2
        src/Customer.cpp
        src/Customer.h
        src/main.cpp
        src/Movie.cpp
        src/Movie.h
        src/Rental.h)
