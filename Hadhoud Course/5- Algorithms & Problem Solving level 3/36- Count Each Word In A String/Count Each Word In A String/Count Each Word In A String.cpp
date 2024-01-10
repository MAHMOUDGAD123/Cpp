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


unsigned short Count_WordsInString(const string Str)
{
	unsigned short Str_len = Str_Size(Str);
	size_t found = 0;
	unsigned short Counter = 0;

	for (unsigned short index = 0; index < Str_len; index++)
	{
		if (Str[index] != ' ')
		{
			found = Find(Str, ' ', index); // Find first ' ' & store its index

			// Count Words
			Counter++;

			// Break the loop when Find() return (npos) which mean that we reach the end of the string
			// we can use ---> if(found > str_len)
			if (found == string::npos)
				break;

			// put --> {index = found} -- to continue from the next word
			index = found;
		}
	}
	return Counter;
}

unsigned short Count_WordsInString_Hadhoud(string Str)
{
	size_t found = 0;
	string delimiters = " "; // Something we need to ignore & use it to find words
	string Word;
	unsigned short Counter = 0;

	unsigned short delim_len = Str_Size(delimiters); // delimiters length

	// use Find() function to get the position of the delimiter
	while ((found = Find(Str, delimiters)) != string::npos)
	{
		Word = Substr(Str, 0, found); // Store Word

		if (Word != "")
			Counter++; // Count

		// Erase --> (Word & delimiters) and move to next word
		Erase(Str, 0, (found + delim_len));
	}

	if (Str != "")
		Counter++; // Count last word

	return Counter;
}



int main(void)
{
	string S = Read_Text("\n-> Enter A String: ");
	//char Char = Read_Char("\n-> Enter A Character: ");


	cout << "\n#######################################################\n\n";

	cout << "-> The Number Of Words = " << Count_WordsInString(S) << '\n';

	cout << "\n#######################################################\n\n";

	cout << "-> The Number Of Words = " << Count_WordsInString_Hadhoud(S) << '\n';

	cout << "\n#######################################################\n\n";



	return 0;
}