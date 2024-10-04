#include <gtest/gtest.h>
#include "lexer/lexer.hpp"
#include "lexer/tokens/token.hpp"

/*
 * SYNTAX
 */

TEST(LexerTest, IdentifyLineBreak) {
    Lexer lexer("\\n");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::LINE_BREAK);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "\\n");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::LINE_BREAK");
    EXPECT_EQ(tokenPtr->desc, "Line Break");
}

TEST(LexerTest, IdentifySemicolon) {
    Lexer lexer(";");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);
    
    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::SEMICOLON);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, ";");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::SEMICOLON");
    EXPECT_EQ(tokenPtr->desc, "Semicolon");
}

TEST(LexerTest, IdentifyComma) {
    Lexer lexer(",");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::COMMA);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, ",");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::COMMA");
    EXPECT_EQ(tokenPtr->desc, "Comma");
}

TEST(LexerTest, IdentifyDot) {
    Lexer lexer(".");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::DOT);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, ".");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::DOT");
    EXPECT_EQ(tokenPtr->desc, "Dot");
}

TEST(LexerTest, IdentifyColon) {
    Lexer lexer(":");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::COLON);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, ":");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::COLON");
    EXPECT_EQ(tokenPtr->desc, "Colon");
}

TEST(LexerTest, IdentifySingleQuote) {
    Lexer lexer("'");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::SINGLE_QUOTE);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "'");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::SINGLE_QUOTE");
    EXPECT_EQ(tokenPtr->desc, "Single Quote");
}

TEST(LexerTest, IdentifyDoubleQuote) {
    Lexer lexer("\"");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::DOUBLE_QUOTE);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "\"");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::DOUBLE_QUOTE");
    EXPECT_EQ(tokenPtr->desc, "Double Quote");
}

TEST(LexerTest, IdentifyOpenParenthesis) {
    Lexer lexer("(");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::OPEN_PARENTHESIS);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "(");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::OPEN_PARENTHESIS");
    EXPECT_EQ(tokenPtr->desc, "Open Parenthesis");
}

TEST(LexerTest, IdentifyCloseParenthesis) {
    Lexer lexer(")");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::CLOSE_PARENTHESIS);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, ")");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::CLOSE_PARENTHESIS");
    EXPECT_EQ(tokenPtr->desc, "Close Parenthesis");
}

TEST(LexerTest, IdentifyOpenBracket) {
    Lexer lexer("[");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::OPEN_BRACKET);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "[");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::OPEN_BRACKET");
    EXPECT_EQ(tokenPtr->desc, "Open Bracket");
}

TEST(LexerTest, IdentifyCloseBracket) {
    Lexer lexer("]");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::CLOSE_BRACKET);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "]");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::CLOSE_BRACKET");
    EXPECT_EQ(tokenPtr->desc, "Close Bracket");
}

TEST(LexerTest, IdentifyOpenBrace) {
    Lexer lexer("{");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::OPEN_BRACE);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "{");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::OPEN_BRACE");
    EXPECT_EQ(tokenPtr->desc, "Open Brace");
}

TEST(LexerTest, IdentifyCloseBrace) {
    Lexer lexer("}");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::CLOSE_BRACE);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "}");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::CLOSE_BRACE");
    EXPECT_EQ(tokenPtr->desc, "Close Brace");
}

TEST(LexerTest, IdentifyInlineComment) {
    Lexer lexer("//");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::INLINE_COMMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "//");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::INLINE_COMMENT");
    EXPECT_EQ(tokenPtr->desc, "Inline Comment");
}

TEST(LexerTest, IdentifyPipe) {
    Lexer lexer("|");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::PIPE);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "|");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::PIPE");
    EXPECT_EQ(tokenPtr->desc, "Pipe");
}

TEST(LexerTest, IdentifyPipeOperator) {
    Lexer lexer("|>");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::PIPE_OPERATOR);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "|>");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::PIPE_OPERATOR");
    EXPECT_EQ(tokenPtr->desc, "Pipe Operator");
}

TEST(LexerTest, IdentifyArrow) {
    Lexer lexer("->");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::ARROW);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "->");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::ARROW");
    EXPECT_EQ(tokenPtr->desc, "Arrow");
}

