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



string Trim_Left(const string& Str)
{
	if (Str != "")
	{
		ULL Str_len = Str_Size(Str);

		for (UL index = 0; index < Str_len; index++)
			if (Str[index] != ' ')
				return Substr(Str, index, Str_len); // Hadhoud said -> (Str_len - index)
	}
	return "";
}

string Trim_Right(const string& Str)
{
	if (Str != "")
	{
		ULL Str_len = Str_Size(Str);

		for (LL index = Str_len - 1; index >= 0; index--)
			if (Str[index] != ' ')
				return Substr(Str, 0, index + 1);
	}
	return "";
}

string Trim(const string& Str)
{

	return Trim_Right(Trim_Left(Str));
}

int main(void)
{
	//string S = Read_Text("\n-> Enter A String: ");
	string S;

	cout << "\n#######################################################\n\n";

	S = "  Mahmoud Gad  ";

	cout << "S Before Trim_Left = \"" << S << "\"\n\n";

	cout << "S After Trim_Left = \"" << Trim_Left(S) << "\"";

	cout << "\n\n#######################################################\n\n";

	S = "  Mahmoud Gad  ";

	cout << "S Before Trim_Right = \"" << S << "\"\n\n";

	cout << "S After Trim_Right = \"" << Trim_Right(S) << "\"";

	cout << "\n\n#######################################################\n\n";

	S = "  Mahmoud Gad  ";

	cout << "S Before Trim = \"" << S << "\"\n\n";

	cout << "S After Trim = \"" << Trim(S) << "\"";

	cout << "\n\n#######################################################\n\n";



	return 0;
}