#include <iostream>
#include <string>


// replace() ---> Replaces the portion of the string that begins at character pos and spans len characters
// (or the part of the string in the range between (i1,i2) by new contents


// https://www.geeksforgeeks.org/stdstringreplace-stdstringreplace_if-c/

// replace() using iterators:-->  https://cplusplus.com/reference/string/string/replace/

using namespace std;

int main()
{
  cout << endl << "__________________________________(1)_________________________________" << endl << endl;


    // Replaces 19 characters from 9th index by S1

    string Name("Mohammed Abdelrahman Ismail");
    //                   ^^^^^^^^^^^^^^^^^^^
    string S1{"Gad"};

    cout << "- Name Before replace is: \" " << Name << " \"" << endl;
    Name.replace(9, 19, S1);
    cout << "- Name After replace is : \" " << Name << " \"" << endl;


  cout << endl << "__________________________________(2)_________________________________" << endl << endl;


    // Replaces 8 characters from 0th index with "Amira"
  
    Name = "Mohammed Abdelrahman Ismail Gad";
    //      ^^^^^^^^
    cout << "- Name Before replace is: \" " << Name << " \"" << endl;
    Name.replace(0, 8, "Amira");
    cout << "- Name After replace is : \" " << Name << " \"" << endl;


  cout << endl << "__________________________________(3)_________________________________" << endl << endl;


    // Replaces 10 characters from 0th index of Name with 8 characters from string "Fuck_You"
    
    Name = "My Name Is John";
    //      ^        ^
    cout << "- Name Before replace is: \" " << Name << " \"" << endl;
    Name.replace(0, 10,"Fuck_You", 8);
    cout << "- Name After replace is : \" " << Name << " \"" << endl;


  cout << endl << "__________________________________(4)_________________________________" << endl << endl;

    // Replaces 7 characters from 11th index of Name with 5 characters from 0th of S2

    Name = "My Name is Mahmoud Gad";
    //                 ^     ^
    string S2{"Amira Gad"};
    //         ^   ^
    cout << "- Name Before replace is: \" " << Name << " \"" << endl;
    Name.replace(11, 7, S2, 0, 5);
    cout << "- Name After replace is : \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(5)_________________________________" << endl << endl;

    // Replaces 11 character from 8th index of Name with 3 copies of '&'
    
    Name = "Mohammed Abdelrahman Ismail Gad";
    //               ^^^^^^^^^^^
    cout << "- Name Before replace is: \" " << Name << " \"" << endl;
    Name.replace(9, 11, 11, '&');
    cout << "- Name After replace is : \" " << Name << " \"" << endl;

  
  cout << endl << "______________________________________________________________________" << endl << endl;


  return 0;


}