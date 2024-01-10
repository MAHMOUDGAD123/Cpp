#include <iostream>
#include <vector>

using namespace std;

int Fun()
{
  return 7;
}

double add(double a, double b)
{
  return a + b;
}

int main()
{
  int N;
  // Pointer to a normal varible
  int *iptr = &N;

  int array[5]{1, 2, 3, 4, 5};
  // Pointer to an array of size '5'
  int(*arrptr)[5] = &array;
  // reference to an array of size '5'
  int(&arrref)[5] = array;

  for (int i(0); i < 5; ++i)
    std::cout << *(*arrptr + i) << ' ';

  for (int i(0); i < 7; ++i)
    std::cout << arrref[i] << ' ';

  //=========================================================

  // Pointer to a function
  int (*Funptr)() = Fun;                  // for function with no parameters
  double (*addptr)(double, double) = add; // for function with parameters

  cout << Funptr() << endl;
  cout << addptr(1.5, 1.5) << endl;

  cout << "\n\n";

  // Pointer to a pointer
  int D = 10;
  int *ptr = &D;
  int **pptr = &ptr; // <--

  // void pointer
  string S{"Mahmoud"};
  void *voiptr{&S};
  cout << *(string *)voiptr << endl;              // C-style casting
  cout << *static_cast<string *>(voiptr) << endl; // static_casting

  cout << "\n\n";

  // Vector of pointers
  int a{2}, b{2}, c{3}, d{4}, e{5};
  vector<int *> vNumbers{&a, &b, &c, &d, &e};

  cout << vNumbers[0] << endl;  // address a
  cout << *vNumbers[0] << endl; // value of a

  return 0;
}