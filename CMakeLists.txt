cmake_minimum_required(VERSION 3.8)
project(ex2_hone)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES MyString.c MyString.h LineSeparator.c LineSeparator.h)
add_executable(ex2_hone ${SOURCE_FILES} MyString.h LineSeparator.c LineSeparator.h)