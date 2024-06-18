#include <string>

enum class TokenType 
{
  Identifier,
  Int,
  Void,
  LeftBrace,
  RightBrace,
  LeftParen,
  RightParen,
  LeftBracket,
  RightBracket,
  Semicolon,
  Return,
  IntegerLiteral
};

struct Token
{
  TokenType type;
  std::string value;
  int line;
  int column;
};

class File {
private:
  std::string source{};
  size_t position{};
  int line{};
  int column{};
public:
  explicit File(const std::string& input): source(input){}
  int getLine(){return line;}
  int getColumn(){return column;};
  char currentChar() const {
      return position < source.size() ? source[position] : '\0';
  }

  void advance() {
    if (currentChar() == '\n') {
        ++line;
        column = 0;
    }
    ++position;
    ++column;
  }

};

void skipWhitespace(File& file); 
std::vector<Token> tokenize(const std::string& input);
