#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// for more about stringstream:
// https://cplusplus.com/reference/sstream/

int CountWords(const string& Str)
{
  // Breaking input into word
  // using stringstream

  // Used for breaking words
  stringstream ss(Str);

  // To store individual words
  string word;

  int Counter = 0;

  while (ss >> word)
    Counter++;

  return Counter;
}

double StringToNumber(const string& Str)
{
  // we can use method [1] or method [2]
  // to add the Str to stringstream

  // stringstream ss(Str); // method [1]
  // ss << Str;            // method [2]
  // then read from stream : ss >> N;

  int N;
  stringstream(Str) >> N; // method [3] add & read in one line
  return N;
}

string NumberToString(double N)
{
  stringstream ss;
  string Str;

  ss << N;
  ss >> Str;
  return Str;
}

vector<string> String_Split(const string& Str)
{
  stringstream ss(Str); // used for breaking words
  vector<string> vWords;
  string Word;

  while (ss >> Word)
    vWords.push_back(Word);

  return vWords;
}




int main(void)
{
  cout << "\n\n"
       << StringToNumber("10") + StringToNumber("10"); // strings
  cout << "\n\n"
       << NumberToString(10.5) + " + " + NumberToString(10.5) + " = " + NumberToString(10.5 + 10.5); // Numbers
  cout << "\n\n"
       << to_string(10.5) + " + " + to_string(10.5) + " = " + to_string(10.5 + 10.5); // Numbers

  //============================================================

  stringstream ss;
  int day, month, year;

  ss << 10 << ' ' << 9 << ' ' << 1997;
  ss >> day >> month >> year;

  cout << "\n\nMy Birth Date Is: " << day << '/' << month << '/' << year << "\n\n";

  //============================================================

  cout << "Number Of Words = " << CountWords("Mahmoud Abdelrahman Ismail Gad") << "\n\n";

  //============================================================

  vector<string> vWords = String_Split("Mahmoud Abdelrahman Ismail Gad");

  cout << "\n\n- Words Are:\n";
  for (const string& S : vWords)
    cout << S << '\n';

  cout << "\n\n";

  return 0;
}