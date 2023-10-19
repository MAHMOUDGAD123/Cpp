#include<iostream>

#define NEWLINE std::cout << std::endl
#define MAIN_BEGIN int main(void) {
#define MAIN_END }

/*=========================================================================================*/
// Random Sorting

template<typename T> constexpr bool less(const T &lhs, const T &rhs) { return lhs < rhs; };
template<typename T> constexpr bool greater(const T &lhs, const T &rhs) { return lhs > rhs; };

template<typename T, typename Compare, size_t n>
static constexpr void _____(T (&_arr)[n], Compare _cmp) {
  
}

template<typename T, typename Compare, size_t n>
static constexpr void _Sort(T (&_arr)[n], Compare _cmp) {

}

template<typename T, size_t n>
static constexpr void random_sort(T (&_arr)[n], const bool _Ascending_Order = true) {
  _Sort(_arr, _Ascending_Order ? less<T> : greater<T>);
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

  int arr[]{ 1, 5, 97, 6, 4, 75, 1, 5 };

  _Display(arr, "Before =>  ");

  // heap_sort(arr);
  random_sort(arr, false);

  _Display(arr, "After  =>  ");

  NEWLINE;

  return 0;

MAIN_END