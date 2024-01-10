#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	unsigned short N = 0;

	cout << "How Many Students Do You Want To Add? --> ";
	cin >> N;
	cout << endl;

	float* ptr;
	
	
	// Memory allocation of (N) number of floats
	ptr = new float[N];

	// Reading the students GPAs
	cout << "Enter The Students GPAs. (Max = 100)\n\n";
	for (unsigned short i = 0; i < N; i++)
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

	// Printing students GPAs
	cout << "\n\nThe Students GPAs:\n\n";
	for (unsigned short i = 0; i < N; i++)
	{
		printf("Student[%hu] GPA = { %.1f }\n", i, *(ptr + i));
	}
	cout << endl << endl;


	// Releasing ptr memory
	delete[] ptr;

	// You can add the following to make the pointer points to nothing (this is a good practice)
	ptr = NULL;



	return 0;
}
