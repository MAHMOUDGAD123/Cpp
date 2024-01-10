#define _use_math_defines

#include <string>
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

//*************************** PROGRAM 1 *****************************
// Rectangel area by one side and the diagonal

void ReadRectangleDimensions(float& a, float& d)
{
	cout << "Please enter the length?\n";
	cin >> a;
	cout << "Plese enter the diagonal?\n";
	cin >> d;
}

float RectangleArea(float a, float d)
{
	return (float) a * sqrt(pow(d, 2) - pow(a, 2));
}

void PrintRectangleArea(float Area)
{
	cout << "\n\n***********************************\n";
	cout << "The area of the Rectangle = " << Area << endl;
	cout << "***********************************\n\n";
}

//*************************** PROGRAM 2 *****************************
// Triangle area by base and height

void ReadTriangleDimensions(float& B, float& H)
{
	cout << "Please enter the triangle base?\n";
	cin >> B;
	cout << "Please enter the triangle height?\n";
	cin >> H;
}

float TriangleAreaByBaseAndHeight(float B, float H)
{
	return 0.5 * B * H;
}

void PrintTriangleArea(float Area)
{
	cout << "\n***********************************\n";
	cout << "The Area of the Triangle = " << Area << endl;
	cout << "***********************************\n\n\n";
}

//*************************** PROGRAM 3 *****************************
// Circle Area

float ReadCircleRadiousOrDiameter()
{
	char answer;
	do
	{
		cout << "How do you want to calculte the circle area?\n";
		cout << "1- by Raious\n";
		cout << "2- by Diameter\n";
		cout << "3- Circle inscribed in a square\n";
		cout << "4- by Circle circumference \n";
		cout << "5- Circle inscribed in an isosceles Triangle\n";
		cout << "6- Circle described around an arbitrary Triangle\n";


		cout << "\njust type (1 to 6)\n\n";
		cout << "your answer : ";
		cin >> answer;
		cout << "\n\n";
	}
	while (answer != '1' && answer != '2' && answer != '3' && answer != '4' && answer != '5' && answer != '6');
	
	return answer;
}

float CircleArea(char answer)
{
	const double PI = 3.1415926535897932384626433832795028841971693993;
	float D;

	if (answer == '1')
	{
		cout << "PLease enter the Radious?\n";
		cin >> D;
		return PI * pow(D, 2);
	}
	else if (answer == '2')
	{
		cout << "Please enter the Diameter?\n";
		cin >> D;
		return PI * 0.25 * pow(D, 2);
	}
	else if (answer == '3')
	{
		cout << "Please enter the Square side?\n";
		cin >> D;
		return PI * 0.25 * pow(D, 2);
	}
	else if (answer == '4')
	{
		cout << "Please enter the Curcumference of the circle?\n";
		cin >> D;
		return pow(D, 2) / (4 * PI);
	}
	else if (answer == '5')
	{
		float a, b;
		cout << "      *        \n";
		cout << "     * *           \n";
		cout << " a  *   *  a    \n";
		cout << "   *     *       \n";
		cout << "  * * * * *      \n";
		cout << "      b          \n\n";
		cout << "Please enter the Triangle side a?\n";
		cin >> a;
		cout << "Please enter the Triangle base b?\n";
		cin >> b;
		return PI * (pow(b / 2,2)) * ((2 * a - b) / (2 * a + b));
	}
	else if (answer == '6')
	{
		float a, b, c;
		cout << "                 *          \n";
		cout << "              * *        \n";
		cout << "            *  *       \n";
		cout << "     a    *   *           \n";
		cout << "        *    *   c        \n";
		cout << "      *     *         \n";
		cout << "    *      *        \n";
		cout << "  * * * * *      \n";
		cout << "       b         \n\n";
		cout << "Please enter the Triangle a?\n";
		cin >> a;
		cout << "Please enter the Triangle b?\n";
		cin >> b;
		cout << "Please enter the Triangle c?\n";
		cin >> c;

		float p = (a + b + c) / 2;

		return PI * pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2);
	}

}

void PrintCircleArea(float Area)
{
	cout << "\n\n***********************************\n";
	cout << "The area of the circle = " << Area << endl;
	cout << "***********************************\n\n\n";
}



int main()
{
	//PROGRAM 1
	/*float a, d;
	ReadRectangleDimensions(a, d);
	PrintRectangleArea(RectangleArea(a, d));*/

	// PROGRAM 2
	/*float B, H;
	ReadTriangleDimensions(B, H);
	PrintTriangleArea(TriangleAreaByBaseAndHeight(B, H));*/

	// PROGRAM 3
	//PrintCircleArea(CircleArea(ReadCircleRadiousOrDiameter()));

	//PROGRAM 4



	return 0;
}