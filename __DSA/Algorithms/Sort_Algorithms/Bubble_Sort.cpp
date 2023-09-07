#include <bits/stdc++.h>

/*==============================================Bubble Sort==========================================*/

auto Ascending = []<typename _Ty>(const _Ty &lhs, const _Ty &rhs) -> bool
{ return lhs > rhs; };

auto Descending = []<typename _Ty>(const _Ty &lhs, const _Ty &rhs) -> bool
{ return lhs < rhs; };

// in the (_Order) parameter:
// for -> ascending sort use  -> { Ascending }
// for -> descending sort use -> { Descending }
// bubble sort
template <typename Ty, typename Ordering, size_t _Size>
static constexpr int _Sort(Ty (&_arr)[_Size], Ordering _Order) noexcept
{
  int iterations(0); // iterations is for testing { not used }
  bool sorted(true);

  for (size_t i(0), len(_Size - 1); len; --len, i = 0, sorted = true)
  {
    for (; i < len; ++i, ++iterations)
      if (_Order(_arr[i], _arr[i + 1]))
        std::swap(_arr[i], _arr[i + 1]), sorted = false;

    if (sorted)
      return iterations;
  }
  return iterations;
}

// choose ascending or descending sorting
template <typename Ty, size_t _Size>
static constexpr int bubble_sort(Ty (&_arr)[_Size], bool _Ascending_Order = true)
{
  if (_Ascending_Order)
    return _Sort(_arr, Ascending);
  else
    return _Sort(_arr, Descending);
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
  int arr[]{9, 7, 5, 4, 3, 2};
  // int arr[]{1, 2, 3, 4, 5, 6, 7};

  _Print(arr);

  std::cout << "\n-> Iterations = " << bubble_sort(arr, false) << "\n\n";

  _Print(arr);

  return 0;
}