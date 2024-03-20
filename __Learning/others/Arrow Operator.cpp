#include <iostream>

#define print(x) cout << x << '\n';

using namespace std;

// https://www.youtube.com/watch?v=4p3grlSpWYA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=45&ab_channel=TheCherno


struct ST
{
  float x, y, z;
};

// trailing return type
auto Mul(int a, int b) -> int {
  return a * b;
}

int main()
{
  cout << Mul(10, 10) << endl;
}