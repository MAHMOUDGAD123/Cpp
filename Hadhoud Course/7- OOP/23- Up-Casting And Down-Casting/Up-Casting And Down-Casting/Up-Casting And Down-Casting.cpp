#include <iostream>

using namespace std;


// It is the process to create the derived class's pointer or reference from the base class's pointer or reference,
// and the process is called Upcasting.
// It means the upcasting used to convert the reference or pointer of the derived class to a base class.

// The Downcasting is an opposite process to the upcasting,
// which converts the base class's pointer or reference to the derived class's pointer or reference.
// It manually cast the base class's object to the derived class's object, so we must specify the explicit typecast. 

// Upcasting is safe casting as compare to downcasting.


// A pointer of type parent can point to an object of child class,
// because all members in which the pointer can access are exist in memory when the object is of child class.

// A pointer of type child can't point to an object of parent class,
// because all members in which the pointer can access do not exist in memory when the object is of parent class.

// you should use up_casting only


class clsParent
{
public: void pPrint() { cout << "This is parent class Print function\n\n"; }
};

class clsChild1 : public clsParent
{
public: void cPrint() { cout << "This is child1 class Print function\n\n"; }
};

class clsChild2 : public clsParent
{
public: void cPrint() { cout << "This is child2 class Print function\n\n"; }
};


int main()
{
	clsParent Parent;
	clsChild1 Child1;
	clsChild1 Child2;

	//================================= Up-casting ==========================================

	cout << "Up-Casting:";
	cout << "\n-----------\n\n";

	clsParent* ptrParent;

	// up-casting can be done using (implicit or explicit) type-casting
	// convert Child1 to Parent

	// pointer implicit casting
	ptrParent = &Child1;
	ptrParent->pPrint();

	// pointer explicit casting
	ptrParent = (clsParent*)&Child2;
	ptrParent->pPrint();


	// reference implicit casting
	clsParent& refParent = Child1;
	refParent.pPrint();

	// reference explicit casting
	refParent = (clsParent&)Child2;
	refParent.pPrint();

	//=================================== Down-casting ======================================

	cout << "\nDown-Casting:";
	cout << "\n-------------\n\n";

	clsChild1* ptrChild1;

	// down-casting done only using (explicit) type-casting
	// Convert Parent to Child

	ptrChild1 = (clsChild1*)&Parent;
	
	ptrChild1->pPrint();
	ptrChild1->cPrint();

	clsChild2& refChild2 = (clsChild2&)Parent;

	refChild2.pPrint();
	refChild2.cPrint();


	return 0;
}