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



char InvertAlphaCase(char C)
{
	return IsLowerCase(C) ? CharToUpperCase(C) : CharToLowerCase(C);
}

string InvertStringCases(string S)
{
	for (char& C : S)
		C = InvertAlphaCase(C);

	return S;
}



int main(void)
{
	string Name = Read_Text("\n-> Enter You Name: ");
	char Char = Read_Char("-> Enter A Character: ");

	cout << "\n#######################################################\n\n";

	Name = InvertStringCases(Name);

	cout << "-> Name After Invert Cases:   " << Name << endl;

	cout << "\n#######################################################\n\n";

	Char = InvertAlphaCase(Char);

	cout << "-> Char After Invert Case:   " << Char << endl;

	cout << "\n#######################################################\n\n";


	return 0;
}