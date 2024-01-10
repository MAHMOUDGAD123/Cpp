
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

using namespace this_thread;
using namespace chrono_literals;
using chrono::system_clock;



int main()
{
	
	for (int i = 1; i <= 21; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		sleep_for(0.1s);
		cout << "\n";
	}




	return 0;
}


//***********************************************************




for (int i = 1; i <= 21; i++)
{
	for (int j = 1; j <= i; j++)
	{
		cout << "*";
	}
	sleep_for(0.1s);
	cout << "\n";
}

for (int i = 21; i >= 1; i--)
{
	for (int j = 1; j <= i; j++)
	{
		cout << "*";
	}
	sleep_for(0.1s);
	cout << "\n";
}




//******************************************************

/*int k = 15;

for (int i = 1; i <= 8; i++)
{
	for (int j = 1; j <= k; j++)
	{
		cout << "*";
	}
	k -= 2;
	cout << "\n";

	for (int z = 1; z <= i; z++)
	{
		cout << " ";
	}


}*/




//***********************************************************************



	/*for (int i = 65; i <= 90; i++)
{
	for (int j = 65; j <= 90; j++)
	{
		cout << char(i) << char(j) << endl;
		sleep_for(0.1s);
	}
}*/


//**********************************************************************************

/*for (;;)
{

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(j);
		}
		sleep_for(0.1s);
		cout << "\n";
	}




	for (int i = 90; i >= 65; i--)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(j);
		}
		sleep_for(0.1s);
		cout << "\n";
	}

}*/



//**********************************************************************************






//*********************************************************************************


/*for (;;)
{
	for (int i = 10; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}
		sleep_for(0.1s);
		cout << "\n";

	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}
		sleep_for(0.1s);
		cout << "\n";

	}

}*/



//********************************************************************



//for (int i = 1; i <= 9; i++)
//{
//	for (int j = 1; j <= i; j++)
//	{
//		cout << i;
//	}
//	sleep_for(0.1s);
//	cout << "\n";
//
//}


//for (int i = 1; i <= 7; i++)
//{
//	for (int j = 7; j >= i; j--)
//	{
//		cout << " ";
//	}
//	
//	for (int z = 1; z <= i; z++)
//	{
//		cout << "*";
//	}
//
//	for (int x = 1; x <= i - 1; x++)
//	{
//		cout << "*";
//	}
//
//	cout << "\n";
//}


//*******************************************************************




//int k = 5;
//int w = 1;
//
//for (int i = 1; i <= 6; i++)
//{
//	for (int j = 1; j <= k; j++)
//	{
//		cout << " ";
//	}
//	k--;
//
//	for (int x = 1; x <= w; x++)
//	{
//		cout << "*";
//	}
//	w += 2;
//	cout << "\n";
//}













