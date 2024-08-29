set(LEXER_HEADERS
    lexer.hpp
    token_recognizers/syntax_recognizers.hpp
    token_recognizers/keyword_recognizers.hpp
    token_recognizers/operator_recognizers.hpp
    token_recognizers/logical_recognizers.hpp
    token_recognizers/log_recognizers.hpp
    tokens/token.hpp
)

install(FILES ${LEXER_HEADERS} DESTINATION include/lexer)
