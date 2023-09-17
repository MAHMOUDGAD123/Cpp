#include <iostream>
#include <string>


// append() --> Extends the string by appending additional characters at the end of its current value


// https://www.geeksforgeeks.org/stdstringappend-in-c/


using namespace std;

int main()
{
  string Name{"Mahmoud"};

  cout << endl << "__________________________________(1)_________________________________" << endl << endl;

  // string& string::append (const string& str)
  string S1(" Gad");

  // Append S1 at the end of Name
  cout << "- Name Before Append is: \" " << Name << " \"" << endl;
  Name.append(S1);
  cout << "- Name After Append is : \" " << Name << " \"" << endl;
  Name.resize(7);

  cout << endl << "__________________________________(2)_________________________________" << endl << endl;

  // string& string::append (const string& str, size_type str_idx, size_type str_num)
  string S2("Mohammed Gad");

  // Append 5 characters from 8th index of S2 at the end of Name
  cout << "- Name Before Append is: \" " << Name << " \"" << endl;
  Name.append(S2, 8, 4);
  cout << "- Name After Append is : \" " << Name << " \"" << endl;
  Name.resize(7);

  cout << endl << "__________________________________(3)_________________________________" << endl << endl;

  // string& string::append (const char* cstr)

  // Append " Gad" at the end of Name
  cout << "- Name Before Append is: \" " << Name << " \"" << endl;
  Name.append(" Gad");
  cout << "- Name After Append is : \" " << Name << " \"" << endl;
  Name.resize(7);

  cout << endl << "__________________________________(4)_________________________________" << endl << endl;

  // string& string::append (const char* chars, size_type chars_len)

  // Append 19 characters of " Abdelrahman Ismail Gad" at the end of Name
  cout << "- Name Before Append is: \" " << Name << " \"" << endl;
  Name.append(" Abdelrahman Ismail Gad", 19);
  cout << "- Name After Append is : \" " << Name << " \"" << endl;
  Name.resize(7);

  cout << endl << "__________________________________(5)_________________________________" << endl << endl;

  // string& string::append (size_type num, char c)

  // Append 7 copies of '&' at the end of Name
  cout << "- Name Before Append is: \" " << Name << " \"" << endl;
  Name.append(7, '&');
  cout << "- Name After Append is : \" " << Name << " \"" << endl;
  Name.resize(7);

  cout << endl << "__________________________________(6)_________________________________" << endl << endl;

  // string& string::append (InputIterator begin, InputIterator end)
  string S3{"Abdelrahman Ismail Abdelrahman Ismail Gad"};

  // Append all characters from 18th index to the end index of S3 at the end of Name  
  cout << "- Name Before Append is: \" " << Name << " \"" << endl;
  Name.append(S3.begin() + 18, S3.end());
  cout << "- Name After Append is : \" " << Name << " \"" << endl;
  Name.resize(7);

  cout << endl << "______________________________________________________________________" << endl << endl;


  return 0;
}