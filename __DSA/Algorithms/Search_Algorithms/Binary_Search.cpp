#include <iostream>

//============================================= Searching alogorithms ============================================
// if not found will return (UINT64_MAX)
// get the index of an element in array

// binary search using loop
template <typename Ty, size_t n>
static constexpr size_t binary_search(const Ty (&arr)[n], const Ty &_elem, size_t first = 0, size_t last = n - 1)
{
  // if (_elem < arr[first] || _elem > arr[last])
  //   return UINT64_MAX;

  // (first & mid & last ) index of arr
  size_t mid(0);

  while (first <= last)
  {
    mid = (first + last) >> 1;

    if (_elem == arr[mid])
      return mid;

    if (_elem > arr[mid])
      first = mid + 1;
    else
      last = mid - 1;
  }
  return UINT64_MAX;
}

// binary search using recursion
template <typename Ty, size_t n>
static constexpr size_t binary_search_rec(const Ty (&arr)[n], const Ty &_elem, size_t first = 0, size_t last = n - 1)
{
  // (first & mid & last ) index of arr
  if (first <= last)
  {
    size_t mid = (first + last) >> 1;

    if (_elem == arr[mid])
      return mid;

    if (_elem > arr[mid])
      return binary_search_rec(arr, _elem, mid + 1, last);

    return binary_search_rec(arr, _elem, first, mid - 1);
  }
  return UINT64_MAX;
}

// binary search using loop
// for descending sorted array
template <typename Ty, size_t n>
static constexpr size_t binary_search_des(const Ty (&arr)[n], const Ty &_elem, size_t first = 0, size_t last = n - 1)
{
  // if (_elem < arr[first] || _elem > arr[last])
  //   return UINT64_MAX;

  // (first & mid & last ) index of arr
  size_t mid(0);
  while (first <= last)
  {
    mid = (first + last) >> 1;

    if (_elem == arr[mid])
      return mid;

    if (_elem > arr[mid])
      last = mid - 1;
    else
      first = mid + 1;
  }
  return UINT64_MAX;
}

//=====================================================================================================================

int main(int argc, char *argv[])
{
  int arr[]{4, 7, 9, 12, 18, 21, 87, 625};

  size_t RES = binary_search_rec(arr, 87);

  std::cout << std::endl;

  if (RES != UINT64_MAX)
    std::cout << "-> Found At Index " << RES << std::endl;
  else
    std::cout << "-> Not Found :-(" << std::endl;

  std::cout << std::endl;

  return 0;
}