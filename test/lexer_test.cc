#include <gtest/gtest.h>
#include "lexer/lexer.hpp"
#include "lexer/tokens/token.hpp"

/*
 * SYNTAX
 */

TEST(LexerTest, IdentifySemicolon) {
    Lexer lexer(";");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::SEMICOLON);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, ";");
    EXPECT_EQ(token.desc, "Semicolon");
}

TEST(LexerTest, IdentifyComma) {
    Lexer lexer(",");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::COMMA);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, ",");
    EXPECT_EQ(token.desc, "Comma");
}

TEST(LexerTest, IdentifyDot) {
    Lexer lexer(".");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::DOT);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, ".");
    EXPECT_EQ(token.desc, "Dot");
}

TEST(LexerTest, IdentifyColon) {
    Lexer lexer(":");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::COLON);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, ":");
    EXPECT_EQ(token.desc, "Colon");
}

TEST(LexerTest, IdentifySingleQuote) {
    Lexer lexer("'");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::SINGLE_QUOTE);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "'");
    EXPECT_EQ(token.desc, "Single Quote");
}

TEST(LexerTest, IdentifyDoubleQuote) {
    Lexer lexer("\"");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::DOUBLE_QUOTE);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "\"");
    EXPECT_EQ(token.desc, "Double Quote");
}

TEST(LexerTest, IdentifyOpenParenthesis) {
    Lexer lexer("(");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::OPEN_PARENTHESIS);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "(");
    EXPECT_EQ(token.desc, "Open Parenthesis");
}

TEST(LexerTest, IdentifyCloseParenthesis) {
    Lexer lexer(")");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::CLOSE_PARENTHESIS);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, ")");
    EXPECT_EQ(token.desc, "Close Parenthesis");
}

TEST(LexerTest, IdentifyOpenBracket) {
    Lexer lexer("[");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::OPEN_BRACKET);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "[");
    EXPECT_EQ(token.desc, "Open Bracket");
}

TEST(LexerTest, IdentifyCloseBracket) {
    Lexer lexer("]");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::CLOSE_BRACKET);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "]");
    EXPECT_EQ(token.desc, "Close Bracket");
}

TEST(LexerTest, IdentifyOpenBrace) {
    Lexer lexer("{");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::OPEN_BRACE);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "{");
    EXPECT_EQ(token.desc, "Open Brace");
}

TEST(LexerTest, IdentifyCloseBrace) {
    Lexer lexer("}");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::CLOSE_BRACE);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "}");
    EXPECT_EQ(token.desc, "Close Brace");
}

TEST(LexerTest, IdentifyArrow) {
    Lexer lexer("->");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::ARROW);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "->");
    EXPECT_EQ(token.desc, "Arrow");
}

TEST(LexerTest, IdentifyHashtag) {
    Lexer lexer("#");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(token.type.syntaxToken, SyntaxToken::HASHTAG);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "#");
    EXPECT_EQ(token.desc, "Hashtag");
}

/*
 * KEYWORDS
 */

TEST(LexerTest, IdentifyVariable) {
    Lexer lexer("var");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::VARIABLE);
    EXPECT_EQ(token.size, 3);
    EXPECT_EQ(token.value, "var");
    EXPECT_EQ(token.desc, "Variable declaration");
}

TEST(LexerTest, IdentifyConstant) {
    Lexer lexer("const");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::CONSTANT);
    EXPECT_EQ(token.size, 5);
    EXPECT_EQ(token.value, "const");
    EXPECT_EQ(token.desc, "Constant declaration");
}

TEST(LexerTest, IdentifyIf) {
    Lexer lexer("if");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::IF);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "if");
    EXPECT_EQ(token.desc, "Conditional statement");
}

TEST(LexerTest, IdentifyElse) {
    Lexer lexer("else");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::ELSE);
    EXPECT_EQ(token.size, 4);
    EXPECT_EQ(token.value, "else");
    EXPECT_EQ(token.desc, "Else statement");
}

TEST(LexerTest, IdentifyElseIf) {
    Lexer lexer("elif");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::ELSE_IF);
    EXPECT_EQ(token.size, 4);
    EXPECT_EQ(token.value, "elif");
    EXPECT_EQ(token.desc, "Else if statement");
}

TEST(LexerTest, IdentifyFor) {
    Lexer lexer("for");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::FOR);
    EXPECT_EQ(token.size, 3);
    EXPECT_EQ(token.value, "for");
    EXPECT_EQ(token.desc, "For loop");
}

TEST(LexerTest, IdentifyFunction) {
    Lexer lexer("fn");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::FUNCTION);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "fn");
    EXPECT_EQ(token.desc, "Function declaration");
}

TEST(LexerTest, IdentifyReturn) {
    Lexer lexer("return");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(token.type.keywordToken, KeywordToken::RETURN);
    EXPECT_EQ(token.size, 6);
    EXPECT_EQ(token.value, "return");
    EXPECT_EQ(token.desc, "Return keyword");
}

/*
 * OPERATORS
 */

TEST(LexerTest, IdentifyAssign) {
    Lexer lexer("=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::ASSIGN); 
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "=");
    EXPECT_EQ(token.desc, "Assign");
}

TEST(LexerTest, IdentifyAddition) {
    Lexer lexer("+");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::ADDITION);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "+");
    EXPECT_EQ(token.desc, "Addition");
}

TEST(LexerTest, IdentifySubtraction) {
    Lexer lexer("-");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::SUBTRACTION);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "-");
    EXPECT_EQ(token.desc, "Subtraction");
}

