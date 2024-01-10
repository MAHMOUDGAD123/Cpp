
#include <string>
#include <iostream>

using namespace std;

void ReadArrayData(int Array[100], int& Length)
{
	cout << "How many numbers do you want to enter?\n\n";
	cout << "your answer : ";
	cin >> Length;
	cout << "\n";

	for (int i = 0; i < Length; i++)
	{
		cout << "Enter Number " << i + 1 << " : ";
		cin >> Array[i];
	}

}

void PrintArrayData(int Array[100], int Length)
{
	cout << "\nYour Numbers are \\\n";
	
	for (int i = 0; i < Length; i++)
	{
		cout << "Number " << i + 1 << " = " << Array[i] << endl;
	}

	cout << "\n" << endl;
}

float SumOfArrayNumbers(int Array[100], int Length)
{
	int sum = 0;

	for (int i = 0; i < Length; i++)
	{
		sum += Array[i];
	}

	return sum;

}


float AverageOfArrayNumbers(int Array[100], int Length)
{

	return (float) SumOfArrayNumbers(Array, Length) / Length;

}




int main()
{
	int Array[100];
	int Length = 0;

	ReadArrayData(Array, Length);
	PrintArrayData(Array, Length);

	// ************************** OPTIMIZED *****************************************
	// using sum

	int sum = SumOfArrayNumbers(Array, Length);

	cout << "The Sum Of your Numbers = " << sum << endl << endl;;
	cout << "The Average of your Numbers = " << (float) sum / Length << endl << endl;

	// ************************** NOT OPTIMIZED *************************************

	cout << "The Sum Of your Numbers = " << SumOfArrayNumbers(Array, Length) << endl << endl;;
	cout << "The Average of your Numbers = " << AverageOfArrayNumbers(Array, Length) << endl << endl;


	return 0;
}


