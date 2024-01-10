#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;



//***************************************************************************************************
//************************************ Global Functions *********************************************
//***************************************************************************************************


bool IsItNumber(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.' || c == '-')
		return true;
	else
		return false;
}

bool Integer_Only(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '-')
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

bool Positive_Only(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.')
		return true;
	else
		return false;
}

bool Check_Number(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (IsItNumber(N[i]) == false || N == "." || N == "-")
			return false;
	}
	for (short j = 1; j < N.length(); j++)
	{
		if (N[j] == '-')
			return false;
	}

	return true;
}

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
// Math Game

enum en_QuizLevel { Easy = 1, Medium = 2, Hard = 3, MixLvl = 4 };
enum en_OperationType { Add = 1, Sub = 2, Multi = 3, Div = 4, MixOp = 5 };
enum en_Operations { Addition = '+', Subtraction = '-', Multiplication = '*', Division = '/' };


struct st_QuizInfo
{
	en_QuizLevel QuizLevel;
	en_OperationType OperationType;
};

struct st_QuizResults
{
	short NumberOfQuestions, NORightAnswers, NOWrongAnswers;
	string QuizLevelName;
	string OperationTypeName;
};

struct st_QuestionInfo
{
	short QuestionNumber, FirstNumber, SecondNumber;
	unsigned int QuestionAnswer, UserAnswer;
	en_Operations QuestionOperation;
};

unsigned short HowManyQuestions(string Message, int from, int to)
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

unsigned short AskForQuizLevel(string Message, int from, int to)
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

en_QuizLevel WhatIsQuizLevel(short UserChoice)
{
	switch (UserChoice)
	{
	case 1:
		return en_QuizLevel::Easy;
	case 2:
		return en_QuizLevel::Medium;
	case 3:
		return en_QuizLevel::Hard;
	case 4:
		return en_QuizLevel::MixLvl;
	}
}

en_OperationType WhatIsOperationType(short UserChoice)
{
	switch (UserChoice)
	{
	case 1:
		return en_OperationType::Add;
	case 2:
		return en_OperationType::Sub;
	case 3:
		return en_OperationType::Multi;
	case 4:
		return en_OperationType::Div;
	case 5:
		return en_OperationType::MixOp;
	}
}

short Generate_QuestionNumbers(en_QuizLevel QuizLevel)
{
	switch (QuizLevel)
	{
	case Easy:
		return Generate_Random_Number_InRange(1, 10);
	case Medium:
		return Generate_Random_Number_InRange(10, 50);
	case Hard:
		return Generate_Random_Number_InRange(50, 100);
	case MixLvl:
		return Generate_Random_Number_InRange(1, 100);
	}
}

bool Num1BiggerThanNum2(short Num1, short Num2)
{
	if (Num2 > Num1)
		return false;
	else
		return true;
}

bool Num1ivisibleByNum2(short Num1, short Num2)
{
	if (Num1 % Num2 != 0)
		return false;
	else
		return true;
}

bool OnlyOperationChars(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	else
		return false;
}

char Generate_OnlyOperationChars()
{
	char C;

	do
	{
		C = Generate_Random_Number_InRange(42, 47);

	} while (!OnlyOperationChars(C));

	return C;
}

en_Operations Generate_OperationType(en_OperationType OperationType)
{
	switch (OperationType)
	{
	case Add:
		return (en_Operations)'+';
	case Sub:
		return (en_Operations)'-';
	case Multi:
		return (en_Operations)'*';
	case Div:
		return (en_Operations)'/';
	case MixOp:
		return (en_Operations)Generate_OnlyOperationChars();
	}
}

void Get_QuestionNumbers (st_QuizInfo QuizInfo, st_QuestionInfo& QuestionInfo)
{
	// Make sure that Num1 > Num2 if Operation is Subtraction or Division
	if (QuestionInfo.QuestionOperation == '-' || QuestionInfo.QuestionOperation == '/')
	{
		do
		{
			QuestionInfo.FirstNumber = Generate_QuestionNumbers(QuizInfo.QuizLevel);
			QuestionInfo.SecondNumber = Generate_QuestionNumbers(QuizInfo.QuizLevel);

		} while (!Num1BiggerThanNum2(QuestionInfo.FirstNumber, QuestionInfo.SecondNumber));

	}
	// Make sure that (Num1 > Num2) & (Num1 % Num1 = 0) if Operation is Division
	/*else if (QuestionInfo.QuestionOperation == '/')
	{
		do
		{
			QuestionInfo.FirstNumber = Generate_QuestionNumbers(QuizInfo.QuizLevel);
			QuestionInfo.SecondNumber = Generate_QuestionNumbers(QuizInfo.QuizLevel);

		} while (!(Num1BiggerThanNum2(QuestionInfo.FirstNumber, QuestionInfo.SecondNumber) && Num1ivisibleByNum2(QuestionInfo.FirstNumber, QuestionInfo.SecondNumber)));
	}*/
	else
	{
		QuestionInfo.FirstNumber = Generate_QuestionNumbers(QuizInfo.QuizLevel);
		QuestionInfo.SecondNumber = Generate_QuestionNumbers(QuizInfo.QuizLevel);
	}
}

