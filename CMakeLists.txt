cmake_minimum_required(VERSION 3.16)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)

file(GLOB GLOB_RECURSE SOURCES *.h)
add_executable(aoc2022 main.cpp ${SOURCES} 5/5_2/soln5_2.h 5/5_1/soln5_2.h)
file(GLOB_RECURSE TXT_INS "*.txt")
file(COPY ${TXT_INS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})