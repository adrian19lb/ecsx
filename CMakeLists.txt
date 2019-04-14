cmake_minimum_required(VERSION 3.8)
project(ecsx)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Add googletest 
option(GTEST_TESTS "Google Test framework test" ON)
if (GTEST_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Add receiver header-only library subdirectory
add_subdirectory(include/ecsx/Receiver)

# Add ecsx-core project subdirectory
add_subdirectory(src/ecsx)
