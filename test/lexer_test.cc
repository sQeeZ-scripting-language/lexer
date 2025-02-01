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

TEST(LexerTest, IdentifyQuestionMark) {
    Lexer lexer("?");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::QUESTION_MARK);
    EXPECT_EQ(tokenPtr->size, 1);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "?");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::QUESTION_MARK");
    EXPECT_EQ(tokenPtr->desc, "Question Mark");
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

TEST(LexerTest, IdentifyCallback) {
    Lexer lexer("=>");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokenPtr->type.syntaxToken, SyntaxToken::CALLBACK);
    EXPECT_EQ(tokenPtr->size, 2);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "=>");
    EXPECT_EQ(tokenPtr->plainText, "SyntaxToken::CALLBACK");
    EXPECT_EQ(tokenPtr->desc, "Callback");
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

TEST(LexerTest, IdentifyPotentiationAssignment) {
    Lexer lexer("**=");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::OPERATOR);
    EXPECT_EQ(tokenPtr->type.operatorToken, OperatorToken::POTENTIATION_ASSIGNMENT);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "**=");
    EXPECT_EQ(tokenPtr->plainText, "OperatorToken::POTENTIATION_ASSIGNMENT");
    EXPECT_EQ(tokenPtr->desc, "Potentiation Assignment");
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
 * Short Notation
 */
TEST(LexerTest, IdentifyLength) {
    Lexer lexer("LENGTH");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::LENGTH);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "LENGTH");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::LENGTH");
    EXPECT_EQ(tokenPtr->desc, "Length function");
}

TEST(LexerTest, IdentifyConcat) {
    Lexer lexer("CONCAT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::CONCAT);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "CONCAT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::CONCAT");
    EXPECT_EQ(tokenPtr->desc, "Concat function");
}

TEST(LexerTest, IdentifyIncludes) {
    Lexer lexer("INCLUDES");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::INCLUDES);
    EXPECT_EQ(tokenPtr->size, 8);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "INCLUDES");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::INCLUDES");
    EXPECT_EQ(tokenPtr->desc, "Includes function");
}

TEST(LexerTest, IdentifyIndexOf) {
    Lexer lexer("INDEX_OF");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::INDEX_OF);
    EXPECT_EQ(tokenPtr->size, 8);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "INDEX_OF");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::INDEX_OF");
    EXPECT_EQ(tokenPtr->desc, "Index of function");
}

TEST(LexerTest, IdentifyLastIndexOf) {
    Lexer lexer("LAST_INDEX_OF");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::LAST_INDEX_OF);
    EXPECT_EQ(tokenPtr->size, 13);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "LAST_INDEX_OF");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::LAST_INDEX_OF");
    EXPECT_EQ(tokenPtr->desc, "Last index of function");
}

TEST(LexerTest, IdentifySlice) {
    Lexer lexer("SLICE");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::SLICE);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "SLICE");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::SLICE");
    EXPECT_EQ(tokenPtr->desc, "Slice function");
}

TEST(LexerTest, IdentifyPush) {
    Lexer lexer("PUSH");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::PUSH);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "PUSH");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::PUSH");
    EXPECT_EQ(tokenPtr->desc, "Push function");
}

TEST(LexerTest, IdentifyPop) {
    Lexer lexer("POP");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::POP);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "POP");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::POP");
    EXPECT_EQ(tokenPtr->desc, "Pop function");
}

TEST(LexerTest, IdentifyShift) {
    Lexer lexer("SHIFT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::SHIFT);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "SHIFT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::SHIFT");
    EXPECT_EQ(tokenPtr->desc, "Shift function");
}

TEST(LexerTest, IdentifyUnshift) {
    Lexer lexer("UNSHIFT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::UNSHIFT);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "UNSHIFT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::UNSHIFT");
    EXPECT_EQ(tokenPtr->desc, "Unshift function");
}

TEST(LexerTest, IdentifySplice) {
    Lexer lexer("SPLICE");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::SPLICE);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "SPLICE");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::SPLICE");
    EXPECT_EQ(tokenPtr->desc, "Splice function");
}

TEST(LexerTest, IdentifyReverse) {
    Lexer lexer("REVERSE");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::REVERSE);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "REVERSE");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::REVERSE");
    EXPECT_EQ(tokenPtr->desc, "Reverse function");
}

TEST(LexerTest, IdentifySort) {
    Lexer lexer("SORT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::SORT);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "SORT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::SORT");
    EXPECT_EQ(tokenPtr->desc, "Sort function");
}

TEST(LexerTest, IdentifyFill) {
    Lexer lexer("FILL");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FILL);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FILL");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FILL");
    EXPECT_EQ(tokenPtr->desc, "Fill function");
}

