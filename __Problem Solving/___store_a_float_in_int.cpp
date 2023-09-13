#include <iostream>

static constexpr inline long __steal_a_float(float &F) noexcept
{
  return *(long *)&F; // steal the address
}
static constexpr inline float __steal_a_long(long &I) noexcept
{
  return *(float *)&I; // steal the address
}

int main(void)
{
  long N(10);
  float F(5.5f);

  N = __steal_a_float(F); // steal the value
  std::cout << "-> N = " << N << "L (address if `F` as a value)\n";

  F = __steal_a_long(N); // ge the value back
  std::cout << "-> F = " << F << "F ()\n\n";

  return 0;
}