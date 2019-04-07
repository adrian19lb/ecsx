cmake_minimum_required(VERSION 3.8)
project(ecsx)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_MAJOR_VERSION 1)
set(CMAKE_MINOR_VERSION 0)
set(CMAKE_PATCH_VERSION 0)

# Add receiver header-only library subdirectory
add_subdirectory(include/ecsx/Receiver)

# Add ecsx-core project subdirectory
add_subdirectory(src/ecsx)
