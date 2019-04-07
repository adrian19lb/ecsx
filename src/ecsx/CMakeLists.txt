project(ecsx-core)

set(CMAKE_MAJOR_VERSION 1)
set(CMAKE_MINOR_VERSION 0)

# Create component lib
add_library(component "")

target_link_libraries(component
    PUBLIC
        receiver
)
add_subdirectory(Component)
