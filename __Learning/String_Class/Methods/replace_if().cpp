#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// https://www.geeksforgeeks.org/stdstringreplace-stdstringreplace_if-c/


using namespace std;


// void replace_if (ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T& new_value );
// replace_if() ---> replaces each element in the range (first, last) when pred is true with newValue. 

bool isVowel(char C)
{
  return (C == 'A' || C == 'E' || C == 'I' || C == 'U' || C == 'O');
}

bool isDigit(char C)
{
  return (C >= 48 && C <= 57);
}

bool isOdd(int N)
{
  return (N % 2 != 0);
}

void String_Replace_if_Vowel(string &S)
{
  replace_if(S.begin(), S.end(), isVowel, '*');
}

void Vector_Replace_if_Odd(vector <int> &V)
{
  replace_if(V.begin(), V.end(), isOdd, 0);
}
void Vector_Replace_if_Digit(vector <char> &V)
{
  replace_if(V.begin(), V.end(), isDigit, 'X');
}

void Print_Vector(vector <int> &V)
{
  for (vector <int>::iterator iter = V.begin(); iter != V.end(); iter++)
    cout << ' ' << *iter;
}
void Print_Vector(vector <char> &V)
{
  for (vector <char>::iterator iter = V.begin(); iter != V.end(); iter++)
    cout << ' ' << *iter;
}


int main()
{
    cout << endl << "__________________________________(1)_________________________________" << endl << endl;


    string Name("MAHMOUD ABDELRAHMAN ISMAIL GAD");
    //            ^  ^^  ^  ^  ^  ^  ^  ^^   ^
  
    cout << "- Name Before replace is: \" " << Name << " \"" << endl;
    String_Replace_if_Vowel(Name);
    cout << "- Name After replace is : \" " << Name << " \"" << endl;


    cout << endl << "__________________________________(2)_________________________________" << endl << endl;

    vector <int> vNumbers{ 1,2,3,4,5,6,7,8,9 };

    cout << "- vNumbers Before Replace: ";
    Print_Vector(vNumbers);
    cout << endl;

    Vector_Replace_if_Odd(vNumbers);

    cout << "- vNumbers After Replace : ";
    Print_Vector(vNumbers);
    cout << endl;


    cout << endl << "__________________________________(3)_________________________________" << endl << endl;

    vector <char> vCharacters{ 'M','1','2','A','3','H','4','M','O','U','5','D' };
    
    cout << "- vCharacters Before Replace:";
    Print_Vector(vCharacters);
    cout << endl;

    Vector_Replace_if_Digit(vCharacters);

    cout << "- vCharacters After Replace :";
    Print_Vector(vCharacters);
    cout << endl;



    cout << endl << "______________________________________________________________________" << endl << endl;

    return 0;

}
