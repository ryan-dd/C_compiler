#include "AST_Node.h"
#include "Tokenizer.h"
#include "Parser.h"

#include <cmath>
#include <gtest/gtest.h>

TEST(IntegrationTest, MainFile)
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

  auto program = parse(tokens);
  ASSERT_EQ(program.functions.size(), 1);

  auto& mainFunction = program.functions.at(0);
  ASSERT_EQ(mainFunction.returnType, expectedTokens.at(0));
  ASSERT_EQ(mainFunction.identifier, expectedTokens.at(1));
  ASSERT_EQ(mainFunction.body.size(), 0);
  ASSERT_EQ(mainFunction.parameters.size(), 0);
}