TEST(LexerTest, IdentifyHashtag) {
    Lexer lexer("#");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::HASHTAG);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "#");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::HASHTAG");
    EXPECT_EQ(tokenPtr->desc, "Hashtag");
}

TEST(LexerTest, IdentifyAt) {
    Lexer lexer("@");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::AT);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "@");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::AT");
    EXPECT_EQ(tokenPtr->desc, "AT");
}

/*
 * KEYWORDS
 */

TEST(LexerTest, IdentifyVariable) {
    Lexer lexer("var");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::VARIABLE);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->value, "var");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::VARIABLE");
    EXPECT_EQ(tokenPtr->desc, "Variable declaration");
}

TEST(LexerTest, IdentifyConstant) {
    Lexer lexer("const");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::CONSTANT);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->value, "const");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::CONSTANT");
    EXPECT_EQ(tokenPtr->desc, "Constant declaration");
}

TEST(LexerTest, IdentifyIf) {
    Lexer lexer("if");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::IF);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "if");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::IF");
    EXPECT_EQ(tokenPtr->desc, "Conditional statement");
}

TEST(LexerTest, IdentifyElse) {
    Lexer lexer("else");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::ELSE);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "else");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::ELSE");
    EXPECT_EQ(tokenPtr->desc, "Else statement");
}

TEST(LexerTest, IdentifyElseIf) {
    Lexer lexer("elif");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::ELSE_IF);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "elif");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::ELSE_IF");
    EXPECT_EQ(tokenPtr->desc, "Else if statement");
}

TEST(LexerTest, IdentifyFor) {
    Lexer lexer("for");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::FOR);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->value, "for");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::FOR");
    EXPECT_EQ(tokenPtr->desc, "For loop");
}

TEST(LexerTest, IdentifyWhile) {
    Lexer lexer("while");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::WHILE);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->value, "while");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::WHILE");
    EXPECT_EQ(tokenPtr->desc, "While loop");
}

TEST(LexerTest, IdentifyDo) {
    Lexer lexer("do");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::DO);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "do");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::DO");
    EXPECT_EQ(tokenPtr->desc, "Do While loop");
}

TEST(LexerTest, IdentifyFunction) {
    Lexer lexer("fn");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::FUNCTION);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "fn");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::FUNCTION");
    EXPECT_EQ(tokenPtr->desc, "Function declaration");
}

TEST(LexerTest, IdentifyReturn) {
    Lexer lexer("return");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::RETURN);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "return");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::RETURN");
    EXPECT_EQ(tokenPtr->desc, "Return keyword");
}

TEST(LexerTest, IdentifyIn) {
    Lexer lexer("in");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::IN);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "in");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::IN");
    EXPECT_EQ(tokenPtr->desc, "In keyword");
}

TEST(LexerTest, IdentifyOf) {
    Lexer lexer("of");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::KEYWORD);
    EXPECT_EQ(tokenPtr->type.keywordToken, KeywordToken::OF);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "of");
    EXPECT_EQ(tokenPtr->plainText, "KeywordToken::OF");
    EXPECT_EQ(tokenPtr->desc, "Of keyword");
}

/*
 * OPERATORS
 */

TEST(LexerTest, IdentifyAssign) {
    Lexer lexer("=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::ASSIGN); 
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "=");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::ASSIGN");
    EXPECT_EQ(tokenPtr->desc, "Assign");
}

TEST(LexerTest, IdentifyAddition) {
    Lexer lexer("+");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::ADDITION);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "+");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::ADDITION");
    EXPECT_EQ(tokenPtr->desc, "Addition");
}

TEST(LexerTest, IdentifySubtraction) {
    Lexer lexer("-");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::SUBTRACTION);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "-");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::SUBTRACTION");
    EXPECT_EQ(tokenPtr->desc, "Subtraction");
}

TEST(LexerTest, IdentifyMultiplication) {
    Lexer lexer("*");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::MULTIPLICATION);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "*");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::MULTIPLICATION");
    EXPECT_EQ(tokenPtr->desc, "Multiplication");
}

TEST(LexerTest, IdentifyDivision) {
    Lexer lexer("/");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::DIVISION);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "/");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::DIVISION");
    EXPECT_EQ(tokenPtr->desc, "Division");
}

