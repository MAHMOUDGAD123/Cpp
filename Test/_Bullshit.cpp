#include <iostream>
#include <functional>

typedef struct
{
  short age;
  const char *name;
  bool sex;
} Person;

constexpr int sum(int a, int b) { return a + b; }

int main(int argc, char *argv[])
{
  // function class
  // std::function<bool(const int&)> _is_even = [&] (const int& _Num) -> bool { return !(abs(_Num) & 1); };

  /*
   float f(3.3);
   long l1(*(long*)&f);
   long l2(f);
   std::cout << f << "\n";
   std::cout << l1 << "\n"; // look at this it's the number itself
   std::cout << l2 << "\n";
  */

  // array of (pointers) vs (pointer to pointer)
  // char *args[]{(char *)"Mahmoud", (char *)"Gad"};
  // char **argo = args;
  // std::cout << *args << "\n";
  // std::cout << *argo << "\n";
  // std::cout << args[0] << "\n";
  // std::cout << argo[0] << "\n\n";

  // ~ Complement
  // binary number of 64-bit
  std::cout << (int64_t)0b1111111111111111111111111111111111111111111111111111111111111111 << '\n';
  std::cout << ~(~0 >> 1) << '\n';
  std::cout << ~1 << '\n'; // 1's complement
  std::cout << ~1 + 1 << '\n'; // 2's complement
  std::cout << -(~1 + 1) << '\n'; // 

  // function pointer
  // int (*fun_ptr)(int, int){sum};
  // std::cout << fun_ptr(10, 20) << std::endl;

  // pointer to array
  // int arr[3]{1, 2, 3};
  // int(*arr_ptr)[3]{&arr};
  // std::cout << *arr << std::endl;
  // std::cout << **arr_ptr << std::endl;

  return 0;
}