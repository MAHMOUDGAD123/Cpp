#include <iostream>
#include <string>

using namespace std;

/*
  --> Graphical Characters <--

  - Digits (0 to 9)
  - Uppercase letters (A to Z)
  - Lowercase letters (a to z)
  - Punctuation characters (  !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~  )
  
*/

bool Isgraph(char C)
{
  return (C >= 33 && C <= 126) ? true : false;
}

void Display_All_Graphical_Characters_Only()
{
  string *Graphical_Chars = new string("");

  for (short i = 33; i <= 126; i++)
  {
    *Graphical_Chars += i;
    *Graphical_Chars += ' ';
  }
  cout << *Graphical_Chars << endl;
  delete Graphical_Chars;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  cout << "-> All Graphical Characters Are:\n\n";
  Display_All_Graphical_Characters_Only();

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}