TEST(LexerTest, IdentifyModulus) {
    Lexer lexer("%");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::MODULUS);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "%");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::MODULUS");
    EXPECT_EQ(tokenPtr->desc, "Modulus");
}

TEST(LexerTest, IdentifyAdditionAssignment) {
    Lexer lexer("+=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::ADDITION_ASSIGNMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "+=");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::ADDITION_ASSIGNMENT");
    EXPECT_EQ(tokenPtr->desc, "Addition Assignment");
}

TEST(LexerTest, IdentifySubtractionAssignment) {
    Lexer lexer("-=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::SUBTRACTION_ASSIGNMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "-=");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::SUBTRACTION_ASSIGNMENT");
    EXPECT_EQ(tokenPtr->desc, "Subtraction Assignment");
}

TEST(LexerTest, IdentifyMultiplicationAssignment) {
    Lexer lexer("*=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::MULTIPLICATION_ASSIGNMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "*=");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::MULTIPLICATION_ASSIGNMENT");
    EXPECT_EQ(tokenPtr->desc, "Multiplication Assignment");
}

TEST(LexerTest, IdentifyDivisionAssignment) {
    Lexer lexer("/=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::DIVISION_ASSIGNMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "/=");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::DIVISION_ASSIGNMENT");
    EXPECT_EQ(tokenPtr->desc, "Division Assignment");
}

TEST(LexerTest, IdentifyModulusAssignment) {
    Lexer lexer("%=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::MODULUS_ASSIGNMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "%=");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::MODULUS_ASSIGNMENT");
    EXPECT_EQ(tokenPtr->desc, "Modulus Assignment");
}

TEST(LexerTest, IdentifyIncrement) {
    Lexer lexer("++");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::INCREMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "++");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::INCREMENT");
    EXPECT_EQ(tokenPtr->desc, "Increment");
}

TEST(LexerTest, IdentifyDecrement) {
    Lexer lexer("--");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::DECREMENT);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "--");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::DECREMENT");
    EXPECT_EQ(tokenPtr->desc, "Decrement");
}

TEST(LexerTest, IdentifyPotentiation) {
    Lexer lexer("**");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::POTENTIATION);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "**");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::POTENTIATION");
    EXPECT_EQ(tokenPtr->desc, "Potentiation");
}

/*
 * LOGICAL OPERATORS
 */

TEST(LexerTest, IdentifyEqual) {
    Lexer lexer("==");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::EQUAL);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "==");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::EQUAL");
    EXPECT_EQ(tokenPtr->desc, "Equal");
}

TEST(LexerTest, IdentifyNotEqual) {
    Lexer lexer("!=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::NOT_EQUAL);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "!=");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::NOT_EQUAL");
    EXPECT_EQ(tokenPtr->desc, "Not Equal");
}

TEST(LexerTest, IdentifyGreater) {
    Lexer lexer(">");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::GREATER);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, ">");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::GREATER");
    EXPECT_EQ(tokenPtr->desc, "Greater");
}

TEST(LexerTest, IdentifyLess) {
    Lexer lexer("<");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::LESS);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "<");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::LESS");
    EXPECT_EQ(tokenPtr->desc, "Less");
}

TEST(LexerTest, IdentifyGreaterEqual) {
    Lexer lexer(">=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::GREATER_EQUAL);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, ">=");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::GREATER_EQUAL");
    EXPECT_EQ(tokenPtr->desc, "Greater Equal");
}

TEST(LexerTest, IdentifyLessEqual) {
    Lexer lexer("<=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::LESS_EQUAL);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "<=");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::LESS_EQUAL");
    EXPECT_EQ(tokenPtr->desc, "Less Equal");
}

TEST(LexerTest, IdentifyAnd) {
    Lexer lexer("&&");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::AND);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "&&");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::AND");
    EXPECT_EQ(tokenPtr->desc, "And");
}

TEST(LexerTest, IdentifyOr) {
    Lexer lexer("||");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::OR);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->value, "||");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::OR");
    EXPECT_EQ(tokenPtr->desc, "Or");
}

