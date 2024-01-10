#include <iostream>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;




// ( Cs ) --> Case Sensitive
string Replace_Words_Cs(string Str, const string& old_txt, const string& new_txt)
{
	size_t found;
	unsigned short old_txt_len = Str_Size(old_txt);

	while ((found = Find(Str, old_txt)) != string::npos)
		Str = Replace(Str, found, old_txt_len, new_txt);

	return Str;
}
string Replace_Words_Cs(string Str, const char* old_txt, const char* new_txt)
{
	size_t found;
	unsigned short old_txt_len = Str_Size(old_txt);

	while ((found = Find(Str, old_txt)) != string::npos)
		Str = Replace(Str, found, old_txt_len, new_txt);

	return Str;
}

// ( NoCs ) --> No Case Sensitive
string Replace_Words_NoCs(string Str, string old_txt, string new_txt)
{
	size_t found;
	unsigned short old_txt_len = Str_Size(old_txt);

	while ((found = Find_NoCs(Str, old_txt)) != string::npos)
		Str = Replace(Str, found, old_txt_len, new_txt);

	return Str;
}
string Replace_Words_NoCs(string Str, const char* old_txt, const char* new_txt)
{
	size_t found;
	unsigned short old_txt_len = Str_Size(old_txt);

	while ((found = Find_NoCs(Str, old_txt)) != string::npos)
		Str = Replace(Str, found, old_txt_len, new_txt);

	return Str;
}

string Custome_Replace(string Str, string old_txt, string new_txt, bool Case_Sensitive = true)
{
	if (Case_Sensitive)
		return Replace_Words_Cs(Str, old_txt, new_txt);
	else
		return Replace_Words_NoCs(Str, old_txt, new_txt);
}
string Custome_Replace(string Str, const char* old_txt, const char* new_txt, bool Case_Sensitive = true)
{
	if (Case_Sensitive)
		return Replace_Words_Cs(Str, old_txt, new_txt);
	else
		return Replace_Words_NoCs(Str, old_txt, new_txt);
}


string ReplaceWordInStringUsingSplit(string Str, string old_txt, string new_txt, bool Case_Sensitive = true)
{
	vector <string> vWords = Split_String(Str, " ");

	for (string& S : vWords)
	{
		if (Case_Sensitive)
		{
			if (S == old_txt)
				S = new_txt;
		}
		else
		{
			if (StringToLowerCase(S) == StringToLowerCase(old_txt))
				S = new_txt;
		}
	}

	return Join_String(vWords, " ");
}

// Welcome to JORDAN, Jordan is a nice country

int main(void)
{
	string Str = Read_Text("\n- Enter A String --> ");

	string S1 = "jordan", S2 = "USA";

	cout << "\n\n";
	cout << "\n-> The String After Replace Words {Case_Sensitive}    = \"" << Custome_Replace(Str, S1, S2) << "\"\n";
	cout << "\n-> The String After Replace Words {No Case_Sensitive} = \"" << Custome_Replace(Str, S1, S2, false) << "\"\n";
	cout << "\n\n";

	//cout << "\n-> The String After Replace Words {Cs}   = \"" << Custome_Replace(Str, "jordan", "usa") << "\"\n";
	//cout << "\n-> The String After Replace Words {NoCs} = \"" << Custome_Replace(Str, "jordan", "usa", false) << "\"\n";

	/*cout << "\n\n";
	cout << "\n-> The String After Replace Words {Case_Sensitive}    = \"" << ReplaceWordInStringUsingSplit(Str, S1, S2) << "\"\n";
	cout << "\n-> The String After Replace Words {No Case_Sensitive} = \"" << ReplaceWordInStringUsingSplit(Str, S1, S2, false) << "\"\n";
	cout << "\n\n";*/



	return 0;
}