TEST(LexerTest, IdentifyJoin) {
    Lexer lexer("JOIN");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::JOIN);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "JOIN");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::JOIN");
    EXPECT_EQ(tokenPtr->desc, "Join function");
}

TEST(LexerTest, IdentifyCount) {
    Lexer lexer("COUNT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::COUNT);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "COUNT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::COUNT");
    EXPECT_EQ(tokenPtr->desc, "Count function");
}

TEST(LexerTest, IdentifyEvery) {
    Lexer lexer("EVERY");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::EVERY);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "EVERY");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::EVERY");
    EXPECT_EQ(tokenPtr->desc, "Every function");
}

TEST(LexerTest, IdentifySome) {
    Lexer lexer("SOME");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::SOME);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "SOME");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::SOME");
    EXPECT_EQ(tokenPtr->desc, "Some function");
}

TEST(LexerTest, IdentifyFind) {
    Lexer lexer("FIND");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FIND);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FIND");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FIND");
    EXPECT_EQ(tokenPtr->desc, "Find function");
}

TEST(LexerTest, IdentifyFindIndex) {
    Lexer lexer("FIND_INDEX");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FIND_INDEX);
    EXPECT_EQ(tokenPtr->size, 10);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FIND_INDEX");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FIND_INDEX");
    EXPECT_EQ(tokenPtr->desc, "Find index function");
}

TEST(LexerTest, IdentifyFindLast) {
    Lexer lexer("FIND_LAST");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FIND_LAST);
    EXPECT_EQ(tokenPtr->size, 9);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FIND_LAST");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FIND_LAST");
    EXPECT_EQ(tokenPtr->desc, "Find last function");
}

TEST(LexerTest, IdentifyFindLastIndex) {
    Lexer lexer("FIND_LAST_INDEX");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FIND_LAST_INDEX);
    EXPECT_EQ(tokenPtr->size, 15);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FIND_LAST_INDEX");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FIND_LAST_INDEX");
    EXPECT_EQ(tokenPtr->desc, "Find last index function");
}

TEST(LexerTest, IdentifyFilter) {
    Lexer lexer("FILTER");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FILTER);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FILTER");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FILTER");
    EXPECT_EQ(tokenPtr->desc, "Filter function");
}

TEST(LexerTest, IdentifyMap) {
    Lexer lexer("MAP");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::MAP);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "MAP");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::MAP");
    EXPECT_EQ(tokenPtr->desc, "Map function");
}

TEST(LexerTest, IdentifyReduce) {
    Lexer lexer("REDUCE");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::REDUCE);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "REDUCE");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::REDUCE");
    EXPECT_EQ(tokenPtr->desc, "Reduce function");
}

TEST(LexerTest, IdentifyFlat) {
    Lexer lexer("FLAT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FLAT);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FLAT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FLAT");
    EXPECT_EQ(tokenPtr->desc, "Flat function");
}

TEST(LexerTest, IdentifyFlatMap) {
    Lexer lexer("FLAT_MAP");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FLAT_MAP);
    EXPECT_EQ(tokenPtr->size, 8);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FLAT_MAP");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FLAT_MAP");
    EXPECT_EQ(tokenPtr->desc, "Flat map function");
}

TEST(LexerTest, IdentifyForEach) {
    Lexer lexer("FOR_EACH");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::FOR_EACH);
    EXPECT_EQ(tokenPtr->size, 8);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "FOR_EACH");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::FOR_EACH");
    EXPECT_EQ(tokenPtr->desc, "For each function");
}

TEST(LexerTest, IdentifyHasKey) {
    Lexer lexer("HAS_KEY");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::HAS_KEY);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "HAS_KEY");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::HAS_KEY");
    EXPECT_EQ(tokenPtr->desc, "Has key function");
}

TEST(LexerTest, IdentifyKeys) {
    Lexer lexer("KEYS");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::KEYS);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "KEYS");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::KEYS");
    EXPECT_EQ(tokenPtr->desc, "Keys function");
}

TEST(LexerTest, IdentifyValues) {
    Lexer lexer("VALUES");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::VALUES);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "VALUES");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::VALUES");
    EXPECT_EQ(tokenPtr->desc, "Values function");
}

TEST(LexerTest, IdentifyEntries) {
    Lexer lexer("ENTRIES");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::ENTRIES);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "ENTRIES");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::ENTRIES");
    EXPECT_EQ(tokenPtr->desc, "Entries function");
}

TEST(LexerTest, IdentifyGET) {
    Lexer lexer("GET");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::GET);
    EXPECT_EQ(tokenPtr->size, 3);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "GET");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::GET");
    EXPECT_EQ(tokenPtr->desc, "Get function");
}

