set(SRC_SOURCES
    interpreter.cpp
)

add_subdirectory(lexer)

add_library(src ${SRC_SOURCES})

target_link_libraries(src lexer)