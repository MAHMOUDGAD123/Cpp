#include <iostream>

using namespace std;


// A constructor is a special type of member function that is called automatically when an object is created.
// In C++, a constructor has the same name as that of the class and it does not have a return type.
// Constructor:
// - should have the same name of the class
// - shouldn't return a type
// - should be public

// A constructor with no parameters is known as a default constructor created by the compiler.
// A constructor with parameters is known as a parameterized constructor - This is the preferred method to initialize member data.
// When you have a parameterized constructor it will override the default constructor.
// if you didn't write the constructor the compiler will create a default constructor for you
// A constructor is primarily used to initialize objects. They are also used to run a default code when an object is created.






class clsAddress
{
private:
   string _AddressLine1;
   string _AddressLine2;
   string _PoBox;
   string _ZipCode;

public:

   // this is Constructor
   clsAddress(string AddressLine1, string AddressLine2, string PostBox, string ZipCode)
   {
      _AddressLine1 = AddressLine1;
      _AddressLine2 = AddressLine2;
      _PoBox = PostBox;
      _ZipCode = ZipCode;
   }

   // another way to define the constructor
   /*
   
   clsAddress(string AddressLine1, string AddressLine2, string PostBox, string ZipCode) :
    _AddressLine1(AddressLine1), _AddressLine2(AddressLine2), _PoBox(PostBox), _ZipCode(ZipCode) {}
   
   */

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
      cout << "- Address L1: " << _AddressLine1 << '\n';
      cout << "- Address L2: " << _AddressLine2 << '\n';
      cout << "- Post Box  : " << _PoBox << '\n';
      cout << "- ZIP Code  : " << _ZipCode;
      cout << "\n========================================================\n";
   }

};


int main()
{
   clsAddress MyAddress("Al Hanteery st - Hy Alzafaran - Mansoura", "Dakahlia - Egypt", "1234", "35511");
   
   MyAddress.PrintAddress();

   return 0;
}