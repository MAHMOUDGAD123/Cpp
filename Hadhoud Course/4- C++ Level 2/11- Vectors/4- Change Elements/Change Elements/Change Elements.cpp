#include <iostream>
#include <vector>


using namespace std;


int main()
{
    vector <short> vNumbers{ 1,2,3,4,5,6,7,8,9,10 };

    // Print vector elements using ranged for loop without changing its elements
    // You should use (const) & (&) to prevent elements modifing and make the process more fast
    cout << "\n-> Initial Vector v1: {  ";
    for (const short& Number : vNumbers)
    {
        cout << Number << "  ";
    }
    cout << "}" << endl;


    cout << "\n_________________________________________________________________________________\n" << endl << endl;



    // Print the vector elements using ranged loop with changing its elements
    // You should use only (&) to make the process more fast
    cout << "-> Updated Vector v2: {  ";
    for (short& Number : vNumbers)
    {
        Number *= 10;
        cout << Number << "  ";
    }
    cout << "}" << endl;


    cout << "\n_________________________________________________________________________________\n" << endl << endl;


    // changing the vector elements by { .at() & [] }
    vNumbers[1] = 11;
    vNumbers.at(3) = 33;
    vNumbers[5] = 55;
    vNumbers.at(7) = 77;
    vNumbers.at(9) = 99;

    cout << "-> Updated Vector v3: {  ";
    for (const short& Number : vNumbers)
    {
        cout << Number << "  ";
    }
    cout << "}" << endl;


    cout << "\n_________________________________________________________________________________\n" << endl << endl;

    
    
    
    return 0;
}