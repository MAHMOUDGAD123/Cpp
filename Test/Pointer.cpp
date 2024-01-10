#include <iostream>
#include <string>

using namespace std;

enum DataType
{
  Integer = 1,
  Float = 2,
  Double = 3,
  Char = 4,
  String = 5,
  CharArr = 6
};

void Print(void *ptr, DataType DataType)
{
  switch (DataType)
  {
  case Integer:
    cout << *((int *)ptr) << endl;
    break;

  case Float:
    cout << *((float *)ptr) << endl;
    break;

  case Double:
    cout << *((double *)ptr) << endl;
    break;

  case Char:
    cout << *((char *)ptr) << endl;
    break;

  case String:
    cout << *((string *)ptr) << endl;
    break;

  default:
    cout << "Invalid Type!!" << endl;
    break;
  }
}

int main()
{
  string *Name = new string{"Mahmoud"};
  int *iNumber = new int{123456789};
  float *fNumber = new float{12.456};

  Print(Name, String);
  Print(iNumber, Integer);
  Print(fNumber, Float);

  return 0;
}