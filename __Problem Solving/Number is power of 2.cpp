#include <iostream>

// O(log n)
constexpr bool _is_power_of_2(long long N)
{
  if(N <= 0) return false;
  while(!(N % 2)) N /= 2;
  return N == 1;
}

// constant O(1)
constexpr bool is_power_of_2(long long N)
{
  return (N > 0 && !(N & (N - 1)));
}

int main()
{
  while(true)
  {
    long long N;
    std::cout << "\n\nEnter A Number: ";
    std::cin >> N;
    std::cout << std::boolalpha
              << _is_power_of_2(N)
              << '\n'
              << is_power_of_2(N)
              << '\n' 
              << std::endl;
  }
}