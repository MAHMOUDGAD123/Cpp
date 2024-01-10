#include <iostream>
#include <vector>
#include <string>



using namespace std;


int main()
{
	// vector is a Dynamic Array
	

	// Initialization
	// vector <Data_Type> Vector_Name;

	// Method(1): Initializer list
	vector <int> vNumbers1 = { 10,20,30,40,50,60 };

	// Method(2): Uniform initialization
	vector <int> vNumbers2{ 10,20,30,40,50,60 };

	// Method(3): By Size
	// (5 -> Size) & (7 -> Elements)
	vector <int> vNumbers3(5, 7); // => vector <int> vNumbers3{ 7,7,7,7,7 };

	// Using Ranged loop to print vector elements

	// This is slow don't use this way
	cout << "Numbers Of Vector = ";
	for (int Number : vNumbers1)
	{
		cout << Number << " ";
	}
	cout << endl;

	// Using Reference Is Faster
	// Because the program get the elements of vector by its address not by coping it
	cout << "Numbers Of Vector By (&) = ";
	for (int& Number : vNumbers3)
	{
		cout << Number << " ";
	}
	cout << endl;


	return 0;
}


