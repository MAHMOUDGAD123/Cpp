#include <iostream>

using namespace std;


int main()
{
  string Name("Gad");

  for(short i = 0, j = i; i < Name.length() && j == i; i++, j++)
  {
    cout << endl << Name << endl;
  }

  cout << endl << endl;

  string S("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

  
  for(short i = 0; i < S.length(); i++)
  {
    for(short j = 0; j < S.length() - i; j++)
      cout << S[j];
      cout << endl;
  }

  return 0;
}