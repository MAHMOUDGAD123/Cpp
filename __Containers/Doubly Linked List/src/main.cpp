#include <iostream>
#include <initializer_list>
#include <list>
#include "../Header Files/list.h"
#include "../Header Files/doubly list.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }



template<typename container>
constexpr static void Print(const container& list)
{
	std::cout << "\n\n";
	if (list.empty()) {
		std::cout << "Empty :-(\n\n";
		return;
	}
	for (const auto& _Node : list) {
		std::cout << _Node << "  ";
	}
	std::cout << "\n\n-> Size = " << list.size();
	std::cout << "\n\n";
}



struct vector final
{
	float _x, _y, _z;

	vector()
		: _x(0.0f), _y(0.0f), _z(0.0)
	{
		std::cout << "\nConstructed\n";
	}

	vector(float x, float y, float z)
		: _x(x), _y(y), _z(z)
	{
		std::cout << "\nConstructed\n";
	}

	vector(vector&& V) noexcept
		: _x(std::move(V._x)), _y(std::move(V._y)), _z(std::move(V._z))
	{
		std::cout << "\nMoved\n";
	}

	vector(const vector& V) noexcept
		: _x(V._x), _y(V._y), _z(V._z)
	{
		std::cout << "\nCopied\n";
	}

	vector& operator=(const vector& V) noexcept
	{
		std::cout << "\nMoved\n";
		_x = V._x;
		_y = V._y;
		_z = V._z;
		return *this;
	}

	vector& operator=(vector&& V) noexcept
	{
		std::cout << "\nMoved\n";
		_x = std::move(V._x);
		_y = std::move(V._y);
		_z = std::move(V._z);
		return *this;
	}

	~vector()
	{
		std::cout << "\nDestructed\n";
	}

	constexpr bool operator==(const vector& other) const noexcept
	{
		return _x == other._x && _y == other._y && _z == other._z;
	}

	constexpr bool operator!=(const vector& other) const noexcept
	{
		return !(*this == other);
	}

	friend std::ostream& operator<<(std::ostream& out, const vector& V)
	{
		out << V._x << " - " << V._y << " - " << V._z << std::endl;
		return out;
	}
};

template<typename container>
static void Vprint(const container& Flist)
{
	std::cout << "\n\n";
	if (Flist.empty()) {
		std::cout << "Empty :-(\n\n";
	}
	for (const auto& _Node : Flist) {
		std::cout << _Node << '\n';
	}
}






MAIN_BEGIN

// lamdas
//auto greater = [&]<typename _Ty>(const _Ty & _lhs, const _Ty & _rhs) { return _lhs > _rhs; };
//auto less = [&]<typename _Ty>(const _Ty & _lhs, const _Ty & _rhs) { return _lhs < _rhs; };
//auto equal = [&]<typename _Ty>(const _Ty & _elem) { return _elem == 1; };
//auto not_equal = [&]<typename _Ty>(const _Ty & _lhs, const _Ty & _rhs) { return _lhs != _rhs; };

MG::doubly_list<int> List{ 1,2,3,4,5,6,7 };
MG::doubly_list<std::string> SList{ "Mr.","Mohammed","Abu-hadhoud","Ali","Mahmoud","Amir","Fady"};
MG::doubly_list<int>::Node_Ptr _Node_{ nullptr };

Print(List);

int X{ 22 };

List.insert_after(11, 6);
List.insert_after(X, 7);
List.insert_after(X, 8);

Print(List);

std::cout << "\n\n\n";

MAIN_END