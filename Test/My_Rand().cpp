#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

static unsigned long Next = 1;

unsigned long Rand(void) // Max  assumed to be 54321
{
  Next = Next * 12654 + 165487;
  return (long long)Next % 54321;
}

void Srand(unsigned long Seed)
{
  Next = Seed;
}


int main()
{
  Srand(13484614);
  srand(13484614);

  for (short i = 0; i < 7; i++)
  {
    cout << "-> My Rand  = " << Rand() % 101 << endl; // from 1 to 100
    cout << "-> C++ rand = " << rand() % 101 << endl; // from 1 to 100
    cout << endl;
  }

  return 0;
}