add_subdirectory(lexer)

set(INCLUDE_HEADERS
    interpreter.hpp
)

install(FILES ${INCLUDE_HEADERS} DESTINATION include)