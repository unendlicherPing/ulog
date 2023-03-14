cmake_minimum_required(VERSION 3.24)
project(ulog
        DESCRIPTION "A logging library for my projects"
        LANGUAGES C)

set(CMAKE_C_STANDARD 23)

add_library(${PROJECT_NAME} src/log.c include/ulog/log.h)
target_include_directories(${PROJECT_NAME} PUBLIC include)