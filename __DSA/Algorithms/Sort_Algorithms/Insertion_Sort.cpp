#include <iostream>

/*==============================================Insertion Sort==========================================*/

auto Ascending = []<typename _Ty>(const _Ty &lhs, const _Ty &rhs) -> bool
{ return lhs > rhs; };

auto Descending = []<typename _Ty>(const _Ty &lhs, const _Ty &rhs) -> bool
{ return lhs < rhs; };

// in the (_Order) parameter:
// for -> ascending sort use  -> { Ascending }
// for -> descending sort use -> { Descending }
// insertion sort
template <typename Ty, typename Ordering, size_t _Size>
static constexpr void _Sort(Ty (&_arr)[_Size], Ordering _Order) noexcept
{
  for (size_t i(1), j(1); i < _Size; ++i, j = i) // starting from index 1
    while (j > 0 && _Order(_arr[j - 1], _arr[j]))
      std::swap(_arr[j - 1], _arr[j]), --j;
}

// choose ascending or descending sorting
template <typename Ty, size_t _Size>
static constexpr void insertion_sort(Ty (&_arr)[_Size], bool _Ascending_Order = true)
{
  if (_Ascending_Order)
    _Sort(_arr, Ascending);
  else
    _Sort(_arr, Descending);
}

/*======================================================================================================*/

template <typename container>
void _Print(const container &_Con)
{
  std::cout << '\n'
            << std::endl;

  for (const auto elem : _Con)
    std::cout << " -> " << elem;

  std::cout << std::endl;
}

/*======================================================================================================*/
// main function

int main(int argc, char *argv[])
{
  // int arr[]{9, 6, 4, 8, 1, 3, 2};
  // int arr[]{1, 2, 3, 4, 5, 6};
  int arr[]{9, 7, 5, 4, 3, 2};

  _Print(arr);

  insertion_sort(arr);
  // insertion_sort(arr, false);

  _Print(arr);

  return 0;
}