#include <iostream>

int main(int argc, char* argv[]) {

  // 4D daynamic array (5 * 5 * 5 * 5)

  // allocating
  int ****_4dTable = new int ***[5];
  for (int i(0); i < 5; ++i) {
    _4dTable[i] = new int **[5];
    
    for (int j(0); j < 5; ++j) {
      _4dTable[i][j] = new int *[5];

      for (int x(0); x < 5; ++x) {
        _4dTable[i][j][x] = new int[5]{1,2,3,4,5};
      }
    }
  }

  // accessing
  for (int i(0); i < 5; ++i) {
    for (int j(0); j < 5; ++j) {
      for (int x(0); x < 5; ++x) {
        for (int y(0); y < 5; ++y)
          std::cout << _4dTable[i][j][x][y] << "  ";
        std::cout << "\n";
      }
      std::cout << "\n";
    }
    std::cout << "\n\n";
  }

  // deallocating
  for (int i(0); i < 5; ++i) {
    for (int j(0); j < 5; ++j) {
      for (int x(0); x < 5; ++x) {
        delete[] _4dTable[i][j][x];
      }
      delete[] _4dTable[i][j];
    }
    delete[] _4dTable[i];
  }
  delete[] _4dTable;

}