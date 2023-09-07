#include <bits/stdc++.h>

//================================================= Searching alogorithms =================================================

template <typename T, size_t n>
size_t ternart_search(const T (&arr)[n], const T &_elem, size_t l = 0, size_t r = n - 1)
{
  if (!n || _elem < arr[l] || _elem > arr[r])
    return UINT64_MAX;

  size_t mid_l(0), mid_r(0);

  while (l <= r)
  {
    mid_l = l + (r - l) / 3, mid_r = r - (r - l) / 3; // slow

    if (arr[mid_l] == _elem)
      return mid_l;

    if (arr[mid_r] == _elem)
      return mid_r;

    if (_elem < arr[mid_l])
      r = mid_l - 1;
    else if (_elem > arr[mid_r])
      l = mid_r + 1;
    else
      l = mid_l + 1, r = mid_r - 1;
  }
  return UINT64_MAX;
}

template <typename T, size_t n>
size_t ternart_search_rec(const T (&arr)[n], const T &_elem, size_t l = 0, size_t r = n - 1)
{
  // size_t mid_l(((l + ((l + r) >> 1)) >> 1)), mid_r((((l + r) >> 1) + r) >> 1); // fast
  size_t mid_l = l + (r - l) / 3, mid_r = r - (r - l) / 3; // slow - better results

  if (l <= r)
  {
    if (arr[mid_l] == _elem)
      return mid_l;

    if (arr[mid_r] == _elem)
      return mid_r;

    if (_elem < arr[mid_l])
      return ternart_search(arr, _elem, l, mid_l - 1);

    if (_elem > arr[mid_r])
      return ternart_search(arr, _elem, mid_r + 1, r);

    return ternart_search(arr, _elem, mid_l + 1, mid_r - 1);
  }
  return UINT64_MAX;
}

//=========================================================================================================================

int main(int argc, char *argv[])
{
  int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

  size_t R(ternart_search(arr, 13));

  if (R != UINT64_MAX)
    std::cout << "Found At Index = " << R << std::endl;
  else
    std::cout << "Not Found :-(" << std::endl;

  return 0;
}