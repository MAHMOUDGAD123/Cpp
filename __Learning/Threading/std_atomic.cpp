#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic>

using namespace std::literals::chrono_literals;
const std::chrono::milliseconds t(500);

static std::atomic<int> a_val(0); // to prevent data racing
static int val(0);

void increment_val(int n)
{
  while (n > 0)
    ++a_val, ++val, --n;
}

int main(void)
{
  int n(1000000);
  std::vector<std::thread> threads;

  std::cout << "\nStart threading.......\n";

  std::thread t1(increment_val, n);
  std::thread t2(increment_val, n);
  t1.join();
  t2.join();

  std::cout << "\nEnd threading.......\n\n";

  std::cout << "-------> a_val = " << a_val;
  std::cout << "\n-------> val   = " << val;

  std::cout << "\n\nDone......\n\n";

  return 0;
}
