#include <iostream>

using namespace std;

/*

  using:

  1- striing::c_str()
  2- string::data()

*/

int main(void)
{
  string S = "Mahmoud Gad";

  cout << "\n\n";

  printf("My Name Is: %s\n", S.data());
  printf("My Name Is: %s", S.c_str());

  cout << "\n\n";

  cout << S.data() << '\n';
  cout << S.c_str();

  cout << "\n\n";

  return 0;
}