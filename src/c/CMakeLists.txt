cmake_minimum_required(VERSION 3.10)
project(jsonpath_parse LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(SOURCE_FILES
    cJSON.c
    jsonpath_gram.c
    jsonpath_scan.c
    main.c
)

add_executable(jsonpath_parse ${SOURCE_FILES})
