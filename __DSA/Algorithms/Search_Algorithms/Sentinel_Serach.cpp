#include <iostream>

//========================================= Searching alogorithms ===============================================

// get the index of an element in array
// if not found will return (UINT64_MAX)
// sentinal linear search
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

//===============================================================================================================

int main(int argc, char *argv[])
{
  int arr[]{2, 6, 8, 7, 4, 6, 9, 1, 4};
  int x(9);

  std::string s_arr[]{"1", "22", "333", "4444", "55555", "666666", "7777777", "88888888"};
  std::string S("55555");

  // size_t RES = sentinel_linear_search(arr, x);
  size_t RES = sentinel_linear_search(s_arr, S);

  if (RES != UINT64_MAX)
    std::cout << "Found At Index " << RES << std::endl;
  else
    std::cout << "Not Found :-(" << std::endl;

  return 0;
}