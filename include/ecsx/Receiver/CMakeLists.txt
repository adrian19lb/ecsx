add_library(receiver INTERFACE)

target_include_directories(receiver INTERFACE
    ${ecsx_SOURCE_DIR}/include/ecsx/Receiver    
)

target_sources(receiver INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Notifier.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Subscriber.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DatabaseSubscriber.hpp    
)
