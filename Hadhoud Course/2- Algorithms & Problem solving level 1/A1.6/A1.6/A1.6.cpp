#include <iostream>
#include <string>
#include <cmath>



using namespace std;



int ReadNumber()
{
	int N;
	cout << "Please enter any number?\n";
	cin >> N;

	return N;
}



// ***************************** PROGRAM 1 *********************************
// Print numbers form 1 to N





// Using For Loop
void PrintNumbersForm_1_to_N_UsingForLoop(int N)
{
	cout << "\nUsing For Loop :\n";
	cout << "*********************\n";
	cout << "Your numbers are :\n";
	cout << "*********************\n";
	for (int i = 1; i <= N; i++)
	{
		cout << i << "\n";
	}

	cout << "************************\n";;
}

// Using While Loop
void PrintNumbersForm_1_to_N_UsingWhileLoop(int N)
{
	cout << "\nUsing While Loop :\n";
	cout << "*********************\n";
	cout << "Your numbers are :\n";
	cout << "*********************\n";
	int i = 1;
	while (i <= N)
	{
		cout << i << "\n";
		i++;
	}
	

	cout << "************************\n";;
}

// Using Do-While Loop
void PrintNumbersForm_1_to_N_UsingDo_WhileLoop(int N)
{
	cout << "\nUsing Do-While Loop :\n";
	cout << "*********************\n";
	cout << "Your numbers are :\n";
	cout << "*********************\n";
	int i = 1;
	do 
	{
		cout << i << "\n";
		i++;

	} while (i <= N);
	


	cout << "************************\n";;
}





// ***************************** PROGRAM 2 *********************************
// Print Numbers From N to 1




// Using For Loop
void PrintNumbersForm_N_to_1_UsingForLoop(int N)
{
	cout << "\nUsing For Loop :\n";
	cout << "*********************\n";
	cout << "Your numbers are :\n";
	cout << "*********************\n";
	for (int i = N; i >= 1; i--)
	{
		cout << i << "\n";
	}

	cout << "************************\n";;
}

// Using While Loop
void PrintNumbersForm_N_to_1_UsingWhileLoop(int N)
{
	cout << "\nUsing While Loop :\n";
	cout << "*********************\n";
	cout << "Your numbers are :\n";
	cout << "*********************\n";
	int i = N;
	while (i >= 1)
	{
		cout << i << "\n";
		i--;
	}

	cout << "************************\n";;
}

// Using Do-While Loop
void PrintNumbersForm_N_to_1_UsingDo_WhileLoop(int N)
{
	cout << "\nUsing Do-While Loop :\n";
	cout << "*********************\n";
	cout << "Your numbers are :\n";
	cout << "*********************\n";
	int i = N;
	do
	{
		cout << i << "\n";
		i--;

	} while (i >= 1);



	cout << "************************\n";;
}




//**************************************************************************

enum en_OddOrEven { Odd = 1, Even = 2 };

en_OddOrEven Check_NumberOddOrEven(int N)
{
	if (N % 2 == 0)
		return en_OddOrEven::Even;
	else
		return en_OddOrEven::Odd;

}


// ***************************** PROGRAM 3 *********************************
// Add odd numbers from 1 to N




// Using for Loop
void PrintOddNumbersFrom_1_to_N_UsingForLoop(int N)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if(Check_NumberOddOrEven(i) == en_OddOrEven::Odd)
		sum += i;
	}

	cout << "The sum of odd numbers (using for loop) = " << sum << endl << endl;
}

// Using While Loop
void PrintOddNumbersFrom_1_to_N_UsingWhileLoop(int N)
{
	int i = 1;
	int sum = 0;
	while (i <= N)
	{
		if (Check_NumberOddOrEven(i) == en_OddOrEven::Odd)
		{
			sum += i;
			
		}
		i++;
	}

	cout << "The sum of odd numbers (using While loop) = " << sum << endl << endl;
}

// Using Do-While Loop
void PrintOddNumbersFrom_1_to_N_UsingDoWhileLoop(int N)
{
	int i = 1;
	int sum = 0;

	do
	{
		if (Check_NumberOddOrEven(i) == en_OddOrEven::Odd)
		{
			sum += i;
			
		}
		i++;

	} while (i <= N);
	
	cout << "The sum of odd numbers (using Do-While loop) = " << sum << endl << endl;
}





// ***************************** PROGRAM 4 *********************************
// Add even numbers from 1 to N




// Using for Loop
void PrintEvenNumbersFrom_1_to_N_UsingForLoop(int N)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if(Check_NumberOddOrEven(i) == en_OddOrEven::Even)
		sum += i;
	}

	cout << "The sum of even numbers (using for loop) = " << sum << endl << endl;
}