TEST(LexerTest, IdentifyMultiplication) {
    Lexer lexer("*");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::MULTIPLICATION);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "*");
    EXPECT_EQ(token.desc, "Multiplication");
}

TEST(LexerTest, IdentifyDivision) {
    Lexer lexer("/");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::DIVISION);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "/");
    EXPECT_EQ(token.desc, "Division");
}

TEST(LexerTest, IdentifyModulus) {
    Lexer lexer("%");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::MODULUS);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "%");
    EXPECT_EQ(token.desc, "Modulus");
}

TEST(LexerTest, IdentifyAdditionAssignment) {
    Lexer lexer("+=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::ADDITION_ASSIGNMENT);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "+=");
    EXPECT_EQ(token.desc, "Addition Assignment");
}

TEST(LexerTest, IdentifySubtractionAssignment) {
    Lexer lexer("-=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::SUBTRACTION_ASSIGNMENT);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "-=");
    EXPECT_EQ(token.desc, "Subtraction Assignment");
}

TEST(LexerTest, IdentifyMultiplicationAssignment) {
    Lexer lexer("*=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::MULTIPLICATION_ASSIGNMENT);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "*=");
    EXPECT_EQ(token.desc, "Multiplication Assignment");
}

TEST(LexerTest, IdentifyDivisionAssignment) {
    Lexer lexer("/=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::DIVISION_ASSIGNMENT);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "/=");
    EXPECT_EQ(token.desc, "Division Assignment");
}

TEST(LexerTest, IdentifyModulusAssignment) {
    Lexer lexer("%=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::MODULUS_ASSIGNMENT);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "%=");
    EXPECT_EQ(token.desc, "Modulus Assignment");
}

TEST(LexerTest, IdentifyIncrement) {
    Lexer lexer("++");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::INCREMENT);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "++");
    EXPECT_EQ(token.desc, "Increment");
}

TEST(LexerTest, IdentifyDecrement) {
    Lexer lexer("--");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::DECREMENT);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "--");
    EXPECT_EQ(token.desc, "Decrement");
}

TEST(LexerTest, IdentifyPotentiation) {
    Lexer lexer("**");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::POTENTIATION);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "**");
    EXPECT_EQ(token.desc, "Potentiation");
}

TEST(LexerTest, IdentifyFloorDivision) {
    Lexer lexer("//");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(token.type.operatorToken, OperatorToken::FLOOR_DIVISION);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "//");
    EXPECT_EQ(token.desc, "Floor Division");
}

/*
 * LOGICAL OPERATORS
 */

TEST(LexerTest, IdentifyEqual) {
    Lexer lexer("==");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::EQUAL);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "==");
    EXPECT_EQ(token.desc, "Equal");
}

TEST(LexerTest, IdentifyNotEqual) {
    Lexer lexer("!=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::NOT_EQUAL);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "!=");
    EXPECT_EQ(token.desc, "Not Equal");
}

TEST(LexerTest, IdentifyGreater) {
    Lexer lexer(">");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::GREATER);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, ">");
    EXPECT_EQ(token.desc, "Greater");
}

TEST(LexerTest, IdentifyLess) {
    Lexer lexer("<");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::LESS);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "<");
    EXPECT_EQ(token.desc, "Less");
}

TEST(LexerTest, IdentifyGreaterEqual) {
    Lexer lexer(">=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::GREATER_EQUAL);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, ">=");
    EXPECT_EQ(token.desc, "Greater Equal");
}

TEST(LexerTest, IdentifyLessEqual) {
    Lexer lexer("<=");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::LESS_EQUAL);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "<=");
    EXPECT_EQ(token.desc, "Less Equal");
}

TEST(LexerTest, IdentifyAnd) {
    Lexer lexer("&&");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::AND);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "&&");
    EXPECT_EQ(token.desc, "And");
}

TEST(LexerTest, IdentifyOr) {
    Lexer lexer("||");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::OR);
    EXPECT_EQ(token.size, 2);
    EXPECT_EQ(token.value, "||");
    EXPECT_EQ(token.desc, "Or");
}

TEST(LexerTest, IdentifyNot) {
    Lexer lexer("!");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(token.type.logicalToken, LogicalToken::NOT);
    EXPECT_EQ(token.size, 1);
    EXPECT_EQ(token.value, "!");
    EXPECT_EQ(token.desc, "Not");
}

/*
 * Loggers
 */

TEST(LexerTest, IdentifyLogger) {
    Lexer lexer("log");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOG);
    EXPECT_EQ(token.type.logToken, LogToken::BASIC);
    EXPECT_EQ(token.size, 3);
    EXPECT_EQ(token.value, "log");
    EXPECT_EQ(token.desc, "Basic logging function");
}

TEST(LexerTest, IdentifyColoredLogger) {
    Lexer lexer("logc");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOG);
    EXPECT_EQ(token.type.logToken, LogToken::COLORED);
    EXPECT_EQ(token.size, 4);
    EXPECT_EQ(token.value, "logc");
    EXPECT_EQ(token.desc, "Colored logging function");
}

TEST(LexerTest, IdentifyErrorLogger) {
    Lexer lexer("error");
    Token token = *lexer.getNextToken();
    EXPECT_EQ(token.tag, Token::TypeTag::LOG);
    EXPECT_EQ(token.type.logToken, LogToken::ERROR);
    EXPECT_EQ(token.size, 5);
    EXPECT_EQ(token.value, "error");
    EXPECT_EQ(token.desc, "Error logging function");
}
