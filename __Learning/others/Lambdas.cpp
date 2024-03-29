#include <iostream>
#include <vector>
#include <array>

// https://www.programiz.com/cpp-programming/lambda-expression
// https://en.cppreference.com/w/cpp/language/lambda

template <typename iterator, typename function>
function For_Each(iterator start, iterator end, function fun)
{
  while (start != end)
  {
    fun(*start);
    ++start;
  }
  return std::move(fun);
}


int main()
{
  std::array<int, 10> vNums{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  // Method 1:
  For_Each(vNums.begin(), vNums.end(), [&](int N) -> void { std::cout << ' ' << N; });

  std::cout << "\n\n";

  // Method 2:
  auto lambda1 = [&](int var) -> void { std::cout << ' ' << var; };

  For_Each(vNums.begin(), vNums.end(), lambda1);

  std::cout << "\n\n";

  // Method 3: template lambda
  auto lambda2 = [&]<typename T>(const T & var) -> void { std::cout << ' ' << var; };
  For_Each(vNums.begin(), vNums.end(), lambda2);

}