TEST(LexerTest, IdentifyNot) {
    Lexer lexer("!");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOGICAL);
    EXPECT_EQ(tokenPtr->type.logicalToken, LogicalToken::NOT);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->value, "!");
    EXPECT_EQ(tokenPtr->plainText, "LogicalToken::NOT");
    EXPECT_EQ(tokenPtr->desc, "Not");
}

/*
 * Loggers
 */

TEST(LexerTest, IdentifyLogger) {
    Lexer lexer("log");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOG);
    EXPECT_EQ(tokenPtr->type.logToken, LogToken::BASIC);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->value, "log");
    EXPECT_EQ(tokenPtr->plainText, "LogToken::BASIC");
    EXPECT_EQ(tokenPtr->desc, "Basic logging function");
}

TEST(LexerTest, IdentifyColoredLogger) {
    Lexer lexer("logc");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOG);
    EXPECT_EQ(tokenPtr->type.logToken, LogToken::COLORED);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "logc");
    EXPECT_EQ(tokenPtr->plainText, "LogToken::COLORED");
    EXPECT_EQ(tokenPtr->desc, "Colored logging function");
}

TEST(LexerTest, IdentifyWarnLogger) {
    Lexer lexer("warn");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOG);
    EXPECT_EQ(tokenPtr->type.logToken, LogToken::WARN);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "warn");
    EXPECT_EQ(tokenPtr->plainText, "LogToken::WARN");
    EXPECT_EQ(tokenPtr->desc, "Warning logging function");
}

TEST(LexerTest, IdentifyErrorLogger) {
    Lexer lexer("error");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::LOG);
    EXPECT_EQ(tokenPtr->type.logToken, LogToken::ERROR);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->value, "error");
    EXPECT_EQ(tokenPtr->plainText, "LogToken::ERROR");
    EXPECT_EQ(tokenPtr->desc, "Error logging function");
}

/*
 * Arrays
 */
TEST(LexerTest, IdentifyLength) {
    Lexer lexer("length");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::LENGTH);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "length");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::LENGTH");
    EXPECT_EQ(tokenPtr->desc, "Get the length of an array");
}

TEST(LexerTest, IdentifyPush) {
    Lexer lexer("push");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::PUSH);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "push");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::PUSH");
    EXPECT_EQ(tokenPtr->desc, "Push item to the end of an array");
}

TEST(LexerTest, IdentifyPop) {
    Lexer lexer("pop");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::POP);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->value, "pop");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::POP");
    EXPECT_EQ(tokenPtr->desc, "Pop item from the end of an array");
}

TEST(LexerTest, IdentifyShift) {
    Lexer lexer("shift");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::SHIFT);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->value, "shift");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::SHIFT");
    EXPECT_EQ(tokenPtr->desc, "Shift item from the beginning of an array");
}

TEST(LexerTest, IdentifyUnshift) {
    Lexer lexer("unshift");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::UNSHIFT);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->value, "unshift");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::UNSHIFT");
    EXPECT_EQ(tokenPtr->desc, "Unshift item to the beginning of an array");
}

TEST(LexerTest, IdentifySplice) {
    Lexer lexer("splice");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::SPLICE);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "splice");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::SPLICE");
    EXPECT_EQ(tokenPtr->desc, "Splice items into an array");
}

TEST(LexerTest, IdentifySlice) {
    Lexer lexer("slice");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::SLICE);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->value, "slice");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::SLICE");
    EXPECT_EQ(tokenPtr->desc, "Slice items from an array");
}

TEST(LexerTest, IdentifyConcat) {
    Lexer lexer("concat");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::CONCAT);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "concat");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::CONCAT");
    EXPECT_EQ(tokenPtr->desc, "Concatenate arrays");
}

TEST(LexerTest, IdentifyJoin) {
    Lexer lexer("join");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::JOIN);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "join");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::JOIN");
    EXPECT_EQ(tokenPtr->desc, "Join array elements into a string");
}

TEST(LexerTest, IdentifyReverse) {
    Lexer lexer("reverse");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::REVERSE);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->value, "reverse");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::REVERSE");
    EXPECT_EQ(tokenPtr->desc, "Reverse array elements");
}

