#include <iostream>
#include <string>

//=====================================================

// 2 ^ 0 ===> 2 ^ 31
const uint32_t _2S[] {
  1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384,
  32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608,
  16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824,
  2147483648
};

// count leading zeros
uint8_t clz32(const uint32_t n) {
  if (!n) return 32;
  uint8_t count = 0;
  for (uint8_t i = std::size(_2S) - 1; i >= 0; --i, ++count) {
    if (n & _2S[i]) break;
  }
  return count;
}

// count trailing zeros
uint8_t ctz32(uint32_t n) {
  if (!n) return 32; // skipping this step would make it return -1
  n &= -n; // equivalent to `int = int & (~int + 1)`
  return 31 - clz32(n);
}

// count leading ones
uint8_t clo32(const uint32_t n) { return clz32(~n); }

int main(void) {
  const uint32_t n = 2147483648; // 2 ^ 31

  printf("- leading zeros  => %u\n", clz32(n));
  printf("- trailing zeros => %u\n", ctz32(n));
  printf("- leading ones   => %u\n", clo32(n));

  return 0;
}