unsigned int Get_QuestionAnswer(st_QuestionInfo& QuestionInfo)
{
	switch (QuestionInfo.QuestionOperation)
	{
	case '+':
		return round((float) QuestionInfo.FirstNumber + QuestionInfo.SecondNumber);
	case '-':
		return round((float) QuestionInfo.FirstNumber - QuestionInfo.SecondNumber);
	case '*':
		return round((float) QuestionInfo.FirstNumber * QuestionInfo.SecondNumber);
	case '/':
		return round((float) QuestionInfo.FirstNumber / QuestionInfo.SecondNumber);
	}
}

void Print_Question(st_QuestionInfo QuestionInfo, short NumberOfQuestions)
{
	cout << "Question [" << QuestionInfo.QuestionNumber << "/" << NumberOfQuestions << "]" << endl << endl;
	
	switch (QuestionInfo.QuestionOperation)
	{
	case Addition:
		cout << QuestionInfo.FirstNumber << " + \n" << QuestionInfo.SecondNumber << endl;
		cout << S_UnderScores(7) << endl;
		break;
	case Subtraction:
		cout << QuestionInfo.FirstNumber << " - \n" << QuestionInfo.SecondNumber << endl;
		cout << S_UnderScores(7) << endl;
		break;
	case Multiplication:
		cout << QuestionInfo.FirstNumber << " * \n" << QuestionInfo.SecondNumber << endl;
		cout << S_UnderScores(7) << endl;
		break;
	case Division:
		cout << QuestionInfo.FirstNumber << " / \n" << QuestionInfo.SecondNumber << endl;
		cout << S_UnderScores(7) << endl;
		break;
	}
}

unsigned int Read_UserAnswer()
{
	string N;

	do
	{
		cin >> N;

	} while (!(Check_Positive_Number_Int(N)));

	return stof(N);
}

bool IsUserAnswerRight(st_QuestionInfo QuestionInfo)
{
	if (QuestionInfo.UserAnswer == QuestionInfo.QuestionAnswer)
		return true;
	else
		return false;
}

void SetAnswerScreenColor(st_QuestionInfo QuestionInfo)
{
	if (IsUserAnswerRight(QuestionInfo))
		system("color 2F");
	else
		system("color 4F");
}

void Print_RightOrWrongAnswerScreen(st_QuestionInfo QuestionInfo)
{
	if (IsUserAnswerRight(QuestionInfo))
	{
		cout << "----> Right Answer :-)" << endl;
		cout << S_UnderScores(15) << endl << endl;
	}
	else
	{
		cout << "----> Wrong Answer" << endl;
		cout << "The Right Answer is : {" << QuestionInfo.QuestionAnswer << "}" << endl;
		cout << S_UnderScores(15) << endl << endl;
	}

	SetAnswerScreenColor(QuestionInfo);
}

void IncreaseCounters(st_QuestionInfo QuestionInfo, short& NORightAnswers, short& NOWrongAnswers)
{
	if (IsUserAnswerRight(QuestionInfo))
		NORightAnswers++;
	else
		NOWrongAnswers++;
}

void Print_FinalResultsScreen(short NORightAnswers, short NOWrongAnswers)
{
	if (NORightAnswers == NOWrongAnswers)
	{
		system("color 6F");
		cout << S_UnderScores(50) << endl << endl;
		cout << S_Spaces(12) << "Final Result Is Pass :-|" << endl;
		cout << S_Spaces(9) << "You Have To Do Better Next Time" << endl;
		cout << S_UnderScores(50) << endl;
	}
	else if (NORightAnswers > NOWrongAnswers)
	{
		system("color 2F");
		cout << S_UnderScores(50) << endl << endl;
		cout << S_Spaces(12) << "Final Result Is Pass :-)" << endl;
		cout << S_Spaces(19) << "Nice Work" << endl;
		cout << S_UnderScores(50) << endl;
	}
	else
	{
		system("color 4F");
		cout << S_UnderScores(50) << endl << endl;
		cout << S_Spaces(12) << "Final Result Is Fail :-(" << endl;
		cout << S_Spaces(16) << "That Was Very Bad" << endl;
		cout << S_UnderScores(50) << endl;
	}
}

