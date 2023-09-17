#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

size_t __n(1ull);

size_t __shiftl(uint8_t t)
{
  std::cout << "\nStart working...\n";

  for (uint8_t i(0); i < t; ++i)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    printf("\n-->  __n = %llu\n", (__n <<= 1));
  }

  return __n;
}

int main(void)
{
  const uint8_t __shift_t(10u);
  const size_t __res(__n << __shift_t);

  printf("\n--> (init) __n = %llu\n", __n);

  std::future<size_t> _async_fun(std::async(std::launch::async, &__shiftl, __shift_t));

  while (__n != __res)
  {
    std::cout << "\nWaiting.......\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
  }

  std::cout << "\nJob...Done\n";

  printf("\n-----> Final result = %llu\n\n", _async_fun.get());

  return 0;
}
