#include <iostream>
#include <string_view>
#include <new>

// using std::string_view class to avoid memory allocation

// https://www.youtube.com/watch?v=ZO68JEgoPeg&ab_channel=TheCherno
// https://en.cppreference.com/w/cpp/string/basic_string_view

// to count allocations
static size_t Allocations(0ull);


  // to know if there's an heap memory Allocations
  void *operator new(size_t size)
  {
    Allocations++;
    std::cout << "Allocating (" << size << ") Bytes\n";
    return malloc(size);
  }

  // to know if there's an heap memory Deallocations
  void operator delete(void *ptr, size_t size)
  {
    Allocations--;
    std::cout << "Deallocating (" << size << ") Bytes\n";
    return free(ptr);
  }


void Print_Name(const std::string &txt)
{
  std::cout << txt << std::endl;
}
void Print_Name(const std::string_view &txt)
{
  std::cout << txt << std::endl;
}
void Print_Name(const char * const txt)
{
  std::cout << txt << std::endl;
}

#define STRING 0
#define STRING_VIEW__STRING 0
#define STRING_VIEW 1

int main()
{
#if STRING

  // 3 heap allocations
  std::string name{"Mahmoud Gad"};      // 1 allocation
  std::string Fname{name.substr(0, 7)}; // 1 allocation
  std::string Lname{name.substr(8, 3)}; // 1 allocation

#elif STRING_VIEW__STRING

  // 1 heap allocation
  std::string name{"Mahmoud Gad"};             // 1 allocation
  std::string_view Fname(name.c_str(), 7);     // 0 allocation
  std::string_view Lname(name.c_str() + 8, 3); // 0 allocation

#elif STRING_VIEW

  // No heap allocations
  const char *name{"Mahmoud Gad"};     // 0 allocation
  std::string_view Fname{name, 7};     // 0 allocation
  std::string_view Lname{name + 8, 3}; // 0 allocation

#endif

  std::cout << "\n\n";
  Print_Name(name);
  Print_Name(Fname);
  Print_Name(Lname);

  std::cout << "Allocations = " << Allocations << "\n\n";
}