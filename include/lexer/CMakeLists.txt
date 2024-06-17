set(LEXER_HEADERS
    lexer.hpp
    token.hpp
    token_recognizers/keyword_recognizers.hpp
    token_recognizers/log_recognizers.hpp
)

install(FILES ${LEXER_HEADERS} DESTINATION include/lexer)
