#include <iostream>
#include <array>

using namespace std;

// https://www.programiz.com/cpp-programming/function-template
// https://www.youtube.com/watch?v=I-hZkUa9mIs&ab_channel=TheCherno

// Generic Add function
template <typename T>
T Add(T Var1, T Var2)
{
  return Var1 + Var2;
}

template <typename T, size_t N>
array<T, N> Add(array<T, N> a, array<T, N> b)
{
  array<T, N> R;
  for (size_t i = 0; i < N; i++)
    R[i] = Add<T>(a[i], b[i]);
  return R;
}

//======================================================================================

// Generic Swap Function
template <class T>
void Swap(T &Var1, T &Var2)
{
  T temp = Var1;
  Var1 = Var2;
  Var2 = temp;
}

template <class T, size_t N>
void Swap(T (&a)[N], T (&b)[N])
{
  for (size_t i = 0; i < N; i++)
    swap(a[i], b[i]);
}

//======================================================================================
// calculate the size of the c-style array.

// using array reference
// pass array --> (array_name)
template <typename T, size_t __size>
size_t _sizeof(T (&ref)[__size])
{
  return __size;
}
// using pointer to array
// pass array --> (&array_name)
template <typename T, size_t __size>
size_t _sizeof(T (*ptr)[__size])
{
  return __size;
}

// not useful
// template <typename T, size_t __size>
// size_t _sizeof(T *ref[__size])
// {
//   return __size;
// }

// not useful
// template <typename T, size_t __size>
// size_t _sizeof(T arr[__size])
// {
//   return __size;
// }

//======================================================================================

int main(void)
{
  cout << "\n\n===============================================\n\n";
  // you can pass the type on not
  cout << Add(10, 20) << endl;
  cout << Add<int>(10, 20) << endl;
  cout << Add<double>(10.5, 20.8) << endl;
  cout << Add<string>("Mahmoud ", "Gad") << endl;

  cout << "\n\n===============================================\n\n";

  int N1 = 10, N2 = 20;
  cout << N1 << " - " << N2 << "\n";
  Swap<int>(N1, N2);
  cout << N1 << " - " << N2 << "\n\n";

  string S1("Mahmoud"), S2("Gad");
  cout << S1 << " - " << S2 << "\n";
  Swap<string>(S1, S2);
  cout << S1 << " - " << S2 << "\n";

  cout << "\n\n===============================================\n\n";
  array<int, 5> arr1{1, 2, 3, 4, 5}, arr2{10, 20, 30, 40, 50}, Sum;

  Sum = Add<int, 5>(arr1, arr2);
  for (const int &i : Sum)
    cout << i << "  ";

  cout << "\n\n===============================================\n\n";

  int arr3[5]{1, 2, 3, 4, 5}, arr4[5]{10, 20, 30, 40, 50};

  cout << "Before Swap:\n";
  for (short i(0); i < 5; i++)
    cout << arr3[i] << "  ";
  cout << '\n';
  for (short i(0); i < 5; i++)
    cout << arr4[i] << "  ";

  Swap<int, 5>(arr3, arr4);

  cout << "\n\nAfter Swap:\n";
  for (short i(0); i < 5; i++)
    cout << arr3[i] << "  ";
  cout << '\n';
  for (short i(0); i < 5; i++)
    cout << arr4[i] << "  ";

  cout << "\n\n===============================================\n\n";

  int iarr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  string sarr[]{"A", "B", "C", "D", "E", "F", "G"};

  cout << _sizeof(iarr) << endl;
  cout << _sizeof(&iarr) << endl;
  cout << _sizeof(sarr) << endl;
  cout << _sizeof(&sarr) << endl;

  cout << "\n\n===============================================\n\n";
  return 0;
}