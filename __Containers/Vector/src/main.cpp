#include "../Header Files/MG_Utility.h"
#include "../Header Files/Vector.h"
#include <vector>

#define MAIN_BEGIN \
	int main()       \
	{
#define MAIN_END }

using namespace MG;
using namespace MG::algorithm;
using namespace MG::utility;

// template<typename Ty>
// void print(const MG::vector<Ty>& _Vec)
//{
//	std::cout << "\n----------------------------------------------------------------------\n ";
//	for (const Ty& elem : _Vec)
//		std::cout << "\"" << elem << "\"" << "  ";
//	std::cout << "\n\n- Size = " << _Vec.size();
//	std::cout << "\n----------------------------------------------------------------------\n\n";
// }

template <typename Ty>
void Print(const std::vector<Ty> &_Vec)
{
	std::cout << "\n----------------------------------------------------------------------\n ";
	for (const Ty &elem : _Vec)
		std::cout << "\"" << elem << "\""
							<< "  ";
	std::cout << "\n\n- Size = " << _Vec.size();
	std::cout << "\n----------------------------------------------------------------------\n\n";
}

MAIN_BEGIN

// std::vector<int> V{ 1,2,3,4,5,6,7 };
// std::vector<int> _V;
// std::vector<int>::const_iterator it;
//
// Print(V);
//
// V = _V;
//
// V.push_back(1);
// V.push_back(2);
// V.push_back(3);
//
// print(V);

// std::initializer_list<std::string> list{ "1","2","3","4","5" };
// std::initializer_list<std::string> _list{ "11" };

MG::vector<int> V1{1, 2, 3, 4, 5, 6, 7};
MG::vector<int> V2;
MG::vector<int>::const_iterator Pos;

// V1.reserve(20);
// V1.remove_if([&]<typename _Ty>(const _Ty& _elem) { return ((int)_elem / 2) != ((float)_elem / 2); }); // removed odd numbers
// V1.remove_if([&]<typename _Ty>(const _Ty& _elem) { return ((int)_elem / 2) == ((float)_elem / 2) ; }); // removed even numbers

V1.print();

V1 = V2; // V1 will be empty

V1.print();

for (int i(0); i < 10; ++i)
{
	V1.push_back(i + 1);
}

V1.print();

V1.clear();

V1.print();

MAIN_END