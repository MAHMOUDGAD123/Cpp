#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex __gLock;
std::condition_variable __gCv;
std::string __name;
bool __start_work(false), __work_done(false);

void worker_thread()
{
  std::unique_lock<std::mutex> _lk(__gLock);
  __gCv.wait(_lk, [&]() -> bool
             { return __start_work; }); // wait for a msg from main()

  std::cout << "\nStart working....\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));

  __name += "\"Mahmoud Gad\"";

  std::cout << "\nThe name is completed Work done....\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));

  _lk.unlock();
  __work_done = true;

  std::cout << "\nSend msg to main() (work is done)\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));

  __gCv.notify_one();
}

int main(void)
{
  std::thread worker(worker_thread);
  __name = "My Name Is: ";
  std::cout << "\n-> " << __name << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));

  {
    std::lock_guard _lk(__gLock);
    __start_work = true;
    std::cout << "\nSend msg to worker to start work\n";
  }
  __gCv.notify_one();

  {
    std::unique_lock<std::mutex> _lk(__gLock);
    __gCv.wait(_lk, []() -> bool
               { return __work_done; }); // wait for the msg from worker()
  }

  std::cout << "\nBack to main()\n";

  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::cout << "\n-> " << __name << "\n\n";

  worker.join();

  return 0;
}
