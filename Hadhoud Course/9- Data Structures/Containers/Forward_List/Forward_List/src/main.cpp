#include <iostream>
#include <forward_list>
#include <initializer_list>
#include "../forward_list.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }




template<typename _Ty>
constexpr static void FLprint(const MG::forward_list<_Ty>& Flist)
{
	std::cout << "\n\n";
	if (Flist.empty()) {
		std::cout << "Empty :-(\n\n";
		return;
	}
	for (const _Ty& _Node : Flist) {
		std::cout << _Node << "  ";
	}
	std::cout << "\n\n";
}



struct vector
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
	}

	vector& operator=(vector&& V) noexcept
	{
		std::cout << "\nMoved\n";
		_x = std::move(V._x);
		_y = std::move(V._y);
		_z = std::move(V._z);
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

static void Vprint(const MG::forward_list<vector>& Flist)
{
	std::cout << "\n\n";
	if (Flist.empty()) {
		std::cout << "Empty :-(\n\n";
	}
	for (const vector& _Node : Flist) {
		std::cout << _Node << '\n';
	}
}





MAIN_BEGIN


//vector V{ 1.1f, 1.1f, 1.1f };
//vector _V{ 2.2f, 2.2f, 2.2f };
//
//std::cout << "\n\nC++ List:\n";
//std::cout << "-------------\n";
//std::forward_list<vector> FL;
//std::forward_list<vector> _FL(3, _V);
//std::forward_list<vector>::iterator it(_FL.before_begin());
//std::forward_list<vector>::iterator F = FL.begin();
//std::forward_list<vector>::iterator _F = FL.begin();
//
//std::cout << "{  ";
//for (const auto& _Node : FL) {
//	std::cout << _Node;
//}
//std::cout << "  }";
//
//FL.splice_after(F, _FL);
//
//std::cout << "\n\n";
//
//std::cout << "{  ";
//for (const auto& _Node : FL) {
//	std::cout << _Node;
//}
//std::cout << "  }";

//std::cout << "\n\n============================\n\n";

//vector V{ 1.1f, 1.1f, 1.1f };


auto greater = [&]<typename _Ty>(const _Ty & _lhs, const _Ty & _rhs) { return _lhs > _rhs; };
auto less = [&]<typename _Ty>(const _Ty & _lhs, const _Ty & _rhs) { return _lhs < _rhs; };

MG::forward_list<int> FL = { 6,4,7,3,5 };

std::cout << *FL.begin() << std::endl;

FLprint(FL);

FL.emplace_front(1);
FL.emplace_after(FL.begin(), 2);

FLprint(FL);

FL.sort();

FLprint(FL);

FL.sort(greater);

FLprint(FL);

FL.reverse();

FLprint(FL);


MAIN_END