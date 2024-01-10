#include <iostream>


// https://www.geeksforgeeks.org/virtual-destructor/
// https://www.youtube.com/watch?v=jELbKhGkEi0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=68&ab_channel=TheCherno

// we use virtual destructor to make sure that the derived class destructor get called 
// when we use pointers up-casting


class Base
{
public:
	Base() { std::cout << "Base - Constructor\n"; }

	// virual Destructor
	virtual ~Base() { std::cout << "Base - Destructor\n"; }
};



class Derived : public Base
{
public:
	Derived() { std::cout << "Derived - Constructor\n"; }
	~Derived() override { std::cout << "Derived - Destructor\n"; }
};




int main()
{
	Base* base = new Base();
	delete base;
	std::cout << "============================\n";

	Derived* derived = new Derived();
	delete derived;

	std::cout << "============================\n";
	// pointer
	Base* upcasting1 = new Derived();
	delete[] upcasting1;

}