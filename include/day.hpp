#ifndef DAY_HPP
#define DAY_HPP

template <typename T1, typename T2>
class IDay {
public:
  virtual ~IDay() = default;
  virtual T1 partOne() = 0;
  virtual T2 partTwo() = 0;
};

#endif //DAY_HPP
