#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;


void Print_Vector(vector <int> &V)
{
  for (vector <int>::iterator iter = V.begin(); iter != V.end(); iter++)
    cout << ' ' << *iter;
    cout << endl;
}
void Print_Vector(vector <char> &V)
{
  for (vector <char>::iterator iter = V.begin(); iter != V.end(); iter++)
    cout << ' ' << *iter;
    cout << endl;
}


/*
  - There is 2 types of swap functions:
    
    (1) void swap(variable1 &V1, varaible2 &V2) --> {   swap(V1, V2);   }

    (2) void swap (variable &V) --> {   V1.swap(V2);   }

    --> You can use both with with all data types
*/




int main()
{
    cout << endl << "__________________________________(1)_________________________________" << endl << endl;

    int N1{123};
    int N2{456};
    
    cout << "N1 Before Swap: ";
    cout << N1 << endl;
    cout << "N2 Before Swap: ";
    cout << N2 << endl;
    
    swap(N1, N2);
    
    cout << endl;
    cout << "N1 After Swap: ";
    cout << N1 << endl;
    cout << "N2 After Swap: ";
    cout << N2 << endl;

    cout << "\n\n----------------------------------------------------\n\n\n";

    int N3{1997};
    int N4{2022};
    
    cout << "N3 Before Swap: ";
    cout << N3 << endl;
    cout << "N4 Before Swap: ";
    cout << N4 << endl;
    
    swap(N3, N4);

    cout << endl;
    cout << "N3 After Swap: ";
    cout << N3 << endl;
    cout << "N4 After Swap: ";
    cout << N4 << endl;

    cout << endl << "__________________________________(2)_________________________________" << endl << endl;

    string S1( "MAHMOUD" );
    string S2( "GAD" );
    
    cout << "S1 Before Swap: ";
    cout << S1 << endl;
    cout << "S2 Before Swap: ";
    cout << S2 << endl;
    
    swap(S1, S2);
    cout << endl;
    cout << "S1 After Swap: ";
    cout << S1 << endl;
    cout << "S2 After Swap: ";
    cout << S2 << endl;

   
    cout << endl << "__________________________________(3)_________________________________" << endl << endl;

    string S3(7, 'M');
    string S4(7, 'G');

    cout << "S3 Before Swap: ";
    cout << S3 << endl;
    cout << "S4 Before Swap: ";
    cout << S4 << endl;
    
    S3.swap(S4);
    cout << endl;
    cout << "S3 After Swap: ";
    cout << S3 << endl;
    cout << "S4 After Swap: ";
    cout << S4 << endl;
 

    cout << endl << "__________________________________(4)_________________________________" << endl << endl;

    vector <int> V1{ 0,1,2,3,4 };
    vector <int> V2{ 5,6,7,8,9 };

    cout << "V1 Before Swap:";
    Print_Vector(V1);
    cout << "V2 Before Swap:";
    Print_Vector(V2);
    cout << endl;

    V1.swap(V2);

    cout << "V1 After Swap:";
    Print_Vector(V1);
    cout << "V2 After Swap:";
    Print_Vector(V2);
    cout << endl;
    
    cout << endl << "__________________________________(5)_________________________________" << endl << endl;

    vector <char> V3 (7,'X');
    vector <char> V4 (7,'Y');

    cout << "V3 Before Swap:";
    Print_Vector(V3);
    cout << "V4 Before Swap:";
    Print_Vector(V4);
    cout << endl;

    swap(V3, V4);
    
    cout << "V3 After Swap:";
    Print_Vector(V3);
    cout << "V4 After Swap:";
    Print_Vector(V4);
    cout << endl;
    

    cout << endl << "______________________________________________________________________" << endl << endl;

    return 0;

}
