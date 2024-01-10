
#include <string>
#include <iostream>

using namespace std;


//******************** PROGRAM 1 ********************************

//enum en_Operation{Addition=1, Subtraction=2, Multiplication=3, Devition=4 };
//
//void Calculator(string &Op, float &n1, float &n2)
//{
//	
//	cout << "Enter n1 (Numerator) : ";
//	cin >> n1;
//
//	cout << "Enter n2 (Denumerator) : ";
//	cin >> n2;
//	cout << "\n";
//
//	cout << "Please enter the operation?\n";
//	cout << "(1) for addition +\n";
//	cout << "(2) for subtraction -\n";
//	cout << "(3) for multiplication *\n";
//	cout << "(4) for devition /\n\n";
//	
//	cout << "you choice :";
//	cin >> Op;
//	cout << "\n" << endl;
//
//}
//
//
//int main()
//{
//
//XXX:
//
//	float n1, n2;
//	string Op;
//	Calculator(Op,n1,n2);
//
//	if (stoi(Op) == 4 && n2 == 0)
//	{
//		cout << "Devition by zero.\n\n";
//		goto XXX;
//	
//	}
//	
//
//	en_Operation Operation = (en_Operation) stoi(Op);
//
//	switch (Operation)
//	{
//	case en_Operation::Addition:
//		cout << "The answer = " << n1 + n2;
//		cout << "\n" << endl;
//		break;
//
//	case en_Operation::Subtraction:
//		cout <<"The answer = " << n1 - n2;
//		cout << "\n" << endl;
//		break;
//
//	case en_Operation::Multiplication:
//		cout <<"The answer = " << n1 * n2;
//		cout << "\n" << endl;
//		break;
//
//	case en_Operation::Devition:
//		cout <<"The answer = " << n1 / n2;
//		cout << "\n" << endl;
//		break;
//
//	default:
//		cout << "Wrong Operation." << endl;
//		goto XXX;
//	}
//
//
//	return 0;
//}



//******************************* Another solution ***************************************


//int main()
//{
//XXX:
//
//	float n1, n2;
//	string Op;
//
//	cout << "Enter n1 (Numerator) : ";
//	cin >> n1;
//
//	cout << "Enter n2 (Denumerator) : ";
//	cin >> n2;
//	cout << "\n";
//
//	cout << "Please enter the operation?\n";
//	cout << "(1) for addition (+)\n";
//	cout << "(2) for subtraction (-)\n";
//	cout << "(3) for multiplication (*)\n";
//	cout << "(4) for devition (/)\n\n";
//
//	cout << "you choice : ";
//	cin >> Op;
//	cout << "\n" << endl;
//
//
//	if (stoi(Op) == 4 && n2 == 0)
//	{
//		cout << "Devition by zero.\n\n";
//		goto XXX;
//
//	}
//
//
//	switch (stoi(Op))
//	{
//	case 1:
//		cout << "The answer = " << n1 + n2;
//		cout << "\n" << endl;
//		break;
//
//	case 2:
//		cout << "The answer = " << n1 - n2;
//		cout << "\n" << endl;
//		break;
//
//	case 3:
//		cout << "The answer = " << n1 * n2;
//		cout << "\n" << endl;
//		break;
//
//	case 4:
//		cout << "The answer = " << n1 / n2;
//		cout << "\n" << endl;
//		break;
//
//	default:
//		cout << "Wrong Operation." << endl;
//		goto XXX;
//	}
//
//
//	return 0;
//
//
//
//}



//************************* PROGRAM 2 **************************************


//int main()
//{
//
//XXX:
//
//	string day, month, year;
//
//	cout << "Please enter the day\\\n\n";
//	
//	cout << "(1) for saturday\n";
//	cout << "(2) for sunday\n";
//	cout << "(3) for monday\n";
//	cout << "(4) for tuesday\n";
//	cout << "(5) for wednesday\n";
//	cout << "(6) for thursday\n";
//	cout << "(7) for friday\n\n";
//
//	cout << "Enter the day : ";
//	cin >> day;
//	cout << "\n\n";
//
//	switch (stoi(day))
//	{
//	case 1:
//		cout << "The day is : Saturday "  << endl;
//		break;
//
//	case 2:
//		cout << "The day is : Sunday " << endl;
//		break;
//
//	case 3:
//		cout << "The day is : Monday " << endl;
//		break;
//	case 4:
//		cout << "The day is : Tuesday " << endl;
//		break;
//
//	case 5:
//		cout << "The day is : Wednesday " << endl;
//		break;
//
//	case 6:
//		cout << "The day is : Thursday " << endl;
//		break;
//
//	case 7:
//		cout << "The day is : Friday " << endl;
//		break;
//
//	default:
//
//		cout << "We have only 7 days a week where is your mind man choose again.\n" << endl;
//		goto XXX;
//	}
//
//
//
//	return 0;
//}



//******************** PROGRAM 3 *******************************************


int main()
{

XXX:

	string Month;

	cout << "Please enter the month number from {1 to 12}\\\n\n";

	cout << "(1) January\n";
	cout << "(2) February\n";
	cout << "(3) March\n";
	cout << "(4) April\n";
	cout << "(5) May\n";
	cout << "(6) June\n";
	cout << "(7) July\n";
	cout << "(8) August\n";
	cout << "(9) September\n";
	cout << "(10) October\n";
	cout << "(11) November\n";
	cout << "(12) December\n\n";

	cout << "Your Choice : ";
	cin >> Month;
	cout << "\n\n";

	switch (stoi(Month))
	{
	case 1:
		cout << "January\n" << endl;
		break;

	case 2:
		cout << "February\n" << endl;
		break;

	case 3:
		cout << "March\n" << endl;
		break;

	case 4:
		cout << "April\n" << endl;
		break;

	case 5:
		cout << "May\n" << endl;
		break;

	case 6:
		cout << "June\n" << endl;
		break;

	case 7:
		cout << "July\n" << endl;
		break;

	case 8:
		cout << "August\n" << endl;
		break;

	case 9:
		cout << "September\n" << endl;
		break;

	case 10:
		cout << "October\n" << endl;
		break;

	case 11:
		cout << "November\n" << endl;
		break;

	case 12:
		cout << "December\n" << endl;
		break;

	default:
		cout << "we have only 12 months in the year where is your mind man choose again " << endl << endl;
		cout << "********************************************************************************" << endl;
		cout << "********************************************************************************\n" << endl;
		goto XXX;
	}



	return 0;
}