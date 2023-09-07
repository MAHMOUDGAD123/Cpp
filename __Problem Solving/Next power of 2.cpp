#include <iostream>
#include <forward_list>

// look here:
// https://stackoverflow.com/questions/1322510/given-an-integer-how-do-i-find-the-next-largest-power-of-two-using-bit-twiddlin/1322548#1322548

// get the next power of 2 of N
// round N to the next power of 2
size_t next_power_of_2(size_t N)
{
  --N;
  N |= (N >> 1);
  N |= (N >> 2);
  N |= (N >> 4);
  N |= (N >> 8);
  N |= (N >> 16);
  return ++N;
}

int main()
{
  std::cout << "\n\n" << next_power_of_2(10000000000) << "\n\n";
  std::cout << (5 + 1) % 5 << "\n\n";
}