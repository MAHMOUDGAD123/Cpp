#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void Read_Students_GPAs(float* ptr, unsigned short NOStudents)
{
	// Reading the students GPAs
	cout << "Enter The Students GPAs -> (Max = 100)\n\n";
	for (unsigned short i = 0; i < NOStudents; i++)
	{
		cout << "Student[" << i + 1 << "]:";
		cin >> *(ptr + i);

		while (*(ptr + i) > 100)
		{
			cout << "\nMax GPA = 100 -> Enter Again?\n\n";
			cout << "Student[" << i + 1 << "]:";
			cin >> ptr[i]; // ==> *(ptr + i)
		}
	}
}

void Display_Students_GPAs(float* ptr, unsigned short NOStudents)
{
	// Printing students GPAs
	cout << "\n\nThe Students GPAs:\n\n";
	for (unsigned short i = 0; i < NOStudents; i++)
	{
		printf("Student[%hu] GPA = { %.1f }\n", i, *(ptr + i));
	}
	cout << endl << endl;
}


int main()
{
	unsigned short NOStudents = 0;

	cout << "How Many Students Do You Want To Add? --> ";
	cin >> NOStudents;
	cout << endl;

	float* ptr;

	ptr = new float[NOStudents];

	Read_Students_GPAs(ptr, NOStudents);

	Display_Students_GPAs(ptr, NOStudents);


	delete[] ptr;
	ptr = NULL;



	return 0;
}
