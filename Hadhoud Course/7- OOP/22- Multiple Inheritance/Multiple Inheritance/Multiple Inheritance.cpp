#include <iostream>

using namespace std;


/*
- syntax of multiple-inheritance:
   
   class [derived-class name] : <visibility mode> [base-class1 name] , <visibility mode> [base-class2 name] , ..........
   {
   };

*/

// we shouldn't use multiple-inheritance because it has alot of problems.


class clsA
{
private:
   void fun1()
   {
      cout << "\n\nThis is class A - function 1\n\n";
   }

protected:
   void fun2()
   {
      cout << "\n\nThis is class A - function 2\n\n";
   }

public:
   void fun3()
   {
      cout << "\n\nThis is class A - function 3\n\n";
   }

};


class clsB
{
   void fun4()
   {
      cout << "\n\nThis is class B - function 4\n\n";
   }

protected:
   void fun5()
   {
      cout << "\n\nThis is class B - function 5\n\n";
   }

public:
   void fun6()
   {
      cout << "\n\nThis is class B - function 6\n\n";
   }
};


class clsC
{
   void fun7()
   {
      cout << "\n\nThis is class C - function 7\n\n";
   }

protected:
   void fun8()
   {
      cout << "\n\nThis is class C - function 8\n\n";
   }

public:
   void fun9()
   {
      cout << "\n\nThis is class C - function 9\n\n";
   }
};


// class X inherits -> class A,B,C at the same time
class clsX : public clsA, public clsB, public clsC
{

public:
   void funX()
   {
      cout << "\n\nThis is class X that inherits class A,B,C at the same time.\n\n";
   }

};






int main()
{
   clsX X;

   X.fun3();
   X.fun6();
   X.fun9();
   X.funX();

   return 0;
}