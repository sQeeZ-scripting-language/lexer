#include <gtest/gtest.h>
#include "lexer/lexer.hpp"
#include "lexer/tokens/token.hpp"

/*
 * SYNTAX
 */

TEST(LexerTest, IdentifySemicolon) {
    Lexer lexer(";");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);
    
    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::SEMICOLON);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
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
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "error");
    EXPECT_EQ(tokenPtr->plainText, "LogToken::ERROR");
    EXPECT_EQ(tokenPtr->desc, "Error logging function");
}

/*
 * Data
 */
TEST(LexerTest, IdentifyIdentifier) {
    Lexer lexer("identifier");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[1].type.dataToken, DataToken::IDENTIFIER);
    EXPECT_EQ(tokens[1].size, 10);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "identifier");
    EXPECT_EQ(tokens[1].plainText, "DataToken::IDENTIFIER");
    EXPECT_EQ(tokens[1].desc, "Identifier");
}

TEST(LexerTest, IdentifyIntegerLiteral) {
    Lexer lexer("12345");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[1].type.dataToken, DataToken::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].size, 5);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "12345");
    EXPECT_EQ(tokens[1].plainText, "DataToken::INTEGER_LITERAL");
    EXPECT_EQ(tokens[1].desc, "Integer Literal");
}

TEST(LexerTest, IdentifyDoubleLiteral) {
    Lexer lexer("123.45");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[1].type.dataToken, DataToken::DOUBLE_LITERAL);
    EXPECT_EQ(tokens[1].size, 6);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "123.45");
    EXPECT_EQ(tokens[1].plainText, "DataToken::DOUBLE_LITERAL");
    EXPECT_EQ(tokens[1].desc, "Double Literal");
}

TEST(LexerTest, IdentifyCommentLiteral) {
    Lexer lexer("// This is a comment");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[1].type.syntaxToken, SyntaxToken::INLINE_COMMENT);
    EXPECT_EQ(tokens[1].size, 2);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "//");
    EXPECT_EQ(tokens[1].plainText, "SyntaxToken::INLINE_COMMENT");
    EXPECT_EQ(tokens[1].desc, "Inline Comment");

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::COMMENT_LITERAL);
    EXPECT_EQ(tokens[2].size, 17);
    EXPECT_EQ(tokens[2].pos, 3);
    EXPECT_EQ(tokens[2].value, "This is a comment");
    EXPECT_EQ(tokens[2].plainText, "DataToken::COMMENT_LITERAL");
    EXPECT_EQ(tokens[2].desc, "Comment Literal");
}

TEST(LexerTest, IdentifyStringLiteral) {
    Lexer lexer("\"Hello, World!\"");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[1].type.syntaxToken, SyntaxToken::DOUBLE_QUOTE);
    EXPECT_EQ(tokens[1].size, 1);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "\"");
    EXPECT_EQ(tokens[1].plainText, "SyntaxToken::DOUBLE_QUOTE");
    EXPECT_EQ(tokens[1].desc, "Double Quote");

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::STRING_LITERAL);
    EXPECT_EQ(tokens[2].size, 13);
    EXPECT_EQ(tokens[2].pos, 1);
    EXPECT_EQ(tokens[2].value, "Hello, World!");
    EXPECT_EQ(tokens[2].plainText, "DataToken::STRING_LITERAL");
    EXPECT_EQ(tokens[2].desc, "String Literal");

    EXPECT_EQ(tokens[3].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[3].type.syntaxToken, SyntaxToken::DOUBLE_QUOTE);
    EXPECT_EQ(tokens[3].size, 1);
    EXPECT_EQ(tokens[3].pos, 14);
    EXPECT_EQ(tokens[3].value, "\"");
    EXPECT_EQ(tokens[3].plainText, "SyntaxToken::DOUBLE_QUOTE");
    EXPECT_EQ(tokens[3].desc, "Double Quote");
}