#include <iostream>
#include <string>
#include <string.h>

using namespace std;


void Clear_String(string &S)
{
  for (short i = 0; i < S.length(); i++)
  {
    S[S.length() - 1 - i] = '\0';
  }
}


int main()
{ 

  cout << endl << "_______________________________________________________________________________________________________\n\n\n";


    cout << "\n\nABCDEFGHIJKLM\0NOPQRSTUVWXYZ" << endl << endl; // ABCDEFGHIJKLM


  cout << endl << "_______________________________________________________________________________________________________\n\n\n";


    // Test NULL character '\0' with string

    string G("Mahmoud");

    cout << "-> G = " << G << endl;
    cout << "-> Size = " << G.size() << endl;

    G = "Mahmou\0d";

    cout << "-> G = " << G << endl;
    cout << "-> Gize = " << G.size() << endl;


  cout << endl << "_______________________________________________________________________________________________________\n\n";


    string S{"Mahmoud Gad"};
    string C{""};

    cout << endl << "-> S Before Nulling All Characters = \"" << S << "\"" << endl;
    cout << "-> Size    = " << S.size() << endl;
    cout << "-> Compare = " << S.compare(C) << endl;

    Clear_String(S);

    cout << endl << "-> S After Nulling All Characters = \"" << S << "\"" << endl;
    cout << "-> Size    = " << S.size() << endl;
    cout << "-> Compare = " << S.compare(C) << endl;
  

  cout << endl << "_______________________________________________________________________________________________________\n\n";

  return 0;
}