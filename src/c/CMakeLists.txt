cmake_minimum_required(VERSION 3.10)
project(jsonpath_parse LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

set(SOURCE_FILES
    cJSON.c
    jsonpath_gram.c
    jsonpath_scan.c
    main.c
)

if (DEFINED EMSCRIPTEN)
    add_executable(jsonpath_parse ${SOURCE_FILES})
    #set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    target_link_options(jsonpath_parse PRIVATE "-sEXPORTED_FUNCTIONS=_jsonpath_to_ast")
    target_link_options(jsonpath_parse PRIVATE "-sEXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']")
    target_link_options(jsonpath_parse PRIVATE "-sMODULARIZE=1")
    target_link_options(jsonpath_parse PRIVATE "-sENVIRONMENT=node")
else ()
    add_executable(jsonpath_parse ${SOURCE_FILES})
endif ()
