#include <iostream>

int main()
{
  // 2D dynamic array (10 x 10)

  // Method 1 (slow method)

  // allocation
  int** _s2dTable = new int* [10];
  for (uint32_t i(0); i < 10; i++)
    _s2dTable[i] = new int[10];

  // accessing
  for (uint32_t i(0); i < 10; i++)
  {
    for (uint32_t j(0); j < 10; j++)
      std::cout << (_s2dTable[i][j] = 1) << "  ";
    std::cout << std::endl;
  }

  // deallocation
  for (uint32_t i(0); i < 10; i++)
    delete[] _s2dTable[i];
  delete[] _s2dTable;

  std::cout << "\n==========================================================";
  std::cout << "\n==========================================================\n\n";

  // Method 2 (fast method) much faster than method 1
  // it's actually a 1D dynamic array work as 2D dynamic array

  // allocation
  // int *_f2dTable = new int[100];  // both are the same
  int* _f2dTable = new int[10 * 10]; // both are the same

  // accessing
  for (uint32_t i(0); i < 10; i++)
  {
    for (uint32_t j(0); j < 10; j++)
      std::cout << (_f2dTable[j + i * 10] = 2) << "  ";
    std::cout << std::endl;
  }

  // deallocation
  delete[] _f2dTable;
}