
#include <string>
#include <iostream>

using namespace std;

//************************* PROGRAM 1 ****************************
// Read name from the user and print it

string ReadNamefromUser()
{
	string Name;
	cout << "Please enter your name : ";
	getline(cin, Name);
	cout << "\n\n";

	return Name;

}

void PrintName(string Name)
{
	cout << "Your name is : " << Name << endl << endl;
}

//******************************** PROGRAM 2 *********************
// check if number even or odd

enum en_EvenOrOdd { odd = 1, even = 2 };

int ReadNumber()
{
	int Number;
	cout << "Please enter any number : ";
	cin >> Number;
	cout << "\n\n";

	return Number;
}

en_EvenOrOdd CheckNumberType(int Number)
{
	if (Number % 2 == 0)
	{
		return en_EvenOrOdd::even;;

	}
	else
	{
		return en_EvenOrOdd::odd;
	}
	

}

void PrintNumberType(int Number)
{
	if (Number == en_EvenOrOdd::even)
	{
		cout << "Your number is : Even\n\n";
	}
	else
	{
		cout << "Your number is : Odd\n\n";
	}

}



//**************************** PROGRAM 3 ************************
// Hire adriver



struct st_DriverInfo
{
	string Name;
	int age;
	bool HasADriverLicense;
	bool HasARecommendation;

};

st_DriverInfo ReadInfo()
{
	st_DriverInfo Info;

	cout << "Please enter your name : ";
	getline(cin, Info.Name);
	cout << "\n";

	cout << "Please enter your age : ";
	cin >> Info.age;
	cout << "\n";

	string Answer;
	cout << "Do you have a driver License? (yes or no)\n";
	cout << "Your answer : ";
	cin >> Answer;
	cout << "\n";
	
	
	if (Answer == "Yes" || Answer == "yes" || Answer == "YES")
	{
		Info.HasADriverLicense = true;
	}
	else if (Answer == "no" || Answer == "No" || Answer == "NO")
	{
		Info.HasADriverLicense = false;
	}


	Answer;
	cout << "Do you have a Recommendation? (yes or no)\n";
	cout << "Your answer : ";
	cin >> Answer;
	cout << "\n\n";


	if (Answer == "Yes" || Answer == "yes" || Answer == "YES")
	{
		Info.HasARecommendation = true;
	}
	else if (Answer == "no" || Answer == "No" || Answer == "NO")
	{
		Info.HasARecommendation = false;
	}


	return Info;

	

}

bool IsAccepted(st_DriverInfo Info)
{
	return ((Info.age > 21 && Info.HasADriverLicense) || Info.HasARecommendation);
}


void Print_AcceptedOrRejected(st_DriverInfo Info)
{

	if(IsAccepted(Info))
	{ 
		cout << "Comgratulations, " << Info.Name << " you are accepted\n\n";
	}
	else
	{
		cout << "Sorry, " << Info.Name << " you are rejected\n\n";
	}

}




int main()
{

	//PrintName(ReadNamefromUser());


	//PrintNumberType(CheckNumberType(ReadNumber()));


	//Print_AcceptedOrRejected(ReadInfo());




	return 0;
}

