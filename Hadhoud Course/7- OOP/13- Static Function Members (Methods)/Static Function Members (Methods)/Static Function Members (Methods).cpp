#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/static-member-function-in-cpp/?ref=gcse

// Static Functions can be called at class level without a need to have an object.
// Static Functions can be called through any object as well as through the class itself.

// Static methods can only access static data members, because static methods can be called at class level without objects
// and you can't access non-static data members without having object first.

class clsX
{

public:

   static int Static_Number;
   int Non_Static_Number = 5;

   // Constructor
   clsX()
   {
      Static_Number++;
   }

   static int Fun0()
   {
      return 10;
   }

   static void Fun1(const char* MSG)
   {
      cout << MSG << endl;
      cout << "- Static_Number + Fun0() = " << Static_Number + Fun0();
   }

   void Fun2(const char* MSG)
   {
      cout << MSG << endl;
      cout << "- Non_Static_Number + Static_Number = " << Non_Static_Number + Static_Number;
   }

};

int clsX::Static_Number = 0; // initialize static data member



int main()
{
   clsX::Fun1("- Calling static method through class_name:");
   //clsX::Fun2("- Calling non-static method without object:"); // not possible
   cout << "\n\n";

   clsX Obj1;

   Obj1.Fun1("- Calling static method through object:");
   
   cout << "\n\n";

   Obj1.Fun2("- Calling non-static method through object:");

   cout << "\n\n";


   return 0;
}