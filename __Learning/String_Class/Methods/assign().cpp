#include <iostream>
#include <string>


// assign() ---> Assigns a new value to the string, replacing its current contents.


// https://www.geeksforgeeks.org/stdstringassign-in-c/

using namespace std;

int main()
{
  string Name{"Mahmoud"};

  cout << "- Original Name is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(1)_________________________________" << endl << endl;

  // string& string::assign (const string& str)
  string S1("Amira");

  Name.assign(S1);
  cout << "- Name After Assign is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(2)_________________________________" << endl << endl;

// string& string::assign (const string& str, size_type str_idx, size_type str_num)
  string S2("Abdelrahman Ismail Gad");

  Name.assign(S2, 11, 21);
  cout << "- Name After assign is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(3)_________________________________" << endl << endl;

  // string & string::assign (const char* cstr)

  Name.assign("Gad");
  cout << "- Name After assign is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(4)_________________________________" << endl << endl;

  // string& string::assign (const char* chars, size_type chars_len)

  Name.assign("Abdelrahman Ismail Gad", 18);
  cout << "- Name After Append is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(5)_________________________________" << endl << endl;

  // string & string::assign (size_type num, char c)

  Name.assign(7, '&');
  cout << "- Name After Append is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(6)_________________________________" << endl << endl;

  // template <class InputIterator> string& assign (InputIterator first, InputIterator last)
  string S3{"Abdelrahman Ismail Gad"};

  Name.assign(S3.begin() + 12, S3.end() - 4);
  cout << "- Name After Append is: \" " << Name << " \"" << endl;

  cout << endl << "______________________________________________________________________" << endl << endl;


//   return 0;


}