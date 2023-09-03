#pragma once

#define MG_BEGIN \
	namespace MG   \
	{
#define MG_END }

MG_BEGIN

template <typename _Ty1, typename _Ty2>
struct pair
{
	_Ty1 _First;
	_Ty2 _Second;

	constexpr pair() noexcept
			: _First(), _Second() {}

	constexpr pair(const _Ty1 &First, const _Ty2 &Second) noexcept
			: _First(First), _Second(Second) {}

	constexpr pair(_Ty1 &&First, _Ty2 &&Second) noexcept
			: _First(std::forward<_Ty1>(First)), _Second(std::forward<_Ty2>(Second)) {}

	constexpr pair(const pair &_Other) noexcept
			: _First(_Other._First), _Second(_Other._Second) {}

	constexpr pair(pair &&_Other) noexcept
			: _First(std::forward<_Ty1>(_Other._First)), _Second(std::forward<_Ty2>(_Other._Second)) {}

	constexpr pair &operator=(const pair &_Other) noexcept
	{
		if (this != &_Other)
		{
			_First = _Other._First;
			_Second = _Other._Second;
		}
		return *this;
	}
	constexpr pair &operator=(pair &&_Other) noexcept
	{
		if (this != &_Other)
		{
			_First = std::forward<_Ty1>(_Other._First);
			_Second = std::forward<_Ty2>(_Other._Second);
		}
		return *this;
	}

	constexpr void swap(pair &_Other) noexcept
	{
		if (this != &_Other)
		{
			std::swap(_First, _Other._First);
			std::swap(_Second, _Other._Second);
		}
	}

	constexpr bool operator==(const pair &_Right) const noexcept
	{
		return _First == _Right._First && _Second == _Right._Second;
	}
	constexpr bool operator!=(const pair &_Right) const noexcept
	{
		return !(*this == _Right);
	}
	constexpr bool operator<(const pair &_Right) const noexcept
	{
		return _First < _Right._First || (!(_Right._First < _First) && _Second < _Right._Second);
	}
	constexpr bool operator>(const pair &_Right) const noexcept
	{
		return _Right < *this;
	}
	constexpr bool operator<=(const pair &_Right) const noexcept
	{
		return !(*this > _Right);
	}
	constexpr bool operator>=(const pair &_Right) const noexcept
	{
		return !(*this < _Right);
	}
};

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_Out, const MG::pair<_Ty1, _Ty2> _Pair)
{
	_Out << _Pair._First << " - " << _Pair._Second << std::endl;
	return _Out;
}

MG_END