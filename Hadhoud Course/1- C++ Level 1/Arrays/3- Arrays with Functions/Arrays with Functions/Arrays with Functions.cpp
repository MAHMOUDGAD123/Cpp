
#include <string>
#include <iostream>

using namespace std;

void ReadGrades(float Grades[3])
{
    cout << "Please enter your Grades?" << endl;

    cout << "Grade 1 : ";
    cin >> Grades[0];
    cout << "\n";
    
    cout << "Grade 2 : ";
    cin >> Grades[1];
    cout << "\n";

    cout << "Grade 3 : ";
    cin >> Grades[2];
    cout << "\n";

    cout << "Your Grades are : " << Grades[0] << " " << Grades[1] << " " << Grades[2] << endl << endl;

}


float PrintGrades(float Grades[3])
{
    
    float Grades_Avg = (Grades[0] + Grades[1] + Grades[2]) / 3;


    return Grades_Avg;

}


int main()
{
    float Grades[3];

    ReadGrades(Grades);
    cout << "The average of your grades = " << PrintGrades(Grades) << endl;


    return 0;
}

