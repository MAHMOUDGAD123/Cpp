#include "Shannon_Fano_Class.h"

#define print cout
#define out <<

string _Read_Str()
{
  string S;
  cout << "\nEnter A Text:  ";
  getline(cin, S);
  return S;
}

int main()
{
  string S(_Read_Str());
  // string Str = "AAAAAAAAAAAAAAABBBBBBBCCCCCCDDDDDDEEEEE";
  // string Str("Mohammed Gad");
  
  // string Str("AAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
  // string Str("AAAAAAAAAAAAAAAA");

  Shannon_Fano Test(S);

  print out "\n\n\tThe Input String: " 
        out S
        out "\n\n";
        
  Test.Run();

  

  return 0;
}