#define _using_math_defines

#include<string>
#include<iostream>
#include<math.h>
#include<cmath>


using namespace std;


enum enGender { male, female };
enum enMaritalStatus { married, single };



struct stAddress
{

    string BuildingNo;
    string StreetName;
    string City;
    string ZipCode;
    string Country;


};


struct stContactInfo
{
    string EmailAdd;
    string PhoneNo;

    stAddress Address;

};

struct stPerson
{
    string FName;
    string LName;
    string Age;
    string NationalId;

    stContactInfo ContactInfo;

    enMaritalStatus MaritalStatus;
    enGender Gender;


};


int main()

{

    stPerson Person1;

    cout << "Please sir we need some information about you :" << endl << endl;


    cout << "first name : ";
    cin >> Person1.FName;
    cout << "\n" << endl;

    cout << "last name : ";
    cin >> Person1.LName;
    cout << "\n" << endl;

    cout << "Age : ";
    cin >> Person1.Age;
    cout << "\n" << endl;


    cout << "National Id : ";
    cin >> Person1.NationalId;
    cout << "\n" << endl;
    
    
    cout << "Phone Number : ";
    cin >> Person1.ContactInfo.PhoneNo;
    cout << "\n" << endl;

    
    cout << "Email Adderss : ";
    cin >> Person1.ContactInfo.EmailAdd;
    cout << "\n" << endl;

    cout << "We need some information about your adderss" << endl;
    cout << "\n" << endl;


    cout << "Building Number : ";
    cin >> Person1.ContactInfo.Address.BuildingNo;
    cout << "\n" << endl;


    cout << "Street Name : ";
    cin >> Person1.ContactInfo.Address.StreetName;
    cout << "\n" << endl;
    
    cout << "Zip code : ";
    cin >> Person1.ContactInfo.Address.ZipCode;
    cout << "\n" << endl;
    
    cout << "City : ";
    cin >> Person1.ContactInfo.Address.City;
    cout << "\n" << endl;
    
    
    cout << "Country : ";
    cin >> Person1.ContactInfo.Address.Country;
    cout << "\n" << endl;

   
    Person1.MaritalStatus = enMaritalStatus::single;
    Person1.Gender = enGender::male;


    cout << "your name is : " << Person1.FName << " " << Person1.LName << endl;
    

    // Print all data .

}


