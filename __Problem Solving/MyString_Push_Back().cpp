#include <iostream>

using namespace std;

size_t Str_Size(const string &S)
{
  size_t Counter{0};
  while (S[Counter] != '\0') Counter++;
  return Counter;
}

void Str_Push_Back(string &Str, const char Char)
{
  // Add 'Char' at the end of "Str"
  Str += Char;
}

int main()
{
  // cout << "\n_______________________________________________(Test 1)________________________________________________________\n\n\n";

  string G{"Mahmoud"}; // Empty String

  cout << "\nC++ Push_Back:\n";
  cout << "\"" << G << "\"" << endl;
  cout << "- Size Before = " << Str_Size(G) << endl;
  G.push_back(60);
  cout << "\"" << G << "\"" << endl;
  cout << "- Size After = " << Str_Size(G) << endl;

  G = "Mahmoud";

  cout << "\nMy Push_Back:\n";
  cout << "\"" << G << "\"" << endl;
  cout << "- Size Before = " << Str_Size(G) << endl;
  Str_Push_Back(G, 60);
  cout << "\"" << G << "\"" << endl;
  cout << "- Size After = " << Str_Size(G) << endl;

  // cout << "-> G Before Push = \"" << G << "\"" << endl;
  // cout << "-> Size Before Push = " << Str_Size(G) << endl;

  // Str_Push_Back(G);

  // cout << "-> G After Push = \"" << G << "\"" << endl;
  // cout << "-> Size After Push = " << Str_Size(G) << endl;

  // cout << endl
  //      << "_______________________________________________(Test 2)________________________________________________________\n\n\n";

  // G = "Mahmoud Gad";

  // cout << "-> G Before Push = \"" << G << "\"" << endl;
  // cout << "-> Size Before Push = " << Str_Size(G) << endl;

  // Str_Push_Back(G);
  // Str_Push_Back(G);
  // Str_Push_Back(G);
  // Str_Push_Back(G);

  // cout << "-> G After Push = \"" << G << "\"" << endl;
  // cout << "-> Size After Push = " << Str_Size(G) << endl;

  // cout << endl
  //      << "_______________________________________________________________________________________________________________\n\n\n";

  // return 0;
}