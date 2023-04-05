cmake_minimum_required(VERSION 3.22)
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
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    target_link_options(jsonpath_parse PRIVATE
        "-sEXPORTED_FUNCTIONS=_jsonpath_to_ast,_perform_exit"
        "-sEXPORTED_RUNTIME_METHODS=ccall,cwrap"
        "-sMODULARIZE=1"
        "-sENVIRONMENT=node"
        "-sWASM_ASYNC_COMPILATION=0"
    )

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(jsonpath_parse PRIVATE "-gsource-map" "-fsanitize=address" )
        target_link_options(jsonpath_parse PRIVATE
            "-gsource-map"
            "-sASSERTIONS=2"
            "-sSTACK_OVERFLOW_CHECK=2"
            "-fsanitize=address"
            "-sINITIAL_MEMORY=67108864"
        )
    endif()

else ()
    add_executable(jsonpath_parse ${SOURCE_FILES})
endif ()
