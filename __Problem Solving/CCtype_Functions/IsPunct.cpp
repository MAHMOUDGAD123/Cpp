#include <iostream>
#include <string>

using namespace std;


/*
  -- Punctuation Characters --

 ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~

*/


bool IsPunct(const char &C)
{
  return ((C >= 33 && C <= 47) || (C >= 58 && C <= 64) || (C >= 91 && C <= 96) || (C >= 123 && C <= 126));
}

void Remove_Punctuation(string &S)
{
  for (short i = 0; i < S.length(); i++)
  {
    if (IsPunct(S[i])) 
      S[i] = ' ';
  }
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";


    string S("Mahmoud_Abdelrahman%Ismail+Gad");

    cout << "-> S Before Remove Punctuation Characters: " << S << endl;

    Remove_Punctuation(S);

    cout << "-> S After Remove Punctuation Characters : " << S << endl;


  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}