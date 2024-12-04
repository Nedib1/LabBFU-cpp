cmake_minimum_required(VERSION 3.15)



set(PROJECT_NAME example)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)


add_executable("${PROJECT_NAME}" mainlab6z4.cpp)