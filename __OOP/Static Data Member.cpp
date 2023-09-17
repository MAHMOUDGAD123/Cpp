#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/static-data-members-c/?ref=gcse

// Static Member is a variable that is shared for all objects, any object modifies it it get modified for all other objects.
// Static members are on the class level not for each object.
// Static Members are accessible from all objects.

class clsX
{
public:
  int Var = 0;
  static int Obj_Counter;

  // if you want to initialize a static member inside the class it must be constant variable
  const static int Const_Var = 1234;

  clsX()
  {
    Obj_Counter++; // to count every object
  }

  void Print(int Counter)
  {
    cout << "\n\n=> Object " << Counter << ':';
    cout << "\n- Var         = " << Var;
    cout << "\n- Obj_Counter = " << Obj_Counter;
    cout << "\n- Const_var   = " << Const_Var;
  }
};

// class static member initialization must be outside the class & before create any object from the class by any function
int clsX::Obj_Counter = 0;



int main()
{
  clsX Obj1;
  Obj1.Var = 10;
  Obj1.Print(clsX::Obj_Counter);

  clsX Obj2;
  Obj2.Var = 20;
  Obj2.Print(clsX::Obj_Counter);

  clsX Obj3;
  Obj3.Var = 30;
  Obj3.Print(clsX::Obj_Counter);

  clsX Obj4;
  Obj4.Var = 40;
  Obj4.Print(clsX::Obj_Counter);

  clsX Obj5;
  Obj5.Var = 50;
  Obj5.Print(clsX::Obj_Counter);

  return 0;
}