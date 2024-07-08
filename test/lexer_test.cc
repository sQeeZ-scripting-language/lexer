#include <gtest/gtest.h>
#include "lexer/lexer.hpp"

/*
 * SYNTAX
 */

TEST(LexerTest, IdentifySemicolon) {
    Lexer lexer(";");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_SEMICOLON);
    EXPECT_EQ(token.value, ";");
    EXPECT_EQ(token.desc, "Semicolon");
}

TEST(LexerTest, IdentifyOpenParenthesis) {
    Lexer lexer("(");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OPEN_PARENTHESIS);
    EXPECT_EQ(token.value, "(");
    EXPECT_EQ(token.desc, "Open Parenthesis");
}

TEST(LexerTest, IdentifyCloseParenthesis) {
    Lexer lexer(")");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CLOSE_PARENTHESIS);
    EXPECT_EQ(token.value, ")");
    EXPECT_EQ(token.desc, "Close Parenthesis");
}

TEST(LexerTest, IdentifyOpenBracket) {
    Lexer lexer("[");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OPEN_BRACKET);
    EXPECT_EQ(token.value, "[");
    EXPECT_EQ(token.desc, "Open Bracket");
}

TEST(LexerTest, IdentifyCloseBracket) {
    Lexer lexer("]");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CLOSE_BRACKET);
    EXPECT_EQ(token.value, "]");
    EXPECT_EQ(token.desc, "Close Bracket");
}

TEST(LexerTest, IdentifyOpenBrace) {
    Lexer lexer("{");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OPEN_BRACE);
    EXPECT_EQ(token.value, "{");
    EXPECT_EQ(token.desc, "Open Brace");
}

TEST(LexerTest, IdentifyCloseBrace) {
    Lexer lexer("}");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CLOSE_BRACE);
    EXPECT_EQ(token.value, "}");
    EXPECT_EQ(token.desc, "Close Brace");
}

TEST(LexerTest, IdentifyArrow) {
    Lexer lexer("->");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ARROW);
    EXPECT_EQ(token.value, "->");
    EXPECT_EQ(token.desc, "Arrow");
}

TEST(LexerTest, IdentifyHashtag) {
    Lexer lexer("#");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_HASHTAG);
    EXPECT_EQ(token.value, "#");
    EXPECT_EQ(token.desc, "Hashtag");
}
