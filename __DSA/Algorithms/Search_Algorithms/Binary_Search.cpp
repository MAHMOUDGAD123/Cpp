#include <bits/stdc++.h>

//================================================= Searching alogorithms =================================================

// get the index of an element in array
// if not found will return (UINT64_MAX)
// linear search (ls)
template <typename T, size_t n>
static constexpr size_t linear_search(const T (&arr)[n], const T &_elem)
{
  for (size_t i(0); i < n; i++)
    if (_elem == arr[i])
      return i;
  return UINT64_MAX;
}

// get the index of an element in array
// if not found will return (UINT64_MAX)
// if the array isn't sorted put the (not_Sorted) parameter --> (true)
// binary search (bs) using loop
template <typename Ty, size_t n>
static constexpr size_t binary_search(const Ty (&arr)[n], const Ty &_elem, bool not_Sorted = false, size_t first = 0, size_t last = n - 1)
{
  // array must be sorted for binary search
  if (not_Sorted)
    return linear_search(arr, _elem); // linear search

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

// get the index of an element in array
// if not found will return (UINT64_MAX)
// if the array isn't sorted put the (not_Sorted) parameter --> (true)
// binary search (bs) using recursion
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

// get the index of an element in array
// if not found will return (UINT64_MAX)
// if the array isn't sorted put the (not_Sorted) parameter --> (true)
// binary search (bs) using loop
// for descending sort
template <typename Ty, size_t n>
static constexpr size_t binary_search_des(const Ty (&arr)[n], const Ty &_elem, bool not_Sorted = false, size_t first = 0, size_t last = n - 1)
{
  // array must be sorted for binary search
  if (not_Sorted)
    return linear_search(arr, _elem); // linear search

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

//=========================================================================================================================

int main(int argc, char *argv[])
{
  int arr[]{4, 7, 9, 12, 18, 21, 87, 625};

  size_t RES = binary_search_rec(arr, 878);

  if (RES != UINT64_MAX)
    std::cout << "Found At Index " << RES << std::endl;
  else
    std::cout << "Not Found :-(" << std::endl;

  return 0;
}