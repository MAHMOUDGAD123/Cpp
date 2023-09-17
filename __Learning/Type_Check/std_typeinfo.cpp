#include <iostream>
#include <typeinfo>

struct MG
{
};

int main(void)
{
  int i = 10;
  float f = 10.f;
  std::string s;
  MG m;

  std::cout << typeid(i).name() << std::endl;
  std::cout << typeid(f).name() << std::endl;
  std::cout << typeid(s).name() << std::endl;
  std::cout << typeid(m).name() << std::endl;

  return 0;
}
