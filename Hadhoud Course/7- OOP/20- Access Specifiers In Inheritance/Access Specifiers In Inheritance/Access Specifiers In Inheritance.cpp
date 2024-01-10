#include <iostream>

using namespace std;



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


class clsB : public clsA
{
public:
   int VarX = 100;
   void FunX()
   {
      cout << "I'm FunctionX\n\n";
   }

   void FunY()
   {
      cout << "\n\nThis is FunctionY which can access to the protected members of classA\n";
      cout <<"This is the protected variable2 from classA: " << clsA::Var2 << endl;
      clsA::Fun2();
   }
};



int main()
{
   clsA A;

   cout << "This Is Variable3: " << A.Var3 << endl;
   A.Fun3();
   
   clsB B;

   cout << "\n\nThis Is VariableX: " << B.VarX << endl;
   B.FunX();

   cout << "\n\nThis Is Variable3: " << B.Var3 << endl;
   B.Fun3();

   B.FunY();


   return 0;
}