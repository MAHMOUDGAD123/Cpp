#include <iostream>

using namespace std;



class clsFamilyAddress
{
private:
   string _Name;
   string _AddressLine1;
   string _AddressLine2;
   string _PoBox;
   string _ZipCode;

public:

   // Constructor
   clsFamilyAddress(string Name, string AddressLine1, string AddressLine2, string PostBox, string ZipCode)
   {
      _Name = Name;
      _AddressLine1 = AddressLine1;
      _AddressLine2 = AddressLine2;
      _PoBox = PostBox;
      _ZipCode = ZipCode;
   }

   // Copy Constructor overload
   clsFamilyAddress(const clsFamilyAddress& old_obj, string Name)
   {
      _Name = Name;
      _AddressLine1 = old_obj._AddressLine1;
      _AddressLine2 = old_obj._AddressLine2;
      _PoBox = old_obj._PoBox;
      _ZipCode = old_obj._ZipCode;
   }

   void setName(string Name)
   {
      _Name = Name;
   }
   string getName()
   {
      return _Name;
   }

   void setAddressLine1(string AddressLine1)
   {
      _AddressLine1 = AddressLine1;
   }
   string getAddressLine1()
   {
      return _AddressLine1;
   }

   void setAddressLine2(string AddressLine2)
   {
      _AddressLine2 = AddressLine2;
   }
   string getAddressLine2()
   {
      return _AddressLine2;
   }

   void setPostBox(string PostBox)
   {
      _PoBox = PostBox;
   }
   string getPostBox()
   {
      return _PoBox;
   }

   void setZipCode(string ZipCode)
   {
      _ZipCode = ZipCode;
   }
   string getZipCode()
   {
      return _ZipCode;
   }

   void PrintAddress()
   {
      cout << "========================================================\n";
      cout << "Address Details:\n";
      cout << "----------------\n";
      cout << "- Name      : " << _Name << '\n';
      cout << "- Address L1: " << _AddressLine1 << '\n';
      cout << "- Address L2: " << _AddressLine2 << '\n';
      cout << "- Post Box  : " << _PoBox << '\n';
      cout << "- ZIP Code  : " << _ZipCode;
      cout << "\n========================================================\n\n";
   }

};


int main()
{
   clsFamilyAddress MGAddress("Mahmoud Gad", "Al Hanteery st - Hy Alzafaran - Mansoura", "Dakahlia - Egypt", "1234", "35511");
   MGAddress.PrintAddress();

   clsFamilyAddress MeraAddress(MGAddress, "Amira Gad");
   MeraAddress.PrintAddress();

   clsFamilyAddress MoAddress(MGAddress, "Mohammed Gad");
   MoAddress.PrintAddress();

   clsFamilyAddress MumAddress(MGAddress, "Amal Aldreeny");
   MumAddress.PrintAddress();

   clsFamilyAddress DadAddress(MGAddress, "Abdelrahman Ismail");
   DadAddress.PrintAddress();



   return 0;
}