#include <iostream>
#include <string>
#include <vector>

using namespace std;

// void GetArray_MixandMax(int Array[])
// {
// }

int main()
{
  int Array[5] = {1, 2, 3, 4, 5};

  int *ptr = new int{0};

  *ptr = Array[5];

  cout << Array[5] << endl;
  // cout << *ptr << endl;

  return 0;
}