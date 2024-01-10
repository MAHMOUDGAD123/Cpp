#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <cctype>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


/*
	ASCII Table Values Of Vowel Letters:

	- A = 65  &  a = 97
	- E = 69  &  e = 101
	- I = 73  &  i = 105
	- O = 79  &  o = 111
	- U = 85  &  u = 117

*/


bool Is_Vowel(char Ch)
{
	Ch = ToUpperCase(Ch);

	for (const char& C : "AEIOU")
		if (Ch == C)
			return true;

	return false;
}

bool IsVowel(char C)
{
	C = ToLowerCase(C);

	return (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u');
}



int main(void)
{
	//string S = Read_Text("\n-> Enter A String: ");
	char Char = Read_Char("\n-> Enter A Character: ");

	cout << "\n#######################################################\n\n";


	if (IsVowel(Char))
		printf("-> (%c) Is Vowel.\n", Char);
	else
		printf("-> (%c) Isn't Vowel.\n", Char);


	cout << "\n#######################################################\n\n";


	if (Is_Vowel(Char))
		printf("-> (%c) Is Vowel.\n", Char);
	else
		printf("-> (%c) Isn't Vowel.\n", Char);


	cout << "\n#######################################################\n\n";




	return 0;
}