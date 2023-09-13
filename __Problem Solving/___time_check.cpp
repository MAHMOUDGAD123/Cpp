#include <stdio.h>
#include <time.h>
#include <iostream>

template <typename operation>
static constexpr inline float __calc_time(operation _op)
{
  clock_t c;
  int n(10000000);

  c = clock();

  for (; n > 0; --n)
    _op;

  c = clock() - c;

  return (float)c / CLOCKS_PER_SEC;
}

/*===============================TEST===============================*/

/*==================================================================*/

int main()
{
  long n = 151234789;

  short test(1); // {1} -> test_1  || {2} -> test_2

  switch (test)
  {
  case 1: // test_1
    printf("- Division = (%f sec).\n\n", __calc_time([&]() -> void
                                                     { n / 2; }));
    break;

  case 2: // test_2
    printf("- Shifting = (%f sec).\n\n", __calc_time([&]() -> void
                                                     { n >> 1; }));
    break;
  }

  return 0;
}
