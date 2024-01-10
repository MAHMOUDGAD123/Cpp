#include <iostream>

using namespace std;


// The copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.

// The process of initializing members of an object through a copy constructor is known as "copy initialization".
// It is also called "member-wise initialization" because the copy constructor initializes one object with the existing object,
// both belonging to the same class on a member-by-member copy basis.

// The copy constructor can be defined explicitly by the programmer.
// If the programmer does not define the copy constructor, the compiler does it for us.

// You shouldn't implement a copy constructor in your code because the compiler do that for you.

// this means that you can have more than one constructor in your class and this is called "Constructor Overloading".

// Now we have three types of constructors:
// 1- Default Constructor
// 2- Parametrized Constructor
// 3- Copy Constructor

class clsAddress
{
private:
   string _AddressLine1;
   string _AddressLine2;
   string _PoBox;
   string _ZipCode;

public:

   // Constructor (override the default constructor)
   clsAddress(string AddressLine1, string AddressLine2, string PostBox, string ZipCode)
   {
      _AddressLine1 = AddressLine1;
      _AddressLine2 = AddressLine2;
      _PoBox = PostBox;
      _ZipCode = ZipCode;
   }

   // Copy Constructor (optional)
   clsAddress(const clsAddress& old_obj)
   {
      _AddressLine1 = old_obj._AddressLine1;
      _AddressLine2 = old_obj._AddressLine2;
      _PoBox = old_obj._PoBox;
      _ZipCode = old_obj._ZipCode;
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
      cout << "- Address L1: " << _AddressLine1 << '\n';
      cout << "- Address L2: " << _AddressLine2 << '\n';
      cout << "- Post Box  : " << _PoBox << '\n';
      cout << "- ZIP Code  : " << _ZipCode;
      cout << "\n========================================================\n";
   }

};


int main()
{
   clsAddress MGAddress("Al Hanteery st - Hy Alzafaran - Mansoura", "Dakahlia - Egypt", "1234", "35511");
   cout << "=> This my address:\n";
   MGAddress.PrintAddress();

   // create a copy objects from 'MGAddress' object

   // [1] Method 1: {by assign}
   // by assign the value of 'MGAddress' to 'MeraAddress'
   clsAddress MeraAddress = MGAddress;
   cout << "\n\n=> This my sister address: (which is the same as my address)\n";
   MeraAddress.PrintAddress();


   // [2] Method 2: {by using copy constructor}
   clsAddress MoAddress(MGAddress);
   cout << "\n\n=> This my Brother address: (which is the same as my address too)\n";
   MoAddress.PrintAddress();


   return 0;
}