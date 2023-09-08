#include <iostream>

//======================================== Searching alogorithms =========================================

// reference to array -> T(&arr)[_Size]

// get the index of an element in array
// if not found will return (UINT64_MAX)
// linear search (ls)
template <typename T, size_t n>
static constexpr size_t linear_search(const T (&arr)[n], const T &_elem)
{
  for (size_t i(0); i < n; ++i)
    if (_elem == arr[i])
      return i;
  return UINT64_MAX;
}

//========================================================================================================

int main(int argc, char *argv[])
{
  int arr[]{2, 6, 8, 7, 4, 6, 9, 1, 4};

  size_t RES = linear_search(arr, 8);

  if (RES != UINT64_MAX)
    std::cout << "Found At Index " << RES << std::endl;
  else
    std::cout << "Not Found :-(" << std::endl;

  return 0;
}