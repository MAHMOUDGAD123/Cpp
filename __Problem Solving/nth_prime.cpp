#include <iostream>

constexpr bool isPrime(size_t n) {
  for (size_t i = 2; i <= n >> 1; ++i) if (!(n % i)) return false;
  return true;
}

constexpr size_t nthPrime(int nth) {
  size_t prime(0);
  for (size_t n = 2; nth >= 0; ++n) if (isPrime(n)) prime = n, --nth;
  return prime;
}


int main(void)
{
  std::cout << "\n\n";

  std::cout << nthPrime(20) << std::endl;

  std::cout << "\n\n\n";
}