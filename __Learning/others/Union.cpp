#include <iostream>

struct stDate
{
  union
  {
    int a, b;
  };
};


int main()
{
  stDate Date{ 1 };
  std::cout << Date.a << " " << Date.b << std::endl;
  int size = sizeof(Date);
  std::cout << size << std::endl;
}