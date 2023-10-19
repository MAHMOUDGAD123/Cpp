#include <iostream>
#include <stdio.h>

#define XOR_SWAP(a, b) \
  ((a) ^= (b), (b) ^= (a), (a) ^= (b))

#define PLUS_SWAP(a, b) \
  ((a) += (b), (b) = (a) - (b), (a) -= (b))


int main(int argc, char *argv[]) {
  int x(10), y(20);

  printf("x = %d, y = %d\n", x, y);
  // XOR_SWAP(x, y);
  PLUS_SWAP(x, y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}
