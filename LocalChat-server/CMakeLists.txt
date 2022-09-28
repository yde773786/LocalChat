cmake_minimum_required(VERSION 3.23)
project(LocalChat_server C)

set(CMAKE_C_STANDARD 99)

add_library(LocalChat_server lcserver.c lcserver.c connection.h connection.c)
