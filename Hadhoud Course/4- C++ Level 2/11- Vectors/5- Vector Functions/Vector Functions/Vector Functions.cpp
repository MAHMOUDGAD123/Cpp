
#include <iostream>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

void Print_Vector(vector <short> vNumbers)
{
    cout << "Vector Eelements = ";

    if (!vNumbers.empty())
    {
        for (short Number : vNumbers)
        {
            cout << Number << " ";
        }
    }
    else
    {
        cout << "Empty";
    }

    cout << endl << endl << endl;
}

void Clear_Vector(vector <short> vNumbers)
{
    while (!vNumbers.empty()) // == (vNumbers.size() > 0)
    {
        vNumbers.pop_back();
    }
}

int main()
{
    vector <short> vNumbers;
    
    // Use push_back() to add elements
    for (short i = 1; i <= 10; i++)
    {
        vNumbers.push_back(i * 10);
    }

    cout << "_____________ Original Vector _____________" << endl << endl;


    // size() returns the number of elements in the vector
    cout << "Vector Size = " << vNumbers.size() << endl;
    // capacity() check the overall size of a vector
    cout << "Vector Capacity = " << vNumbers.capacity() << endl;

    // You have to check first if the vector is empty or not
    if (!vNumbers.empty())
    {
        cout << "The First Element = " << vNumbers.front() << endl;
        cout << "The Last Element = " << vNumbers.back() << endl;
    }

    Print_Vector(vNumbers);

    cout << "___________ Vector After Update ___________" << endl << endl;

    // Use pop_back() to remove vector elements (element by element)
    vNumbers.pop_back();
    
    cout << "Vector Size = " << vNumbers.size() << endl;
    cout << "Vector Capacity = " << vNumbers.capacity() << endl;

    if (!vNumbers.empty())
    {
        cout << "The First Element = " << vNumbers.front() << endl;
        cout << "The Last Element = " << vNumbers.back() << endl;
    }

    Print_Vector(vNumbers);

    vNumbers.pop_back();
    vNumbers.pop_back();

    cout << "Vector Size = " << vNumbers.size() << endl;
    cout << "Vector Capacity = " << vNumbers.capacity() << endl;

    if (!vNumbers.empty())
    {
        cout << "The First Element = " << vNumbers.front() << endl;
        cout << "The Last Element = " << vNumbers.back() << endl;
    }

    Print_Vector(vNumbers);
    
    // Before clear vector using pop_back() you have to check if the vector is empty or not
    // You can use empty() that returns 1(true) if vector is empty
    // Or you can use size() to check the number of elements

    Clear_Vector(vNumbers);

    // Or you can just use clear() to remove all vector elements (Recommended)
    vNumbers.clear();

    cout << "Vector Size = " << vNumbers.size() << endl;
    cout << "Vector Capacity = " << vNumbers.capacity() << endl;

    if (!vNumbers.empty())
    {
        cout << "The First Element = " << vNumbers.front() << endl;
        cout << "The Last Element = " << vNumbers.back() << endl;
    }

    Print_Vector(vNumbers);



    return 0;
}
