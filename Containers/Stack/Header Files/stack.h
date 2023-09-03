#pragma once

#include <initializer_list>
#include "MG_utility.h"

#ifndef MG_BEGIN
#define MG_BEGIN namespace MG {
#define MG_END }
#endif


MG_BEGIN



template <typename _Ty>
class stack
{
public:
	using value_type = _Ty;
	using pointer = _Ty*;
	using const_pointer = const _Ty*;
	using reference = _Ty&;
	using const_reference = const _Ty&;
	using rvalue_reference = _Ty&&;

private:
	pointer _Data;
	size_t _Size;
	size_t _Capacity;

private:
	constexpr void _Init(pointer Data = nullptr, size_t Capacity = 0, size_t Size = 0)
	{
		_Data = Data;
		_Capacity = Capacity;
		_Size = Size;
	}

	constexpr void _Destruct_All()
	{
		for (size_t i(0); i < _Size; ++i)
			_Data[i].~_Ty();
	}

	constexpr pointer _Alloc(size_t Capacity)
	{
		return (pointer)::operator new(Capacity * sizeof(_Ty));
	}

	constexpr void _Dealloc(size_t Capacity)
	{
		::operator delete(_Data, Capacity * sizeof(_Ty));
	}

	constexpr void _Reallocate(size_t new_Capacity)
	{
		pointer _new_{ _Alloc(new_Capacity) };

		for (size_t i(0); i < _Size; ++i)
			new(&_new_[i]) _Ty(std::move(_Data[i]));

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_new_, new_Capacity, _Size); // _Size keep the same
		_new_ = nullptr;
	}

	constexpr void _Construct(const stack& Other)
	{
		_Init(_Alloc(Other._Capacity), Other._Capacity, Other._Size);

		for (size_t i(0); i < Other._Size; ++i)
			new(&_Data[i]) _Ty(Other._Data[i]);
	}

	constexpr void _Steal_Data(stack& Other)
	{
		_Init(Other._Data, Other._Capacity, Other._Size);
		Other._Init();
	}

	template<typename _Iter>
	constexpr size_t _Get_Range_Len(_Iter _First, _Iter _Last)
	{
		size_t _Count(0);
		for (; _First != _Last; ++_First) ++_Count;
		return _Count;
	}

	template<typename _Iterator>
	constexpr void _Construct_Range(_Iterator _First, _Iterator _Last)
	{
		for (size_t i(0); _First != _Last; ++_First, ++i)
			new(&_Data[i]) _Ty(std::move(*_First));
	}

	constexpr void _Clear()
	{
		if (_Data) {
			_Destruct_All();
			_Dealloc(_Capacity);
			_Init();
		}
	}


public:
	constexpr stack() { _Init(); }

	constexpr stack(const stack& Other)
	{
		if (Other._Size) _Construct(Other);
		else _Init();
	}

	constexpr stack(stack&& Other) noexcept
	{
		if (Other._Size) _Steal_Data(Other);
		else _Init();
	}

	constexpr stack(std::initializer_list<_Ty> _il)
	{
		size_t Size{ _il.size() };
		if (Size) {
			size_t new_Capacity{ Size * 2 };
			_Init(_Alloc(new_Capacity), new_Capacity, Size);
			_Construct_Range(_il.begin(), _il.end());
		}
		else _Init();
	}

	template<typename _Iterator>
	constexpr stack(_Iterator _First, _Iterator _Last)
	{
		size_t Size{ _Get_Range_Len(_First, _Last) };
		if (Size) {
			size_t new_Capacity{ Size * 2 };
			_Init(_Alloc(new_Capacity), new_Capacity, Size);
			_Construct_Range(_First, _Last);
		}
		else _Init();
	}

	~stack() { _Clear(); }

	constexpr stack& operator=(const stack& Other)
	{
		if (this == &Other) return *this;

		if (Other._Size) {
			_Clear();
			_Construct(Other);
		}
		else _Clear();
		return *this;
	}

	constexpr stack& operator=(stack&& Other) noexcept
	{
		if (this == &Other) return *this;

		if (Other._Size) {
			_Clear();
			_Steal_Data(Other);
		}
		else _Clear();
		return *this;
	}

	constexpr stack& operator=(std::initializer_list<value_type> _il)
	{
		size_t Size{ _il.size() };
		if (Size) {
			_Clear();
			size_t new_Capacity{ Size * 2 };
			_Init(_Alloc(new_Capacity), new_Capacity, Size);
			_Construct_Range(_il.begin(), _il.end());
		}
		else _Clear();
		return *this;
	}

	constexpr size_t size() const { return _Size; }

	constexpr bool empty() const { return _Size == 0; }

	constexpr reference top() { return _Data[_Size - 1]; }
	constexpr const_reference top() const { return _Data[_Size - 1]; }

	template<typename... Args>
	constexpr reference emplace(Args... args)
	{
		if (!_Data) {
			// if null allocate memory for 7 elements
			_Init(_Alloc(7), 7);
		}
		else if (_Size >= _Capacity) {
			// buffer is full
			_Reallocate(_Capacity * 2);
		}
		new(&_Data[_Size]) _Ty(std::forward<Args>(args)...);
		return _Data[_Size++];
	}

	constexpr void push(const value_type& val)
	{
		(void)emplace(val);
	}
	constexpr void push(value_type&& val)
	{
		(void)emplace(std::move(val));
	}

	constexpr void pop()
	{
		if (_Size) {
			_Data[--_Size].~_Ty();
		}
	}

	constexpr void swap(stack& other)
	{
		stack temp{ std::move(*this) };
		_Steal_Data(other);
		other._Steal_Data(temp);
	}

	constexpr void reverse() const noexcept
	{
		if (_Size < 2) return;

		for (size_t S(0), E(_Size - 1); S < E; ++S, --E)
			algorithm::swap(_Data[S], _Data[E]);
	}


	constexpr bool operator==(const stack& _rhs) const
	{
		if (this == &_rhs) return true;
		if (_Size != _rhs._Size) return false;

		for (size_t i(0); i < _Size; ++i) {
			if (_Data[i] != _rhs._Data[i]) {
				return false;
			}
		}
		return true;
	}

	constexpr bool operator!=(const stack& _rhs) const
	{
		return !(*this == _rhs);
	}


	// demo
	void print() const noexcept
	{
		std::cout << "\n\n";
		if (empty()) {
			std::cout << "-> Empty :-(";
		}
		else {
			for (int64_t i(_Size - 1); i >= 0; --i) {
				std::cout << _Data[i] << "  ";
			}
			std::cout << "\n-> Size = " << _Size
				<< " - TOS = " << top();
		}

		std::cout << "\n\n";
	}

};



MG_END
