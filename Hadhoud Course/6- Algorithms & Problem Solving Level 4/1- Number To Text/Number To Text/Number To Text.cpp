#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Trim_Right(const string& Str)
{
	if (Str != "")
	{
		unsigned long long Str_len = Str.length();

		for (long long index = Str_len - 1; index >= 0; index--)
			if (Str[index] != ' ')
				return Str.substr(0, index + 1);
	}
	return "";
}

long long Read_Int_Number(const char* Message = "")
{
	long long Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Number, Enter An Integer Number:  ";
		cin >> Number;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return Number;
}

string ReadTxt(const char* Message)
{
	string Txt;
	cout << Message;
	getline(cin >> ws, Txt);
	return Txt;
}

bool IsDigit(char C)
{
	return (C >= 48 && C <= 57);
}

bool IsDigits(const string& Str)
{
	for (const char& C : Str)
		if (!IsDigit(C))
			return false;

	return true;
}

bool isValidNumber(string Number)
{
	if (!(Number[0] == '-' || (IsDigit(Number[0]) && Number[0] != '0')))
		return false;

	Number.erase(Number.begin());

	if (!IsDigits(Number))
		return false;

	return true;
}


const string __1To9[10] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

const string __10To19[10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

const string __20To90[10] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

const string __Tags[42] = { "", "Thousand", "Million", "Billion", "Trillion", "Quadrillion", "Quintillion",
									"Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion", "Undecillion", "Duodecillion",
									"Tredecillion", "Quattuordecillion", "Quindecillion", "Sedecillion", "Septendecillion", "Octodecillion",
									"Novendecillion", "Vigintillion", "Unvigintillion", "Duovigintillion", "Tresvigintillion",
									"Quattuorvigintillion", "Quinvigintillion", "Sesvigintillion", "Septemvigintillion",
									"Octovigintillion", "Novemvigintillion", "Trigintillion", "Untrigintillion",
									"Duotrigintillion", "Trestrigintillion", "Quattuortrigintillion", "Quintrigintillion",
									"Sestrigintillion", "Septentrigintillion", "Octotrigintillion", "Noventrigintillion", "Quadragintillion" };




string NumberToTxt(long long Number)
{
	string TxtNum = "", NegativeTag = "";
	bool isNegativeNumber = false;
	vector<string> vRevTxtNum;
	unsigned short ones = 0, tens = 0, hundreds = 0, TagIndex = 0;

	if (Number < 0)
	{
		NegativeTag = "Negative";
		isNegativeNumber = true;
		Number *= -1;
	}

	while (Number > 0)
	{
		ones = Number % 10;
		Number /= 10;

		tens = Number % 10;
		Number /= 10;

		hundreds = Number % 10;
		Number /= 10;

		if (hundreds != 0)
			TxtNum += __1To9[hundreds] + " Hundred ";

		if (tens == 0)
		{
			if (ones != 0)
				TxtNum += __1To9[ones] + " ";
		}
		else if (tens == 1)
		{
			TxtNum += __10To19[ones] + " ";
		}
		else if (tens > 1)
		{
			TxtNum += __20To90[tens] + " ";

			if (ones != 0)
				TxtNum += __1To9[ones] + " ";
		}

		if (TxtNum != "")
			vRevTxtNum.push_back(TxtNum + __Tags[TagIndex]);

		TagIndex++;
		TxtNum = "";
	}

	if (vRevTxtNum.size() != 0)
	{
		if (isNegativeNumber)
			vRevTxtNum.push_back(NegativeTag); // add negative tag

		vector<string>::iterator iter = vRevTxtNum.end();

		while (iter-- != vRevTxtNum.begin())
			TxtNum += *iter + " ";

		return Trim_Right(TxtNum);
	}

	return "Zero"; // when number = 0
}




string NumberToText(string Number)
{
	if (isValidNumber(Number))
	{
		if (Number == "0")
			return "Zero";

		string TxtNum = "", NegativeTag = "";
		bool isNegativeNumber = false;
		vector<string> vRevTxtNum;
		unsigned short ones, tens, hundreds, len, TagIndex = 0;

		if (Number[0] == '-')
		{
			NegativeTag = "Negative";
			isNegativeNumber = true;
			Number.erase(Number.begin());
		}

		while ((len = Number.size()) > 0)
		{
			ones = Number[len - 1] - '0';
			Number.pop_back();

			if (len > 1)
			{
				tens = Number[len - 2] - '0';
				Number.pop_back();
			}
			else
				tens = 0;

			if (len > 2)
			{
				hundreds = Number[len - 3] - '0';
				Number.pop_back();
			}
			else
				hundreds = 0;

			if (hundreds != 0)
				TxtNum += __1To9[hundreds] + " Hundred ";

			if (tens == 0)
			{
				if (ones != 0)
					TxtNum += __1To9[ones] + " ";
			}
			else if (tens == 1)
			{
				TxtNum += __10To19[ones] + " ";
			}
			else if (tens > 1)
			{
				TxtNum += __20To90[tens] + " ";

				if (ones != 0)
					TxtNum += __1To9[ones] + " ";
			}

			if (TxtNum != "")
				vRevTxtNum.push_back(TxtNum + __Tags[TagIndex]);

			TagIndex++;
			TxtNum = "";
		}

		if (vRevTxtNum.size() != 0)
		{
			if (isNegativeNumber)
				vRevTxtNum.push_back(NegativeTag); // add negative tag

			vector<string>::iterator iter = vRevTxtNum.end();

			while (iter != vRevTxtNum.begin())
			{
				iter--;
				TxtNum += *iter + " ";
			}

			return Trim_Right(TxtNum);
		}
	}

	return "Not A Valid Number :-(";
}




int main(void)
{
	while (true)
	{
		string Number = ReadTxt("\n-> Enter An Integer Number: ");

		cout << "\n{ \"" << NumberToText(Number) << "\" }\n";
	}

	return 0;
}