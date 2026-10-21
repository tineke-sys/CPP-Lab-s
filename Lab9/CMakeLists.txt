cmake_minimum_required(VERSION 3.10)
project(Lab9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab9 
    Main.cpp 
    Antenna.cpp 
    Antenna.h 
    OmnidirectionalAntenna.cpp 
    OmnidirectionalAntenna.h 
    DirectionalAntenna.cpp 
    DirectionalAntenna.h
)
