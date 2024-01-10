#include <iostream>
#include <string>

using namespace std;


struct stStudent
{
    string Name = "";
    string MobileNumber = "";
    unsigned short age = 0;
    unsigned int Id = 0;
};

int main()
{
    stStudent Student, *ptr;

    ptr = &Student;


    //  (*ptr).  ==  ptr->  ==  Student.
    // But  ptr->  is far more preferable than  (*ptr)


    // Reading Student Data
    cout << "Enter The Student Data:\n\n";

    cout << "Full Name: ";
    getline(cin, (*ptr).Name);

    cout << "Mobile No.: ";
    getline(cin, (*ptr).MobileNumber);

    cout << "Age: ";
    cin >> (*ptr).age;

    cout << "Id: ";
    cin >> (*ptr).Id;

    cout << endl;


    cout << "__________________________________________________\n\n";



    // Printing Student Data using structure
    cout << "Displaying Student Data Using Structre:\n\n";

    cout << "- Student Name      : ";
    cout << Student.Name << endl;

    cout << "- Student Mobile No.: ";
    cout << Student.MobileNumber << endl;

    cout << "- Student Age       : ";
    cout << Student.age << endl;

    cout << "- Student Id        : ";
    cout << Student.Id << endl;


    cout << "__________________________________________________\n\n";


    // Printing Student Data using Pointer
    cout << "Displaying Student Data Using Pointer:\n\n";

    cout << "- Student Name      : ";
    cout << ptr->Name << endl;

    cout << "- Student Mobile No.: ";
    cout << ptr->MobileNumber<< endl;

    cout << "- Student Age       : ";
    cout << ptr->age << endl;

    cout << "- Student Id        : ";
    cout << ptr->Id << endl;

    cout << "__________________________________________________\n\n";


    return 0;
}
