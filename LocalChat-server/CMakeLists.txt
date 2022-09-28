cmake_minimum_required(VERSION 3.23)
project(LocalChat_server C)

set(CMAKE_C_STANDARD 99)

add_executable(LocalChat_server lcserver.c connection.h connection.c)
