
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;



int main()
{

	for (;;)
	{
		cout << "Multiplication Table\\\n\n";

		cout << "1- number 1 table\n";
		cout << "2- number 2 table\n";
		cout << "3- number 3 table\n";
		cout << "4- number 4 table\n";
		cout << "5- number 5 table\n";
		cout << "6- number 6 table\n";
		cout << "7- number 7 table\n";
		cout << "8- number 8 table\n";
		cout << "9- number 9 table\n";
		cout << "10- number 10 table\n";
		cout << "11- number 11 table\n";
		cout << "12- number 12 table\n";
		cout << "13- All Numbers table\n\n\n";

	XXX:

		int choice;
		cout << "Choose the number table from the list from 1 to 12 \\\n";
		cout << "Your choice : ";
		cin >> choice;
		cout << "\n";

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 &&
			choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11 && choice != 12 && choice != 13)
		{
			cout << "Wrong number choose again.\n\n";
			goto XXX;
		}

		switch (choice)
		{

		case 1:
			cout << "\n*********************************\n";
			cout << "\nNumber (1) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 1 * " << i << " = " << 1 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 2:
			cout << "\n*********************************\n";
			cout << "\nNumber (2) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 2 * " << i << " = " << 2 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 3:
			cout << "\n*********************************\n";
			cout << "\nNumber (3) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 3 * " << i << " = " << 3 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 4:
			cout << "\n*********************************\n";
			cout << "\nNumber (4) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 4 * " << i << " = " << 4 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 5:
			cout << "\n*********************************\n";
			cout << "\nNumber (5) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 5 * " << i << " = " << 5 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 6:
			cout << "\n*********************************\n";
			cout << "\nNumber (6) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 6 * " << i << " = " << 6 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 7:
			cout << "\n*********************************\n";
			cout << "\nNumber (7) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 7 * " << i << " = " << 7 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 8:
			cout << "\n*********************************\n";
			cout << "\nNumber (8) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 8 * " << i << " = " << 8 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 9:
			cout << "\n*********************************\n";
			cout << "\nNumber (9) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 9 * " << i << " = " << 9 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 10:
			cout << "\n*********************************\n";
			cout << "\nNumber (10) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 10 * " << i << " = " << 10 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 11:
			cout << "\n*********************************\n";
			cout << "\nNumber (11) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 11 * " << i << " = " << 11 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 12:
			cout << "\n*********************************\n";
			cout << "\nNumber (12) Table :\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "- 12 * " << i << " = " << 12 * i << endl;
			}
			cout << "\n*********************************\n\n";
			cout << "Pleasee press enter to continue ........\n\n";
			cin.ignore(1, '\n');
			cin.get() != '\n';
			cout << "\n\n";
			break;

		case 13:
			cout << "\n*********************************\n";
			for (int i = 1; i <= 12; i++)
			{
				cout << "\n*********************************\n";
				cout << "\nNumber (" << i << ") " << "Table :\n";
				for (int j = 1; j <= 12; j++)
				{
					cout << "- " << i << " * " << j << " = " << i * j << endl;
				}
				cout << "\n*********************************\n\n";
				cout << "Pleasee press enter for the next table >>";
				cin.ignore(1, '\n');
				cin.get() != '\n';
			}
			cout << "\n*********************************\n\n";
			cout << "Please, press enter to continue ........";
			cin.ignore(1, '\n');
			//cin.get() != '\n';
			cout << "\n\n";
			break;

		default:
			cout << "Wrong number choose again.\n\n";
			goto XXX;



		}


	}


	return 0;
}

