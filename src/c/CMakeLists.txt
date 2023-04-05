cmake_minimum_required(VERSION 3.10)
project(jsonpath_parse LANGUAGES C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(SOURCE_FILES main.c cJSON.c jsonpath_gram.c jsonpath_scan.c)

add_executable(jsonpath_parse ${SOURCE_FILES})
