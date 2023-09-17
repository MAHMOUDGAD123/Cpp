#include <iostream>
#include <string>


// insert() ---> is used to insert characters in string at specified position.


// https://www.geeksforgeeks.org/stdstringinsert-in-c/


using namespace std;

int main()
{
  cout << endl << "__________________________________(1)_________________________________" << endl << endl;

  // string& string::insert (size_type idx, const string& str)
  string Name{"Mahmoud Ismail Gad"};
  //                   ^
  string S1("Abdelrahman ");

  Name.insert(8, S1);
  cout << "- Name After Insert is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(2)_________________________________" << endl << endl;

  // string& string::insert (size_type idx, const string& str, size_type str_idx, size_type str_num)
  Name = "Mahmoud Ismail Gad";
  //              ^
  string S2("Mohammed Abdelrahman Ismail Gad");
  //                  ^          ^  
  Name.insert(8, S2, 9, 12);
  cout << "- Name After Insert is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(3)_________________________________" << endl << endl;

  // string& string::insert (size_ type idx, const char* cstr)
  Name = "Mahmoud Abdelrahman ail";
  //                          ^

  Name.insert(20, "Ism");
  cout << "- Name After Insert is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(4)_________________________________" << endl << endl;

  // string& string::insert (size_type idx, const char* chars, size_type chars_len)
  Name = "Mahmoud Abdelail";
  //                    ^
  Name.insert(13, "rahman Ismail Gad", 10);
  //               ^        ^  
  cout << "- Name After Insert is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(5)_________________________________" << endl << endl;

  // string& string ::insert (size_type idx, size_type num, char c)
  Name = "************";
  //            ^
  Name.insert(6, 4,'&');
  cout << "- Name After insert is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(6)_________________________________" << endl << endl;

  // void string ::insert (iterator pos, size_type num, char c)
  Name = "************";
  //            ^
  Name.insert(Name.begin() + 6, 4, '&');
  cout << "- Name After insert is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(7)_________________________________" << endl << endl;

  // iterator string ::insert (iterator pos, char c)
  Name = "************";
  //            ^
  string::iterator iter = Name.insert(Name.begin() + 6, '&');
  cout << "- Name After insert is: \" " << Name << " \"" << endl;

  cout << endl << "__________________________________(8)_________________________________" << endl << endl;

  // void string ::insert (iterator pos, InputIterator begin, InputIterator end)
  Name = "Mahmoud Abdelail";
  //                  ^
  string S3{"Abdelrahman Ismail Gad"};
  //              ^        ^
  Name.insert(Name.begin() + 13, S3.begin() + 5, S3.end() - 7);
  cout << "- Name After insert is: \" " << Name << " \"" << endl;

  cout << endl << "______________________________________________________________________" << endl << endl;


  return 0;


}