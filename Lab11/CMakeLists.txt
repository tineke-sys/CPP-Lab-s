cmake_minimum_required(VERSION 3.10)
project(Lab11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Lab11
    Main.cpp
    Antenna.cpp
    OmnidirectionalAntenna.cpp
    DirectionalAntenna.cpp
    AntennaManager.cpp
)

