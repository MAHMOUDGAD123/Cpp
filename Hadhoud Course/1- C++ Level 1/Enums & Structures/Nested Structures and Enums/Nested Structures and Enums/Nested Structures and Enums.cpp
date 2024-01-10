#define _using_math_defines

#include<string>
#include<iostream>
#include<math.h>
#include<cmath>


using namespace std;


enum enColor{ red , purple , blue , green , yellow };
enum enGender{ male , female };
enum enMaritalStatus{ married , single};



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

    enColor FavColor;
    enMaritalStatus MaritalStatus;
    enGender Gender;


};


int main()

{

    stPerson Person1;

    Person1.FName = "Mahmoud";
    Person1.LName = "Gad";
    Person1.Age = "25";

    Person1.NationalId = "29709101204993";
    Person1.ContactInfo.PhoneNo = "01097890670";
    Person1.ContactInfo.EmailAdd = "hooda.gad333@gmail.com";
    Person1.ContactInfo.Address.BuildingNo = "777";
    Person1.ContactInfo.Address.StreetName = "7";
    Person1.ContactInfo.Address.ZipCode = "35511";
    Person1.ContactInfo.Address.City = "Mansoura";
    Person1.ContactInfo.Address.Country = "Egypt";

    Person1.FavColor = enColor::purple;
    Person1.MaritalStatus = enMaritalStatus::single;
    Person1.Gender = enGender::male;


    cout << "your name is : " << Person1.FName << " " << Person1.LName << endl;




}


