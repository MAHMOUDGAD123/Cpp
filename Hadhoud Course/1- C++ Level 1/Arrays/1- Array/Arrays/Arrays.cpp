
#include <cmath>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;


int main()
{
	float Grades[3];

	cout << "Please Enter your Grades?" << endl;
	cout << "Grade 1 : ";
	cin >> Grades[0];

	cout << "Grade 2 : ";
	cin >> Grades[1];

	cout << "Grade 3 : ";
	cin >> Grades[2];


	cout << "your Grades are : " << Grades[0] << " " << Grades[1] << " " << Grades[2] << endl << endl;

	cout << "The average of you Grades = " << (Grades[0] + Grades[1] + Grades[2]) / 3 << endl;

	return 0;
}

