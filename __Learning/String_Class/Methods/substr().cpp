#include <iostream>
#include <string>
#include <string.h>

using namespace std;


// Look at this:
// https://www.geeksforgeeks.org/substring-in-cpp/




// string substr (size_t pos, size_t len) const;

/*

  pos: Position of the first character to be copied.
  len: Length of the sub-string.
  size_t: It is an unsigned integral type.

*/

int main()
{ 
  string Name("Mahmoud Abdelrahman Ismail Abdelrahman Ismail Gad");


  cout << endl << "________________________________________(1)________________________________________" << endl << endl;

  cout << Name.substr() << endl; // Return all Name
  cout << Name.substr(27) << endl; // Print from 27th index of Name
  cout << Name.substr(0, 19) + Name.substr(38, 11) << endl; // Mahmoud Abdelrahman + Ismail Gad

  cout << endl << "________________________________________(2)________________________________________" << endl << endl;
  
  string S1("Amira");
  
  cout << "S1 Before Substr = \" " << S1 << " \"" << endl;
  S1 += Name.substr(Name.length() - 4, 4);
  cout << "S1 After Substr  = \" " << S1 << " \"" << endl; 
  
  cout << endl << "________________________________________(3)________________________________________" << endl << endl;
  
  Name = "Fuck You: Mahmoud Gad";
  //                ^^^^^^^^^^^
  string S2("John");
  unsigned short pos = Name.find(':'); // position = 8

  cout << "Name = \"" << Name.substr(pos + 2) << "\"" << endl; // Name = "Mahmoud Gad"
  cout << Name.substr(0, pos + 2) + S2 << endl; // Fuck You: john
  
  cout << endl << "___________________________________________________________________________________" << endl << endl;

  return 0;
}