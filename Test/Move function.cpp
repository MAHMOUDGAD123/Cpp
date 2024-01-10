#include <iostream>

using namespace std;

int mian()
{
  string x = "M";
  string y;

  cout << "\n\nx = " << x << endl;
  cout << "y = " << y << endl;

  y = move(x);

  cout << "\n\nx = " << x << endl;
  cout << "y = " << y << endl;

  return 0;
}