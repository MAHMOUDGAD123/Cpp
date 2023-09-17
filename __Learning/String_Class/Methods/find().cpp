#include <iostream>
#include <string>

using namespace std;

// find is used to find the first occurrence of sub-string in the specified string being called upon.
// It returns the index of the first occurrence of the substring in the string from given starting position.
// The default value of starting position is 0.

// https://www.geeksforgeeks.org/string-find-in-cpp/
// https://cplusplus.com/reference/string/string/find/


// rfind() ---> works as reversed find() it search from the end to the begin

// https://www.geeksforgeeks.org/stdstringrfind-in-c-with-examples/
// https://cplusplus.com/reference/string/string/rfind/


// Look too at:
// (1) find_first_of()
// (2) find_last_of()
// (3) find_first_not_of()
// (4) find_last_not_of()

// Here -----> https://cplusplus.com/reference/string/string/


int main ()
{

  string Name("Mahmoud Abdelrahman Ismail Abdelrahman Ismail Gad .");

  size_t found{0};

  // [1] size_t find (const string& str, size_t pos = 0) const noexcept;
  cout << endl << "___________________________________________(1)___________________________________________" << endl << endl;

  // Find first occurrence of "Abdelrahman"
  found = Name.find("Abdelrahman");
  (found != Name.npos) ? cout << "- First Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;

  // Find next occurrence of "Abdelrahman"
  found = Name.find("Abdelrahman", found + 1);
  (found != Name.npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;


  cout << endl << "___________________________________________(2)___________________________________________" << endl << endl;

  string S1("Ismail");

  // Find first occurrence of "Ismail"
  found = Name.find(S1);
  (found != Name.npos) ? cout << "- First Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;
  // Find next occurrence of "Ismail"
  found = Name.find(S1, found + 1);
  (found != Name.npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;

  // Find next occurrence of "Ismail"
  found = Name.find(S1, found + 1);
  (found != Name.npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;


  // [2] size_t find (const char* s, size_t pos = 0) const;
  cout << endl << "___________________________________________(3)___________________________________________" << endl << endl;

  char S2[4]("Gad");

  // Find first occurrence of S2
  found = Name.find(S2);
  (found != Name.npos) ? cout << "- First Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;

  // Find next occurrence of S2
  found = Name.find(S2, found + 1);
  (found != Name.npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;


  // [3] size_t find (char c, size_t pos = 0) const noexcept;
  cout << endl << "___________________________________________(4)___________________________________________" << endl << endl;

  // Find first occurrence of '.'
  found = Name.find('.');
  (found != string::npos) ? cout << "- First Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;

  // Find next occurrence of '.'
  found = Name.find('.', found + 1);
  (found != string::npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;


  cout << "\n-------------------------------------------\n\n";


  char C1('A');

  // Find first occurrence of C1
  found = Name.find(C1);
  (found != string::npos) ? cout << "- First Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;

  // Find next occurrence of C1
  found = Name.find(C1, found + 1);
  (found != string::npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;
  
  // Find next occurrence of C1
  found = Name.find(C1, found + 1);
  (found != string::npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;
  
  
  // [4] size_t find (const char* s, size_t pos, size_type n) const;
  cout << endl << "___________________________________________(5)___________________________________________" << endl << endl;


  // Only search first 6 characters of "Ismail_Gad"
  found = Name.find("Ismail_Gad", 0, 6);
  (found != string::npos) ? cout << "- First Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;

  // Find next occurrence of first 6 characters of "Ismail_Gad"
  found = Name.find("Ismail_Gad", found + 1, 6);
  (found != string::npos) ? cout << "- Next Found At Position:--> (" << found << ")" << endl : cout << "- Not Found!" << endl;


  cout << endl << "___________________________________________(6)___________________________________________" << endl << endl;

  // Replace all "Abdelrahman" with "Ali"

  string S("Abdelrahman");
  string S3("Ali");

  cout << "Name Before Replace     : \" " << Name << endl;

  found = Name.find(S);
  if(found != string::npos)
    Name.replace(found, S.length(), S3);

  cout << "Name After First Replace: \" " << Name << endl;

  found = Name.find(S, found + 1);
  if(found != string::npos)
    Name.replace(found, S.length(), S3);

  cout << "Name After Next Replace : \" " << Name << endl;

  cout << endl << "_________________________________________________________________________________________" << endl << endl;


  return 0;
}