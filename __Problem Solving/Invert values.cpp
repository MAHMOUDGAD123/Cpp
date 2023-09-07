#include <iostream>
#include <vector>

using namespace std;

// Convert the negative numbers positive
// and the positive to negative
vector<int> invert(vector<int> values)
{
  for (int& N : values)
    N *= -1;

  return values;
}



int main()
{
  vector<int> V{1, -2, 3, -4, -5, 6, 7, 8, -9, -10, -11};

  cout << "\nOriginal: ";
  for (int n : V)
    cout << n << "  ";
    
  cout << endl;

  V = invert(V);

  cout << "\nInverted: ";
  for(int n : V)cout << n << "  ";

  cout << endl << endl;

  return 0;
}