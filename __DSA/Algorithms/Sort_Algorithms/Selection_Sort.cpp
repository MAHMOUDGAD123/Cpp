#include <bits/stdc++.h>

/*==============================================Selection Sort==========================================*/

// min function
auto Ascending = []<typename _Ty, size_t n>(const _Ty (&_arr)[n], const size_t _idx)
{
  size_t min(_idx);
  for (size_t i(_idx + 1); i < n; i++)
    if (_arr[i] < _arr[min])
      min = i;

  return min;
};

// max function
auto Descending = []<typename _Ty, size_t n>(const _Ty (&_arr)[n], const size_t _idx)
{
  size_t max(_idx);
  for (size_t i(_idx + 1); i < n; i++)
    if (_arr[i] > _arr[max])
      max = i;

  return max;
};

// in the (_Order) parameter:
// for -> ascending sort use  -> { Ascending }
// for -> descending sort use -> { Descending }
// selection sort
// using reference to array
template <typename Ty, typename Ordering, size_t _Size>
static constexpr void _Sort(Ty (&_arr)[_Size], Ordering _Order) noexcept
{
  for (size_t i(0); i < _Size; ++i)
    std::swap(_arr[i], _arr[_Order(_arr, i)]);
}

// choose ascending or descending sorting
template <typename Ty, size_t _Size>
static constexpr void selection_sort(Ty (&_arr)[_Size], bool _Ascending_Order = true)
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
  std::cout << " - ";
  for (const auto elem : _Con)
    std::cout << elem << " - ";

  std::cout << std::endl;
}

/*======================================================================================================*/
// main function

int main(int argc, char *argv[])
{
  int arr[]{9, 7, 5, 2, 1, 4, 7};

  _Print(arr);

  selection_sort(arr);

  _Print(arr);

  return 0;
}