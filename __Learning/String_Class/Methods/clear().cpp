#include <iostream>
#include <string>



using namespace std;

int main()
{
  string S{""};
  char c;

  cout << endl << "___________________________________________________________________" << endl << endl;

  cout << "Please type some lines of text. Enter a dot (.) to finish:\n";
  do 
  {
    c = cin.get();
    S += c;
    if (c =='\n')
    {
      cout << S;
      S.clear();
    }
  } while (c != '.');

  cout << S << endl;

  cout << endl << "___________________________________________________________________" << endl << endl;


  return 0;
}