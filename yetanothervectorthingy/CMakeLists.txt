cmake_minimum_required(VERSION 3.5)

project(yetanothervectorthingy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(yetanothervectorthingy main.cpp)

install(TARGETS yetanothervectorthingy
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
