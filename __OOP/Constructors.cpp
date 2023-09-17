#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/
// https://www.geeksforgeeks.org/constructors-c/?ref=lbp

/*

  ## A constructor is different from normal functions in following ways:

   - Constructor has same name as the class itself
   - Default Constructors don’t have input argument however, Copy and Parameterized Constructors have input arguments.
   - Constructors don’t have return type.
   - A constructor is automatically called when an object is created.
   - It must be placed in public section of class.
   - If we do not specify a constructor, C++ compiler generates a default constructor for object (expects no parameters and has an empty body).

*/

/*

  Let us understand the types of constructors in C++ by taking a real-world example.
  Suppose you went to a shop to buy a marker. When you want to buy a marker, what are the options.
  The first one you go to a shop and say give me a marker.
  So just saying give me a marker mean that you did not set which brand name and which color,
  you didn’t mention anything just say you want a marker.
  So when we said just I want a marker so whatever the frequently sold marker is
  there in the market or in his shop he will simply hand over that.
  -> And this is what a default constructor is!

  The second method is you go to a shop and say I want a marker a red in color and XYZ brand.
  So you are mentioning this and he will give you that marker.
  So in this case you have given the parameters.
  -> And this is what a parameterized constructor is!

  Then the third one you go to a shop and say I want a marker like this(a physical marker on your hand).
  So the shopkeeper will see that marker. Okay, and he will give a new marker for you. So copy of that marker.
  -> And that’s what a copy constructor is!

*/

//=======================================================================
//=======================================================================

class clsPerson
{
private:
  string _Name;
  string _NationalId;
  int _Age;

public:
  // you can define the constructor inside the class
  clsPerson()
  {
    cout << "- Enter The Name:  ";
    getline(cin >> ws, _Name);
    cout << "- Enter The NId:  ";
    cin >> _NationalId;
    cout << "- Enter The Age:  ";
    cin >> _Age;
  }

  void PrintData()
  {
    cout << "\n=====================================\n";
    cout << "- Name       :" << _Name << '\n';
    cout << "- National Id:" << _NationalId << '\n';
    cout << "- Age        :" << _Age;
    cout << "\n=====================================\n\n";
  }
};

//=======================================================================
//=======================================================================

class clsStudent
{
private:
  string _Name;
  string _UId;
  string _Major;

public:
  // default constructor
  clsStudent()
  {
    _Name = "MG";
    _UId = "123";
    _Major = "Eng";
  }

  // constructor declaration
  clsStudent(string Name, string UId, string Major);

  // copy constructor
  clsStudent(const clsStudent &old_obj)
  {
    _Name = old_obj._Name;
    _UId = old_obj._UId;
    _Major = old_obj._Major;
  }

  // function declaration
  void StudentPrintData();
};

// you can define the constructor outside the class
clsStudent::clsStudent(string Name, string UId, string Major)
{
  _Name = Name;
  _UId = UId;
  _Major = Major;
}

// you can define the function outside the class
void clsStudent::StudentPrintData()
{
  cout << "\n=======================================\n";
  cout << "- Name         : " << _Name << '\n';
  cout << "- University Id: " << _UId << '\n';
  cout << "- Major        : " << _Major;
  cout << "\n=======================================\n\n";
}

//=======================================================================
//=======================================================================

int main(void)
{
  // // Implicit constructor call
  // clsPerson Person1;
  // Person1.PrintData();

  // // Explicit constructor call
  // clsPerson Person2 = clsPerson();
  // Person2.PrintData();

  // Implicit constructor call
  clsStudent Student1("Mahmoud Gad", "1000152612", "Engineering");
  Student1.StudentPrintData();

  // Explicit constructor call
  clsStudent Student2 = clsStudent("Amira Gad", "1000148765", "Engineering");
  Student2.StudentPrintData();

  //======================================================================

  // you can make an array of class type
  // but this requires a default constructor inside the class
  clsStudent Students[2];

  Students[0].StudentPrintData();

  Students[1] = Student2;
  Students[1].StudentPrintData();

  return 0;
}