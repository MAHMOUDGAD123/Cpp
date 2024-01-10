#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

int main()
{
	//                   if          else
	//                 (true)       (false)
	// (condition) ? Expression1 : Expression2


	float Number = Read_Number("What is your Number?");

	cout << "Your number is: " << Number << endl << endl;

	(Number == 0) ? cout << "-> (Number = Zero)" : (Number > 0) ? cout << "-> (Number > 0)" : cout << "-> (Number < 0)";

	cout << endl;

	(Number == 0) ? (cout << "-> (Number = Zero)") : (IsPositiveNumber(Number)) ? cout << "-> (Number > 0)" : cout << "-> (Number < 0)";


	cout << endl;

	return 0;
}