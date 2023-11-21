#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

static void __sum_odds_promise(std::promise<size_t>&& odd_sum_promise, size_t from, size_t to) {
  std::cout << "\nStart working...\n";
  size_t _sum(0);
  for (size_t i(0); i <= to; ++i) _sum += i & 1 ? i : 0;
  odd_sum_promise.set_value(_sum); // notify the future
}

static size_t __sum_odds(size_t from, size_t to) {
  std::cout << "\nStart working...\n";
  size_t _sum(0);
  for (size_t i(0); i <= to; ++i) _sum += i & 1 ? i : 0;
  return _sum;
}

int main(void)
{
  size_t from(0ull), to(10000000000ull);

  printf("\n--> get odd numbers sum from %llu to %llu\n", from, to);

  std::promise<size_t> odd_sum_promise;
  std::future<size_t> odd_sum_future(odd_sum_promise.get_future());

  std::cout << "\nStart Threading\n";
  std::thread worker(__sum_odds_promise, std::move(odd_sum_promise), from, to);

  std::cout << "\nWaiting.......\n";

  // future::get() will wait until the future has a valid result and retrieves it.
  // Calling wait() before get() is not needed
  // accumulate_future.wait(); // wait for result
  printf("\n-----> Final result = %llu\n", odd_sum_future.get());
  worker.join(); // wait for thread completion

  std::cout << "\nStart Normal Calculation\n";
  std::cout << "\nWaiting.......\n";
  printf("\n-----> Final result = %llu\n", __sum_odds(from, to));

  std::cout << "\nJob...Done\n\n";

  return 0;
}
