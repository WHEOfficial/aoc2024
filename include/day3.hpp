#ifndef DAY3_HPP
#define DAY3_HPP

#include "common.hpp"
#include "day.hpp"

#include <string>
#include <regex>

class Day3 final : public IDay<int, int> {
  const std::string TURN_ON = "do()";
  const std::string TURN_OFF = "don't()";

  std::vector<std::string> instructions;
public:
  explicit Day3(const char* inputFile) {
    FileHandler handler(inputFile);

    instructions = handler.GetVector();
  }

  int partOne() override {
    const std::regex pattern(R"(mul\((\d+),(\d+)\))");
    int sum = 0;

    for (const auto& l : instructions) {
      std::smatch match;

      auto searchStart(l.begin());

      while (std::regex_search(searchStart, l.cend(), match, pattern)) {
        const int n1 = std::stoi(match[1]);
        const int n2 = std::stoi(match[2]);

        sum += n1 * n2;

        searchStart = match.suffix().first;
      }
    }

    return sum;
  }

  int partTwo() override {
    const std::regex pattern(R"(mul\((\d+),(\d+)\)|(do\(\))|(don't\(\)))");
    int sum = 0;
    bool multiply = true;

    for (const auto& l : instructions) {
      std::smatch match;

      auto searchStart(l.begin());

      while (std::regex_search(searchStart, l.cend(), match, pattern)) {
        std::string matchType = match[0];

        if (match[0] == TURN_ON) {
          multiply = true;
        } else if (match[0] == TURN_OFF) {
          multiply = false;
        } else if (multiply) {
          const int n1 = std::stoi(match[1]);
          const int n2 = std::stoi(match[2]);

          sum += n1 * n2;
        }

        searchStart = match.suffix().first;
      }
    }

    return sum;
  }
};

#endif //DAY3_HPP