TEST(LexerTest, IdentifySort) {
    Lexer lexer("sort");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::SORT);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "sort");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::SORT");
    EXPECT_EQ(tokenPtr->desc, "Sort array elements");
}

TEST(LexerTest, IdentifyMap) {
    Lexer lexer("map");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::MAP);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->value, "map");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::MAP");
    EXPECT_EQ(tokenPtr->desc, "Map array elements");
}

TEST(LexerTest, IdentifyFilter) {
    Lexer lexer("filter");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::FILTER);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "filter");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::FILTER");
    EXPECT_EQ(tokenPtr->desc, "Filter array elements");
}

TEST(LexerTest, IdentifyReduce) {
    Lexer lexer("reduce");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::REDUCE);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "reduce");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::REDUCE");
    EXPECT_EQ(tokenPtr->desc, "Reduce array elements");
}

TEST(LexerTest, IdentifyIncludes) {
    Lexer lexer("includes");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::INCLUDES);
    EXPECT_EQ(tokenPtr->size, 8);
    EXPECT_EQ(tokenPtr->value, "includes");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::INCLUDES");
    EXPECT_EQ(tokenPtr->desc, "Check if an array includes an element");
}

TEST(LexerTest, IdentifyForEach) {
    Lexer lexer("forEach");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::FOR_EACH);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->value, "forEach");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::FOR_EACH");
    EXPECT_EQ(tokenPtr->desc, "Iterate over array elements");
}

TEST(LexerTest, IdentifyIndexOf) {
    Lexer lexer("indexOf");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::ARRAY);
    EXPECT_EQ(tokenPtr->type.arrayToken, ArrayToken::INDEX_OF);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->value, "indexOf");
    EXPECT_EQ(tokenPtr->plainText, "ArrayToken::INDEX_OF");
    EXPECT_EQ(tokenPtr->desc, "Find index of an element in an array");
}

/*
 * Objects
 */
TEST(LexerTest, IdentfyEntries) {
    Lexer lexer("entries");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OBJECT);
    EXPECT_EQ(tokenPtr->type.objectToken, ObjectToken::ENTRIES);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->value, "entries");
    EXPECT_EQ(tokenPtr->plainText, "ObjectToken::ENTRIES");
    EXPECT_EQ(tokenPtr->desc, "Get key-value pairs of an object");
}

TEST(LexerTest, IdentfyKeys) {
    Lexer lexer("keys");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OBJECT);
    EXPECT_EQ(tokenPtr->type.objectToken, ObjectToken::KEYS);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->value, "keys");
    EXPECT_EQ(tokenPtr->plainText, "ObjectToken::KEYS");
    EXPECT_EQ(tokenPtr->desc, "Get keys of an object");
}

TEST(LexerTest, IdentfyValues) {
    Lexer lexer("values");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OBJECT);
    EXPECT_EQ(tokenPtr->type.objectToken, ObjectToken::VALUES);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "values");
    EXPECT_EQ(tokenPtr->plainText, "ObjectToken::VALUES");
    EXPECT_EQ(tokenPtr->desc, "Get values of an object");
}

TEST(LexerTest, IdentifyHasOwnProperty) {
    Lexer lexer("hasOwnProperty");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OBJECT);
    EXPECT_EQ(tokenPtr->type.objectToken, ObjectToken::HAS_OWN_PROPERTY);
    EXPECT_EQ(tokenPtr->size, 14);
    EXPECT_EQ(tokenPtr->value, "hasOwnProperty");
    EXPECT_EQ(tokenPtr->plainText, "ObjectToken::HAS_OWN_PROPERTY");
    EXPECT_EQ(tokenPtr->desc, "Check if an object has a property");
}

TEST(LexerTest, IdentifyDelete) {
    Lexer lexer("delete");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OBJECT);
    EXPECT_EQ(tokenPtr->type.objectToken, ObjectToken::DELETE);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "delete");
    EXPECT_EQ(tokenPtr->plainText, "ObjectToken::DELETE");
    EXPECT_EQ(tokenPtr->desc, "Delete a property from an object");
}

