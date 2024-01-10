#include "Utility.h"

#define Main_Begin int main(){
#define Main_End return 0;}

using namespace MG::utility;





// print a c-style array
template <typename T, uint64_t _size>
void arr_print(T(&arr)[_size], uint8_t _width = 3)
{
	for (uint64_t i = 0; i < _size; i++)
		std::cout << std::setw(_width) << arr[i];
}

// print an array
template <typename T, uint64_t _size>
void arr_print(std::array <T, _size> arr, uint8_t _width = 3)
{
	for (uint64_t i = 0; i < _size; i++)
		std::cout << std::setw(_width) << arr[i];
}





Main_Begin

srand((unsigned)time(nullptr));



int arr1[10]{ 1,1,1,1,1,1,1,1,1,1 };

int arr2[5]{ 1,2,3,4,5 };

int _elem{ 3 };

arr_print(arr1);
std::cout << std::endl;

arr_print(arr2);
std::cout << std::endl;

std::cout << std::boolalpha << arr_util::is_palindrome(arr1) << "\n";
std::cout << std::boolalpha << arr_util::is_palindrome(arr2) << "\n";


Main_End

