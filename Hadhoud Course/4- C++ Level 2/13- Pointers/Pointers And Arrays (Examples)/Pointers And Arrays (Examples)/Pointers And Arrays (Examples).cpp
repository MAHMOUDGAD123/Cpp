#include <iostream>

using namespace std;

// https://www.programiz.com/cpp-programming/pointers-arrays


void ReadArray_UnsingPointer(short Array[], short arr_length)
{
	short* ptr = Array;

	cout << "Enter Array Elements:\n\n";
	for (short i = 0; i < arr_length; i++)
	{
		printf("Array[%hi]: ", i);
		cin >> ptr[i];
	}
}

void PrintArrayData_UsingPointer(short Array[], short arr_length)
{
	short* ptr = Array;

	cout << "\n\nArray Elements:\n\n";
	for (short i = 0; i < arr_length; i++)
	{
		printf("Element[%hi]:\n", i);
		cout << "- Address = " << ptr + i << endl;
		cout << "- Value = " << *(ptr + i) << endl;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	//short Array[5];
	//
	//short* ptr = Array;

	//// Read Array elements
	//// You can use ( Array[i]  or  ptr[i]  or  *(Array + i)  or  *(ptr + i) )
	//// Remember (ptr) & (Array) are the same pointers

	//cout << "Enter Array Elements:\n\n";
	//for (short i = 0; i < sizeof(Array) / sizeof(short); i++)
	//{
	//	printf("Array[%hi]: ", i);
	//	cin >> ptr[i];
	//}
	//cout << "\n\n";

	//// Print Array elements
	//// You can use ( Array[i]  or  ptr[i]  or  *(Array + i)  or  *(ptr + i) )

	//cout << "Array Elements:\n\n";
	//for (short i = 0; i < sizeof(Array) / sizeof(short); i++)
	//{
	//	printf("Array[%hi] = ", i);
	//	cout << *(ptr + i) << endl;
	//}
	

	cout << "\n\n__________________________________\n\n";

	short arr[7], arr_length = 7;

	ReadArray_UnsingPointer(arr, arr_length);
	
	PrintArrayData_UsingPointer(arr, arr_length);
	
	return 0;
}


