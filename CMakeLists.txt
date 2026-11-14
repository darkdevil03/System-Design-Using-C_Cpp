cmake_minimum_required(VERSION 4.2)
project(System-Design-CPP)

set(CMAKE_CXX_STANDARD 20)

# Keeps your main folder clean by putting .exe files in the build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# 1. Find all .cpp files in your project directory
file(GLOB_RECURSE CPP_FILES "*.cpp")

# 2. FILTER OUT any files that are inside the cmake-build directories
list(FILTER CPP_FILES EXCLUDE REGEX "cmake-build-")

# 3. Loop through the safe files and create an executable only if it contains a main() function
foreach(FILE ${CPP_FILES})
    # Check if the file contains a main() function
    file(STRINGS "${FILE}" HAS_MAIN REGEX "int[ \t]+main[ \t]*\\(")
    if(HAS_MAIN)
        # Create a unique target name by replacing directory separators with underscores
        get_filename_component(FILE_DIR ${FILE} DIRECTORY)
        get_filename_component(TARGET_NAME ${FILE} NAME_WE)
        file(RELATIVE_PATH REL_DIR "${PROJECT_SOURCE_DIR}" "${FILE_DIR}")
        if(NOT REL_DIR STREQUAL "")
            string(REPLACE "/" "_" REL_DIR_SAFE "${REL_DIR}")
            string(REPLACE "\\" "_" REL_DIR_SAFE "${REL_DIR_SAFE}")
            set(TARGET_NAME "${REL_DIR_SAFE}_${TARGET_NAME}")
        endif()
        add_executable(${TARGET_NAME} ${FILE})

        # Force this specific target to output to the build directory
        set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
    endif()
endforeach()