#include <iostream>
#include <compare>

int main(void)
{
  int x = 50;
  int y = 10;

  // std::strong_ordering __res(x <=> y);
  // std::weak_ordering __res(x <=> y);
  // std::partial_ordering __res(x <=> y);
  const auto __res(x <=> y);

  

  if (__res > 0)
    std::cout << "\n\nx > y\n\n";
  else if (__res < 0)
    std::cout << "\n\nx < y\n\n";
  else if (__res == 0)
    std::cout << "\n\nx == y\n\n";
  else
    std::cout << "\n\nUnordered\n\n";

  return 0;
}