cmake_minimum_required(VERSION 4.2)
project(System-Design-CPP)

set(CMAKE_CXX_STANDARD 20)

# Keeps your main folder clean by putting .exe files in the build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# 1. Find all .cpp files in your project directory
file(GLOB_RECURSE CPP_FILES "*.cpp")

# 2. FILTER OUT any files that are inside the cmake-build directories
list(FILTER CPP_FILES EXCLUDE REGEX "cmake-build-")

# 3. Loop through the safe files and create an executable for each
foreach(FILE ${CPP_FILES})
    get_filename_component(TARGET_NAME ${FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${FILE})

    # NEW LINE: Force this specific target to output to the build directory
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
endforeach()