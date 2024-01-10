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


void Print_Vowels(const string Str)
{	
	for (const char& C : Str)
		if (IsVowel(C))
			cout << ' ' << C;
}



int main(void)
{
	string S = Read_Text("\n-> Enter A String: ");
	//char Char = Read_Char("\n-> Enter A Character: ");



	cout << "\n#######################################################\n\n";


	cout << "-> Vowel Letters Are = ";
	Print_Vowels(S);


	cout << "\n\n#######################################################\n\n";




	return 0;
}