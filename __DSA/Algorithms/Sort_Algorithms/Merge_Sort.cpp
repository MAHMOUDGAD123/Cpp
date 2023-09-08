#include <iostream>

//========================== Merge Sorting =============================

template <typename T, typename ordering, size_t n>
static constexpr void _Merge(T (&_arr)[n], ordering _Order, const size_t begin, const size_t mid, const size_t end)
{
  // sizes
  const size_t l_sub_size(mid - begin + 1);
  const size_t r_sub_size(end - mid);

  // prepare the temp sub arrays
  T l_sub[l_sub_size], r_sub[r_sub_size];

  // copy the data from the main array
  for (size_t i(0); i < l_sub_size; ++i)
    l_sub[i] = _arr[begin + i];
  for (size_t i(0); i < r_sub_size; ++i)
    r_sub[i] = _arr[mid + 1 + i];

  // prepare the iterators
  size_t l_index(0), r_index(0), merged_index(begin);

  // merge the [left & right] sub arrays
  while (l_index < l_sub_size && r_index < r_sub_size)
  {
    if (_Order(l_sub[l_index], r_sub[r_index]))
      _arr[merged_index++] = l_sub[l_index++]; // add the left element
    else
      _arr[merged_index++] = r_sub[r_index++]; // add the right element
  }

  // chech if the left array remain something
  while (l_index < l_sub_size)
    _arr[merged_index++] = l_sub[l_index++];

  // chech if the right array remain something
  while (r_index < r_sub_size)
    _arr[merged_index++] = r_sub[r_index++];
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
          { return lhs < rhs; }); // min
  else
    _Sort(_arr, [&](const T &lhs, const T &rhs) -> bool
          { return lhs > rhs; }); // max
}

//======================================================================

template <typename Container>
void _Print(const Container &_Con)
{
  std::cout << '\n'
            << std::endl;

  for (const auto &elem : _Con)
    std::cout << "  " << elem;

  std::cout << std::endl;
}

//======================================================================

// main function
int main(int argc, char *argv[])
{
  int arr[]{9, 6, 4, 8, 1, 3, 2};
  // int arr[]{1, 2, 3, 4, 5, 6};
  // int arr[]{9, 7, 5, 4, 3, 2};

  _Print(arr);

  merge_sort(arr);
  // merge_sort(arr, false);

  _Print(arr);

  std::cout << std::endl;

  return 0;
}