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


string StringToUpperCase(string str)
{
	for (char& C : str)
		if (C >= 97 && C <= 122) // Check if a small letter
			C -= ' ';             // ' ' == 32
	return str;
}

string StringToLowerCase(string str)
{
	for (char& C : str)
		if (C >= 65 && C <= 90) // Check if a Capital letter
			C += ' ';			   // ' ' == 32
	return str;
}



int main(void)
{
	string Name = ReadText("\n-> Enter You Name: ");


	cout << "\n#######################################################\n\n";

	Name = StringToUpperCase(Name);

	cout << "-> Name After Uppercase:   " << Name << endl;

	cout << "\n#######################################################\n\n";

	Name = StringToLowerCase(Name);

	cout << "-> Name After Lowercase:   " << Name << endl;

	cout << "\n#######################################################\n\n";



	return 0;
}