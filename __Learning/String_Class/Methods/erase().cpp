#include <iostream>
#include <string>

// erase() ---> Erases part of the string, reducing its length:

/*

- sequence (1)  : string& erase (size_t pos = 0, size_t len = npos);
- character (2) : iterator erase (const_iterator p);
- range (3)     : iterator erase (const_iterator first, const_iterator last);

*/

// https://www.geeksforgeeks.org/stdstringerase-in-cpp/

using namespace std;

int main()
{
  cout << endl
       << "__________________________________(1)_________________________________" << endl
       << endl;

  // string& string ::erase() --> to erase all
  string Name("Mohammed Abdelrahman Ismail Gad");

  cout << "- Name Before erase is: \" " << Name << " \"" << endl;
  Name.erase();
  cout << "- Name After erase is : \" " << Name << " \"" << endl;

  cout << endl
       << "__________________________________(2)_________________________________" << endl
       << endl;

  // string& string ::erase (size_type pos) -->  Erases all characters after position ‘pos’
  Name = "Mohammed Abdelrahman Ismail Gad";
  //             ^^^^^^^^^^^^^^^^^^^^^^^^
  cout << "- Name Before erase is: \" " << Name << " \"" << endl;
  Name.erase(8);
  cout << "- Name After erase is : \" " << Name << " \"" << endl;

  cout << endl
       << "__________________________________(3)_________________________________" << endl
       << endl;

  // string& string ::erase (size_type idx, size_type len ) --> remove 'len' characters from index 'idx'
  Name = "Mohammed Abdelrahman Ismail Gad";
  //       ^^^^^^^
  cout << "- Name Before erase is: \" " << Name << " \"" << endl;
  Name.erase(1, 7); // Deletes 7 characters from index number 1
  cout << "- Name After erase is : \" " << Name << " \"" << endl;

  cout << endl
       << "__________________________________(4)_________________________________" << endl
       << endl;

  // string& string ::erase (iterator pos) --> Erase the single character at iterator position 'pos'
  Name = "Mohammed Abdelrahman Ismail Gad";
  //          ^^
  cout << "- Name Before erase is: \" " << Name << " \"" << endl;
  Name.erase(Name.begin() + 4); // Deletes the character at position 4
  Name.erase(Name.begin() + 4); // Deletes the character at position 5
  cout << "- Name After erase is : \" " << Name << " \"" << endl;

  cout << endl
       << "__________________________________(5)_________________________________" << endl
       << endl;

  // string& string ::erase (iterator beg, iterator end) --> Erase characters from iterator pos to another iterator pos.
  Name = "Mohammed Abdelrahman Ismail Gad";
  //       ^^^^^^^^
  cout << "- Name Before erase is: \" " << Name << " \"" << endl;
  Name.erase(Name.begin() + 1, Name.begin() + 8); // Deletes 7 characters from index number 1
  cout << "- Name After erase is : \" " << Name << " \"" << endl;

  cout << endl
       << "______________________________________________________________________" << endl
       << endl;

  return 0;
}