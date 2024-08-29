set(SRC_SOURCES
    main.cpp
)

add_subdirectory(lexer)

add_library(src ${SRC_SOURCES})

target_link_libraries(src lexer)