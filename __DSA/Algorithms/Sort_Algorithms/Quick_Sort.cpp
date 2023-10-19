#include <iostream>

template <typename T>
constexpr bool _less(const T &lhs, const T &rhs) { return lhs < rhs; }

template <typename T>
constexpr bool _greater(const T &lhs, const T &rhs) { return lhs > rhs; }

//========================== Quick Sorting =============================

template <typename T, typename Compare, size_t n>
static constexpr int _Partition(T (&_arr)[n], Compare _cmp, const int begin, const int end)
{
  const T &_pivot(_arr[end]); // pivot is the last elem

  int i(begin - 1);

  for (int j(begin); j < end; ++j)
    if (_cmp(_arr[j], _pivot))
      std::swap(_arr[++i], _arr[j]);

  // put pivot in the right place and return it's position
  std::swap(_arr[++i], _arr[end]);
  return i;
}

template <typename T, typename Compare, size_t n>
static constexpr void _Sort(T (&_arr)[n], Compare _cmp, const int begin = 0, const int end = n - 1)
{
  if (begin >= end) return;

  const int _pivot_pos(_Partition(_arr, _cmp, begin, end));

  _Sort(_arr, _cmp, begin, _pivot_pos - 1);
  _Sort(_arr, _cmp, _pivot_pos + 1, end);
}

template <typename T, size_t n>
static constexpr void quick_sort(T (&_arr)[n], bool _Assending_Sort = true)
{
  _Sort(_arr, _Assending_Sort ? _less<T> : _greater<T>);
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
  std::string s_arr[]{"55555", "22", "4444", "333", "1"};

  _Print(arr);
  _Print(s_arr);

  // quick_sort(arr);
  quick_sort(arr, false);
  // quick_sort(s_arr);
  quick_sort(s_arr, false);

  _Print(arr);
  _Print(s_arr);

  std::cout << std::endl;

  return 0;
}