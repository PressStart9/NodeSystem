add_library(node_system
        Node.cpp
)

target_include_directories(node_system PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
