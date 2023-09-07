#include <iostream>
#include <string>
#include <cctype> // Needed

using namespace std;

void StringToUpperCase(string &str)
{
  for (char &C : str)
  {
    if (C >= 97 && C <= 122) // Check if a small letter
      C -= ' '; // ' ' == 32
  }
}

constexpr int CharToUpperCase(int ch)
{
  return (ch >= 97 && ch <= 122) ? ch - ' ' : ch;
}



int main()
{
  string S{"hooda.gad333@gmail.com"};

  cout << "\n_______________________________________________(1)_______________________________________________\n\n\n";


    cout << "-> S Before Uppering = " << S << endl;
    StringToUpperCase(S);
    cout << "-> S After Uppering  = " << S << endl;

  cout << "\n_______________________________________________(2)_______________________________________________\n\n\n";


    cout << (char)CharToUpperCase('a') << endl;

    cout << (char)CharToUpperCase('A') << endl;

    cout << (char)CharToUpperCase('9') << endl;

    cout << (char)CharToUpperCase('@') << endl;


  cout << "\n_______________________________________________(3)_______________________________________________\n\n\n";
  
    string G("mahmoud_gad1997");

    for (char &c : G)
      c = CharToUpperCase(c);

    cout << "-> S = " << G << endl;
  
  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}