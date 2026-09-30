cmake_minimum_required(VERSION 3.10)
project(CarProject)

# Вказуємо стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Перераховуємо всі файли вашого проєкту
add_executable(program main.cpp Car.cpp)