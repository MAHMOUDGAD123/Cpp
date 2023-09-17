#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/* 
  How to compare 2 strings:

  1- String strcmp() function -- Deals with array of chars 
  2- The built-in compare() function
  3- C++ Relational Operators (==, !=)

  ------>  https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus
 
*/

/*
  compare functions:

  - Returns {0}  : if both the strings are the same.
  - Returns {< 0}: (less than zero) if the value of the character of the first string is smaller as compared to the second string input.
  - Results {> 0}: (greater than zero) when the second string is greater in comparison.

*/

/*
  -- compare()

  -> int compare (const string& str) const noexcept;  *****
  -> int compare (size_t pos, size_t len, const string& str) const;
  -> int compare (size_t pos, size_t len, const string& str, size_t subpos, size_t sublen = npos) const;
  -> int compare (const char* s) const;
  -> int compare (size_t pos, size_t len, const char* s) const;
  -> int compare (size_t pos, size_t len, const char* s, size_t n) const;

  ----> https://cplusplus.com/reference/string/string/compare/

*/


void Get_Compare_Result(short *Result)
{
  cout << "-> Result = " << *Result << endl;
  if (*Result == 0)
    cout << "-> The 2 Strings Are Equal";
  else
    (*Result < 0) ? cout << "-> First String Is Larger Than The Second" : cout << "-> First String Is Smaller Than The Second";
}


int main()
{
  short *Result = new short{0};

  cout << endl << "--------------------------------------> Using compare() Funtion <------------------------------------" << endl;

  cout << endl << "_________________________________________________(1)_________________________________________________" << endl << endl;

    string S1("Mahmoud Gad");
    string S2("Mahmoud Gad");

    *Result = S1.compare(S2);

    Get_Compare_Result(Result);

  cout << endl << "_________________________________________________(2)_________________________________________________" << endl << endl;
  
    S1 = "Mahmoud Gad";
    S2 = "Mahmoud_Gad";
    
    *Result = S1.compare(S2);

    Get_Compare_Result(Result);

  cout << endl << "_________________________________________________(3)_________________________________________________" << endl << endl;
  
    S1 = "mahmoud Gad";
    S2 = "Mahmoud Gad";
    
    *Result = S1.compare(S2);

    Get_Compare_Result(Result);

  cout << endl << "_________________________________________________(4)_________________________________________________" << endl << endl;
  
    S1 = "&&&&&&&&&&&";
    S2 = "&&&&&*&&&&&";
    
    *Result = S1.compare(S2);

    Get_Compare_Result(Result);

  cout << endl << "_________________________________________________(5)_________________________________________________" << endl << endl;
  
    S1 = "Mahmoud Gad";
    //            ^^^
    
    *Result = S1.compare(8, 3, "Gad");

    Get_Compare_Result(Result);
  
  cout << endl << "_________________________________________________(6)_________________________________________________" << endl << endl;
  
    S1 = "Mahmoud Gad";
    //            ^^^    
    S2 = "Amira Gad";
    //          ^^^
    *Result = S1.compare(8, 3, S2, 6, 3);

    Get_Compare_Result(Result);
  
  cout << endl << "_________________________________________________(7)_________________________________________________" << endl << endl;
  
    S1 = "Mahmoud Gad";
    //               
    char C1[] = "Mahmoud Gad";
    //          
    char C2[] = "Gad";
    //          

    *Result = S1.compare(C1);
    Get_Compare_Result(Result);

    cout << endl;

    *Result = S1.compare(8, 3, C2);
    Get_Compare_Result(Result);

    cout << endl;

    *Result = S1.compare(0, 7, C1, 7);
    Get_Compare_Result(Result);
  
  cout << endl << "_____________________________________________________________________________________________________" << endl << endl;

  return 0;
}