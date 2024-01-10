#include <iostream>

using namespace std;



// Visibility Mode "Private" will make everything private in the derived class,
// so it can make use of it and no one will make use of it neither derived classes nor objects.


// Visibility Mode "Protected" will make everything protected in the derived class,
// so it can make use of it and all other derived classes will make use of it, but no objects will make use of it.


// Visibility Mode "Public" will inherit the class publicly so every public members and protected members are useful for others.


// Private Members in the Base Class are not accessible from outside the class nor the derived classes.




class clsA
{

private:
   int _Var1 = 100;
   void Fun1()
   {
      cout << "I'm Function[1]\n\n";
   }
protected:
   int Var2 = 200;
   void Fun2()
   {
      cout << "I'm Function[2]\n\n";
   }
public:
   int Var3 = 300;
   void Fun3()
   {
      cout << "I'm Function[3]\n\n";
   }

};



// class B inherits class A (Publicly)
class clsB : public clsA
{
public:

   void FunX()
   {
      cout << "\n\nThis is Class B - FunctionX which can access to the protected members of class A\n\n";
   }
};


// class C inherits class A (protectly)
class clsC : protected clsA
{
public:

   void FunY()
   {
      cout << "\n\nThis is Class C - FunctionY which can access to the protected members of class A\n";
   }
};


// class D inherits class A (privately)
class clsD : private clsA
{
public:
 
   void FunZ()
   {
      cout << "\n\nThis is class D - FunctionZ which can access to the protected members of class A\n";
   }
};



int main()
{
   clsA A;
   A.Fun3();

   clsB B;
   B.Fun3();
   B.FunX();

   clsC C;
   C.FunY();
   
   clsD D;
   D.FunZ();


   return 0;
}