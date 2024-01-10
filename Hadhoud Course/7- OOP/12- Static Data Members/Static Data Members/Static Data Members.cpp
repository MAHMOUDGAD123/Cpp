#include <iostream>

using namespace std;


// https://www.geeksforgeeks.org/static-data-members-c/?ref=gcse

// Static Member is a variable that is shared for all objects, any object modifies it it get modified for all other objects.
// Static members are on the class level not for each object.
// Static Members are accessible from all objects.
// Static Members must be public.
// we can say that the static data member is a global variable for all objects from the class


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

	void Print()
	{
		cout << "\n- Var         = " << Var;
		cout << "\n- Obj_Counter = " << Obj_Counter;
		cout << "\n- Const_var   = " << Const_Var;
		cout << "\n\n";
	}

};

// class static member initialization must be outside the class
int clsX::Obj_Counter = 0;


int main()
{
	clsX Obj1;
	clsX Obj2; 
	clsX Obj3;
	clsX Obj4;
	clsX Obj5;

	Obj1.Var = 10;
	Obj2.Var = 20;
	Obj3.Var = 30;
	Obj4.Var = 40;
	Obj5.Var = 50;

	Obj1.Print();
	Obj2.Print();
	Obj3.Print();
	Obj4.Print();
	Obj5.Print();

	// if we change the value of the static member 'Obj_Counter' in one object this will change its value for all objects.

	Obj1.Obj_Counter = 1997; // or clsX::Obj_Counter = 1997;
	Obj1.Var = 100;

	cout << "\n\n---------------------------------------------------";
	cout << "\n- Obj_Counter after update its value in one object:";
	cout << "\n---------------------------------------------------";

	Obj1.Print();
	Obj2.Print();
	Obj3.Print();
	Obj4.Print();
	Obj5.Print();



	return 0;
}