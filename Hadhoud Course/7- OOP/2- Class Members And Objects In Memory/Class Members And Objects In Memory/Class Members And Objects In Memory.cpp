#include <iostream>
#include <string>

using namespace std;


// Public & Private called -> Access Specifier
// class members:
// [1] variables called: {Attributes} or Data members
// [1] functions & procedures called: {Methods} or function members


// Each object(instance) of the class has its own space in the memory that holds only the data members (variables).
// only function members are shared among all objects in the memory and has one space for them in the memory.


// this is a class
class clsStudent
{
   // private data members by default
   string UniversityId, NationalId;
   bool Marital_Status = false;

public:

   // public data members (variables)
   string FirstName, LastName;

   // public function members (methods)
   string fullName()
   {
      return FirstName + ' ' + LastName;
   }
   string GetNationalId(string NId)
   {
      NationalId = NId;
      return NationalId;
   }
   string GetUniversityId(string UId)
   {
      UniversityId = UId;
      return UniversityId;
   }
   string GetMaritalStatus(bool isMarried)
   {
      Marital_Status = isMarried;
      return (isMarried) ? "Married" : "Single";
   }
};


int main()
{
   clsStudent Student1, Student2;

   cout << "=========================================================================\n\n";

   Student1.FirstName = "Mahmoud";
   Student1.LastName = "Gad";

   cout << "Student1 Data:\n";
   cout << "=============\n\n";
   cout << "[1] Full Name     : " << Student1.fullName() << '\n';
   cout << "[2] National Id   : " << Student1.GetNationalId("29709101204993") << '\n';
   cout << "[3] University Id : " << Student1.GetUniversityId("1000152612") << '\n';
   cout << "[4] Martial Status: " << Student1.GetMaritalStatus(false) << '\n';

   cout << "\n\n=========================================================================\n\n";

   Student2.FirstName = "Amira";
   Student2.LastName = "Gad";

   cout << "Student2 Data:\n";
   cout << "=============\n\n";
   cout << "[1] Full Name     : " << Student2.fullName() << '\n';
   cout << "[2] National Id   : " << Student2.GetNationalId("29404011208323") << '\n';
   cout << "[3] University Id : " << Student2.GetUniversityId("1000485945") << '\n';
   cout << "[4] Martial Status: " << Student2.GetMaritalStatus(false) << '\n';

   cout << "\n\n=========================================================================\n\n";
}