// Using While Loop
void PrintEvenNumbersFrom_1_to_N_UsingWhileLoop(int N)
{
	int i = 0;
	int sum = 0;
	while (i <= N)
	{
		if (Check_NumberOddOrEven(i) == en_OddOrEven::Even)
		{
			sum += i;
		}
		i++;
	}

	cout << "The sum of even numbers (using While loop) = " << sum << endl << endl;
}

// Using Do-While Loop
void PrintEvenNumbersFrom_1_to_N_UsingDoWhileLoop(int N)
{
	int i = 1;
	int sum = 0;

	do
	{
		if (Check_NumberOddOrEven(i) == en_OddOrEven::Even)
		{
			sum += i;
		}
		i++;

	} while (i <= N);

	cout << "The sum of even numbers (using Do-While loop) = " << sum << endl << endl;
}



//**************************************************************************



// ***************************** PROGRAM 5 *********************************
// Add (all - odd - even ) numbers from 1 to N (using for loop)


bool MakeSureThatInputIs_0_1_2(string Answer)
{
	if (Answer == "0" || Answer == "1" || Answer == "2" )
		return true;
	else
		return false;
}

int Choose()
{
	string Answer;

	do 
	{
		cout << "What to Add from 1 to N?\n";
		cout << "(0) All numbers\n";
		cout << "(1) Odd numbers\n";
		cout << "(2) Even numbers\n";
		cout << "your answer : ";
		cin >> Answer;
		cout << "\n\n";

	} while (!MakeSureThatInputIs_0_1_2(Answer));



	return stoi(Answer);

}

enum en_AddAll_Odd_even { _All = 0, _Odd = 1, _Even = 2 };

en_AddAll_Odd_even CheckAdd_AllorOddorEven()
{

	if (Choose() == 0)
		return en_AddAll_Odd_even::_All;

	else if (Choose() == 1)
		return en_AddAll_Odd_even::_Odd;

	else if (Choose() == 2)
		return en_AddAll_Odd_even::_Even;


}

int SumAll_Odd_even(int N)
{
	int sum = 0;

	if (CheckAdd_AllorOddorEven() == en_AddAll_Odd_even::_All)
	{
		for (int i = 1; i <= N; i++)
		{
			sum += i;
		}
		return sum;
		
	}
		
	if (CheckAdd_AllorOddorEven() == en_AddAll_Odd_even::_Odd)
	{
		for (int i = 1; i <= N; i++)
		{
			if (Check_NumberOddOrEven(i) == en_OddOrEven::Odd)
				sum += i;
		}
		return sum;
	}
		

	if (CheckAdd_AllorOddorEven() == en_AddAll_Odd_even::_Even)
	{
		for (int i = 1; i <= N; i++)
		{
			if (Check_NumberOddOrEven(i) == en_OddOrEven::Even)
				sum += i;
		}
		return sum;
	}

	 
	
	
}


// ***************************** PROGRAM 6 *********************************
//Factorial of N

int ReadAPossitiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while(Number < 0);

	return Number;
}

int Factorial(int N)
{
	int Factorial = 1;

	for(int i = N; i > 1; i--)
	{
		Factorial *= i;
	}

	return Factorial;
}


//**************************************************************************
//**************************************************************************


int main()
{
	//int N = ReadNumber();

	//PROGRAM 1
	//PrintNumbersForm_1_to_N_UsingForLoop(N);
	//PrintNumbersForm_1_to_N_UsingWhileLoop(N);
	//PrintNumbersForm_1_to_N_UsingDo_WhileLoop(N);


	//PROGRAM 2
	//PrintNumbersForm_N_to_1_UsingForLoop(N);
	//PrintNumbersForm_N_to_1_UsingWhileLoop(N);
	//PrintNumbersForm_N_to_1_UsingDo_WhileLoop(N);


	//PROGRAM 3
	//PrintOddNumbersFrom_1_to_N_UsingForLoop(N);
	//PrintOddNumbersFrom_1_to_N_UsingWhileLoop(N);
	//PrintOddNumbersFrom_1_to_N_UsingDoWhileLoop(N);


	//PROGRAM 4
	//PrintEvenNumbersFrom_1_to_N_UsingWhileLoop(N);
	//PrintEvenNumbersFrom_1_to_N_UsingWhileLoop(N);
	//PrintEvenNumbersFrom_1_to_N_UsingDoWhileLoop(N);



	//PROGRAM 5
	//cout << "The sum = " << SumAll_Odd_even(N) << endl;
	

	//PROGRAM 6
	//cout << "The factorial = " << Factorial(ReadAPossitiveNumber("Please, Enter a Positive Number?")) << endl << endl;




	return 0;
}