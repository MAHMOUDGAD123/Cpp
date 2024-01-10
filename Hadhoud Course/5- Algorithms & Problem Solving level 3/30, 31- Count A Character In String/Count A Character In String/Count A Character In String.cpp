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


unsigned short CountCharacterInString(const string Str, const char Char)
{
	// Case Sensitive in Letters

	unsigned short Counter = 0;

	for (const char& C : Str)
		if (C == Char)
			Counter++;

	return Counter;
}


unsigned short CountLetterInString(const string Str, const char Char, bool Case_Sensitive = true)
{
	unsigned short Counter = 0;

	if (Case_Sensitive)
	{
		// Count only the user input case

		for (const char& C : Str)
			if (C == Char)
				Counter++;
	}
	else
	{
		// Count all cases

		char OtherCase = InvertAlphaCase(Char);
		for (const char& C : Str)
			if (C == Char || C == OtherCase)
				Counter++;
	}

	return Counter;
}



int main(void)
{
	string S = Read_Text("\n-> Enter A String: ");
	char Char = Read_Char("-> Enter A Char To Count: ");

	char OtherCase = InvertAlphaCase(Char);

	cout << "\n#######################################################\n\n";

	printf("-> The Number Of (%c) In The String = %hu\n", Char, CountLetterInString(S, Char));

	cout << "\n#######################################################\n\n";

	printf("-> The Number Of (%c) or (%c) In The String = %hu\n", Char, OtherCase, CountLetterInString(S, Char, false));

	cout << "\n#######################################################\n\n";


	return 0;
}