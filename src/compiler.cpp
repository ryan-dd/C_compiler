#include "compiler.h"

#include <cctype>
#include <sstream>
#include <optional>
#include <unordered_map>
#include <vector>
#include <string_view>

void skipWhitespace(File& file) {
  while (std::isspace(file.currentChar())) {
      file.advance();
  }
}

static const std::unordered_map<std::string, TokenType> keywords{
  {"int", TokenType::Int},
  {"return", TokenType::Return}
};

std::optional<TokenType> isKeyword(const std::string& identifierString)
{
  auto it = keywords.find(identifierString);
  if(it == keywords.end())
  {
    return std::nullopt;
  }

  return it->second;
}

Token getKeywordOrIdentifier(File& file)
{
  std::stringstream value{};
  int lineNumber = file.getLine();
  int columnNumber = file.getColumn();

  char c = file.currentChar();
  while(std::isalnum(c) || c == '_')
  {
    value << c;
    file.advance();
    c = file.currentChar();
  }

  // Assume it is an identifier unless the value matches a keyword
  Token token{
    .type = TokenType::Identifier,
    .value = value.str(),
    .line = lineNumber,
    .column = columnNumber
  };

  if(auto keywordTokenType = isKeyword(token.value))
  {
    token.type = keywordTokenType.value();
  }

  return token;
}

std::optional<TokenType> isPunctuation(char c)
{
  switch (c)
  {
    case '{': return TokenType::LeftBrace;
    case '}': return TokenType::RightBrace;
    case '(': return TokenType::LeftParen;
    case ')': return TokenType::RightParen;
    case ';': return TokenType::Semicolon;
    case '[': return TokenType::LeftBracket;
    case ']': return TokenType::RightBracket;
  }

  return std::nullopt;
}

std::vector<Token> tokenize(const std::string& input)
{
  File file(input);
  std::vector<Token> tokens;

  while(true)
  {
    skipWhitespace(file);
    char c = file.currentChar();

    if(c == '\0') return tokens;

    if (isalpha(c) || c == '_') 
    {
      tokens.push_back(getKeywordOrIdentifier(file));
    }

    if (auto punctuation = isPunctuation(c))
    {
      tokens.push_back(
        Token{
          .type = punctuation.value(),
          .value = std::to_string(c),
          .line = file.getLine(),
          .column = file.getColumn()
        }
      );
    }
  }

  return tokens;
}


