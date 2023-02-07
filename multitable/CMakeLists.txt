cmake_minimum_required(VERSION 3.5)

project(multitable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(multitable main.cpp)

install(TARGETS multitable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
