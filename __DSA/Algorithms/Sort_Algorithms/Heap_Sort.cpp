#include<iostream>

#define NEWLINE std::cout << std::endl
#define MAIN_BEGIN int main(void) {
#define MAIN_END }

/*=========================================================================================*/
// Heap Sorting

template<typename T> constexpr bool less(const T &lhs, const T &rhs) { return lhs < rhs; };
template<typename T> constexpr bool greater(const T &lhs, const T &rhs) { return lhs > rhs; };

// max_heap function
template<typename T, typename Compare, size_t n>
static constexpr void _Heapify(T (&_arr)[n], Compare _cmp, const int len, const int parent_idx) {
  int max(parent_idx);
  const int l(2 * parent_idx + 1); // left node of parent
  const int r(2 * parent_idx + 2); // right node of parent

  // get max element of the sub-tree
  if (l < len && _cmp(_arr[l], _arr[max])) max = l;
  if (r < len && _cmp(_arr[r], _arr[max])) max = r;

  if (max != parent_idx) { // check if the max had changed or not
    std::swap(_arr[parent_idx], _arr[max]);
    _Heapify(_arr, _cmp, len, max);
  }
}

template<typename T, typename Compare, size_t n>
static constexpr void _Sort(T (&_arr)[n], Compare _cmp) {
  // Build (rearrange the array as a) max_heap
  for (int i((n >> 1) - 1); i >= 0; --i)
    _Heapify(_arr, _cmp, n, i);

  for (int len(n - 1); len > 0; --len) {
    // move the current root ( _arr[0] ) to the end
    std::swap(_arr[0], _arr[len]);
    // _Heapify the reduced _arr
    _Heapify(_arr, _cmp, len, 0);
  }
}

template<typename T, size_t n>
static constexpr void heap_sort(T (&_arr)[n], const bool _Ascending_Order = true) {
  _Sort(_arr, _Ascending_Order ? greater<T> : less<T>);
}

/*=========================================================================================*/

template<typename Container>
static void _Display(const Container &_cont, const char *msg) {
  std::cout << msg << "{   ";
  for (const auto &e : _cont) std::cout << e << "   ";
  std::cout << "}" << std::endl;
}

MAIN_BEGIN

NEWLINE;

// int arr[]{ 1, 5, 97, 6, 4, 75, 1, 10 };
std::string arr[]{ "11", "5", "97", "6", "4", "75", "1", "10" };

_Display(arr, "Before =>  ");

heap_sort(arr);
// heap_sort(arr, false);

_Display(arr, "After  =>  ");

NEWLINE;

return 0;

MAIN_END