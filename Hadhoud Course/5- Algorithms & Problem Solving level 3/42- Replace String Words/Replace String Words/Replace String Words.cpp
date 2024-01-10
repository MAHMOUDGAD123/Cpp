#include <iostream>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



string Replace_Word(string Str, const char* old_txt, const char* new_txt)
{
	size_t found;
	unsigned short old_txt_len = Str_Size(old_txt);

	while ((found = Find(Str, old_txt)) != string::npos)
		Str = Replace(Str, found, old_txt_len, new_txt);

	return Str;
}

string Replace_Word(string Str, const string& old_txt, const string& new_txt)
{
	size_t found;
	unsigned short old_txt_len = Str_Size(old_txt);

	while ((found = Find(Str, old_txt)) != string::npos)
		Str = Replace(Str, found, old_txt_len, new_txt);

	return Str;
}

// Welcome to Jordan, Jordan is a nice country

int main(void)
{
	string Str = Read_Text("\n- Enter A String --> ");

	cout << "\n-> The String After Replace Words = \"" << Replace_Word(Str, "Jordan", "USA") << "\"\n";

	string S1 = "Jordan", S2 = "USA";

	cout << "\n-> The String After Replace Words = \"" << Replace_Word(Str, S1, S2) << "\"\n";

	return 0;
}