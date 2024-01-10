#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;



//***************************************************************************************************
//************************************ Global Functions *********************************************
//***************************************************************************************************


bool Check_TheNumberOfDigits(string N, int NumberOfDigits)
{
	if (N.length() == NumberOfDigits)
		return true;
	else
		return false;
}

bool CheckNumber_InRange(string N, int from, int to)
{
	if (stoul(N) >= from && stoul(N) <= to)
		return true;
	else
		return false;
}

bool Positive_Integer_Only(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return true;
	else
		return false;
}

bool Check_Positive_Number_Int(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Positive_Integer_Only(N[i]) == false)
			return false;
	}

	return true;
}

unsigned int Read_Positive_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N)));

	return stoul(N);
}

unsigned int Read_Positive_Int_NumberInRange(int from, int to)
{
	string N;
	do
	{
		cout << "Range ( " << from << " -> " << to << " ) " << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	return stoul(N);
}

unsigned int Read_Positive_Int_NumberInRange_Message(string Message, int from, int to)
{
	string N;
	do
	{
		cout << Message;
		cout << "Range( " << from << " -> " << to << " ) " << endl;
		cout << "- Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	return stoul(N);
}

int Generate_Random_Number_InRange(int From, int To)
{
	//Function To Generate A Random Number In Range Of (From -> To)

	return rand() % (To - From + 1) + From;
}

// 	srand((unsigned)time(NULL));

void V_Spaces(short NumberOfSpaces)
{
	for (short i = 1; i <= NumberOfSpaces; i++)
	{
		cout << " ";
	}
}

string S_Spaces(short NumberOfSpaces)
{
	string Spaces = "";

	for (short i = 1; i <= NumberOfSpaces; i++)
	{
		Spaces += " ";
	}

	return Spaces;
}

void V_Tabs(short NumberOfTabs)
{
	for (short i = 1; i <= NumberOfTabs; i++)
	{
		cout << "\t";
	}
}

string S_Tabs(short NumberOfTabs)
{
	string Tabs = "";

	for (short i = 1; i <= NumberOfTabs; i++)
	{
		Tabs += "\t";
	}

	return Tabs;
}

void NewLines(short NumberOfLines)
{
	for (short i = 1; i <= NumberOfLines; i++)
	{
		cout << "\n";
	}
}

void V_UnderScores(short NubmerOfUnderScores)
{
	for (short i = 1; i <= NubmerOfUnderScores; i++)
	{
		cout << "_";
	}
}

string S_UnderScores(short NubmerOfUnderScores)
{
	string UnderScores = "";

	for (short i = 1; i <= NubmerOfUnderScores; i++)
	{
		UnderScores += "_";
	}

	return UnderScores;
}

void V_Stars(short NumberOfStars)
{
	for (short i = 1; i <= NumberOfStars; i++)
	{
		cout << "*";
	}
}

string S_Stars(short NumberOfStars)
{
	string Stars = "";

	for (short i = 1; i <= NumberOfStars; i++)
	{
		Stars += "*";
	}

	return Stars;
}

//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
// Paper -> Stone -> Scissors

enum en_GameChoices { Paper = 1, Stone = 2, Scissors = 3 };
enum en_Winner { Player = 1, Computer = 2, Draw = 3 };

struct st_RoundInfo
{
	short RoundNumber;
	en_GameChoices PlayerChoice;
	en_GameChoices ComputerChoice;
	en_Winner RoundWinner;
	string RoundWinnerName = "";
};

struct st_GameResults
{
	short GameRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes;
	en_Winner GameWinner;
	string GameWinnerName = "";
};

unsigned short HowManyRounds(string Message, int from, int to)
{
	string N;
	do
	{
		cout << Message;
		cout << "from (" << from << ") to (" << to << ") ?" << endl;
		cout << "- Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	return stoul(N);
}

en_GameChoices ReadPlayerChoice(short from, short to)
{
	string N;
	short Choice;

	do
	{
		cout << "What Is Your Choice:[1]Paper [2]Stone [3]Scissors ? ";
		cout << "-> Your Answer : ";
		cin >> N;

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	Choice = stoul(N);
	
	return (en_GameChoices)Choice;
}

en_GameChoices ReadComputerChoice(short from, short to)
{
	return (en_GameChoices)Generate_Random_Number_InRange(from, to);
}

en_Winner WhoWonTheRound(st_RoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return en_Winner::Draw;
	}

	switch (RoundInfo.PlayerChoice)
	{
	case en_GameChoices::Paper:
		if (RoundInfo.PlayerChoice == en_GameChoices::Stone)
		{
			return en_Winner::Computer;
		}
	case en_GameChoices::Stone:
		if (RoundInfo.ComputerChoice == en_GameChoices::Paper)
		{
			return en_Winner::Computer;
		}
	case en_GameChoices::Scissors:
		if (RoundInfo.ComputerChoice == en_GameChoices::Stone)
		{
			return en_Winner::Computer;
		}
	}

	//if you reach here then player1 is the winner.
	return en_Winner::Player;
}

string WinnerName(en_Winner Winner)
{
	string arr_WinnerName[3] = { "Player", "Computer", "No Winner" };
	return arr_WinnerName[Winner - 1];
}

st_RoundInfo FillRoundInfo(short GameRound)
{
	st_RoundInfo RoundInfo;

	RoundInfo.RoundNumber = GameRound;
	RoundInfo.PlayerChoice = ReadPlayerChoice(1, 3);
	RoundInfo.ComputerChoice = ReadComputerChoice(1, 3);
	RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
	RoundInfo.RoundWinnerName = WinnerName(RoundInfo.RoundWinner);

	return RoundInfo;
}

void IncreaseWinnerPoints(st_RoundInfo RoundInfo, short& PlayerWinTimes, short& ComputerWinTimes, short& DrawTimes)
{
	//Increase win/Draw counters.
	if (RoundInfo.RoundWinner == en_Winner::Player)
		PlayerWinTimes++;
	else if (RoundInfo.RoundWinner == en_Winner::Computer)
		ComputerWinTimes++;
	else
		DrawTimes++;
}

string ChoiceName(en_GameChoices Choice)
{
	string arr_GameChoices[3] = {"Paper", "Stone", "Scissors"};
	return arr_GameChoices[Choice - 1];
}

void SetWinnerScreenColor(en_Winner Winner)
{
	switch (Winner)
	{
	case Player:
		system("color 2F"); // Green
		break;
	case Computer:
		system("color 4F"); // Red
		break;
	case Draw:
		system("color 6F"); // Yellow
		break;
	}
}

void Print_RoundResults(st_RoundInfo RoundInfo)
{
	cout << "\n____________Round [" << RoundInfo.RoundNumber << "]____________\n\n";
	cout << "- Player Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "- Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "- Round Winner: {" << RoundInfo.RoundWinnerName << "}\n";
	cout << "_________________________________\n" << endl;

	SetWinnerScreenColor(RoundInfo.RoundWinner);

}

en_Winner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes > ComputerWinTimes)
		return en_Winner::Player;
	else if (ComputerWinTimes > PlayerWinTimes)
		return en_Winner::Computer;
	else
		return en_Winner::Draw;
}

st_GameResults FillGameResults(short GameRounds, short PlayerWintimes, short ComputerWinTimes, short DrawTimes)
{
	st_GameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.PlayerWinTimes = PlayerWintimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(PlayerWintimes, ComputerWinTimes);
	GameResults.GameWinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

st_GameResults PlayGame(short NumberOfRounds)
{
	st_RoundInfo RoundInfo;

	//Counters
	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= NumberOfRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] Begins:" << endl;
		cout << S_Stars(18) << endl;

		RoundInfo = FillRoundInfo(GameRound);

		IncreaseWinnerPoints(RoundInfo, PlayerWinTimes, ComputerWinTimes, DrawTimes);

		Print_RoundResults(RoundInfo);
	}

	st_GameResults GameResults = FillGameResults(NumberOfRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);

	return GameResults;
}

