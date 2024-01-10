
#include <string>
#include <iostream>

using namespace std;


bool check_number(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (isdigit(N[i]) == false)
		{
			return false;
		}
	}


	return true;


}



int EnterANumberInRange_UsingWhile(int from, int to)
{
	string N;
	cout << "Please, enter a number between " << from << " and " << to << endl;
	cin >> N;


	while (check_number(N) == false || stoi(N) < from || stoi(N) > to)
	{

		
		cout << "\nPlease Enter a numerical number between " << from << " and " << to << endl;
		cin >> N;

	}

	cout << "\n\n";
	return stoi(N);
}


int EnterANumberInRange_UsingDoWhile(int from, int to)
{
	string N;
	
	do 
	{
		cout << "Please, Enter a numerical number between " << from << " and " << to << endl;
		cin >> N;
		cout << "\n";

	}
	while (check_number(N) == false || stoi(N) < from || stoi(N) > to);


	return stoi(N);
}


int main()
{
	

	
	//cout << "Your number is : " << EnterANumberInRange_UsingWhile(1, 100) << endl << endl;
	cout << "Your number is : " << EnterANumberInRange_UsingDoWhile(1, 100) << endl << endl;


	return 0;
}


