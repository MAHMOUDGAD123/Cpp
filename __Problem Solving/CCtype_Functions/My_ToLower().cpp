#include <iostream>
#include <string>
#include <cctype> // Needed

using namespace std;

constexpr int to_lower(int _ch)
{
  return (_ch >= 65 && _ch <= 90) ? _ch + ' ' : _ch;
}

constexpr int _to_lower(int _ch)
{ // for alpha chars only
  return _ch | ' ';
}

void str_tolower(string &str)
{ 
  for (char &C : str) C = to_lower(C);
}

int main()
{
  string S{"HOODA.GAD333@GMAIL.COM"};

  cout << "\n_______________________________________________(1)_______________________________________________\n\n\n";

  cout << "-> S Before Lowering = " << S << endl;
  str_tolower(S);
  cout << "-> S After Lowering  = " << S << endl;

  cout << "\n_______________________________________________(2)_______________________________________________\n\n\n";

  cout << (char)to_lower('a') << endl;

  cout << (char)to_lower('A') << endl;

  cout << (char)to_lower('9') << endl;

  cout << (char)to_lower('@') << endl;

  cout << "\n_______________________________________________(3)_______________________________________________\n\n\n";

  string G("MAHMOUD_GAD1997");

  cout << "G before = " << G << "\n";

  for (char &c : G)
    c = to_lower(c);

  cout << "-> G After = " << G << endl;

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  string X("MAHMOUD_GAD1997");
  
  cout << "X before = " << X << "\n";

  for (char &c : G)
    c = _to_lower(c);

  cout << "-> X After = " << G << endl;

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}