TEST(LexerTest, IdentifyTypeOf) {
    Lexer lexer("typeof");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OBJECT);
    EXPECT_EQ(tokenPtr->type.objectToken, ObjectToken::TYPE_OF);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->value, "typeof");
    EXPECT_EQ(tokenPtr->plainText, "ObjectToken::TYPE_OF");
    EXPECT_EQ(tokenPtr->desc, "Get the type of an object");
}


/*
 * Data Types
 */
TEST(LexerTest, IdentifyIntegerLiteral) {
    Lexer lexer("12345");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[1].type.dataToken, DataToken::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].size, 5);
    EXPECT_EQ(tokens[1].value, "12345");
    EXPECT_EQ(tokens[1].plainText, "DataToken::INTEGER_LITERAL");
    EXPECT_EQ(tokens[1].desc, "Integer Literal");
}

TEST(LexerTest, IdentifyDoubleLiteral) {
    Lexer lexer("123.45");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[1].type.dataToken, DataToken::DOUBLE_LITERAL);
    EXPECT_EQ(tokens[1].size, 6);
    EXPECT_EQ(tokens[1].value, "123.45");
    EXPECT_EQ(tokens[1].plainText, "DataToken::DOUBLE_LITERAL");
    EXPECT_EQ(tokens[1].desc, "Double Literal");
}

TEST(LexerTest, IdentifyStringLiteral) {
    Lexer lexer("\"Hello, World!\"");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[1].type.syntaxToken, SyntaxToken::DOUBLE_QUOTE);
    EXPECT_EQ(tokens[1].size, 1);
    EXPECT_EQ(tokens[1].value, "\"");
    EXPECT_EQ(tokens[1].plainText, "SyntaxToken::DOUBLE_QUOTE");
    EXPECT_EQ(tokens[1].desc, "Double Quote");

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::STRING_LITERAL);
    EXPECT_EQ(tokens[2].size, 13);
    EXPECT_EQ(tokens[2].value, "Hello, World!");
    EXPECT_EQ(tokens[2].plainText, "DataToken::STRING_LITERAL");
    EXPECT_EQ(tokens[2].desc, "String Literal");

    EXPECT_EQ(tokens[3].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[3].type.syntaxToken, SyntaxToken::DOUBLE_QUOTE);
    EXPECT_EQ(tokens[3].size, 1);
    EXPECT_EQ(tokens[3].value, "\"");
    EXPECT_EQ(tokens[3].plainText, "SyntaxToken::DOUBLE_QUOTE");
    EXPECT_EQ(tokens[3].desc, "Double Quote");
}

/*
 * Store Identifiers
 */

TEST(LexerTest, StoreFunctionIdentifier) {
    Lexer lexer("fn name");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::SET_FUNCTION_IDENTIFIER);
    EXPECT_EQ(tokens[2].size, 4);
    EXPECT_EQ(tokens[2].value, "name");
    EXPECT_EQ(tokens[2].plainText, "DataToken::SET_FUNCTION_IDENTIFIER");
    EXPECT_EQ(tokens[2].desc, "Function identifier stored");
}

TEST(LexerTest, StoreVariableIdentifier) {
    Lexer lexer("var name");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::SET_VARIABLE_IDENTIFIER);
    EXPECT_EQ(tokens[2].size, 4);
    EXPECT_EQ(tokens[2].value, "name");
    EXPECT_EQ(tokens[2].plainText, "DataToken::SET_VARIABLE_IDENTIFIER");
    EXPECT_EQ(tokens[2].desc, "Variable identifier stored");
}

TEST(LexerTest, StoreConstantIdentifier) {
    Lexer lexer("const name");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::SET_CONSTANT_IDENTIFIER);
    EXPECT_EQ(tokens[2].size, 4);
    EXPECT_EQ(tokens[2].value, "name");
    EXPECT_EQ(tokens[2].plainText, "DataToken::SET_CONSTANT_IDENTIFIER");
    EXPECT_EQ(tokens[2].desc, "Constant identifier stored");
}

/*
 * Access Identifiers
 */

TEST(LexerTest, AccessFunctionIdentifier) {
    Lexer lexer("fn name; name");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[4].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[4].type.dataToken, DataToken::USE_FUNCTION_IDENTIFIER);
    EXPECT_EQ(tokens[4].size, 4);
    EXPECT_EQ(tokens[4].value, "name");
    EXPECT_EQ(tokens[4].plainText, "DataToken::USE_FUNCTION_IDENTIFIER");
    EXPECT_EQ(tokens[4].desc, "Function identifier");
}

