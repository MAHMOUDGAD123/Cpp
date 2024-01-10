#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



double Read_Number() {

	double Number = 0;

	cout << "Please, Enter A Number:--> ";
	cin >> Number;
	cout << endl;
	
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid Number, Enter a valid Number: --> ";
		cin >> Number;
		cout << endl;
	}
	cout << endl;


	return Number;
}




int main()
{
	double Number = Read_Number();

	cout << "- Your number is --> " << setprecision(7) << Number << endl;




	return 0;
}