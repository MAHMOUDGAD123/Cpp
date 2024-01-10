
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


// Using Recursion




void PrintNumbersFromNUpToM(short N, short M)
{
    if (N <= M)
    {
        cout << N << "  ";
        PrintNumbersFromNUpToM(N + 1, M);
    }
}

void PrintNumbersFromMDownToN(short M, short N)
{
    if (M >= N)
    {
        cout << M << "  ";
        PrintNumbersFromMDownToN(M - 1, N);
    }
}

//******************************************************************

int Result = 1; // Global Variable
int Power_MG(short N, short P)
{
    if (N == 0)
    {
        return 0;
    }

    if (P == 0)
    {
        return 1;
    }

    
    if (P > 1)
    {
        P--;
        Result *= N;
        Power_MG(N, P);
    }
    else
    {
        return Result * N;
    }
}

int Power(short Base, short P)
{
    if (P == 0)
    {
        return 1;
    }
    else
    {
        return (Base * Power(Base, P - 1));
    }
}

//******************************************************************

int Factorial(short N)
{
    if (N == 0 || N == 1)
    {
        return 1;
    }
    else
    {
        return (N * Factorial(N - 1));
    }
}

//******************************************************************

void Print_NumberReversed(unsigned int Number)
{
    if (Number > 0)
    {
        cout << Number % 10;
        Print_NumberReversed(Number / 10);
    }
}

unsigned int ReverseANumber(unsigned int Number)
{
    static int Reversed ,Remainder;

    if(Number > 0)
    {
        Remainder = Number % 10;
        Reversed = Reversed * 10 + Remainder;
        ReverseANumber(Number / 10);
    }
    else
    {
        return Reversed;
    }
}

//******************************************************************

bool IsPrimeNumber(int Number, unsigned short i = 2)
{
    if (Number <= 2)
    {
        return true;
    }
    if (Number % i == 0)
    {
        return false;
    }
    if (i >= Number / 2)
    {
        return true;
    }

    return IsPrimeNumber(Number, i + 1);
}

//******************************************************************

string ReverseAString(string S, short i = 2)
{
    static string Reversed_S;

    if (Reversed_S.length() != S.length())
    {
        Reversed_S += S[S.length() - 1];

        if (Reversed_S.length() != S.length())
        {
            S[S.length() - 1] = S[S.length() - i];
        }

        ReverseAString(S, i + 1);
    }
    
    return Reversed_S;
}

string RevString(string S)
{
    static string Reversed_S;

    if (S.length() > 0)
    {
        Reversed_S += S[S.length() - 1];
        S.pop_back();

        RevString(S);
    }

    return Reversed_S;
}

string RevStr(string S, short i = 0)
{
    static string Reversed_S;

    if (Reversed_S.length() != S.length())
    {
        Reversed_S += S[S.length() - 1 - i];

        RevStr(S, i + 1);
    }

    return Reversed_S;
}

//******************************************************************


int main()
{
    //cout << "Number From N UP To M --> { ";
    //PrintNumbersFromNUpToM(1, 10);
    //cout << "}";


    //cout << endl << endl;


    //cout << "Number From M Down To N --> { ";
    //PrintNumbersFromMDownToN(10, 1);
    //cout << "}";


    //cout << endl << endl;


   //cout << "- MG Power = " << Power_MG(4, 0.5) << endl;
    cout << endl;
    cout << "- Hadhoud Power = " << Power(2, 3) << endl;


    //cout << endl << endl;


    //cout << "-> Factorail = " << Factorial(1) << endl;


    //cout << endl << endl;


    //cout << "The Number Reversed is: " << ReverseANumber(1234567) << endl;


    //cout << endl << endl;


    /*unsigned short Number = Read_Positive_Number("Enter A Number:--> ");

    if (IsPrimeNumber(Number))
    {
        cout << "{ " << Number << " } Is A Prime Number." << endl;
    }
    else
    {
        cout << "{ " << Number << " } Is Not A Prime Number." << endl;
    }*/


    //cout << endl << endl;


    //string S = Read_Text("Enter A Text:--> ");

    //cout << "The String Reversed Is: " << ReverseAString(S) << endl;

    //cout << "The String Reversed Is: " << RevString(S) << endl;

    //cout << "The String Reversed Is: " << RevStr(S) << endl;


    return 0;
}

