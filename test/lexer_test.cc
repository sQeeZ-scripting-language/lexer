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

TEST(LexerTest, IdentifyVariableDeclaration) {
    Lexer lexer("!!");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_VARIABLE_DECLARATION);
    EXPECT_EQ(token.value, "!!");
    EXPECT_EQ(token.desc, "Variable declaration");
}

TEST(LexerTest, IdentifyIf) {
    Lexer lexer("?");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_IF);
    EXPECT_EQ(token.value, "?");
    EXPECT_EQ(token.desc, "Conditional statement");
}

TEST(LexerTest, IdentifyElse) {
    Lexer lexer("??");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ELSE);
    EXPECT_EQ(token.value, "??");
    EXPECT_EQ(token.desc, "Else statement");
}

TEST(LexerTest, IdentifyElseIf) {
    Lexer lexer("???");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ELSE_IF);
    EXPECT_EQ(token.value, "???");
    EXPECT_EQ(token.desc, "Else if statement");
}

TEST(LexerTest, IdentifyFor) {
    Lexer lexer("@");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FOR);
    EXPECT_EQ(token.value, "@");
    EXPECT_EQ(token.desc, "For loop");
}

TEST(LexerTest, IdentifyBreak) {
    Lexer lexer("<<");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_BREAK);
    EXPECT_EQ(token.value, "<<");
    EXPECT_EQ(token.desc, "Break keyword");
}

TEST(LexerTest, IdentifyContinue) {
    Lexer lexer(">>");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_CONTINUE);
    EXPECT_EQ(token.value, ">>");
    EXPECT_EQ(token.desc, "Continue keyword");
}

TEST(LexerTest, IdentifyFunction) {
    Lexer lexer("$");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FUNCTION);
    EXPECT_EQ(token.value, "$");
    EXPECT_EQ(token.desc, "Function declaration");
}

TEST(LexerTest, IdentifyReturn) {
    Lexer lexer("=>");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_RETURN);
    EXPECT_EQ(token.value, "=>");
    EXPECT_EQ(token.desc, "Return keyword");
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
}

TEST(LexerTest, IdentifyAddition) {
    Lexer lexer("+");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ADDITION);
    EXPECT_EQ(token.value, "+");
    EXPECT_EQ(token.desc, "Addition");
}

TEST(LexerTest, IdentifySubtraction) {
    Lexer lexer("-");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_SUBTRACTION);
    EXPECT_EQ(token.value, "-");
    EXPECT_EQ(token.desc, "Subtraction");
}

TEST(LexerTest, IdentifyMultiplication) {
    Lexer lexer("*");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MULTIPLICATION);
    EXPECT_EQ(token.value, "*");
    EXPECT_EQ(token.desc, "Multiplication");
}

TEST(LexerTest, IdentifyDivision) {
    Lexer lexer("/");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DIVISION);
    EXPECT_EQ(token.value, "/");
    EXPECT_EQ(token.desc, "Division");
}

TEST(LexerTest, IdentifyModulus) {
    Lexer lexer("%");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MODULUS);
    EXPECT_EQ(token.value, "%");
    EXPECT_EQ(token.desc, "Modulus");
}

TEST(LexerTest, IdentifyAdditionAssignment) {
    Lexer lexer("+=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_ADDITION_ASSIGNMENT);
    EXPECT_EQ(token.value, "+=");
    EXPECT_EQ(token.desc, "Addition Assignment");
}

TEST(LexerTest, IdentifySubtractionAssignment) {
    Lexer lexer("-=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_SUBTRACTION_ASSIGNMENT);
    EXPECT_EQ(token.value, "-=");
    EXPECT_EQ(token.desc, "Subtraction Assignment");
}

TEST(LexerTest, IdentifyMultiplicationAssignment) {
    Lexer lexer("*=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MULTIPLICATION_ASSIGNMENT);
    EXPECT_EQ(token.value, "*=");
    EXPECT_EQ(token.desc, "Multiplication Assignment");
}

TEST(LexerTest, IdentifyDivisionAssignment) {
    Lexer lexer("/=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DIVISION_ASSIGNMENT);
    EXPECT_EQ(token.value, "/=");
    EXPECT_EQ(token.desc, "Division Assignment");
}

TEST(LexerTest, IdentifyModulusAssignment) {
    Lexer lexer("%=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_MODULUS_ASSIGNMENT);
    EXPECT_EQ(token.value, "%=");
    EXPECT_EQ(token.desc, "Modulus Assignment");
}

TEST(LexerTest, IdentifyIncrement) {
    Lexer lexer("++");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_INCREMENT);
    EXPECT_EQ(token.value, "++");
    EXPECT_EQ(token.desc, "Increment");
}

TEST(LexerTest, IdentifyDecrement) {
    Lexer lexer("--");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_DECREMENT);
    EXPECT_EQ(token.value, "--");
    EXPECT_EQ(token.desc, "Decrement");
}

TEST(LexerTest, IdentifyPotentiation) {
    Lexer lexer("**");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_POTENTIATION);
    EXPECT_EQ(token.value, "**");
    EXPECT_EQ(token.desc, "Potentiation");
}

TEST(LexerTest, IdentifyFloorDivision) {
    Lexer lexer("//");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_FLOOR_DIVISION);
    EXPECT_EQ(token.value, "//");
    EXPECT_EQ(token.desc, "Floor Division");
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
}

TEST(LexerTest, IdentifyNotEqual) {
    Lexer lexer("!=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_NOT_EQUAL);
    EXPECT_EQ(token.value, "!=");
    EXPECT_EQ(token.desc, "Not Equal");
}

TEST(LexerTest, IdentifyGreater) {
    Lexer lexer(">");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_GREATER);
    EXPECT_EQ(token.value, ">");
    EXPECT_EQ(token.desc, "Greater");
}

TEST(LexerTest, IdentifyLess) {
    Lexer lexer("<");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LESS);
    EXPECT_EQ(token.value, "<");
    EXPECT_EQ(token.desc, "Less");
}

TEST(LexerTest, IdentifyGreaterEqual) {
    Lexer lexer(">=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_GREATER_EQUAL);
    EXPECT_EQ(token.value, ">=");
    EXPECT_EQ(token.desc, "Greater Equal");
}

TEST(LexerTest, IdentifyLessEqual) {
    Lexer lexer("<=");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LESS_EQUAL);
    EXPECT_EQ(token.value, "<=");
    EXPECT_EQ(token.desc, "Less Equal");
}

TEST(LexerTest, IdentifyAnd) {
    Lexer lexer("&&");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_AND);
    EXPECT_EQ(token.value, "&&");
    EXPECT_EQ(token.desc, "And");
}

TEST(LexerTest, IdentifyOr) {
    Lexer lexer("||");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_OR);
    EXPECT_EQ(token.value, "||");
    EXPECT_EQ(token.desc, "Or");
}

TEST(LexerTest, IdentifyNot) {
    Lexer lexer("!");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_NOT);
    EXPECT_EQ(token.value, "!");
    EXPECT_EQ(token.desc, "Not");
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
}

TEST(LexerTest, IdentifyColoredLogger) {
    Lexer lexer("logc");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LOG_COLORED);
    EXPECT_EQ(token.value, "logc");
    EXPECT_EQ(token.desc, "Colored logging function");
}

TEST(LexerTest, IdentifyErrorLogger) {
    Lexer lexer("err");
    Token token = lexer.getNextToken();
    EXPECT_EQ(token.type, TokenType::TOKEN_LOG_ERROR);
    EXPECT_EQ(token.value, "err");
    EXPECT_EQ(token.desc, "Error logging function");
}
