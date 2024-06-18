#include "Tokenizer.h"

#include <gtest/gtest.h>

TEST(TokenizerTest, MainFile)
{
  std::string input = R"(
        int main() {
            return 0;
        }
    )";

  std::vector<Token> expectedTokens = {
    {TokenType::Int, "int", 1, 9},
    {TokenType::Identifier, "main", 1, 13},
    {TokenType::LeftParen, "(", 1, 17},
    {TokenType::RightParen, ")", 1, 18},
    {TokenType::LeftBrace, "{", 1, 20},
    {TokenType::Return, "return", 2, 13},
    {TokenType::IntegerLiteral, "0", 2, 20},
    {TokenType::Semicolon, ";", 2, 21},
    {TokenType::RightBrace, "}", 3, 9}
  };

  std::vector<Token> tokens = tokenize(input);

  // Test members individually for better error messages
  for (std::size_t i = 0; i < tokens.size(); ++i) 
  {
    ASSERT_EQ(tokens[i].value, expectedTokens[i].value);
    ASSERT_EQ(tokens[i].type, expectedTokens[i].type);
    ASSERT_EQ(tokens[i].column, expectedTokens[i].column);
    ASSERT_EQ(tokens[i].line, expectedTokens[i].line);
  }
}
