#include <iostream>
#include <array>
#include <vector>
#include <stdexcept>
#include "../Header Files/Array.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }


template<typename Ty, size_t _Size>
constexpr void print(const MG::array<Ty, _Size>& _arr)
{
	std::cout << "\n----------------------------------------------------------------------\n ";
	for (const Ty& elem : _arr)
		std::cout << elem << "  ";
	std::cout << "\n\n- Size = " << _arr.size();
	std::cout << "\n----------------------------------------------------------------------\n\n";
}

template<typename Ty, size_t _Size>
constexpr void print(const std::array<Ty, _Size>& _arr)
{
	std::cout << "\n----------------------------------------------------------------------\n ";
	for (const Ty& elem : _arr)
		std::cout << elem << "  ";
	std::cout << "\n\n- Size = " << _arr.size();
	std::cout << "\n----------------------------------------------------------------------\n\n";
}


MAIN_BEGIN

MG::array<int, 5> Nums;
std::array<int, 5> CNums{};

std::cout << Nums[4] << "\n\n";
std::cout << CNums[4] << "\n\n";
std::cout << Nums.at(4) << "\n\n";
std::cout << CNums.at(4) << "\n\n";

print(Nums);
print(CNums);

MG::array<int, 5>::const_iterator it(Nums.begin());
std::cout << *it << std::endl;

MAIN_END