#include <iostream>
#include <array>
#include <tuple>
#include <cstdarg>

// https://www.programiz.com/cpp-programming/class-templates

template <typename T, size_t size>
class Array
{
private:
  T Arr[size];

public:
  // default constructor
  Array() {}

  // parameterized constructor to store the assigned data
  Array(T first, ...)
  {
    va_list args;          // argument list variable
    va_start(args, first); // initialize argument list variable (args)

    Arr[0] = first; // store the element[0]

    // store the rest elements
    for (size_t i = 1; i < size; ++i)
      Arr[i] = va_arg(args, T);

    va_end(args); // End using argument list variable (args)
  }

  // [] operator overloading
  T &operator[](size_t index) noexcept { return Arr[index]; }

  size_t Size() const { return size; }

  void Fill(size_t N)
  {
    for (size_t i = 0; i < size; ++i)
      Arr[i] = N;
  }
};

int main(void)
{
  std::array<int, 5> CNums = {1, 2, 3, 4, 5}; // c++ array class
  Array<int, 5> MyNums = {1, 2, 3, 4, 5};     // MG array class

  std::cout << "Size of C++ Array = " << CNums.size() << "\n";
  std::cout << "Size of MG Array = " << MyNums.Size() << "\n\n";

  // print elements of myArray
  std::cout << "CNums Elements :  ";
  for (size_t i = 0; i < CNums.size(); i++)
    std::cout << CNums[i] << " ";

  std::cout << "\n\n";

  // update the values
  MyNums[0] = 10;
  MyNums[1] = 20;
  MyNums[2] = 30;
  MyNums[3] = 40;
  MyNums[4] = 50;

  // print elements of myArray
  std::cout << "MyNums Elements :  ";
  for (size_t i = 0; i < MyNums.Size(); i++)
    std::cout << MyNums[i] << " ";

  std::cout << "\n";

  MyNums.Fill(1);

  std::cout << "MyNums Elements :  ";
  for (size_t i = 0; i < MyNums.Size(); i++)
    std::cout << MyNums[i] << " ";

  std::cout << "\n\n";

  return 0;
}