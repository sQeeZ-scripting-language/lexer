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
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyComma) {
    Lexer lexer(",");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_COMMA);
    EXPECT_EQ(token.value, ",");
    EXPECT_EQ(token.desc, "Comma");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyDot) {
    Lexer lexer(".");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DOT);
    EXPECT_EQ(token.value, ".");
    EXPECT_EQ(token.desc, "Dot");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyColon) {
    Lexer lexer(":");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_COLON);
    EXPECT_EQ(token.value, ":");
    EXPECT_EQ(token.desc, "Colon");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifySingleQuote) {
    Lexer lexer("'");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_SINGLE_QUOTE);
    EXPECT_EQ(token.value, "'");
    EXPECT_EQ(token.desc, "Single Quote");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyDoubleQuote) {
    Lexer lexer("\"");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DOUBLE_QUOTE);
    EXPECT_EQ(token.value, "\"");
    EXPECT_EQ(token.desc, "Double Quote");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyOpenParenthesis) {
    Lexer lexer("(");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OPEN_PARENTHESIS);
    EXPECT_EQ(token.value, "(");
    EXPECT_EQ(token.desc, "Open Parenthesis");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyCloseParenthesis) {
    Lexer lexer(")");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CLOSE_PARENTHESIS);
    EXPECT_EQ(token.value, ")");
    EXPECT_EQ(token.desc, "Close Parenthesis");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyOpenBracket) {
    Lexer lexer("[");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OPEN_BRACKET);
    EXPECT_EQ(token.value, "[");
    EXPECT_EQ(token.desc, "Open Bracket");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyCloseBracket) {
    Lexer lexer("]");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CLOSE_BRACKET);
    EXPECT_EQ(token.value, "]");
    EXPECT_EQ(token.desc, "Close Bracket");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyOpenBrace) {
    Lexer lexer("{");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OPEN_BRACE);
    EXPECT_EQ(token.value, "{");
    EXPECT_EQ(token.desc, "Open Brace");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyCloseBrace) {
    Lexer lexer("}");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CLOSE_BRACE);
    EXPECT_EQ(token.value, "}");
    EXPECT_EQ(token.desc, "Close Brace");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyArrow) {
    Lexer lexer("->");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ARROW);
    EXPECT_EQ(token.value, "->");
    EXPECT_EQ(token.desc, "Arrow");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyHashtag) {
    Lexer lexer("#");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_HASHTAG);
    EXPECT_EQ(token.value, "#");
    EXPECT_EQ(token.desc, "Hashtag");
    EXPECT_EQ(lexer.pos, 1);
}

/*
 * KEYWORDS
 */

TEST(LexerTest, IdentifyVariable) {
    Lexer lexer("var");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_VARIABLE);
    EXPECT_EQ(token.value, "var");
    EXPECT_EQ(token.desc, "Variable declaration");
    EXPECT_EQ(lexer.pos, 3);
}

TEST(LexerTest, IdentifyIf) {
    Lexer lexer("if");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_IF);
    EXPECT_EQ(token.value, "if");
    EXPECT_EQ(token.desc, "Conditional statement");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyElse) {
    Lexer lexer("else");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ELSE);
    EXPECT_EQ(token.value, "else");
    EXPECT_EQ(token.desc, "Else statement");
    EXPECT_EQ(lexer.pos, 4);
}

TEST(LexerTest, IdentifyElseIf) {
    Lexer lexer("elif");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ELSE_IF);
    EXPECT_EQ(token.value, "elif");
    EXPECT_EQ(token.desc, "Else if statement");
    EXPECT_EQ(lexer.pos, 4);
}

TEST(LexerTest, IdentifyFor) {
    Lexer lexer("for");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FOR);
    EXPECT_EQ(token.value, "for");
    EXPECT_EQ(token.desc, "For loop");
    EXPECT_EQ(lexer.pos, 3);
}

TEST(LexerTest, IdentifyFunction) {
    Lexer lexer("fn");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FUNCTION);
    EXPECT_EQ(token.value, "fn");
    EXPECT_EQ(token.desc, "Function declaration");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyReturn) {
    Lexer lexer("return");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_RETURN);
    EXPECT_EQ(token.value, "return");
    EXPECT_EQ(token.desc, "Return keyword");
    EXPECT_EQ(lexer.pos, 6);
}

/*
 * OPERATORS
 */

