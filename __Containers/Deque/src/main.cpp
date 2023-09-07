#include <iostream>
#include <deque>
#include <vector>
#include "../Header Files/Deque.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }

template<typename Ty>
void printDQ(const MG::deque<Ty>& DQ)
{
	std::cout << "\n\n- Your Data:\n";
	for (const Ty& elem : DQ)
		std::cout << elem << "  ";
	std::cout << "\nSize = " << DQ.size();
	std::cout << "\nCapacity = " << DQ.capacity();
	std::cout << "\nOffset = " << DQ.offset();
}

template<typename _Ty>
inline constexpr bool is_premative(_Ty const& data)
{
	return std::is_fundamental<_Ty>::value;
}




MAIN_BEGIN

MG::deque<int> DQ(7, 7);

printDQ(DQ);

DQ.emplace_back(9);

printDQ(DQ);

DQ = {};

printDQ(DQ);

MAIN_END