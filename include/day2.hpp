#ifndef DAY2_HPP
#define DAY2_HPP

#include "common.hpp"
#include "day.hpp"

#include <sstream>

class Day2 final : public IDay<int, int> {
  static constexpr int SAFE_LIMIT = 3;
  std::vector<std::vector<int>> levels;
public:
  explicit Day2(const char* inputFile) {
    FileHandler handler(inputFile);

    auto lines = handler.GetVector();

    for (auto& l : lines) {
      std::istringstream iss(l);
      std::vector<int> level;

      int n;
      while (iss >> n) {
        level.push_back(n);
      }

      levels.push_back(level);
    }
  }

  int partOne() override {
    int safeLevels = 0;

    for (const auto& level : levels) {
      int first = level[0], second = level[1];

      if (first != second && std::abs(second - first) <= SAFE_LIMIT) {
        const bool isAscending = first < second;
        bool failed = false;

        for (int i = 2; i < level.size(); i++) {
          int previous = level[i - 1], current = level[i];

          if ((previous <= current && !isAscending) || (previous >= current && isAscending) ||
              std::abs(previous - current) > SAFE_LIMIT) {
            failed = true;
            break;
          }
        }

        safeLevels += !failed;
      }
    }

    return safeLevels;
  }

  int partTwo() override {
    int safeLevels = 0;

    for (auto& level : levels) {
      for (int i = 0; i < level.size(); i++) {
        int n = level.at(i);
        level.erase(level.begin() + i);

        int first = level[0], second = level[1];

        if (first != second && std::abs(second - first) <= SAFE_LIMIT) {
          const bool isAscending = first < second;
          bool failed = false;

          for (int j = 2; j < level.size(); j++) {
            int previous = level[j - 1], current = level[j];

            if ((previous <= current && !isAscending) || (previous >= current && isAscending) ||
                std::abs(previous - current) > SAFE_LIMIT) {
              failed = true;
              break;
            }
          }

          if (!failed) {
            safeLevels++;
            break;
          }

          level.insert(level.begin() + i, n);
        } else {
          level.insert(level.begin() + i, n);
        }
      }
    }

    return safeLevels;
  }
};

#endif //DAY2_HPP
