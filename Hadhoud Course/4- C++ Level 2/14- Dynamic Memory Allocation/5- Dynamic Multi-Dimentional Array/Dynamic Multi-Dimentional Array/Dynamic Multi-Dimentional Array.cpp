#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;


// Code Beauty --> https://youtu.be/kiUGf_Z08RQ?t=4226
// The Cherno --> https://www.youtube.com/watch?v=gNgUMA_Ur0U&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=64&ab_channel=TheCherno


string UnderScores(uint16_t NumberOfDashes)
{
	string UnderScores = "";

	for (uint16_t i = 0; i < NumberOfDashes; i++)
	{
		UnderScores += '_';
	}
	return UnderScores;
}

string Spaces(uint16_t NumberOfDashes)
{
	string Spaces = "";

	for (uint16_t i = 0; i < NumberOfDashes; i++)
	{
		Spaces += ' ';
	}
	return Spaces;
}

unsigned long Read_Positive_Number(const char* Message = "")
{
	unsigned long Number{ 0 };

	cout << Message;
	cin >> Number;

	while (cin.fail() || !((Number > 0)))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Number, Enter A Positive Number |-> ";
		cin >> Number;
	}

	return Number;
}

int Read_Number(const char* Message = "")
{
	int Number{ 0 };

	cout << Message;
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Number, Enter A Valid Number |-> ";
		cin >> Number;
	}

	return Number;
}

//**********************************************************************************************************

void Create_DynamicTable(int** table, uint16_t Rows, uint16_t Columns)
{
	for (uint16_t i{ 0 }; i < Rows; i++)
		table[i] = new int[Columns];
}

void Fill_DynamicTableWithUserInput(int** table, uint16_t Rows, uint16_t Columns)
{
	cout << "\n-- Enter The >| Table |< Elements//\n\n";
	for (uint16_t i{ 0 }; i < Rows; i++)
		for (uint16_t j{ 0 }; j < Columns; j++)
		{
			printf("- Element[%hu][%hu]: ", i, j);
			table[i][j] = Read_Number();
		}
	printf("\n-> You Had Created A (%hux%hu) Dynamic Table.\n", Rows, Columns);
}

void Fill_DynamicTable_Randomly(int** table, uint16_t Rows, uint16_t Columns)
{
	for (uint16_t i{ 0 }; i < Rows; i++)
		for (uint16_t j{ 0 }; j < Columns; j++)
			table[i][j] = rand() % 101;

	printf("\n-> You Had Created A (%hux%hu) Dynamic Table.\n\n", Rows, Columns);
}

void Print_DynamicTable_Formatted(int** table, uint16_t Rows, uint16_t Columns)
{
	if (table)
	{
		cout << UnderScores(5 * Columns / 2 - 3) << " Your Table " << UnderScores(5 * Columns / 2 - 3) << "\n\n";
		for (uint16_t i{ 0 }; i < Rows; i++)
		{
			cout << '|' << Spaces(2 * 5 * Columns / 2 + 4) << '|' << '\n' << '|';
			for (uint16_t j{ 0 }; j < Columns; j++)
			{
				cout << setw(5) << table[i][j];
			}
			cout << setw(5) << '|' << endl;
			cout << '|' << Spaces(2 * 5 * Columns / 2 + 4) << '|' << '\n';
		}
		cout << UnderScores(2 * 5 * Columns / 2 + 6) << "\n\n";
	}
	else
	{
		cout << "-> Empty Table" << endl;
	}
}

void Table_Deallocation(int** table, uint16_t Rows)
{
	// To free up the memory locations

	for (uint16_t i{ 0 }; i < Rows; i++)
		delete[] table[i]; // Deallocate the Rows pointers
}


int main()
{
	cout << "-- Enter The Number Of Rows & Columns Of Your Dynamic Table?\n";
	uint16_t Rows = (uint16_t)Read_Positive_Number("-> Rows: ");
	uint16_t Columns = (uint16_t)Read_Positive_Number("-> Columns: ");

	// Create a pointer to the table itself (pointer to an array of pointers)
	int** table = new int* [Rows];

	Create_DynamicTable(table, Rows, Columns);

	//Fill_DynamicTableWithUserInput(table, Rows, Columns);
	Fill_DynamicTable_Randomly(table, Rows, Columns);

	Print_DynamicTable_Formatted(table, Rows, Columns);

	Table_Deallocation(table, Rows);

	delete[] table;  // Deallocate the table pointer
	table = nullptr; // Make table points to nothing

	// You Now can't access the data anymore
	Print_DynamicTable_Formatted(table, Rows, Columns);

	return 0;
}