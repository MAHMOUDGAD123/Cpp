#include <iostream>
#include <string>

using namespace std;


// this is a structure
struct sPerson
{
   string NationalId, FirstName, LastName, Job;
   bool Marital_Status = false;

   string fullName()
   {
      return FirstName + ' ' + LastName;
   }

   string GetMaritalStatus(bool isMarried)
   {
      Marital_Status = isMarried;
      return (isMarried) ? "Married" : "Single";
   }
};



// Public & Private called -> Access Specifier
// class members:
// [1] variables called: {Attributes}
// [1] functions & procedures called: {Methods}

// this is a class
class clsStudent
{
   string UniversityId; // this variable is private by default
   bool Marital_Status = false; // this variable is private by default

private: // anything under this is private member

   string NationalId;

public: /// anything under this is public member

   string FirstName, LastName;

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
   cout << "=========================================================================\n\n";

   // everthing in the structure is public by default
   sPerson Person;
   Person.FirstName = "Mahmoud";
   Person.LastName = "Gad";
   Person.NationalId = "29709101204993";
   Person.Job = "Software Engineer";

   cout << "Person Data:\n";
   cout << "============\n\n";
   cout << "[1] Full Name     : " << Person.fullName() << '\n';
   cout << "[2] National Id   : " << Person.NationalId << '\n';
   cout << "[3] Job           : " << Person.Job << '\n';
   cout << "[4] Martial Status: " << Person.GetMaritalStatus(false) << '\n';

   cout << "\n\n=========================================================================\n\n";

   clsStudent Student;

   Student.FirstName = "Mahmoud";
   Student.LastName = "Gad";
   //Student.NationalId -> can't access
   //Student.UniversityId -> can't access
   
   cout << "Student Data:\n";
   cout << "=============\n\n";
   cout << "[1] Full Name     : " << Student.fullName() << '\n';
   cout << "[2] National Id   : " << Student.GetNationalId("29709101204993") << '\n';
   cout << "[3] University Id : " << Student.GetUniversityId("1000152612") << '\n';
   cout << "[4] Martial Status: " << Student.GetMaritalStatus(false) << '\n';
    
   cout << "\n\n=========================================================================\n\n";
}