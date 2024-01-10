#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Like an array, we can also use the square brackets [] to access vector elements.
    // However, the at() function is preferred over [].
    // Because at() throws an exception whenever the vector is out of bound.
    // While [] gives a garbage value when the vector is out of bound.


    vector <int> vNumbers{ 1,2,3,4,5,6,7,8,9 };

    cout << "#Accessing Vector Elements Using { vNumbers.at(i) }\n\n";
    for (short i = 0; i < vNumbers.size(); i++)
    {
        cout << "- Element[" << i + 1 << "]: " << vNumbers.at(i) << endl;
    }
    cout << endl << "_________________________________________" << endl << endl;


    vector <float> vfNumbers = { 10.54,20.87,30.89,40.45,50.41,60.41,70.87,80.63,90.65 };

    cout << "#Accessing Vector Elements Using { vfNumbers[i] }\n\n";
    for (short i = 0; i < vfNumbers.size(); i++)
    {
        cout << "- Element[" << i + 1 << "]: " << vfNumbers[i] << endl;
    }
    cout << endl << "_________________________________________" << endl << endl;



    return 0;
}