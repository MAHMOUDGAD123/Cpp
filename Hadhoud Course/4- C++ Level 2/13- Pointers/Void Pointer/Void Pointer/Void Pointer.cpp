#include <iostream>
#include <string>

using namespace std;

// https://www.programiz.com/cpp-programming/pointer-void


struct stStudent
{
    string name = "";
    short age = 0;
};

int main()
{
    // if you want to use the pointer to point to a different data types 
    // you have to use the (Void Pointer)
    // (Void Pointer) is a generic pointer which you can point to all data types
    
    // You can't use  _ *ptr _  to access the value of the varible
    // To acces Data the value of the variable
    // You have used the static_cast operator to convert the data type of the pointer from (void*) to (data_type*)
   
    // *(static_cast<data_type*>(pointer_name))  --> this called (static_cast)
    // *((data_type*)ptr)  --> this called (C-style casting)
    // (static_cast) is preferred to (C-style casting).
    // Don't use (C-style casting)



    /*
        void pointers cannot be used to store addresses of variables with const or volatile qualifiers.

        void *ptr;
        const double d = 9.0;

        Error: invalid conversion from const void* to void*
        ptr = &d;
    */


    void* ptr;

    int i = 10;

    ptr = &i;

    cout << "When Pointing to (ptr)-> (i)int:\n\n";
    cout << "- Address Of Pointer                           = " << ptr << endl;
    cout << "- The Value of Pointer Using (static_cast)     = " << *(static_cast<int*>(ptr)) << endl;
    cout << "- The Value of Pointer Using (C-style casting) = " << *((int*)ptr) << endl;
    cout << endl;

    cout << "_____________________________________________________\n\n";

    float f = 76.64;
    ptr = &f;

    cout << "When Pointing to (ptr)-> (f)float:\n\n";
    cout << "- Address Of Pointer   = " << ptr << endl;
    cout << "- The Value of Pointer = " << *(static_cast<float*>(ptr)) << endl;
    cout << endl;

    cout << "_____________________________________________________\n\n";

    string s = "Mahmoud";

    ptr = &s;

    cout << "When Pointing to (ptr)-> (s)string:\n\n";
    cout << "- Address Of Pointer   = " << ptr << endl;
    cout << "- The Value of Pointer = " << *(static_cast<string*>(ptr)) << endl;
    cout << endl;

    cout << "_____________________________________________________\n\n";

    stStudent Student;

    ptr = &Student;

    /*
        for struct data_type you have to use this:

        (static_cast<struct_name*>(pointer_name))->variable_name
    */

    cout << "Enter Student Name: ";
    getline(cin, (static_cast<stStudent*>(ptr))->name);

    cout << "Enter Student Age: ";
    cin >> (static_cast<stStudent*>(ptr))->age;

    cout << "\nWhen Pointing to (ptr)-> (Student)struct:\n\n";
    cout << "- Address Of Pointer   = " << ptr << endl;
    cout << "- Student Name         = " << (static_cast<stStudent*>(ptr))->name << endl;
    cout << "- Student Age          = " << (static_cast<stStudent*>(ptr))->age << endl;
    cout << endl;

    cout << "_____________________________________________________\n\n";

    return 0;
}