TEST(LexerTest, IdentifyCharAt) {
    Lexer lexer("CHAR_AT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::CHAR_AT);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "CHAR_AT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::CHAR_AT");
    EXPECT_EQ(tokenPtr->desc, "Char at function");
}

TEST(LexerTest, IdentifyCharCodeAt) {
    Lexer lexer("CHAR_CODE_AT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::CHAR_CODE_AT);
    EXPECT_EQ(tokenPtr->size, 12);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "CHAR_CODE_AT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::CHAR_CODE_AT");
    EXPECT_EQ(tokenPtr->desc, "Char code at function");
}

TEST(LexerTest, IdentifyMatch) {
    Lexer lexer("MATCH");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::MATCH);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "MATCH");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::MATCH");
    EXPECT_EQ(tokenPtr->desc, "Match function");
}

TEST(LexerTest, IdentifyMatchAll) {
    Lexer lexer("MATCH_ALL");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::MATCH_ALL);
    EXPECT_EQ(tokenPtr->size, 9);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "MATCH_ALL");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::MATCH_ALL");
    EXPECT_EQ(tokenPtr->desc, "Match all function");
}

TEST(LexerTest, IdentifyPadEnd) {
    Lexer lexer("PAD_END");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::PAD_END);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "PAD_END");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::PAD_END");
    EXPECT_EQ(tokenPtr->desc, "Pad end function");
}

TEST(LexerTest, IdentifyPadStart) {
    Lexer lexer("PAD_START");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::PAD_START);
    EXPECT_EQ(tokenPtr->size, 9);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "PAD_START");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::PAD_START");
    EXPECT_EQ(tokenPtr->desc, "Pad start function");
}

TEST(LexerTest, IdentifyRepeat) {
    Lexer lexer("REPEAT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::REPEAT);
    EXPECT_EQ(tokenPtr->size, 6);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "REPEAT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::REPEAT");
    EXPECT_EQ(tokenPtr->desc, "Repeat function");
}

TEST(LexerTest, IdentifyReplace) {
    Lexer lexer("REPLACE");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::REPLACE);
    EXPECT_EQ(tokenPtr->size, 7);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "REPLACE");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::REPLACE");
    EXPECT_EQ(tokenPtr->desc, "Replace function");
}

TEST(LexerTest, IdentifyReplaceAll) {
    Lexer lexer("REPLACE_ALL");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::REPLACE_ALL);
    EXPECT_EQ(tokenPtr->size, 11);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "REPLACE_ALL");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::REPLACE_ALL");
    EXPECT_EQ(tokenPtr->desc, "Replace all function");
}

TEST(LexerTest, IdentifySplit) {
    Lexer lexer("SPLIT");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::SPLIT);
    EXPECT_EQ(tokenPtr->size, 5);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "SPLIT");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::SPLIT");
    EXPECT_EQ(tokenPtr->desc, "Split function");
}

TEST(LexerTest, IdentifyStartsWith) {
    Lexer lexer("STARTS_WITH");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::STARTS_WITH);
    EXPECT_EQ(tokenPtr->size, 11);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "STARTS_WITH");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::STARTS_WITH");
    EXPECT_EQ(tokenPtr->desc, "Starts with function");
}

TEST(LexerTest, IdentifyEndsWith) {
    Lexer lexer("ENDS_WITH");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::ENDS_WITH);
    EXPECT_EQ(tokenPtr->size, 9);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "ENDS_WITH");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::ENDS_WITH");
    EXPECT_EQ(tokenPtr->desc, "Ends with function");
}

TEST(LexerTest, IdentifySubstring) {
    Lexer lexer("SUBSTRING");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::SUBSTRING);
    EXPECT_EQ(tokenPtr->size, 9);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "SUBSTRING");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::SUBSTRING");
    EXPECT_EQ(tokenPtr->desc, "Substring function");
}

TEST(LexerTest, IdentifyLowercase) {
    Lexer lexer("LOWERCASE");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::LOWERCASE);
    EXPECT_EQ(tokenPtr->size, 9);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "LOWERCASE");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::LOWERCASE");
    EXPECT_EQ(tokenPtr->desc, "Lowercase function");
}

TEST(LexerTest, IdentifyUppercase) {
    Lexer lexer("UPPERCASE");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::UPPERCASE);
    EXPECT_EQ(tokenPtr->size, 9);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "UPPERCASE");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::UPPERCASE");
    EXPECT_EQ(tokenPtr->desc, "Uppercase function");
}