string Get_QuizLevelName(en_QuizLevel QuizLevel)
{
	string Levels[4] = { "Easy", "Medium", "Hard", "Mix" };
	return Levels[QuizLevel - 1];
}

string Get_QuizOperationName(en_OperationType OperationType)
{
	string Operation[5] = { "Addition", "Subtraction", "Multiplication", "Division", "Mix"};
	return Operation[OperationType - 1];
}

st_QuizResults FillQuizResults(st_QuizInfo QuizInfo, short NumberOfQuestions, short NORightAnswers, short NOWrongAnswers)
{
	st_QuizResults QuizResults;

	QuizResults.NumberOfQuestions = NumberOfQuestions;
	QuizResults.QuizLevelName = Get_QuizLevelName(QuizInfo.QuizLevel);
	QuizResults.OperationTypeName = Get_QuizOperationName(QuizInfo.OperationType);
	QuizResults.NORightAnswers = NORightAnswers;
	QuizResults.NOWrongAnswers = NOWrongAnswers;

	return QuizResults;
}

st_QuizResults Play_MathGame(short NumberOfQuestions)
{
	st_QuizInfo QuizInfo;
	st_QuestionInfo QuestionInfo;

	// Counters
	short NORightAnswers = 0, NOWrongAnswers = 0;

	
	QuizInfo.QuizLevel = WhatIsQuizLevel(AskForQuizLevel("- Enter The Quiz Level: [1]Easy [2]Medium [3]Hard [4]Mix / ", 1, 4));
	QuizInfo.OperationType = WhatIsOperationType(AskForQuizLevel("- Enter The Operation Type: [1]Add [2]Sub [3]Multi [4]Div [5]Mix / ", 1, 5));

	cout << "* Note: Get The Rounded Result For The Division Operation" << endl << endl;

	cout << S_UnderScores(50) << endl << endl << endl;


	for (short QuestionNumber = 1; QuestionNumber <= NumberOfQuestions; QuestionNumber++)
	{
		QuestionInfo.QuestionNumber = QuestionNumber;
		QuestionInfo.QuestionOperation = Generate_OperationType(QuizInfo.OperationType);

		Get_QuestionNumbers(QuizInfo, QuestionInfo);

		QuestionInfo.QuestionAnswer = Get_QuestionAnswer(QuestionInfo);

		Print_Question(QuestionInfo, NumberOfQuestions);

		QuestionInfo.UserAnswer = Read_UserAnswer();

		Print_RightOrWrongAnswerScreen(QuestionInfo);

		IncreaseCounters(QuestionInfo, NORightAnswers, NOWrongAnswers);
	}
	
	return FillQuizResults(QuizInfo, NumberOfQuestions, NORightAnswers, NOWrongAnswers);
}

void Print_QuizResults(st_QuizResults QuizResults)
{
	cout << endl << S_UnderScores(50) << endl << endl;
	cout << "- Number Of Questions ---------------: " << QuizResults.NumberOfQuestions << endl;
	cout << "- Quiz Level ------------------------: " << QuizResults.QuizLevelName << endl;
	cout << "- Quiz Operation Type ---------------: " << QuizResults.OperationTypeName << endl;
	cout << "- Number Of Right Answers -----------: " << QuizResults.NORightAnswers << endl;
	cout << "- Number Of Wrong Answers -----------: " << QuizResults.NOWrongAnswers << endl;
	cout << S_UnderScores(50) << endl << endl;
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

	} while (!(S == "Y" || S == "y" || S == "N" || S == "n"));

	return S;
}

void PlayAgainOrEndGame(string& PlayAgain)
{
	PlayAgain = Read_YesOrNo_FromUser("- Do You Want To Play Another Game? ");

	if (PlayAgain == "N" || PlayAgain == "n")
	{
		system("color 5F");

		cout << endl << S_Tabs(1) << S_UnderScores(100) << endl << endl;
		cout << S_Tabs(5) << "Thank's For Playing Our Game Good Bye :-)" << endl;
		cout << S_Tabs(1) << S_UnderScores(100) << endl << endl << endl;
	}
}

void Start_MathGame()
{
	st_QuizResults QuizResults;
	string PlayAgain;

	do
	{
		ResetGame();

		QuizResults = Play_MathGame(HowManyQuestions("- How Many Questions Do You Want / ", 1, 30));

		Print_FinalResultsScreen(QuizResults.NORightAnswers, QuizResults.NOWrongAnswers);

		Print_QuizResults(QuizResults);

		PlayAgainOrEndGame(PlayAgain);

	} while (PlayAgain == "Y" || PlayAgain == "y");

	NewLines(3);
}


//________________________________________________________________________________________________________________________________________


int main()
{
	srand((unsigned)time(NULL));


	Start_MathGame();



	return 0;

}

