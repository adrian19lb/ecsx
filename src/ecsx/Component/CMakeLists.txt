set(INCROOT ${ecsx_SOURCE_DIR}/include/ecsx/Component)
set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(component PUBLIC
    ${INCROOT}    
)

target_sources(component
    PUBLIC
        ${INCROOT}/BaseComponent.hpp
        ${SRCDIR}/BaseComponent.cpp
        ${INCROOT}/Component.hpp
        ${INCROOT}/Component.hpp
        ${INCROOT}/PositionComponent.hpp
        ${INCROOT}/VelocityComponent.hpp
    PUBLIC
        ${INCROOT}/ComponentsHolder.hpp
        ${INCROOT}/ComponentsHolder.inl
        ${SRCDIR}/ComponentsHolder.cpp
    PUBLIC
        ${INCROOT}/Bitset.hpp
        ${INCROOT}/Bitset.inl
        ${INCROOT}/Entity.hpp
        ${SRCDIR}/Entity.cpp
        ${INCROOT}/ComponentsManager.hpp
        ${INCROOT}/ComponentsManager.inl
        ${SRCDIR}/ComponentsManager.cpp
)
