#include <iostream>

using namespace std;

int main()
{

    // cin.get(char& var_Name, int length);

    char Name[20];

    cout << "Enter Your Name:--> ";
    cin.get(Name, 20);

    printf("\n\nYour Name Is: \"%s\"\n\n", Name);

    cout << "Enter Your Name:--> ";
    cin.ignore(1,'\n');
    *Name = cin.get(); // only take a char input

    printf("\n\nYour Name Is: \"%s\"\n\n", Name);

    return 0;
}