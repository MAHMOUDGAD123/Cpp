#include <iostream>
#include <ctime>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template <class T, size_t n>
void Copy(T (&arr1)[n], T (&arr2)[n])
{
	for (size_t i(0); i < n; i++)
		arr1[i] = arr2[i];
}

template <class T>
void Swap(T &Var1, T &Var2)
{
	T temp = Var1;
	Var1 = Var2;
	Var2 = temp;
}

template <typename T, uint64_t _size>
constexpr bool equal(T (&arr1)[_size], T (&arr2)[_size])
{
	if (arr1 == arr2)
		return true;

	for (uint64_t i(0); i < _size; ++i)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

// get the index of the max element of the array start searching from (_idx) to n
template <class Ty, size_t n>
size_t Min(Ty (&arr)[n], size_t _idx = 0)
{
	size_t min(_idx);
	for (size_t i(_idx); i < n; i++)
		if (arr[i] < arr[min])
			min = i;
	return min;
}

template <typename Ty, size_t n>
constexpr inline void Sort(Ty (&arr)[n])
{
	for (size_t i(0); i < n; i++)
		Swap(arr[i], arr[Min(arr, i)]);
}



int main()
{
	int arr[10]{10, 5, 3, 6, 9, 8, 7, 1, 4, 2};
	int _arr[10]{10, 5, 3, 6, 9, 8, 7, 1, 4, 2};

	std::cout << std::boolalpha << equal(arr, _arr) << "\n\n\n";

	clock_t t;
	int n = 10000000;
	string S;
	printf("\n\n\nCalculating...\n\n");

	t = clock();

	// test
	for (size_t i = 0; i < n; i++)
	{
		Sort(arr);
		Copy(arr, _arr);
	}

	t = clock() - t;
	printf("\nUsing MG took %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);

	//============================================================================

	t = clock();

	// test
	for (size_t i = 0; i < n; i++)
	{
		std::sort(arr, arr + 10);
		Copy(arr, _arr);
	}

	t = clock() - t;
	printf("\nUsing C++ took %d clicks (%f seconds).\n\n", t, ((float)t) / CLOCKS_PER_SEC);

	//============================================================================

	return 0;
}