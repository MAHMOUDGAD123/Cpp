#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <cctype>
#include <string>
#include <string_view>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

template<typename T>
void vPrint(const vector <T>& Words) { for (const T& W : Words) std::cout << "\"" << W << "\"" << endl; }



std::vector<std::string> _split_str(const std::string& S)
{
	if (S.empty()) return {};

	std::vector<std::string> Words;
	std::stringstream ss(S);
	std::string _x_;

	while (ss >> _x_) Words.push_back(_x_);
	return Words;
}

std::vector<std::string> __split_str(const std::string& _Str) {
	if (_Str.empty()) return {};

	vector<string> tokens;
	tokens.reserve(std::count(_Str.cbegin(), _Str.cend(), ' ') + 1);

	string::size_type start(0), end(0), len(_Str.size());

	while ((end = _Str.find(' ', start)) != string::npos) {
		if (end != start) tokens.push_back(_Str.substr(start, end - start));
		start = end + 1;
	}

	if (len != start) tokens.push_back(_Str.substr(start));
	return tokens;
}

std::vector<std::string_view> ___split_str(const std::string& _Str, std::string_view delim = " ") {
	if (_Str.empty()) return {};

	std::vector<std::string_view> Words;

	std::string::size_type delim_len(delim.size()), len(_Str.size()), start(0), end(0);

	while ((end = _Str.find(delim, start)) != std::string::npos) {
		if (end != start) Words.push_back({ _Str.c_str() + start, end - start }); // Store word
		start = end + delim_len;
	}

	if (len != start) Words.push_back({ _Str.c_str() + start, len - start });

	return Words;
}



std::vector<std::string_view> split_str(const std::string& _Str, std::string_view delim = " ") {
	if (_Str.empty()) return {};

	std::vector<std::string_view> Words;

	size_t delim_len(delim.size()), len(_Str.size()), idx(0), found(0);

	for (; (found = _Str.find(delim, idx)) != std::string::npos; idx = found + delim_len) {
		// if (found == idx) this means that the word is empty ""
		if (found != idx) Words.push_back({ _Str.c_str() + idx, found - idx }); // Store word
	}

	// Store the last word if not ""
	if (len != idx) Words.push_back({ _Str.c_str() + idx, len - idx });

	return Words;
}



vector <string> Split_String_Hadhoud(string Str, const char* const delimiter = " ")
{
	vector <string> Words;
	size_t found = 0;
	string Word;
	uint16_t delim_len = (uint16_t)Str_Size(delimiter); // delimiters length

	// use Find() function to get the position of the delimiter
	while ((found = Str.find(delimiter)) != string::npos)
	{
		Word = Str.substr(0, found); // Store Word

		if (Word != "")
			Words.push_back(Word); // store in vector

		// Erase --> (Word & delimiters) and move to next word
		Str.erase(0, (found + delim_len));
	}

	if (Str != "")
		Words.push_back(Str); // Store last word

	return Words;
}




int main(void)
{

	vector <std::string_view> Words;
	vector <std::string> vWords;


	std::string S("Mr.   Mohammed   Abu-Hadhoud  ");
	//std::string S("   ");

	vWords = __split_str(S);

	std::cout << "-> Tokens = " << vWords.size() << endl;
	std::cout << "\n-> Stored Words Are:\n\n";
	vPrint(vWords);


	return 0;
}