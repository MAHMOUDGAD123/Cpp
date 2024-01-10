#include<iostream>

using namespace std;

void Message(void)
{
  cout << "\nFuck U\n";
}

int Sum(...)
{
  return 10 + 5;
}


int main(void)
{
  Message();
  cout << Sum() << endl;

  return 0;
}