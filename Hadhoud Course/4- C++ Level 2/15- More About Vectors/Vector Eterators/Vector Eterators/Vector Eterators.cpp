#include <iostream>
#include <vector>

using namespace std;

    /*
       Vector iterators are used to point to the memory address of a vector element.
       In some ways, they act like pointers in C++.

       So, we can say iterator is a (Pointer) for the vector

       data_type of the iterator must be the same as the vector

       We can create vector iterators with the syntax:

       vector <data_type>::iterator iteratorName;
   */



// look at this :----> https://www.programiz.com/cpp-programming/vectors


int main()
{
    vector <short> vNums{ 1,2,3,4 };

    // Iterator Declaration
    vector <short>::iterator iter;
    
    // The begin() function returns an iterator that points to the first element of the vector.
    // iter points to num[0] = 1
    iter = vNums.begin();

    cout << "-> vNums[0] = " << *iter << endl;

    // The end() function points to the "theoretical" element that comes after the final element of the vector.
    // Due to the nature of the end() function
    // We have used the code { num.end() - 1 } to point to the last element of the num vector num[3] = 4
    iter = vNums.end() - 1;

    cout << "-> vNums[3] = " << *iter << endl;

    // We can use iterator to points to any element of the vector
    iter = vNums.begin() + 1;
    cout << "-> vNums[1] = " << *iter << endl;

    iter = vNums.end() - 2;
    cout << "-> vNums[2] = " << *iter << endl;


    cout << endl << "________________________________________________________________________________________" << endl << endl;


    // We can use iterator to access vector elements
    // But first we need to make it iterate to the first element
    iter = vNums.begin();

    cout << "-> Initial Vector Elements: {  ";
    for (short i = 0; i < vNums.size(); i++)
    {
        cout << iter[i] << "  ";
    }
    cout << "}" << endl;


    // We can change the vector elements using iterator

    cout << "-> Updated Vector Elements: {  ";
    for (short i = 0; i < vNums.size(); i++)
    {
        iter[i] *= 10;
        cout << iter[i] << "  ";
    }
    cout << "}";


    cout << endl << "________________________________________________________________________________________" << endl << endl;

    vector <int> vNumbers{ 1,2,3,4,5,6,7,8,9 };

    vector <int>::iterator Iiter;

    // Using iterator with for loop.
    // Access & Print form begin element ---> end element.
    /* 
        Here, we have used a for loop to initialize and iterate
        the iterator from the beginning of the vector to the end of the vector
        using the begin() and end() functions.
    */

    cout << "-> Integer Vector Elements: {  ";
    for (Iiter = vNumbers.begin(); Iiter != vNumbers.end(); Iiter++)
    {
        cout << *Iiter << "  ";
    }
    cout << "}";

    cout << endl << "________________________________________________________________________________________" << endl << endl;

    vector <string> vName{ "Mahmoud","Abdelrahman","Ismail","Abdelrahman","Ismail","Gad" };

    vector <string>::iterator Siter;

    cout << "-> String Vector Elements: {  ";
    for (Siter = vName.begin(); Siter != vName.end(); Siter++)
    {
        cout << *Siter << "  ";
    }
    cout << "}";

    cout << endl << "________________________________________________________________________________________" << endl << endl;













    return 0;
}