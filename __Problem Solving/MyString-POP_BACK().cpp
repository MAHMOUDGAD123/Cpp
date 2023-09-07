#include <iostream>
#include <initializer_list>

using namespace std;

size_t Str_Size(const string &S)
{
  size_t Counter = 0;
  while (S[Counter] != '\0') Counter++;
  return Counter;
}

void Str_Pop_Back(string &Str)
{
  size_t Str_len = Str_Size(Str);

  if (Str_len > 0)
  {
    string temp_str = "";

    for (size_t i = 0; i < Str_len - 1; i++)
      temp_str += Str[i];

    Str = temp_str;
  }
}

int main()
{
  cout << endl
       << "_______________________________________________(Test 1)________________________________________________________\n\n\n";

  string G{""}; // Empty String

  cout << "-> G Before POP = \"" << G << "\"" << endl;
  cout << "-> Size Before POP = " << Str_Size(G) << endl;

  Str_Pop_Back(G);

  cout << "-> G After POP = \"" << G << "\"" << endl;
  cout << "-> Size After POP = " << Str_Size(G) << endl;

  cout << endl
       << "_______________________________________________(Test 2)________________________________________________________\n\n\n";

  G = "Mahmoud Gad";

  cout << "-> G Before POP = \"" << G << "\"" << endl;
  cout << "-> Size Before POP = " << Str_Size(G) << endl;

  Str_Pop_Back(G);
  Str_Pop_Back(G);
  Str_Pop_Back(G);
  Str_Pop_Back(G);

  cout << "-> G After POP = \"" << G << "\"" << endl;
  cout << "-> Size After POP = " << Str_Size(G) << endl;

  cout << endl
       << "_______________________________________________________________________________________________________________\n\n\n";

  return 0;
}