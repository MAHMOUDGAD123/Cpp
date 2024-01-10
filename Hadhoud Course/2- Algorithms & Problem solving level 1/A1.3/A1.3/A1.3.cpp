#include <iostream>
#include <string>

using namespace std;

//************************** PROGRAM 1 *******************************
// Average pass or fail

enum en_PassOrFail{ Fail = 0, Pass = 1};

void ReadMarks(int Marks[], int& NumberOfMarks)
{
	cout << "How much marks do you have?\n";
	cout << "your answer : ";
	cin >> NumberOfMarks;
	cout << "\n\n";

	cout << "Please enter your marks\\\n\n";

	for (int i = 0; i < NumberOfMarks; i++)
	{
		cout << "Mark " << i + 1 << " : ";
		cin >> Marks[i];
		cout << "\n";
	}

}

float AverageOfMarks(int Marks[], int NumberOfMarks)
{
	float sum = 0;
	for (int i = 0; i < NumberOfMarks; i++)
	{
		sum += Marks[i];
	}

	float Average = sum / NumberOfMarks;

	return (float) Average;

}

en_PassOrFail CheckAverage(float Average)
{
	if (Average < 50)
		return en_PassOrFail::Fail;
	else
		return en_PassOrFail::Pass;

}

void PrintResult(float Average)
{
	cout << "Your average = " << Average << endl << endl;


	if (CheckAverage(Average) == en_PassOrFail::Fail)
	{
		cout << "******************\n";
		cout << "Sorry, you faild.\n";
		cout << "******************\n\n\n";
	}
	else if(CheckAverage(Average) == en_PassOrFail::Pass)
	{
		cout << "****************************\n";
		cout << "Congratulations, you Pass.\n";
		cout << "****************************\n\n\n";
	}
}


//************************** PROGRAM 2 *******************************
// Max of 2 numbers

void Read2Numbers(int& num1, int& num2)
{
	cout << "Please enter Numbers\n\n";

	cout << "Number 1 : ";
	cin >> num1;
	cout << "\n";

	cout << "Number 2 : ";
	cin >> num2;
	cout << "\n";

}

int MaxOf2Numbers(int num1, int num2)
{

	if (num1 > num2)
	{
		return num1;
	}
	else if (num1 < num2)
	{
		return num2;
	}
}


void PrintMaxOf2Numbers(int Max)
{
	cout << "The maximum number is : " << Max << endl << endl;
}


//***************************************************************************************
// Another solution to Program 2
// Get Maximum & minimum number

void ReadNumbers(int Numbers[], int& N)
{
	do 
	{
		cout << "How much numbers to compare? (Range 2-100)\n";
		cout << "your answer : ";
		cin >> N;
		cout << "\n\n";
	} while (N == 1);
	

	cout << "Please enter numbers\n\n";
	for (int i = 0; i < N; i++)
	{
		cout << "Number " << i + 1 << " : ";
		cin >> Numbers[i];
		cout << "\n";
	}
}

int MaxOfNumbers(int Numbers[], int N)
{
	int Max = Numbers[0];

	for (int i = 1; i < N; i++)
	{
		if (Numbers[i] > Max )
		{
			Max = Numbers[i];
		}
				
	}
	
	return Max;
}

int MinOfNumbers(int Numbers[], int N)
{
	int Min = Numbers[0];

	for (int i = 1; i < N; i++)
	{
		if (Numbers[i] < Min)
		{
			Min = Numbers[i];
		}

	}

	return Min;
}

void PrintMax_Min(int Max, int Min)
{
	cout << "The maximun number is : " << Max << endl << endl;
	cout << "The minimum number is : " << Min << endl << endl;
}


//************************** PROGRAM 3 *******************************
//Max of 3 Numbers

void Read3Numbers(int& A, int& B, int& C)
{
	cout << "Enter number 1 : ";
	cin >> A;
	cout << "\n";


	cout << "Enter number 2 : ";
	cin >> B;
	cout << "\n";


	cout << "Enter number 3 : ";
	cin >> C;
	cout << "\n";

}


int MaxOf3Numbers(int A, int B, int C)
{
	if (A > B)
		if (A > C)
			return A;
		else
			return C;
	else
		if (B > C)
			return B;
		else
			return C;
	
}

void PrintMaxOf3Numbers(int Max)
{
	cout << "The maximum number = " << Max << endl << endl;
}


//************************** PROGRAM 4 *******************************
//Swap 2 numbers

void Read2Numbers_ToSwap(int& N1, int& N2)
{
	cout << "Please enter 2 numbers to swap them\n";
	cout << "Number 1 : ";
	cin >> N1;
	cout << "\n";

	cout << "Number 2 : ";
	cin >> N2;
	cout << "\n";

}

void Swapping(int& A, int& B)
{
	int Temp;
	Temp = A;
	A = B;
	B = Temp;

}

void Print2numbers_Swap(int N1, int N2)
{
	cout << "The numbers now are :\n" << "- Number 1 = " << N1 << "\n- Number 2 = " << N2 << endl << endl;
}


//************************** PROGRAM 5 *******************************
// Calculate recatangle area

void ReadRectangleSides(float& L, float& W)
{
	cout << "Please enter the rectangle length?\n";
	cin >> L;

	cout << "Please enter the rectangle width?\n";
	cin >> W;

}

float RectangleArea(float L, float W)
{
	return (float) L * W;
}

void PrintRectangleArea(float Area)
{
	cout << "\nThe area of Rectangle = " << Area << endl << endl;
}





//************************************************* END *****************************************************

int main()
{
	// PROGRAM 1
	/*int NumberOfMarks = 0;
	int Marks[100];
	ReadMarks(Marks, NumberOfMarks);
	PrintResult(AverageOfMarks(Marks, NumberOfMarks));*/





	// PROGRAM 2
	/*int num1, num2;
	Read2Numbers(num1, num2);
	PrintMaxOf2Numbers(MaxOf2Numbers(num1, num2));*/

	// PROGRAM 2 another solution
	/*int N;
	int Numbers[100];
	ReadNumbers(Numbers, N);
	PrintMax_Min(MaxOfNumbers(Numbers, N), MinOfNumbers(Numbers, N));*/






	// PROGRAM 3
	/*int A, B, C;
	Read3Numbers(A, B, C);
	PrintMaxOf3Numbers(MaxOf3Numbers(A, B, C));*/






	//PROGRAM 4
	/*int N1, N2;
	Read2Numbers_ToSwap(N1, N2);
	Print2numbers_Swap(N1, N2);
	Swapping(N1, N2);
	Print2numbers_Swap(N1, N2);*/


	// PROGRAM 5
	float L, W;
	ReadRectangleSides(L, W);
	PrintRectangleArea(RectangleArea(L, W));




	return 0;
}