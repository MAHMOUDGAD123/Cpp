#include <iostream>
#include <string>

using namespace std;

char *Name(const int *PIN)
{
  char S[12] = "Mahmoud Gad";
  char R[10] = "Wrong PIN";

  if(*PIN == 1234)
    return S;

  return R;
}

int main()
{
  int PIN = 123456;

  cout << Name(&PIN) << endl;
  return 0;
}
