#include <iostream>

// take a look here
// https://en.cppreference.com/w/cpp/language/parameter_pack


// base function
void tprintf(const char* format)
{
    std::cout << format;
}

// recursive variadic function
template <typename Ty, typename... Targs>
void tprintf(const char *format, Ty value, Targs... Fargs)
{
  for (; *format != '\0'; ++format)
  {
    if (*format == '%')
    {
      ++format;
      if (*format == 'i' || *format == 'c' || *format == 's')
        std::cout << value;

      tprintf(format + 1, Fargs...); // recursive call
      return; // to break after finish recursive call
    }
    std::cout << *format;
  }
}

int main()
{
  tprintf("%c%c -- My Name is: %s -- my birth day is: %i/%i/%i.", 'M', 'G', "Mahmoud Gad", 10, 9, 1997);
}