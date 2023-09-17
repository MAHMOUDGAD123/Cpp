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

constexpr const uint32_t __shift(12ul);
constexpr const uint32_t __div(1 << __shift);

void div()
{
  timer t("Div");
  size_t _res(1);

  for (size_t i(0); i < __n; ++i)
    _res = __x / __div;
}

void shift()
{
  timer t("Shift");
  size_t _res(1);

  for (size_t i(0); i < __n; ++i)
    _res = __x >> __shift;
}

//=============================================================================

int main(void)
{
  div();
  shift();

  return 0;
}
