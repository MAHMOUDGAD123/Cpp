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

bool Check_PositiveOrNot(string N)
{
	if (stod(N) > 0)
		return true;
	else
		return false;
}

bool Check_Number_Int(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Integer_Only(N[i]) == false || N == "-")
			return false;
	}
	for (short j = 1; j < N.length(); j++)
	{
		if (N[j] == '-')
			return false;
	}

	return true;
}

bool Check_Positive_Number(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Positive_Only(N[i]) == false)
			return false;
	}

	return true;
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
	if (stoi(N) >= from && stoi(N) <= to)
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

int Read_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!Check_Number_Int(N));

	return stoi(N);
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

enum en_QuestionLevel { EasyLvl = 1, MediumLvl = 2, HardLvl = 3, MixedLvl = 4 };
enum en_OperationType { Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4, MixedOp = 5 };

struct st_Question
{
	short Number1 = 0, Number2 = 0;
	en_QuestionLevel QuestionLevel;
	en_OperationType OperationType;
	int CorrectAnswer = 0, UserAnswer = 0;
	bool AnswerResult = false;
};

struct st_Quiz
{
	st_Question QuestionList[100];
	en_QuestionLevel QuizLevel;
	en_OperationType QuizOperationType;
	short NumberOfQuestions = 0, NumberOfRightAnswers = 0, NumberOfWrongAnswers = 0;
	bool IsPass = false;
};

void ResetGame()
{
	system("cls");
	system("color 0F");
}

short Read_NumberFromUser(string Message, int from, int to)
{
	string N;
	do
	{
		cout << Message;
		cout << "-> Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	return stoi(N);
}

en_QuestionLevel Read_QuizLevel()
{
	return (en_QuestionLevel)Read_NumberFromUser("- Choose The Quiz Level : [1]Easy [2]Medium [3]Hard [4]Mixed ", 1, 4);
}

en_OperationType Read_QuizOperationType()
{
	return (en_OperationType)Read_NumberFromUser("- Choose The Operation Type : [1]Addition [2]Subtraction [3]Multiplication [4]Division [5]Mixed ",1,5);
}

int Calculator(short Num1, short Num2, en_OperationType OperationType)
{
	switch (OperationType)
	{
	case Addition:
		return Num1 + Num2;
	case Subtraction:
		return Num1 - Num2;
	case Multiplication:
		return Num1 * Num2;
	case Division:
		return Num1 / Num2;
	default:
		return Num1 + Num2;
	}
}

void MakeSureNum1BiggerThanNum2InDivision(short& Number1, short& Number2, en_OperationType OpType, short from, short to)
{
	if (OpType == Division)
	{
		do
		{
			Number1 = Generate_Random_Number_InRange(from, to);
			Number2 = Generate_Random_Number_InRange(from, to);

		} while (Number1 < Number2);
	}
	else
	{
		Number1 = Generate_Random_Number_InRange(from, to);
		Number2 = Generate_Random_Number_InRange(from, to);
	}
}

st_Question GenerateQuestion(en_QuestionLevel QuizLevel, en_OperationType QuizOpType)
{
	st_Question Question;

	if (QuizLevel == MixedLvl)
	{
		QuizLevel = (en_QuestionLevel)Generate_Random_Number_InRange(1, 3);
	}

	if (QuizOpType == MixedOp)
	{
		QuizOpType = (en_OperationType)Generate_Random_Number_InRange(1, 4);
	}

	Question.OperationType = QuizOpType;

	switch (QuizLevel)
	{
	case EasyLvl:
		MakeSureNum1BiggerThanNum2InDivision(Question.Number1, Question.Number2, Question.OperationType, 1, 10);
		Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuizLevel;
		return Question;

	case MediumLvl:
		MakeSureNum1BiggerThanNum2InDivision(Question.Number1, Question.Number2, Question.OperationType, 10, 50);
		Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuizLevel;
		return Question;

	case HardLvl:
		MakeSureNum1BiggerThanNum2InDivision(Question.Number1, Question.Number2, Question.OperationType, 50, 100);
		Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuizLevel;
		return Question;

	default:
		return Question;
	}
}

void GenerateQuizQuestions(st_Quiz& Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		Quiz.QuestionList[QuestionNumber] = GenerateQuestion(Quiz.QuizLevel, Quiz.QuizOperationType);
	}
}

char GetOperationTypeSymbol(en_OperationType OpType)
{
	switch (OpType)
	{
	case Addition:
		return '+';
	case Subtraction:
		return '-';
	case Multiplication:
		return '*';
	case Division:
		return '/';
	}
}

