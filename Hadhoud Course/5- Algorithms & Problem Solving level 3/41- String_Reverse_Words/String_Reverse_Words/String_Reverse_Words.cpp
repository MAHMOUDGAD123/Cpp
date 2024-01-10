#include <iostream>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



vector <string> Split(const string& Str, const char* delim)
{
	vector <string> Words;
	size_t found = 0;
	size_t Str_len = Str_Size(Str);
	unsigned short delim_len = Str_Size(delim);

	for (unsigned short index = 0; index < Str_len; index++)
	{
		// Find first delimiter & store its index
		if ((found = Find(Str, delim, index)) != string::npos)
		{
			// if (found == index) this means that the word that we will store is empty ""
			if (found != index)
				Words.push_back(Substr(Str, index, found - index)); // Store word

			// to continue from the next word
			index = found + delim_len - 1;
		}
		else
		{
			// Store the last word and break loop
			Words.push_back(Substr(Str, index, Str_len - 1));
			break;
		}
	}
	return Words;
}

string Reverse_String_Words(const string& Str)
{
	if (Str == "")
		return "";

	vector <string> vWords = Split(Str, "  ");
	vector <string>::iterator iter = vWords.end();
	string Rev_Str = "";

	while (iter != vWords.begin())
	{
		iter--;

		Rev_Str += *iter + ' ';
	}

	return Rev_Str.substr(0, Rev_Str.length() - 1); // remove the last ' '
}



int main(void)
{
	string Str = Read_Text("- Enter A String --> ");


	cout << "\n-> The String After Reverse Words = \"" << Reverse_String_Words(Str) << "\"\n";

	return 0;
}