#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <cctype>
#include <string>
#include "MGLib.h"


using namespace std;
using namespace MGLib;

using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
using L = long;
using US = unsigned short;




string Join_String(vector <string> vWords, const char* delimeter)
{
	string Str = "";

	for (const string& Substr : vWords)
		Str += (Substr + delimeter);

	return Substr(Str, 0, Str_Size(Str) - Str_Size(delimeter));
}

string Join_String(string arWords[], const US arr_len, const char* delimeter)
{
	string Str = "";

	for (US index = 0; index < arr_len; index++)
		Str += arWords[index] + delimeter;

	return Substr(Str, 0, Str_Size(Str) - Str_Size(delimeter));
}


int main(void)
{
	vector <string> Words = { "Mahmoud" , "Abdelrahman" , "Ismail" , "Abdelrahman" , "Ismail" , "Gad" };
	string arWords[] = { "Mahmoud" , "Abdelrahman" , "Ismail" , "Abdelrahman" , "Ismail" , "Gad" };
	string Str;


	cout << "\n#######################################################\n\n";

	Str = Join_String(Words, "  ");

	cout << "-> Vector After Join = \"" << Str << "\"";

	cout << "\n\n#######################################################\n\n";

	Str = "";

	Str = Join_String(arWords, 6, "  ");

	cout << "-> Array After Join  = \"" << Str << "\"";

	cout << "\n\n#######################################################\n\n";

	return 0;
}