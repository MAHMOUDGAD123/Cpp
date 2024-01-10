#include <bits/stdc++.h>

/*===============================================Test======================================================*/

template <typename T, size_t n>
static constexpr size_t sentinel_linear_search(T (&arr)[n], T &_elem)
{
  T last(std::move(arr[n - 1]));
  arr[n - 1] = std::move(_elem);

  size_t i(0);

  while (arr[i] != arr[n - 1])
    ++i;

  _elem = std::move(arr[n - 1]);
  arr[n - 1] = std::move(last);

  if (i < n - 1 || _elem == arr[n - 1])
    return i;

  return UINT64_MAX;
}

template <typename T, size_t n>
static constexpr size_t _sentinel_linear_search(T (&arr)[n], const T &_elem)
{
  T last(arr[n - 1]);
  arr[n - 1] = _elem;

  size_t i(0);

  while (arr[i] != _elem)
    ++i;

  arr[n - 1] = last;

  if (i < n - 1 || _elem == last)
    return i;

  return UINT64_MAX;
}

/*=========================================================================================================*/

int main(void)
{
  clock_t start, end;
  uint64_t n(10000000);

  /*=======================================Data============================================*/
  int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int x(14);

  std::string s_arr[]{"1", "22", "333", "4444", "55555", "666666", "7777777", "88888888"};
  std::string S("55555");
  /*=======================================================================================*/

  start = clock();

  while (n)
  {
    // test here  <--------

    size_t RES = sentinel_linear_search(s_arr, S);
    // size_t RES = _sentinel_linear_search(s_arr, S);
    --n;
  }

  end = clock();

  std::cout << "Test = " << std::fixed
            << double(end - start) / CLOCKS_PER_SEC
            << std::setprecision(15)
            << " sec" << std::endl;
}