#ifndef DAY1_HPP
#define DAY1_HPP

#include "common.hpp"
#include "day.hpp"

#include <bits/stdc++.h>
#include <sstream>

class Day1 final : public IDay<int, int> {
  std::vector<int> list1;
  std::vector<int> list2;
public:
  explicit Day1(const char* inputFile) {
    FileHandler handler(inputFile);

    for (auto& l : handler.GetVector()) {
      int n1, n2;

      std::istringstream iss(l);

      iss >> n1 >> n2;

      list1.push_back(n1);
      list2.push_back(n2);
    }

    std::ranges::sort(list1);
    std::ranges::sort(list2);
  }

  int partOne() override {
    int n = 0;
    for (int i = 0; i < list1.size(); i++) {
      int n1 = list1.at(i), n2 = list2.at(i);

      n += std::abs(n2 - n1);
    }

    return n;
  }
  int partTwo() override {
    std::set<int> s;
    std::map<int, int> occurrences;
    for (auto i : list1) {
      if (!s.contains(i)) {
        s.insert(i);
      }
      occurrences[i] += 1;
    }

    int score = 0;
    for (auto i : list2) {
      if (s.contains(i)) {
        score += i * occurrences[i];
      }
    }

    return score;
  }
};

#endif //DAY1_HPP
