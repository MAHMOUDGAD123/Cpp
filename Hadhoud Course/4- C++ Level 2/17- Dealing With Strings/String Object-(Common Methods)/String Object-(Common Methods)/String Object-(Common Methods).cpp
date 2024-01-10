#include <iostream>
#include <string>

using namespace std;

// https://cplusplus.com/reference/string/string/



string Find_Letters_In_String(string& S, const string &s)
{
    return (S.find(s) != S.npos) ? "--> \"" + s + "\" Is Found" :"--> \"" + s + "\" Not Found";
}



int main()
{
    string Name{ "Mahmoud" };

    //***************************************** String iterators *****************************************************

    // string::begin()  &  string::end()  

    cout << "- Name.begin() = " << *(Name.begin()) << endl;
    cout << "- Name.end()   = " << *(Name.end() - 1) << endl;

    cout << "- Print A String Using Iterator: \" ";
    for (string::iterator iter = Name.begin(); iter != Name.end(); iter++)
        cout << *iter;
    cout << " \"";
        
    cout << endl << "___________________________________________________________________" << endl << endl;
    

    // string::rbegin()  &  string::rend()

    cout << "- Name.rbegin() = " << *(Name.rbegin()) << endl;
    cout << "- Name.rend()   = " << *(Name.rend() - 1) << endl;

    cout << "- Print A String Reversed Using Reverse_Iterator: \" ";
    for (string::reverse_iterator iter = Name.rbegin(); iter != Name.rend(); iter++)
        cout << *iter;
    cout << " \"";
    
    cout << endl << "___________________________________________________________________" << endl << endl;

    // string::cbegin()  &  string::cend()

    cout << "- Name.cbegin() = " << *(Name.cbegin()) << endl;
    cout << "- Name.cend()   = " << *(Name.cend() - 1) << endl;

    cout << "- Print A String Reversed Using Const_Iterator: \" ";
    for (auto iter = Name.cbegin(); iter != Name.cend(); iter++)
        cout << *iter;
    cout << " \"";

    cout << endl << "___________________________________________________________________" << endl << endl;


    // string::crbegin()  &  string::crend()

    cout << "- Name.crbegin() = " << *(Name.crbegin()) << endl;
    cout << "- Name.crend()   = " << *(Name.crend() - 1) << endl;

    cout << "- Print A String Reversed Using Const_Reverse_Iterator: \" ";
    for (auto iter = Name.crbegin(); iter != Name.crend(); iter++)
        cout << *iter;
    cout << " \"";

    cout << endl << "___________________________________________________________________" << endl << endl;
    cout << endl << "___________________________________________________________________" << endl << endl;

    //********************************************* String Capacity ***********************************************************


    // string::size() & string::length() & string::capacity() & string::max_size()

    cout << "- Size     = " << Name.size() << endl;
    cout << "- Length   = " << Name.length() << endl;
    cout << "- Max_Size = " << Name.max_size() << endl;
    cout << "- Capacity = " << Name.capacity() << endl;
    

    cout << endl << "___________________________________________________________________" << endl << endl;

    // string::resize(unsigned n, char c)
    string S1{ "This C" };

    cout << "- S1 Before Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 Before Resizing = " << S1.size() << endl;

    S1.resize(S1.size() + 2, '+');
    cout << "- S1 After Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 After Resizing = " << S1.size() << endl;

    S1.resize(6);
    cout << "- S1 After Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 After Resizing = " << S1.size() << endl;

    // when resizing up with nothing resize() add a NULL values (add nothing)
    // but it only increase the size of the string
    S1.resize(20);
    cout << "- S1 After Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 After Resizing = " << S1.size() << endl;

    cout << endl << "___________________________________________________________________" << endl << endl;
    
    // string::clear()

    string S2{ "Clear it!" };

    cout << "- S2 Before Clear: \" " << S2 << " \"" << endl;

    S2.clear();
    cout << "- S2 After Clear: \" " << S2 << " \"" << endl;
    

    cout << endl << "___________________________________________________________________" << endl << endl;
    
    // string::empty() --> return (true) if the string is empty
    
    string S3{ "Empty!" };

    cout << (S3.empty() ? "Empty!\n" : "Not Empty!\n") << endl;

    S3.clear();
    cout << (S3.empty() ? "Empty!\n" : "Not Empty!\n") << endl;


    cout << endl << "___________________________________________________________________" << endl << endl;
    
    // string::shrink_to_fit()
    // Requests the string to reduce its capacity to fit its size.

    string S4(30, 'M'); // Another way to define a string variable (size, character)
    cout << "- S4 = \" " << S4 << " \"" << endl;

    cout << "- Original Capacity = " << S4.capacity() << endl;
    cout << "- Size = " << S4.size() << endl;

    S4.resize(10);
    cout << "- Capacity After Resizing = " << S4.capacity() << endl;
    cout << "- Size = " << S4.size() << endl;

    S4.shrink_to_fit();
    cout << "- Capacity After Shrinking = " << S4.capacity() << endl;
    cout << "- Size = " << S4.size() << endl;



    cout << endl << "___________________________________________________________________" << endl << endl;

    // push_back()  & pop_back()
    
    string Name1{ "Mahmoud" };

    Name1.push_back(' ');
    Name1.push_back('G');
    Name1.push_back('a');
    Name1.push_back('d');
    cout << Name1 << endl;

    Name1.pop_back();
    Name1.pop_back();
    Name1.pop_back();
    Name1.pop_back();
    cout << Name1 << endl;


    cout << endl << "___________________________________________________________________" << endl << endl;

    string S("My Name Is: \" Mahmoud Abdelrahman Ismail Gad");

    cout << Find_Letters_In_String(S, "Gad") << endl;
    cout << Find_Letters_In_String(S, "Mahmoud") << endl;
    cout << Find_Letters_In_String(S, "Amira") << endl;



    cout << endl << "___________________________________________________________________" << endl << endl;



    // More Method in This Link:  https://cplusplus.com/reference/string/string/

    // Training in VS Code 




    
    return 0;
}