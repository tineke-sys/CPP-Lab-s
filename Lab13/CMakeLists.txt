cmake_minimum_required(VERSION 3.10)
project(Lab13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Lab13
    Main.cpp
    RadioRelay.cpp
    ElectromagneticRelay.cpp
    SolidStateRelay.cpp
    RelayManager.cpp
)
