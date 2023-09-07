# include <iostream>

using namespace std;


// Normal Square Function
double square1(const double &Number)
{
  return Number * Number;
}


// General Square Function
template <typename T>
T square2(const T  &Number)
{
  return Number * Number;
}


int main()
{
  cout << square1(321.897) << endl;
  cout << square2(321.897) << endl;

  return 0;
}