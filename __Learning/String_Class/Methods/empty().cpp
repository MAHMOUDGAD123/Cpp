#include <iostream>
#include <string>



using namespace std;

int main()
{
  string Fullname{""}, name{""};

  cout << endl << "___________________________________________________________________" << endl << endl;

  cout << "Enter Your FullName Name By Name, Then Press 'Enter' To Print:\n\n";

  do
  {
    getline(cin, name);
    Fullname += (!name.empty()) ? name + ' ' : "\b";
    
  } while (!name.empty());
  cout << "Your Name Is: \" " << Fullname << " \"" << endl;
  
  cout << endl << "___________________________________________________________________" << endl << endl;


  return 0;
}