#include <iostream>

int main()
{
  // 2D dynamic array (10 x 10)

  // allocation
  int **_2dTable = new int *[10];
  for (uint32_t i(0); i < 10; i++)
    _2dTable[i] = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "\n\n\n2D Array:\n\n";
  // accessing
  for (int i(0); i < 10; ++i)
  {
    for (int j(0); j < 10; ++j)
      std::cout << _2dTable[i][j] << "  ";
    std::cout << std::endl;
  }

  // deallocation
  for (uint32_t i(0); i < 10; i++)
    delete[] _2dTable[i];
  delete[] _2dTable;

  //==========================================================
  //==========================================================
  // 3D dynamic array (10 x 10 x 10)

  // allocation
  int ***_3dTable = new int **[10];
  for (uint32_t i(0); i < 10; ++i)
  {
    _3dTable[i] = new int *[10];

    for (uint32_t j(0); j < 10; ++j)
      _3dTable[i][j] = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  }

  std::cout << "\n\n\n2D Array:\n\n";
  // accessing
  for (int i(0); i < 10; ++i)
  {
    for (int j(0); j < 10; ++j)
    {
      for (int x(0); x < 10; ++x)
        std::cout << _3dTable[i][j][x] << "  ";

      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  // dealloation
  for (uint32_t i(0); i < 10; ++i)
  {
    for (uint32_t j(0); j < i; ++j)
      delete[] _3dTable[i][j];

    delete[] _3dTable[i];
  }
  delete[] _3dTable;
}