set(INCROOT ${ecsx_SOURCE_DIR}/include/ecsx/Component)
set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(component PUBLIC
    ${INCROOT}    
)
