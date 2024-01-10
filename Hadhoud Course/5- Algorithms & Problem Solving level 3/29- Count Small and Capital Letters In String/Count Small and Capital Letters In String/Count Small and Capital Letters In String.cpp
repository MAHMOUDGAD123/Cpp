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


enum en_WhatToCount { Capital_Alpha = 0, Small_Alpha = 1, All_Alpha = 3 };

unsigned short CountCapitalAlpha(const string S)
{
	unsigned short Counter = 0;

	for (const char& C : S)
		if (IsUpperCase(C))
			Counter++;

	return Counter;
}

unsigned short CountSmallAlpha(const string S)
{
	unsigned short Counter = 0;

	for (const char& C : S)
		if (IsLowerCase(C))
			Counter++;

	return Counter;
}

unsigned short CountAlpha(const string S)
{
	unsigned short Counter = 0;

	for (const char& C : S)
		if (IsAlphaChar(C))
			Counter++;

	return Counter;
}

unsigned short CustomAlphaCount(const string S, en_WhatToCount WhatToCount = All_Alpha)
{
	switch (WhatToCount)
	{
	case Capital_Alpha:
		return CountCapitalAlpha(S);
	case Small_Alpha:
		return CountSmallAlpha(S);
	case All_Alpha:
		return CountAlpha(S);
	}
}




int main(void)
{
	string S = Read_Text("\n-> Enter A String: ");

	cout << "\n#######################################################\n\n";

	cout << "-> The String Size-------------------= " << String_Size(S) << endl; // The Full Size

	cout << "-> No. Alphabet Characters-----------= " << CustomAlphaCount(S) << endl; // All Alpha 'Default'

	cout << "-> No. Capital Alphabet Characters---= " << CustomAlphaCount(S, Capital_Alpha) << endl; // Capital Alpha

	cout << "-> No. Small Alphabet Characters-----= " << CustomAlphaCount(S, Small_Alpha) << endl; // Small Alpha

	cout << "\n#######################################################\n\n";


	return 0;
}