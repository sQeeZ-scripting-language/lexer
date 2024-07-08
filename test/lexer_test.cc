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

TEST(LexerTest, IdentifyComma) {
    Lexer lexer(",");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_COMMA);
    EXPECT_EQ(token.value, ",");
    EXPECT_EQ(token.desc, "Comma");
}

TEST(LexerTest, IdentifyDot) {
    Lexer lexer(".");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DOT);
    EXPECT_EQ(token.value, ".");
    EXPECT_EQ(token.desc, "Dot");
}

TEST(LexerTest, IdentifyColon) {
    Lexer lexer(":");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_COLON);
    EXPECT_EQ(token.value, ":");
    EXPECT_EQ(token.desc, "Colon");
}

TEST(LexerTest, IdentifySingleQuote) {
    Lexer lexer("'");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_SINGLE_QUOTE);
    EXPECT_EQ(token.value, "'");
    EXPECT_EQ(token.desc, "Single Quote");
}

TEST(LexerTest, IdentifyDoubleQuote) {
    Lexer lexer("\"");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DOUBLE_QUOTE);
    EXPECT_EQ(token.value, "\"");
    EXPECT_EQ(token.desc, "Double Quote");
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

/*
 * KEYWORDS
 */

TEST(LexerTest, IdentifyLet) {
    Lexer lexer("let");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LET);
    EXPECT_EQ(token.value, "let");
    EXPECT_EQ(token.desc, "Variable declaration");
}

TEST(LexerTest, IdentifyConst) {
    Lexer lexer("const");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CONST);
    EXPECT_EQ(token.value, "const");
    EXPECT_EQ(token.desc, "Constant declaration");
}

TEST(LexerTest, IdentifyIf) {
    Lexer lexer("if");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_IF);
    EXPECT_EQ(token.value, "if");
    EXPECT_EQ(token.desc, "Conditional statement");
}

TEST(LexerTest, IdentifyElse) {
    Lexer lexer("else");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ELSE);
    EXPECT_EQ(token.value, "else");
    EXPECT_EQ(token.desc, "Else statement");
}

TEST(LexerTest, IdentifyElseIf) {
    Lexer lexer("elif");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ELSE_IF);
    EXPECT_EQ(token.value, "elif");
    EXPECT_EQ(token.desc, "Else if statement");
}

TEST(LexerTest, IdentifyFor) {
    Lexer lexer("for");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FOR);
    EXPECT_EQ(token.value, "for");
    EXPECT_EQ(token.desc, "For loop");
}

TEST(LexerTest, IdentifyIn) {
    Lexer lexer("in");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_IN);
    EXPECT_EQ(token.value, "in");
    EXPECT_EQ(token.desc, "In keyword");
}

TEST(LexerTest, IdentifyBreak) {
    Lexer lexer("break");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_BREAK);
    EXPECT_EQ(token.value, "break");
    EXPECT_EQ(token.desc, "Break keyword");
}

TEST(LexerTest, IdentifyContinue) {
    Lexer lexer("continue");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CONTINUE);
    EXPECT_EQ(token.value, "continue");
    EXPECT_EQ(token.desc, "Continue keyword");
}

TEST(LexerTest, IdentifyFunction) {
    Lexer lexer("fn");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FUNCTION);
    EXPECT_EQ(token.value, "fn");
    EXPECT_EQ(token.desc, "Function declaration");
}

TEST(LexerTest, IdentifyReturn) {
    Lexer lexer("return");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_RETURN);
    EXPECT_EQ(token.value, "return");
    EXPECT_EQ(token.desc, "Return keyword");
}