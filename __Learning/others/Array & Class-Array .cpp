#include <iostream>
#include <vector>
#include <array> // for class array

// for more -> https://cplusplus.com/reference/array/array/

using namespace std;

int main(void)
{
  int Nums[5] = {1, 2, 3, 4, 5}; // c-style array

  array<int, 5> arrNums = {1, 2, 3, 4, 5}; // class array

  cout << arrNums[0] << endl;
  cout << arrNums[1] << endl;
  cout << arrNums[2] << endl;
  cout << arrNums[3] << endl;

  cout << "\n\n";

  arrNums.fill(7);
  cout << arrNums[0] << endl;
  cout << arrNums[1] << endl;
  cout << arrNums[2] << endl;
  cout << arrNums[3] << endl;

  return 0;
}