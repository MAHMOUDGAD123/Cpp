#include <iostream>
#include <ctime>
#include <cmath>

// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
// https://www.youtube.com/watch?v=PPup1yeU45I&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=85&ab_channel=TheCherno

// singleton class
class Random
{
private:
  static uint32_t _Next;
  static constexpr int Rand_Max = 32767;

public:
  // disable default/copy/move constructors
  // no one can create an instance
  Random() = delete;
  Random(const Random &) = delete;
  Random(Random &&) = delete;
  // disable copy/move assignment operators
  Random &operator=(const Random &) = delete;
  Random &operator=(Random &&) = delete;

  // initiate the _Next member
  static void srand(uint32_t seed)
  {
    _Next = seed;
  }

  // generate random integer number
  static uint32_t irand(void)
  {
    // Rand_Max = 32767
    _Next = _Next * 123456789 + 12345;
    return (_Next / 65536) % (Rand_Max + 1);
  }

  // generate random double number
  static double frand(void)
  {
    // Rand_Max = 32767
    _Next = _Next * 123456789 + 12345;
    return std::fmod(_Next / 12345.6789, (Rand_Max + 1));
  }

  // generate random integer number (from -> to)
  static int32_t rrand(int32_t from, int32_t to)
  {
    return irand() % (to - from + 1) + from;
  }

  // generate random double number (from -> to)
  static double frand(double from, double to)
  {
    return from + (frand() / (double)Rand_Max) * (to - from);
  }
};
// initialize the Random static member
uint32_t Random::_Next(1);

int main()
{
  Random::srand((unsigned)std::time(nullptr));

  std::cout << "\n\n\n";

  for (size_t i(0); i < 10; i++)
    std::cout << " " << Random::irand();

  std::cout << "\n";

  for (size_t i(0); i < 10; i++)
    std::cout << " " << Random::frand();

  std::cout << "\n\n\n";

  for (size_t i(0); i < 10; i++)
    std::cout << " " << Random::rrand(0.5, 2);

  std::cout << "\n\n";

  for (size_t i(0); i < 10; i++)
    std::cout << " " << Random::frand(0.5, 2);

  std::cout << "\n\n\n";
}