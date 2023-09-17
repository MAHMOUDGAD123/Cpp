#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;

void fun(const int tn)
{
  printf("\n(norm_fun)thread no. %d\n", tn);
  // printf("\nthread id. %d\n", std::this_thread::get_id());
  // std::cout << "thread id. " << std::this_thread::get_id() << '\n';
  // std::this_thread::sleep_for(std::literals::chrono_literals::operator""s(1));
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

struct fun_class
{
  void fun(const int tn) const
  {
    printf("\n(cls_fun)thread no. %d\n", tn);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  static void s_fun(const int tn)
  {
    printf("\n(cls_s_fun)thread no. %d\n", tn);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
};

struct fun_obj
{
  void operator()(const int tn) const
  {
    printf("\n(fun_obj)thread no. %d\n", tn);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
};

int main(void)
{
  short n(10);
  std::vector<std::thread> threads;

  fun_class fc;

  std::cout << "\nStart threading.......\n";

  for (short i(1); i <= n; ++i)
    threads.push_back(std::thread(fun_obj{}, i));

  for (std::thread &t : threads)
    t.join();

  std::cout << "\nEnd threading.......\n\n";

  std::cout << "--------------------------------\n\n";

  std::cout << "Start Sequential.......\n";

  for (short i(1); i <= n; ++i)
    fun_obj{}(i);

  std::cout << "\nEnd Sequential.......\n\n";

  std::cout << "\nDone......\n\n";

  return 0;
}