TEST(LexerTest, AccessVariableIdentifier) {
    Lexer lexer("var name; name");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[4].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[4].type.dataToken, DataToken::USE_VARIABLE_IDENTIFIER);
    EXPECT_EQ(tokens[4].size, 4);
    EXPECT_EQ(tokens[4].value, "name");
    EXPECT_EQ(tokens[4].plainText, "DataToken::USE_VARIABLE_IDENTIFIER");
    EXPECT_EQ(tokens[4].desc, "Variable identifier");
}

TEST(LexerTest, AccessConstantIdentifier) {
    Lexer lexer("const name; name");
    std::vector<Token> tokens = lexer.lex(false);

    EXPECT_EQ(tokens[4].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[4].type.dataToken, DataToken::USE_CONSTANT_IDENTIFIER);
    EXPECT_EQ(tokens[4].size, 4);
    EXPECT_EQ(tokens[4].value, "name");
    EXPECT_EQ(tokens[4].plainText, "DataToken::USE_CONSTANT_IDENTIFIER");
    EXPECT_EQ(tokens[4].desc, "Constant identifier");
}

/*
 * Invalid Identifiers
 */

TEST(LexerTest, InvalidIdentifierFormat) {
    Lexer lexer("fn 1");
    std::vector<Token> tokens = lexer.lex(false);
    EXPECT_EQ(tokens[2].tag, Token::TypeTag::ERROR);
    EXPECT_EQ(tokens[2].type.errorToken, ErrorToken::IDENTIFIER_INVALID_FORMAT);
    EXPECT_EQ(tokens[2].size, 1);
    EXPECT_EQ(tokens[2].value, "1");
    EXPECT_EQ(tokens[2].plainText, "ErrorToken::IDENTIFIER_INVALID_FORMAT");
    EXPECT_EQ(tokens[2].desc, "Invalid identifier format");
}

TEST(LexerTest, ReservedKeyword) {
    Lexer lexer("fn var");
    std::vector<Token> tokens = lexer.lex(false);
    EXPECT_EQ(tokens[2].tag, Token::TypeTag::ERROR);
    EXPECT_EQ(tokens[2].type.errorToken, ErrorToken::IDENTIFIER_RESERVED_KEYWORD);
    EXPECT_EQ(tokens[2].size, 3);
    EXPECT_EQ(tokens[2].value, "var");
    EXPECT_EQ(tokens[2].plainText, "ErrorToken::IDENTIFIER_RESERVED_KEYWORD");
    EXPECT_EQ(tokens[2].desc, "Reserved keyword");
}

TEST(LexerTest, IdentifierAlreadyExists) {
    Lexer lexer("fn name; fn name");
    std::vector<Token> tokens = lexer.lex(false);
    EXPECT_EQ(tokens[5].tag, Token::TypeTag::ERROR);
    EXPECT_EQ(tokens[5].type.errorToken, ErrorToken::IDENTIFIER_ALREADY_EXISTS);
    EXPECT_EQ(tokens[5].size, 4);
    EXPECT_EQ(tokens[5].value, "name");
    EXPECT_EQ(tokens[5].plainText, "ErrorToken::IDENTIFIER_ALREADY_EXISTS");
    EXPECT_EQ(tokens[5].desc, "Identifier already exists");
}

TEST(LexerTest, InvalidIdentifier) {
    Lexer lexer("fn name; name2");
    std::vector<Token> tokens = lexer.lex(false);
    EXPECT_EQ(tokens[4].tag, Token::TypeTag::ERROR);
    EXPECT_EQ(tokens[4].type.errorToken, ErrorToken::IDENTIFIER_NOT_FOUND);
    EXPECT_EQ(tokens[4].size, 5);
    EXPECT_EQ(tokens[4].value, "name2");
    EXPECT_EQ(tokens[4].plainText, "ErrorToken::IDENTIFIER_NOT_FOUND");
    EXPECT_EQ(tokens[4].desc, "Invalid identifier");
}