#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

using namespace std::literals::chrono_literals;
const std::chrono::milliseconds t(500);

static long long shared_val(0);
std::mutex __mLock;

void increment_val()
{
  // lock_guard lock() & unlock() automatically
  const std::lock_guard<std::mutex> lg(__mLock);

  ++shared_val; // only one thread can access this code

  std::cout << "\nthread id. "
            << std::this_thread::get_id()
            << " => (val = "
            << shared_val
            << ")"
            << std::endl;
}

int main(void)
{
  short n(100);
  std::vector<std::thread> threads;

  std::cout << "\nStart threading.......\n";

  for (short i(1); i <= n; ++i)
    threads.emplace_back(std::thread(increment_val));

  for (std::thread &t : threads)
    t.join();

  std::cout << "\nEnd threading.......\n\n";

  std::cout << "-------> Val = " << shared_val;

  std::cout << "\n\nDone......\n\n";

  return 0;
}
