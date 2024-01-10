#include <iostream>

using namespace std;


class clsPerson
{
private:

   struct sAddress
   {
      string _AddressLine;
      string _City;
      string _Country;
   };

   string _FullName;
   sAddress Address;

public:

   clsPerson(string FN, string AL, string City, string Countery)
   {
      _FullName = FN;
      Address._AddressLine = AL;
      Address._City = City;
      Address._Country = Countery;
   }

   void PrintAddress()
   {
      cout << "Address:\n";
      cout << "--------\n";
      cout << "Address Line-> " << Address._AddressLine << '\n';
      cout << "City-> " << Address._City << '\n';
      cout << "Country-> " << Address._Country << '\n';
   }

   void PrintInfo()
   {
      cout << "\n\nPerson Info:\n";
      cout << "------------\n";
      cout << "FullName-> " << _FullName << '\n';
      cout << "Address-> " << Address._AddressLine;
      cout << " - " << Address._City;
      cout << " - " << Address._Country << '\n';
   }

};


int main()
{
   clsPerson Person("Mahmoud Abdelrahman Ismail Gad", "Alhantery st - Mansoura Qism 1", "Mansoura", "Egypt");

   Person.PrintAddress();

   Person.PrintInfo();


   return 0;
}