TEST(LexerTest, IdentifyTrim) {
    Lexer lexer("TRIM");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::TRIM);
    EXPECT_EQ(tokenPtr->size, 4);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "TRIM");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::TRIM");
    EXPECT_EQ(tokenPtr->desc, "Trim function");
}

TEST(LexerTest, IdentifyTrimEnd) {
    Lexer lexer("TRIM_END");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::TRIM_END);
    EXPECT_EQ(tokenPtr->size, 8);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "TRIM_END");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::TRIM_END");
    EXPECT_EQ(tokenPtr->desc, "Trim end function");
}

TEST(LexerTest, IdentifyTrimStart) {
    Lexer lexer("TRIM_START");
    std::unique_ptr<Token> tokenPtr;
    lexer.getNextToken(tokenPtr);

    EXPECT_EQ(tokenPtr->tag, Token::TypeTag::SHORT_NOTATION);
    EXPECT_EQ(tokenPtr->type.shortNotationToken, ShortNotationToken::TRIM_START);
    EXPECT_EQ(tokenPtr->size, 10);
    EXPECT_EQ(tokenPtr->pos, 0);
    EXPECT_EQ(tokenPtr->value, "TRIM_START");
    EXPECT_EQ(tokenPtr->plainText, "ShortNotationToken::TRIM_START");
    EXPECT_EQ(tokenPtr->desc, "Trim start function");
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

TEST(LexerTest, IdentifyBooleanLiteral) {
    Lexer lexer("true");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[1].type.dataToken, DataToken::BOOLEAN_LITERAL);
    EXPECT_EQ(tokens[1].size, 4);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "true");
    EXPECT_EQ(tokens[1].plainText, "DataToken::BOOLEAN_LITERAL");
    EXPECT_EQ(tokens[1].desc, "Boolean Literal");
}

TEST(LexerTest, IdentifyNullLiteral) {
    Lexer lexer("null");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[1].type.dataToken, DataToken::NULL_LITERAL);
    EXPECT_EQ(tokens[1].size, 4);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "null");
    EXPECT_EQ(tokens[1].plainText, "DataToken::NULL_LITERAL");
    EXPECT_EQ(tokens[1].desc, "Null Literal");
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

TEST(LexerTest, IdentifyCharLiteral) {
    Lexer lexer("'A'");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[1].type.syntaxToken, SyntaxToken::SINGLE_QUOTE);
    EXPECT_EQ(tokens[1].size, 1);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "'");
    EXPECT_EQ(tokens[1].plainText, "SyntaxToken::SINGLE_QUOTE");
    EXPECT_EQ(tokens[1].desc, "Single Quote");

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::CHAR_LITERAL);
    EXPECT_EQ(tokens[2].size, 1);
    EXPECT_EQ(tokens[2].pos, 1);
    EXPECT_EQ(tokens[2].value, "A");
    EXPECT_EQ(tokens[2].plainText, "DataToken::CHAR_LITERAL");
    EXPECT_EQ(tokens[2].desc, "Character Literal");

    EXPECT_EQ(tokens[3].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[3].type.syntaxToken, SyntaxToken::SINGLE_QUOTE);
    EXPECT_EQ(tokens[3].size, 1);
    EXPECT_EQ(tokens[3].pos, 2);
    EXPECT_EQ(tokens[3].value, "'");
    EXPECT_EQ(tokens[3].plainText, "SyntaxToken::SINGLE_QUOTE");
    EXPECT_EQ(tokens[3].desc, "Single Quote");
}

TEST(LexerTest, IdentifyHexCodeLiteral) {
    Lexer lexer("#ffffff");
    std::vector<Token> tokens = lexer.tokenize(false);

    EXPECT_EQ(tokens[1].tag, Token::TypeTag::SYNTAX);
    EXPECT_EQ(tokens[1].type.syntaxToken, SyntaxToken::HASHTAG);
    EXPECT_EQ(tokens[1].size, 1);
    EXPECT_EQ(tokens[1].pos, 0);
    EXPECT_EQ(tokens[1].value, "#");
    EXPECT_EQ(tokens[1].plainText, "SyntaxToken::HASHTAG");
    EXPECT_EQ(tokens[1].desc, "Hashtag");

    EXPECT_EQ(tokens[2].tag, Token::TypeTag::DATA);
    EXPECT_EQ(tokens[2].type.dataToken, DataToken::HEX_CODE_LITERAL);
    EXPECT_EQ(tokens[2].size, 6);
    EXPECT_EQ(tokens[2].pos, 1);
    EXPECT_EQ(tokens[2].value, "ffffff");
    EXPECT_EQ(tokens[2].plainText, "DataToken::HEX_CODE_LITERAL");
    EXPECT_EQ(tokens[2].desc, "Hex Code Literal");
}