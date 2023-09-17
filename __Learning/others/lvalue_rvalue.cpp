#include <iostream>

using namespace std;

// https://www.youtube.com/watch?v=fbYknr-HPYE&ab_channel=TheCherno

int &getsValue()
{
  static int V = 10;
  return V;
}

void printName(const string &name)
{
  // this function take both lvalue & rvalue as parameter
  cout << "[lvalue] " << name << endl;
}

void printName(string &&name)
{
  // this function take only rvalue as parameter
  cout << "[rvalue] " << name << endl;
}

int main()
{
  cout << "\n\n====================================\n\n";

  int X = 10; // (x) is a lvalue ---- (10) is a rvalue

  int &Y = X; // ok -> Y is a rvalue reference which takes only rvalue
  // int &Y = 10; // error -> must assign a lvalue only to it
  cout << "Y = " << Y << endl;

  const int &Z = 20; // ok -> lvalue reference had to be 'const' to be able to assign a rvalue to it
  cout << "Z = " << Z << endl;
  const int &M = X; // ok -> const lvalue reference can take both lvalue or rvalue
  cout << "M = " << M << endl;

  int &&W = 30; // W is a rvalue reference which can take only a rvalue
  // int &&W = X; // error -> W can't take a lvalue
  cout << "W = " << W << endl;

  cout << "\n====================================\n\n";

  cout << "s Value = " << getsValue() << endl; // 10
  getsValue() = 100;                           // modifiable because it returns a reference of a static variable
  cout << "s Value = " << getsValue();         // 100

  cout << "\n\n====================================\n\n";

  string fname = "Mahmoud";
  string lname = " Gad";

  string fullname = fname + lname;

  printName(fullname);      // cosnt &
  printName("Amira Gad");   // &&
  printName(fname + lname); // &&

  cout << "\n====================================\n\n";

  return 0;
}