TEST(LexerTest, IdentifyAssign) {
    Lexer lexer("=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ASSIGN); 
    EXPECT_EQ(token.value, "=");
    EXPECT_EQ(token.desc, "Assign");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyAddition) {
    Lexer lexer("+");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ADDITION);
    EXPECT_EQ(token.value, "+");
    EXPECT_EQ(token.desc, "Addition");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifySubtraction) {
    Lexer lexer("-");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_SUBTRACTION);
    EXPECT_EQ(token.value, "-");
    EXPECT_EQ(token.desc, "Subtraction");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyMultiplication) {
    Lexer lexer("*");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MULTIPLICATION);
    EXPECT_EQ(token.value, "*");
    EXPECT_EQ(token.desc, "Multiplication");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyDivision) {
    Lexer lexer("/");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DIVISION);
    EXPECT_EQ(token.value, "/");
    EXPECT_EQ(token.desc, "Division");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyModulus) {
    Lexer lexer("%");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MODULUS);
    EXPECT_EQ(token.value, "%");
    EXPECT_EQ(token.desc, "Modulus");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyAdditionAssignment) {
    Lexer lexer("+=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ADDITION_ASSIGNMENT);
    EXPECT_EQ(token.value, "+=");
    EXPECT_EQ(token.desc, "Addition Assignment");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifySubtractionAssignment) {
    Lexer lexer("-=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_SUBTRACTION_ASSIGNMENT);
    EXPECT_EQ(token.value, "-=");
    EXPECT_EQ(token.desc, "Subtraction Assignment");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyMultiplicationAssignment) {
    Lexer lexer("*=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MULTIPLICATION_ASSIGNMENT);
    EXPECT_EQ(token.value, "*=");
    EXPECT_EQ(token.desc, "Multiplication Assignment");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyDivisionAssignment) {
    Lexer lexer("/=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DIVISION_ASSIGNMENT);
    EXPECT_EQ(token.value, "/=");
    EXPECT_EQ(token.desc, "Division Assignment");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyModulusAssignment) {
    Lexer lexer("%=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MODULUS_ASSIGNMENT);
    EXPECT_EQ(token.value, "%=");
    EXPECT_EQ(token.desc, "Modulus Assignment");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyIncrement) {
    Lexer lexer("++");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_INCREMENT);
    EXPECT_EQ(token.value, "++");
    EXPECT_EQ(token.desc, "Increment");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyDecrement) {
    Lexer lexer("--");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DECREMENT);
    EXPECT_EQ(token.value, "--");
    EXPECT_EQ(token.desc, "Decrement");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyPotentiation) {
    Lexer lexer("**");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_POTENTIATION);
    EXPECT_EQ(token.value, "**");
    EXPECT_EQ(token.desc, "Potentiation");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyFloorDivision) {
    Lexer lexer("//");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FLOOR_DIVISION);
    EXPECT_EQ(token.value, "//");
    EXPECT_EQ(token.desc, "Floor Division");
    EXPECT_EQ(lexer.pos, 2);
}

/*
 * LOGICAL OPERATORS
 */

TEST(LexerTest, IdentifyEqual) {
    Lexer lexer("==");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_EQUAL);
    EXPECT_EQ(token.value, "==");
    EXPECT_EQ(token.desc, "Equal");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyNotEqual) {
    Lexer lexer("!=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_NOT_EQUAL);
    EXPECT_EQ(token.value, "!=");
    EXPECT_EQ(token.desc, "Not Equal");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyGreater) {
    Lexer lexer(">");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_GREATER);
    EXPECT_EQ(token.value, ">");
    EXPECT_EQ(token.desc, "Greater");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyLess) {
    Lexer lexer("<");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LESS);
    EXPECT_EQ(token.value, "<");
    EXPECT_EQ(token.desc, "Less");
    EXPECT_EQ(lexer.pos, 1);
}

TEST(LexerTest, IdentifyGreaterEqual) {
    Lexer lexer(">=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_GREATER_EQUAL);
    EXPECT_EQ(token.value, ">=");
    EXPECT_EQ(token.desc, "Greater Equal");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyLessEqual) {
    Lexer lexer("<=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LESS_EQUAL);
    EXPECT_EQ(token.value, "<=");
    EXPECT_EQ(token.desc, "Less Equal");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyAnd) {
    Lexer lexer("&&");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_AND);
    EXPECT_EQ(token.value, "&&");
    EXPECT_EQ(token.desc, "And");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyOr) {
    Lexer lexer("||");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OR);
    EXPECT_EQ(token.value, "||");
    EXPECT_EQ(token.desc, "Or");
    EXPECT_EQ(lexer.pos, 2);
}

TEST(LexerTest, IdentifyNot) {
    Lexer lexer("!");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_NOT);
    EXPECT_EQ(token.value, "!");
    EXPECT_EQ(token.desc, "Not");
    EXPECT_EQ(lexer.pos, 1);
}

/*
 * Loggers
 */

TEST(LexerTest, IdentifyLogger) {
    Lexer lexer("log");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LOG_BASIC);
    EXPECT_EQ(token.value, "log");
    EXPECT_EQ(token.desc, "Basic logging function");
    EXPECT_EQ(lexer.pos, 3);
}

TEST(LexerTest, IdentifyColoredLogger) {
    Lexer lexer("logc");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LOG_COLORED);
    EXPECT_EQ(token.value, "logc");
    EXPECT_EQ(token.desc, "Colored logging function");
    EXPECT_EQ(lexer.pos, 4);
}

TEST(LexerTest, IdentifyErrorLogger) {
    Lexer lexer("error");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LOG_ERROR);
    EXPECT_EQ(token.value, "error");
    EXPECT_EQ(token.desc, "Error logging function");
    EXPECT_EQ(lexer.pos, 5);
}
