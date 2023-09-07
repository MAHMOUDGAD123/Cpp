#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void Swap(T &Var1, T &Var2)
{
  T temp = std::move(Var1);
  Var1 = std::move(Var2);
  Var2 = std::move(temp);
}

// get the index of the max element of the array start searching from (_idx) to n
template <class Ty, size_t n>
constexpr size_t Min(Ty (&arr)[n], size_t _idx = 0)
{
  size_t min(_idx);
  for (size_t i(_idx + 1); i < n; i++)
    if (arr[i] < arr[min])
      min = i;
  return min;
}

// get the index of the max element of the array start searching from (_idx) to n
template <typename T, uint64_t _size>
constexpr size_t Max(T (&arr)[_size], size_t _idx)
{
  size_t max(_idx);
  for (uint64_t i(_idx + 1); i < _size; i++)
    if (arr[i] > arr[max])
      max = i;
  return max;
}

template <typename Ty, size_t n>
constexpr inline void Sort(Ty (&arr)[n], size_t (*comp)(Ty (&_arr)[n], size_t _idx) = Min)
{
  for (size_t i(0); i < n; i++)
    Swap(arr[i], arr[comp(arr, i)]);
}

int main()
{
  int arr[10]{10, 5, 3, 6, 9, 8, 7, 1, 4, 2};
  float _arr[10]{10.54, 5.46, 3.87, 6.89, 9.87, 8.45, 7.32, 1.78, 4.78, 2.12};

  // std::sort(std::begin(arr), std::end(arr), [&](const float &lhs, const float &rhs){ return lhs < rhs; });
  // std::sort(std::begin(_arr), std::end(_arr), [&](const float &lhs, const float &rhs){ return lhs > rhs; });
  Sort(arr, Min);
  Sort(_arr, Max);

  cout << "\n\n";

  for (const int &N : arr)
    cout << N << "  ";

  cout << "\n";

  for (const float &N : _arr)
    cout << N << "  ";

  cout << "\n\n";

  return 0;
}