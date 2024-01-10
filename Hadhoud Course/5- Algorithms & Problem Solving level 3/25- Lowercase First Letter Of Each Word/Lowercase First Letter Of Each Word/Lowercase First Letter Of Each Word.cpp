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


string ReadText(const char* Message)
{
	string Txt = "";

	cout << Message;
	getline(cin, Txt);

	return Txt;
}

short CharToUpperCase(short ch)
{
	return (ch >= 97 && ch <= 122) ? ch - ' ' : ch;
}

short CharToLowerCase(short ch)
{
	return (ch >= 65 && ch <= 90) ? ch + ' ' : ch;
}

void UppercaseFirstLetterOfEachWord(string& S)
{
	bool isFirstLetter = true;

	for (size_t i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ' && isFirstLetter)
			S[i] = CharToLowerCase(S[i]);

		isFirstLetter = (S[i] == ' ') ? true : false;
	}
}




int main(void)
{
	string Name = ReadText("\n-> Enter You Name: ");

	cout << "\n#######################################################\n\n";

	cout << "-> Name Before Lowercase: " << Name << endl;

	cout << "\n#######################################################\n\n";

	UppercaseFirstLetterOfEachWord(Name);

	cout << "-> Name After Lowercase: " << Name << endl;

	cout << "\n#######################################################\n\n";



	return 0;
}