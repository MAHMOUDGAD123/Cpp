#include <iostream>
#include <string>

using namespace std;


int main ()
{
  // copy() takes a copy of 6 characters from 5th index of str and put into buffer

  char buffer[20]{"Shit"};
  string str ("Test string...");
  size_t length = str.copy(buffer,6,5); // This returns a the number of copied characters (6) and put it in length
  cout << "str    = " << str << endl;
  cout << "Buffer = " << buffer << endl; // buffer = "string"
  buffer[length]='\0'; // length = 6
  cout << "buffer contains: " << buffer << '\n';
  return 0;
}