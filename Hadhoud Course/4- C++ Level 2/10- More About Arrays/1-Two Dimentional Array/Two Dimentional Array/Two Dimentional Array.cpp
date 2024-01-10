
#include <iostream>

using namespace std;


int main()
{
	// Print 2 Dimentional Array

	short Arr[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // You can use this bad way 


	//                        Row1          Row2           Row3
	short Array[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} }; // But this way is better


	cout << "\tCol1\tCol2\tcol3\tcol4" << endl;
	for (short i = 0; i < 3; i++)
	{
		cout << "Raw1:\t";
		for (short j = 0; j < 4; j++)
		{
			cout << Array[i][j] << "\t";
		}

		cout << endl;
	}

}

