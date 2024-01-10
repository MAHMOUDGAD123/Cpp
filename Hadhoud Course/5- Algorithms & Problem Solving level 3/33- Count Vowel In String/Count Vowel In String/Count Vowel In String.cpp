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


unsigned short CountVowels(const string Str)
{
	unsigned short Counter = 0;

	for (const char& C : Str)
		if (IsVowel(C))
			Counter++;

	return Counter;
}


int main(void)
{
	string S = Read_Text("\n-> Enter A String: ");
	//char Char = Read_Char("\n-> Enter A Character: ");

	cout << "\n#######################################################\n\n";


	cout << "-> The Number Of Vowel Letters = " << CountVowels(S) << endl;


	cout << "\n#######################################################\n\n";




	return 0;
}