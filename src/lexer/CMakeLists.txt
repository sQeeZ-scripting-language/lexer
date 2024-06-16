set(LEXER_SOURCES
    lexer.cpp
    token_recognizers/keyword_recognizers.cpp
)

add_library(lexer ${LEXER_SOURCES})
