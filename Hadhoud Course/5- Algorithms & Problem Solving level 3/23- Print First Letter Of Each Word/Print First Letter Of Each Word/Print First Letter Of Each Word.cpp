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
	getline(cin >> ws, Txt);

	return Txt;
}

void Print_FirstLetterOfEachWord(const string& S)
{
	cout << "->";

	bool isFirstLetter(true);

	for (unsigned short i = 0; i < S.length(); ++i)
	{
		if (S[i] != ' ' && isFirstLetter)
			cout << ' ' << S[i];

		isFirstLetter = S[i] == ' ';
	}
	cout << endl;
}

void Print_FirstLetterOfEachWord_Find(const string& S)
{
	cout << "->";

	size_t Found = S.find(' ');

	if (S[0] != ' ')
		cout << ' ' << S[0]; // print first letter if not ' '

	while (Found != string::npos)
	{
		if (S[Found + 1] != ' ')
			cout << ' ' << S[Found + 1];

		Found = S.find(' ', Found + 1);
	}
	cout << endl;
}


int main(void)
{
	string UserInput = ReadText("\n-> Enter You Name: ");

	cout << "\n#######################################################\n\n";

	Print_FirstLetterOfEachWord(UserInput);

	cout << "\n#######################################################\n\n";

	Print_FirstLetterOfEachWord_Find(UserInput);

	cout << "\n#######################################################\n\n";



	return 0;
}