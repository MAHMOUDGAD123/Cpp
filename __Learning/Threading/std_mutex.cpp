#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

using namespace std::literals::chrono_literals;
const std::chrono::milliseconds t(500);

static long long val(0);
std::mutex __mLock;

void increment_val()
{
  __mLock.lock(); /* lock the code */

  ++val; // only one thread can access this code
  std::cout << "\nthread id. "
            << std::this_thread::get_id()
            << " => (val = "
            << val
            << ")"
            << std::endl;

  __mLock.unlock(); /* unlock the code */
  
  std::this_thread::sleep_for(t);
}

int main(void)
{
  short n(100);
  std::vector<std::thread> threads;

  std::cout << "\nStart threading.......\n";

  for (short i(1); i <= n; ++i)
    threads.push_back(std::thread(increment_val));

  for (std::thread &t : threads)
    t.join();

  std::cout << "\nEnd threading.......\n\n";

  std::cout << "-------> Val = " << val;

  std::cout << "\n\nDone......\n\n";

  return 0;
}
