#include <iostream>
#include <memory> // for smart pointers

using namespace std;

// https://www.geeksforgeeks.org/smart-pointers-cpp/
// https://cplusplus.com/reference/memory/?kw=memory

struct Data
{
  string Name, ID;
};

// my smart prt using template
template <typename T>
class Smart_Ptr
{
private:
  T *ptr;

public:
  // constructor
  Smart_Ptr(T *p = NULL) { ptr = p; }

  // destructor
  ~Smart_Ptr() { delete ptr; }

  // dereferancing operator * overloading
  T &operator*() { return *ptr; }

  // arrow operator -> overloading
  T *operator->() { return ptr; }
};


int main(void)
{
  Smart_Ptr<int> Int_ptr(new int(120));

  cout << "\n\nInt_ptr = " << *Int_ptr << "\n";

  Smart_Ptr<string> Str_ptr(new string("Mahmoud Gad"));

  cout << "Str_ptr = " << *Str_ptr << "\n\n";

  return 0;
}