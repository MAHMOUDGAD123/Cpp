#include <iostream>
#include <string>

using namespace std;

/*
  --> Control Characters <--

  By default, the characters with the codes from 0x00 to 0x1F and 0x7F are considered control characters

  look ASCII-Table -> file:///C:/Users/MG/Desktop/ASCII-Table.pdf
  
*/

bool IsCntrl(const char &C)
{
  return ((C >= 0 && C <= 31) || C == 127) ? true : false;
}

void Get_Result(const char &C)
{
  (IsCntrl(C)) ? cout << "\'" << C << "\'" << " Is A Control Character.\n" : cout << C << " Is A Printable Character.\n";
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

    char c1('\t');
    char c2('1');
    Get_Result(c1);
    Get_Result(c2);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}