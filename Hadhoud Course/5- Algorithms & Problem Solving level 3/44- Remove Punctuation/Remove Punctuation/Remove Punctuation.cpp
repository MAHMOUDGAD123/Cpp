#include <iostream>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


string Remove_Punct(const string& Str)
{
	string Clean_Str = "";

	for (const char& C : Str)
		if (!IsPunct(C))
			Clean_Str += C;

	return Clean_Str;
}


int main(void)
{
	string Str = Read_Text("\n- Enter A String --> ");

	cout << "\n\n-> String After Remove Punc = " << "\"" << Remove_Punct(Str) << "\"\n\n";


	return 0;
}