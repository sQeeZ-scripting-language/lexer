set(LEXER_HEADERS
    lexer.hpp
    token.hpp
    token_recognizers/keyword_recognizers.hpp
)

install(FILES ${LEXER_HEADERS} DESTINATION include/lexer)
