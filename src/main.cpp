#include "Tokenizer.h"

#include <cstdio>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string_view>
#include <optional>
#include <vector>
#include <print>

std::optional<std::string> getFileContents(std::string_view filePathString)
{
  std::filesystem::path filePath{filePathString};

  // Check if the file exists
  if (!std::filesystem::exists(filePath)) 
  {
    std::println(stderr, "File does not exist: {}", filePath.string()); 
    return std::nullopt;
  }

  // Open the file
  std::ifstream file(filePath);
  if (!file) 
  {
    std::println(stderr, "Failed to open file: {}", filePath.string()); 
    return std::nullopt;
  }

  // Read the contents of the file
  std::string line;
  std::stringstream ss;
  while (std::getline(file, line)) 
  {
    ss << line << '\n';
  }

  return ss.str();
}

int main(int argc, const char* argv[])
{
  if(argc != 2)
  {
    std::println(stderr, "Must give file to compile in command line args");
    return 1;
  }

  if(auto result = getFileContents(argv[1]))
  {
    auto tokens = tokenize(result.value());
    return 0;
  }
  else
  {
    return 1;
  }
}
