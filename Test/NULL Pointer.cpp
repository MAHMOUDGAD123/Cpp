#include <iostream>

using namespace std;

int main()
{
  int N{123};
  int *ptr = &N;

  cout << *ptr << endl;

  ptr = NULL;

  if (ptr == nullptr) // you can use if (ptr) to check too
  {
    cout << "-> ptr is a 'nullptr'" << endl;
  }
  else
  {
    cout << "-> ptr isn't a 'nullptr'" << endl;
  }

  return 0;
}