set(LEXER_HEADERS
    lexer.hpp
    token_recognizers/data_recognizers.hpp
    token_recognizers/keyword_recognizers.hpp
    token_recognizers/log_recognizers.hpp
    token_recognizers/logical_recognizers.hpp
    token_recognizers/operator_recognizers.hpp
    token_recognizers/syntax_recognizers.hpp
    tokens/data_token.hpp
    tokens/error_token.hpp
    tokens/keyword_token.hpp
    tokens/log_token.hpp
    tokens/logical_token.hpp
    tokens/operator_token.hpp
    tokens/syntax_token.hpp
    tokens/token.hpp
)

install(FILES ${LEXER_HEADERS} DESTINATION include/lexer)
