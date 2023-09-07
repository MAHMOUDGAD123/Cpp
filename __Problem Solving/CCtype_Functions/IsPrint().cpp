#include <iostream>
#include <string>

using namespace std;

/*
  -- Printable Characters --

  Digits (0 to 9)
  Uppercase letters (A to Z)
  Lowercase letters (a to z)
  Punctuation characters (  !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~  )
  Space ' '

*/

bool IsPrint(const char &C)
{
  return (C >= 32 && C <= 126);
}

void Display_All_Printable_Characters_Only()
{
  string *Printable_Chars = new string("");

  for (short i = 32; i <= 126; i++)
  {
    *Printable_Chars += i;
    *Printable_Chars += ' ';
  }
  cout << *Printable_Chars << endl;
  delete Printable_Chars;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  cout << "-> All Printable Characters Are:\n\n";
  Display_All_Printable_Characters_Only();

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}