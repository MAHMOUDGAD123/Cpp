
#include <string>
#include <iostream>


using namespace std;




//***************************** PROGRAM 1 ***********************************
// Print fullname

struct st_Info
{
    string firstname;
    string lastname;
    bool Reversed;
};

st_Info ReadInfo()
{
    st_Info Info;

    cout << "Please enter first name : ";
    cin >> Info.firstname;
    cout << "\n";

    cout << "Please enter last name : ";
    cin >> Info.lastname;
    cout << "\n";

    string answer;
    cout << "Do you want your name reversed or not? (yes or no)\n";
    cin >> answer;

    if (answer == "Yes" || answer == "yes" || answer == "YES")
        Info.Reversed = true;

    else if (answer == "No" || answer == "no" || answer == "NO")
        Info.Reversed = false;



    return Info;
}

string GetFullName(st_Info Info)
{
    string fullname;

    if(Info.Reversed)
        fullname = Info.lastname + " " + Info.firstname;

    else
        fullname = Info.firstname + " " + Info.lastname;



    return fullname;
}

void PrintInfo(string fullname)
{
    cout << "your full_name is : " << fullname << endl << endl;
}


//***************************** PROGRAM 2 ***********************************
// Half number


float ReadNumber()
{
    float number;
    cout << "Please enter any number : ";
    cin >> number;
    cout << "\n\n";

    return number;
}

float GetHalfNumber(float number)
{
    return number / 2;
}

void PrintHalfNumber(float number)
{
    cout << "The half of " << number << " = " << GetHalfNumber(number) << endl << endl;
}



//***************************** PROGRAM 3 ***********************************
// Mark Pass\fail

enum en_PassOrFail{Fail = 0, Pass = 1};

int ReadMark()
{
    int Mark;
    cout << "Please enter your mark : ";
    cin >> Mark;
    cout << "\n";

    return Mark;

}

en_PassOrFail CheckMark(int Mark)
{
    
    if (Mark < 50)
        return en_PassOrFail::Fail;
    else
        return en_PassOrFail::Pass;

}

void PrintPass_Fail(int Mark)
{
    if (CheckMark(Mark) == en_PassOrFail::Fail)
        cout << "Sorry, your faild.\n\n";
    else
        cout << "Congratulaltioins, you pass.\n\n";

}



//***************************** PROGRAM 4 ***********************************
// sum & Average of 3 numbers


void ReadNumbers(int& n1, int& n2, int& n3)
{
    cout << "Please enter 3 numbers to get sum\\\n\n";

    cout << "Number 1 : ";
    cin >> n1;
    cout << "\n";

    cout << "Number 2 : ";
    cin >> n2;
    cout << "\n";

    cout << "Number 3 : ";
    cin >> n3;
    cout << "\n";


}


int SumOf3Numbers(int n1, int n2, int n3)
{   
    int Result = n1 + n2 + n3;
    return Result;
}


void PrintTheResults(int Result)
{
    cout << "***************\n";
    cout << "The Summation = " << Result << endl;
    cout << "The Average = " << (float) Result / 3 << endl;
    cout << "***************\n\n\n";
}




// Program 4 Another solution using array

void ReadNumbersUsingArray(int Numbers[], int& ArrayNumbers)
{
    cout << "How many numbers you want to add?\n";
    cout << "your answer : ";
    cin >> ArrayNumbers;
    cout << "\n";

    cout << "Please enter numbers\\\n\n";

    for (int i = 0; i < ArrayNumbers; i++)
    {
        cout << "Number " << i + 1 << " : ";
        cin >> Numbers[i];
        cout << "\n";

    }

}

int SUMOfArrayNumbers(int Numbers[], int ArrayNumbers)
{
    int SUM = 0;
    for (int i = 0; i < ArrayNumbers; i++)
    {
        SUM += Numbers[i];
    }

    return SUM;

}

void PrintSUMOfArrayNumbers(int SUM, int ArrayNumbers)
{
    cout << "******************\n";
    cout << " The Result = " << SUM << endl;
    cout << " The Result = " << (float) SUM / ArrayNumbers << endl;
    cout << "******************\n\n\n";
}

//************************************************************

int main()
{
    // PROGRAM 1
    //PrintInfo(GetFullName(ReadInfo()));


    
    //PROGRAM 2
    //PrintHalfNumber(ReadNumber());
    


    //PROGRAM 3
    //PrintPass_Fail(ReadMark());




    //PROGRAM 4
    //int n1, n2, n3;
    //ReadNumbers(n1, n2, n3);
    //PrintTheSUM(SumOf3Numbers(n1, n2, n3));
    // Or
    //cout << n1 << " + " << n2 << " + " << n3 << " = " << SumOf3Numbers(n1, n2, n3) << endl << endl;

    //PROGRAM 4 another solution
    int Numbers[100];
    int ArrayNumbers = 0;
    ReadNumbersUsingArray(Numbers, ArrayNumbers);
    PrintSUMOfArrayNumbers(SUMOfArrayNumbers(Numbers, ArrayNumbers), ArrayNumbers);






    
    return 0;
}
