#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
#include<math.h>

using namespace std;


short sum(short a, short b)
{
	short sum = 0;
	sum = a + b;

	return sum;
}

short sub(short a, short b)
{
	short sub = 0;
	sub = a - b;

	return sub;
}


int main()
{
	short arr[5] = { 1, 2, 3, 4, 5 };

	short a = 10, b = 20;

	short c = sum(a, b);

	cout << "c = " << c << endl;

	for (short i = 1; i <= 5; i++)
	{
		a = 2 * a + i;
		b = b + i;
	}
	cout << "c = " << sum(a, b) << endl;
	cout << endl << endl;


	for (short i : arr) // for-each loop
	{
		a = a + i;
	}

	c = sub(a, b);

	cout << "c = " << c << endl;
	cout << endl << endl; 





	string Name = "";

	Name = "My name is mahmoud abdelrahman ismail gad";

	for (short i = 0; i < Name.length(); i++)
	{
		cout << Name[i];
	}
	cout << endl << endl;

	for (char i : Name)
	{
		cout << i;
	}
	cout << endl << endl;

	return 0;
}
