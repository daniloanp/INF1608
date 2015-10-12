cmake_minimum_required(VERSION 2.8)
project(lab6_INF1608)

set(CMAKE_C_FLAGS "-std=c99 -lm")

set(SOURCE_FILES teste_poly.c poly.c poly.h  )
add_executable(lab6_INF1608 ${SOURCE_FILES})