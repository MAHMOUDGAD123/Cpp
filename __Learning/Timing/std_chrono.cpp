#include <iostream>
#include <chrono>
#include <thread>

#define MILLISECONDS 0

struct timer
{
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  std::chrono::duration<float> duration;
  std::string_view __msg;

  timer(const char *msg) noexcept
  {
    start = std::chrono::high_resolution_clock::now();
    __msg = msg;
  }

  ~timer()
  {
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);

#if MILLISECONDS
    std::cout << "\n\n"
              << __msg << " Took => " << (duration.count() * 1000.f) << " ms\n\n"; // in millisecends
#else
    std::cout << "\n"
              << __msg << " Took => " << duration << " s\n\n"; // in seconds
#endif
  }
};

//================================== TEST =====================================

constexpr const size_t __n(1000000000ull);
constexpr const size_t __x(9874652318676572134ull);

void test1()
{
  timer t("Div");
  double _res(1);

  for (size_t i(0); i < __n; ++i)
    _res = __x / 1000;
}

void test2()
{
  timer t("mul");
  double _res(1);

  for (size_t i(0); i < __n; ++i)
    _res = __x * 0.001;
}

//=============================================================================

int main(void)
{
  test1();
  test2();

  return 0;
}