void Print_GameResults(st_GameResults GameResults)
{
	cout << S_Tabs(2) << S_UnderScores(40) << "[Game Results]" << S_UnderScores(40) << endl << endl;
	cout << S_Tabs(2) << "- Game Rounds -----------------------------------------------------: " << GameResults.GameRounds << endl;
	cout << S_Tabs(2) << "- Player Won Times ------------------------------------------------: " << GameResults.PlayerWinTimes << endl;
	cout << S_Tabs(2) << "- Computer Won Times ----------------------------------------------: " << GameResults.ComputerWinTimes << endl;
	cout << S_Tabs(2) << "- Draw Times ------------------------------------------------------: " << GameResults.DrawTimes << endl;
	cout << S_Tabs(2) << "- Final Winner ----------------------------------------------------: " << GameResults.GameWinnerName << endl;
	cout << S_Tabs(2) << S_UnderScores(94) << endl << endl;
	

	SetWinnerScreenColor(GameResults.GameWinner);
}

void GameOverScreen()
{
	cout << S_Tabs(2) << S_UnderScores(94) << endl << endl;
	cout << S_Tabs(6) << S_Spaces(3) << "+++ G a m e  O v e r +++" << endl;
	cout << S_Tabs(2) << S_UnderScores(94) << endl << endl;
}

void ResetGame()
{
	system("cls");
	system("color 0F");
}

string Read_YesOrNo_FromUser(string Message)
{
	string S;

	do
	{
		cout << Message;
		cout << "[Y/y]Yes [N/n]No -> ";
		cout << "Your Answer : ";
		cin >> S;

	} while (!(S == "S" || S == "y" || S == "N" || S == "n"));

	return S;
}

void PlayAgainOrEndGame(string& PlayAgain)
{
	PlayAgain = Read_YesOrNo_FromUser("\t\t- Do You Want To Play Another Game? ");

	if (PlayAgain == "N" || PlayAgain == "n")
	{
		system("color 5F");

		NewLines(2);
		V_Tabs(2);
		V_UnderScores(94);
		NewLines(2);
		V_Spaces(43);
		cout << "Thank's For Playing Our Game Good Bye :-)";
		NewLines(1);
		V_Tabs(2);
		V_UnderScores(94);
		NewLines(2);
	}
}

void StartGame()
{

	string PlayAgain ;

	do
	{
		ResetGame();

		st_GameResults GameResults = PlayGame(HowManyRounds("How Many Rounds You Want To Play ", 1, 10));

		GameOverScreen();

		Print_GameResults(GameResults);

		PlayAgainOrEndGame(PlayAgain);


	} while (PlayAgain == "Y" || PlayAgain == "y");


	NewLines(2);
}




//________________________________________________________________________________________________________________________________________

int main()
{
	srand((unsigned)time(NULL));


	StartGame();


	return 0;

}