void Print_Question(st_Quiz& Quiz, short QuestionNumber)
{
	cout << endl;
	cout << "Question[" << QuestionNumber + 1 << "]\n";
	cout << S_Stars(13) << endl;
	cout << Quiz.QuestionList[QuestionNumber].Number1 << " ";
	cout << GetOperationTypeSymbol(Quiz.QuestionList[QuestionNumber].OperationType) << endl;
	cout << Quiz.QuestionList[QuestionNumber].Number2 << endl;
	cout << "_________\n";
}

int Read_UserAnswer()
{
	string N;

	do
	{
		cin >> N;
		cout << endl;

	} while (!Check_Number_Int(N));

	return stoi(N);
}

void SetScreenColor(bool RightAnswer)
{
	if (RightAnswer)
	{
		system("color 2F");
	}
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

void CorrectTheQuestionAnswer(st_Quiz& Quiz, short QuestionNumber)
{
	if (Quiz.QuestionList[QuestionNumber].UserAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :-(\n";
		cout << "The Right Answer is: { " << Quiz.QuestionList[QuestionNumber].CorrectAnswer << " }\n" << endl;
	}
	else
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;

		cout << "Right Answer :-)\n" << endl;
	}

	SetScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(st_Quiz& Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		Print_Question(Quiz, QuestionNumber);
		Quiz.QuestionList[QuestionNumber].UserAnswer = Read_UserAnswer();

		CorrectTheQuestionAnswer(Quiz, QuestionNumber);
	}

	Quiz.IsPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}

string GetFinalResult(bool IsPass)
{
	if (IsPass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

string GetQuizLevelText(en_QuestionLevel QuizLevel)
{
	switch (QuizLevel)
	{
	case EasyLvl:
		return "Easy Lvl";
	case MediumLvl:
		return "Medium Lvl";
	case HardLvl:
		return "Hard Lvl";
	case MixedLvl:
		return "Mixed Lvl";
	}
}

string GetQuizOptype(en_OperationType OpType)
{
	switch (OpType)
	{
	case Addition:
		return "Addition";
	case Subtraction:
		return "Sutruction";
	case Multiplication:
		return "Multiplication";
	case Division:
		return "Division";
	case MixedOp:
		return "Mixed Op";
	}
}

void Print_QuizFinalResults(st_Quiz Quiz)
{
	cout << S_UnderScores(45) << endl << endl;
	cout << "- Final Result is --> " << GetFinalResult(Quiz.IsPass) << endl;
	cout << S_UnderScores(45) << endl << endl;

	cout << "- Number Of Questions ---------: " << Quiz.NumberOfQuestions << endl;
	cout << "- Quiz Level ------------------: " << GetQuizLevelText(Quiz.QuizLevel) << endl;
	cout << "- Operation Type --------------: " << GetQuizOptype(Quiz.QuizOperationType) << endl;
	cout << "- Number Of Right Answers -----: " << Quiz.NumberOfRightAnswers << endl;
	cout << "- Number Of Wrong Answers -----: " << Quiz.NumberOfWrongAnswers << endl;
	cout << S_UnderScores(45) << endl << endl;
}

void Play_MathGame()
{
	st_Quiz Quiz;

	Quiz.NumberOfQuestions = Read_NumberFromUser("- How Many Questions Do You Want? / Max = 100 ", 1, 100);
	Quiz.QuizLevel = Read_QuizLevel();
	Quiz.QuizOperationType = Read_QuizOperationType();
	
	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionListAnswers(Quiz);

	Print_QuizFinalResults(Quiz);
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

void Print_ByeByeScreen()
{
	system("color 5F");

	cout << endl << S_Tabs(1) << S_UnderScores(100) << endl << endl;
	cout << S_Tabs(5) << "Thank's For Playing Our Game Good Bye :-)" << endl;
	cout << S_Tabs(1) << S_UnderScores(100) << endl << endl << endl;
}

void PlayAgainOrEndGame(string& PlayAgain)
{
	PlayAgain = Read_YesOrNo_FromUser("- Do You Want To Play Another Game? ");

	if (PlayAgain == "N" || PlayAgain == "n")
	{
		Print_ByeByeScreen();
	}
}

void Start_MathGame()
{
	string PlayAgain;

	do
	{
		ResetGame();

		Play_MathGame();

		PlayAgainOrEndGame(PlayAgain);

	} while (PlayAgain == "Y" || PlayAgain == "y");

	NewLines(5);
}



//________________________________________________________________________________________________________________________________________


int main()
{
	srand((unsigned)time(NULL));


	Start_MathGame();



	return 0;

}

