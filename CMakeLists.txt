cmake_minimum_required(VERSION 3.22)

project(system_login)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
include_directories(src)

add_executable( login_system
                src/main.cpp
                src/fs_file.cpp
                src/jsoncpp.cpp
                include/fs_file.hpp
                include/json/json.h
                include/json/json-forwards.h)
