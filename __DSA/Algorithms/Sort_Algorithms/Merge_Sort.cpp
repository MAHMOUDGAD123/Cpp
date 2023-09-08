#include <iostream>

//========================== Merge Sorting =============================

template <typename T, typename ordering, size_t n>
static constexpr void _Merge(T (&_arr)[n], ordering _Order, const size_t begin, const size_t mid, const size_t end)
{
}

template <typename T, typename ordering, size_t n>
static constexpr void _Sort(T (&_arr)[n], ordering _Order, const size_t begin = 0, const size_t end = n - 1)
{
  if (begin >= end)
    return;

  size_t mid(begin + ((end - begin) >> 1));

  _Sort(_arr, _Order, begin, mid);
  _Sort(_arr, _Order, mid + 1, end);

  _Merge(_arr, _Order, begin, mid, end);
}

template <typename T, size_t n>
static constexpr void merge_sort(T (&_arr)[n], bool _Assending_Sort = true)
{
  if (_Assending_Sort)
    _Sort(_arr, [&](const T &lhs, const T &rhs) -> bool
          { return lhs > rhs ? lhs : rhs; }); // max
  else
    _Sort(_arr, [&](const T &lhs, const T &rhs) -> bool
          { return lhs < rhs ? lhs : rhs; }); // min
}

//======================================================================

template <typename Container>
void _Print(const Container &_Con)
{
  std::cout << '\n'
            << std::endl;

  for (cont auto &elem : _Con)
    std::cout << " -> " << elem;

  std::cout << std::endl;

  return;
}

//======================================================================

// main function
int main(int argc, char *argv[])
{
  // int arr[]{9, 6, 4, 8, 1, 3, 2};
  // int arr[]{1, 2, 3, 4, 5, 6};
  int arr[]{9, 7, 5, 4, 3, 2};

  _Print(arr);

  merge_sort(arr);
  // merge_sort(arr, false);

  _Print(arr);

  return 0;
}