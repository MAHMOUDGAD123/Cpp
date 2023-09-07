#include <bits/stdc++.h>

//================================================= Searching alogorithms =================================================

template <typename Ty, size_t n>
static constexpr size_t binary_search(const Ty (&arr)[n], const Ty &_elem, size_t first = 0, size_t last = n - 1)
{
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

template <typename T, size_t n>
size_t exponential_search(const T (&arr)[n], const T &_elem)
{
  if (!n)
    return UINT64_MAX;

  if (arr[0] == _elem)
    return 0;

  size_t i(1);

  while (i < n && arr[i] <= _elem)
    i <<= 2; // i *= 2;

  return binary_search(arr, _elem, i >> 1, std::min(i, n - 1));
}

//=========================================================================================================================

int main(int argc, char *argv[])
{
  int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

  size_t R(exponential_search(arr, 1));

  if (R != UINT64_MAX)
    std::cout << "Found At Index = " << R << std::endl;
  else
    std::cout << "Not Found :-(" << std::endl;

  return 0;
}