#pragma once

#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include "MG_Utility.h"

#define MG_BEGIN namespace MG{
#define MG_END }

MG_BEGIN

//===========================================================================================================
//================================================ Iterators ================================================
//===========================================================================================================


// array const_iterator class
template<typename Ty, size_t _Size>
class array_const_iterator
{
public:
	using valueType = Ty;
	using size_type = size_t;
	using ptrdiff_type = int64_t;
	using pointer = const Ty*;
	using reference = const Ty&;

private:
	pointer _Ptr; // beginning of array

public:
	constexpr array_const_iterator() noexcept : _Ptr(nullptr) {}

	constexpr array_const_iterator(pointer Ptr, size_type _Off = 0) noexcept : _Ptr(Ptr + _Off) {}


	constexpr reference operator*() const noexcept
	{
		return *_Ptr;
	}

	constexpr reference operator[](const ptrdiff_type _idx) const noexcept
	{
		return *(_Ptr + _idx);
	}

	constexpr pointer operator->() const noexcept
	{
		return _Ptr;
	}


	constexpr array_const_iterator& operator++() noexcept
	{
		// pre increament
		++_Ptr;
		return *this;
	}
	constexpr array_const_iterator operator++(int) noexcept
	{
		// post increament
		array_const_iterator _temp = *this;
		++_Ptr;
		return _temp;
	}

	constexpr array_const_iterator& operator--() noexcept
	{
		// pre decreament
		--_Ptr;
		return *this;
	}
	constexpr array_const_iterator operator--(int) noexcept
	{
		// post decreament
		array_const_iterator _temp = *this;
		--_Ptr;
		return _temp;
	}

	constexpr array_const_iterator& operator+=(const ptrdiff_type _Off) noexcept
	{
		_Ptr += _Off;
		return *this;
	}

	constexpr array_const_iterator& operator-=(const ptrdiff_type _Off) noexcept
	{
		_Ptr -= _Off;
		return *this;
	}


	constexpr array_const_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		return { _Ptr + _Off };
	}

	constexpr array_const_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		return { _Ptr - _Off };
	}


	constexpr ptrdiff_type operator-(const array_const_iterator& _Right) const noexcept
	{
		return _Ptr - _Right._Ptr;
	}

	friend constexpr array_const_iterator operator+(const ptrdiff_type _Off, const array_const_iterator& _Next) noexcept
	{
		return { _Next._Ptr + _Off };
	}



	// comparison operators
	//-------------------------------------------------------------------------
	constexpr bool operator==(const array_const_iterator& _Right) const noexcept
	{
		return _Ptr == _Right._Ptr;
	}

	constexpr bool operator !=(const array_const_iterator& _Right) const noexcept
	{
		return _Ptr != _Right._Ptr;
	}

	constexpr bool operator<(const array_const_iterator& _Right) const noexcept
	{
		return _Ptr < _Right._Ptr;
	}

	constexpr bool operator>(const array_const_iterator& _Right) const noexcept
	{
		return _Ptr > _Right._Ptr;
	}

	constexpr bool operator<=(const array_const_iterator& _Right) const noexcept
	{
		return _Ptr <= _Right._Ptr;
	}

	constexpr bool operator>=(const array_const_iterator& _Right) const noexcept
	{
		return _Ptr >= _Right._Ptr;
	}
	//-------------------------------------------------------------------------

};



// array iterator class
template<typename Ty, size_t _Size>
class array_iterator : public array_const_iterator<Ty, _Size>
{
public:
	using _Base = array_const_iterator<Ty, _Size>;

	using valueType = Ty;
	using size_type = size_t;
	using ptrdiff_type = int64_t;
	using pointer = Ty*;
	using reference = Ty&;


public:
	constexpr array_iterator() noexcept {}

	constexpr explicit array_iterator(pointer Ptr, size_type _Off = 0) noexcept : _Base(Ptr, _Off) {}


	constexpr reference operator*() const noexcept
	{
		return const_cast<reference>(_Base::operator*());
	}

	constexpr reference operator[](const ptrdiff_type _idx) const noexcept
	{
		return const_cast<reference>(_Base::operator[](_idx));
	}

	constexpr pointer operator->() const noexcept
	{
		return const_cast<pointer>(_Base::operator->());
	}


	constexpr array_iterator& operator++() noexcept
	{
		_Base::operator++();
		return *this;
	}
	constexpr array_iterator operator++(int) noexcept
	{
		array_iterator _temp = *this;
		_Base::operator++();
		return *this;
	}

	constexpr array_iterator& operator--() noexcept
	{
		_Base::operator--();
		return *this;
	}
	constexpr array_iterator operator--(int) noexcept
	{
		// post decreament
		array_iterator _temp = *this;
		_Base::operator--();
		return _temp;
	}

	constexpr array_iterator& operator+=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator+=(_Off);
		return *this;
	}

	constexpr array_iterator& operator-=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator-=(_Off);
		return *this;
	}


	constexpr array_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		array_iterator _temp = *this;
		_temp += _Off;
		return _temp;
	}

	constexpr array_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		array_iterator _temp = *this;
		_temp -= _Off;
		return _temp;
	}


	constexpr ptrdiff_type operator-(const array_iterator& _Right) const noexcept
	{
		return _Base::operator-(_Right);
	}

	friend constexpr array_iterator operator+(const ptrdiff_type _Off, const array_iterator& _Next) noexcept
	{
		return { _Next + _Off };
	}


};


//===========================================================================================================
//=========================================== Reverse Iterators =============================================
//===========================================================================================================

// array const_reverse_iterator class
template<typename Ty, size_t _Size>
class array_const_reverse_iterator
{
public:
	using valueType = Ty;
	using size_type = size_t;
	using ptrdiff_type = int64_t;
	using pointer = const Ty*;
	using reference = const Ty&;

private:
	pointer _Ptr;

public:
	constexpr array_const_reverse_iterator() noexcept
		: _Ptr(nullptr) {}

	constexpr explicit array_const_reverse_iterator(pointer Ptr) noexcept
		: _Ptr(Ptr) {}

	constexpr reference operator*() const noexcept
	{
		pointer _temp = _Ptr;
		return *--_temp;
	}

	constexpr reference operator[](const ptrdiff_type _Off) const noexcept
	{
		return *(_Ptr - _Off - 1);
	}

	constexpr pointer operator->() const noexcept
	{
		pointer _temp = _Ptr;
		return --_temp;
	}


	constexpr array_const_reverse_iterator& operator++() noexcept
	{
		--_Ptr;
		return *this;
	}
	constexpr array_const_reverse_iterator operator++(int) noexcept
	{
		array_const_reverse_iterator _temp = *this;
		--_Ptr;
		return _temp;
	}

	constexpr array_const_reverse_iterator& operator--() noexcept
	{
		++_Ptr;
		return *this;
	}
	constexpr array_const_reverse_iterator operator--(int) noexcept
	{
		array_const_reverse_iterator _temp = *this;
		++_Ptr;
		return _temp;
	}

	constexpr array_const_reverse_iterator& operator+=(const ptrdiff_type _Off) noexcept
	{
		_Ptr -= _Off;
		return *this;
	}

	constexpr array_const_reverse_iterator& operator-=(const ptrdiff_type _Off) noexcept
	{
		_Ptr += _Off;
		return *this;
	}


	constexpr array_const_reverse_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		return { _Ptr - _Off };
	}

	constexpr array_const_reverse_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		return { _Ptr + _Off };
	}

	constexpr ptrdiff_type operator-(const array_const_reverse_iterator& _Right) const noexcept
	{
		return _Right._Ptr - _Ptr;
	}

	friend constexpr array_const_reverse_iterator operator+(const ptrdiff_type _Off, const array_const_reverse_iterator& _Right) noexcept
	{
		return { _Right + _Off };
	}

	// comparison operators
	constexpr bool operator==(const array_const_reverse_iterator& _Right) const noexcept
	{
		return _Ptr == _Right._Ptr;
	}
	constexpr bool operator!=(const array_const_reverse_iterator& _Right) const noexcept
	{
		return _Ptr != _Right._Ptr;
	}
	constexpr bool operator<(const array_const_reverse_iterator& _Right) const noexcept
	{
		return _Ptr > _Right._Ptr;
	}
	constexpr bool operator>(const array_const_reverse_iterator& _Right) const noexcept
	{
		return _Ptr < _Right._Ptr;
	}
	constexpr bool operator<=(const array_const_reverse_iterator& _Right) const noexcept
	{
		return _Ptr >= _Right._Ptr;
	}
	constexpr bool operator>=(const array_const_reverse_iterator& _Right) const noexcept
	{
		return _Ptr <= _Right._Ptr;
	}

};


// array const_reverse_iterator class
template<typename Ty, size_t _Size>
class array_reverse_iterator : public array_const_reverse_iterator<Ty, _Size>
{
public:
	using _Base = array_const_reverse_iterator<Ty, _Size>;

	using valueType = Ty;
	using size_type = size_t;
	using ptrdiff_type = int64_t;
	using pointer = Ty*;
	using reference = Ty&;

public:
	constexpr array_reverse_iterator() noexcept {}

	constexpr explicit array_reverse_iterator(pointer Ptr) noexcept : _Base(Ptr) {}

	constexpr reference operator*() const noexcept
	{
		return const_cast<reference>(_Base::operator*());
	}

	constexpr reference operator[](const ptrdiff_type _Off) const noexcept
	{
		return const_cast<reference>(_Base::operator[](_Off));
	}

	constexpr pointer operator->() const noexcept
	{
		return const_cast<pointer>(_Base::operator->());
	}


	constexpr array_reverse_iterator& operator++() noexcept
	{
		_Base::operator++();
		return *this;
	}
	constexpr array_reverse_iterator operator++(int) noexcept
	{
		array_reverse_iterator _temp = *this;
		_Base::operator++();
		return _temp;
	}

	constexpr array_reverse_iterator& operator--() noexcept
	{
		_Base::operator--();
		return *this;
	}
	constexpr array_reverse_iterator operator--(int) noexcept
	{
		array_reverse_iterator _temp = *this;
		_Base::operator--();
		return _temp;
	}

	constexpr array_reverse_iterator& operator+=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator+=(_Off);
		return *this;
	}

	constexpr array_reverse_iterator& operator-=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator-=(_Off);
		return *this;
	}


	constexpr array_reverse_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		array_reverse_iterator _temp = *this;
		_temp += _Off;
		return _temp;
	}

	constexpr array_reverse_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		array_reverse_iterator _temp = *this;
		_temp -= _Off;
		return _temp;
	}

	constexpr ptrdiff_type operator-(const array_reverse_iterator& _Right) const noexcept
	{
		return _Base::operator-(_Right);
	}

	friend constexpr array_reverse_iterator operator+(const ptrdiff_type _Off, const array_reverse_iterator& _Right) noexcept
	{
		return { _Right + _Off };
	}


};



//===========================================================================================================
//================================================== Array ==================================================
//===========================================================================================================

// array class
template <typename Ty, size_t _Size>
struct array
{
public:
	using value_type = Ty;
	using reference = Ty&;
	using const_reference = const Ty&;
	using pointer = Ty*;
	using const_pointer = const Ty*;
	using size_type = size_t;
	using ptrdiff_type = int64_t;

	using iterator = array_iterator<Ty, _Size>;
	using const_iterator = array_const_iterator<Ty, _Size>;

	using reverse_iterator = array_reverse_iterator<Ty, _Size>;
	using const_reverse_iterator = array_const_reverse_iterator<Ty, _Size>;

private:
	Ty _arr[_Size]; // actual fixed size array

public:
	// default constructor
	constexpr array() noexcept : _arr() {}

	constexpr array(std::initializer_list<Ty> list) noexcept
	{
		const_pointer first = list.begin();
		for (size_t i(0); i < _Size; ++i, ++first) {
			_arr[i] = *first;
		}
	}


	// assignment operator =
	//------------------------------------------------------------------------------
	array& operator =(const array& other) noexcept
	{
		for (size_t i(0); i < _Size; i++)
			_arr[i] = other[i];
		return *this;
	}

	array& operator =(array&& other) noexcept
	{
		for (size_t i(0); i < _Size; i++)
			_arr[i] = std::move(other[i]);
		return *this;
	}
	//------------------------------------------------------------------------------


	constexpr reference operator[](size_type _idx) noexcept { return _arr[_idx]; }
	constexpr reference operator[](size_type _idx) const noexcept { return _arr[_idx]; }

	constexpr reference at(size_type _idx) noexcept
	{
		if (_Size <= _idx) {
			std::out_of_range("_idx is out_of range");
		}
		return _arr[_idx];
	}
	constexpr const_reference at(size_type _idx) const noexcept
	{
		if (_Size <= _idx) {
			std::out_of_range("_idx is out_of range");
		}
		return _arr[_idx];
	}

	constexpr pointer data() noexcept { return _arr; }
	constexpr const_pointer data() const noexcept { return _arr; }

	constexpr reference front() noexcept { return _arr[0]; }
	constexpr reference front() const noexcept { return _arr[0]; }

	constexpr reference back() noexcept { return _arr[_Size - 1]; }
	constexpr reference back() const noexcept { return _arr[_Size - 1]; }

	constexpr size_type size() const noexcept { return _Size; }
	constexpr size_type max_size() const noexcept { return _Size; }

	constexpr bool empty() const noexcept { return false; } // never be empty

	void fill(const reference val) noexcept
	{
		for (size_t i(0); i < _Size; i++)
			_arr[i] = val;
	}

	void swap(array& other) noexcept
	{
		MG::utility::arr_util::arr_swap(_arr, other._arr);
	}

	// friends Comparison operators
	//-------------------------------------------------------------------------------------
	friend constexpr bool operator ==(const array <Ty, _Size>& lhs, const array <Ty, _Size>& rhs) noexcept
	{
		return MG::utility::arr_util::equal(lhs._arr, rhs._arr);
	}

	friend constexpr bool operator !=(const array <Ty, _Size>& lhs, const array <Ty, _Size>& rhs) noexcept
	{
		return !(lhs == rhs);
	}
	//-------------------------------------------------------------------------------------

	// iterator
	//------------------------------------------------------------------------------
	constexpr iterator begin() noexcept { return iterator(_arr); }
	constexpr const_iterator begin() const noexcept { return const_iterator(_arr); }
	constexpr const_iterator cbegin() const noexcept { return begin(); }

	constexpr iterator end() noexcept { return iterator(_arr + _Size); }
	constexpr const_iterator end() const noexcept { return const_iterator(_arr + _Size); }
	constexpr const_iterator cend() const noexcept { return end(); }


	constexpr reverse_iterator rbegin() noexcept { return reverse_iterator(_arr + _Size); }
	constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(_arr + _Size); }
	constexpr const_reverse_iterator crbegin() const noexcept { return rbegin(); }

	constexpr reverse_iterator rend() noexcept { return reverse_iterator(_arr); }
	constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator(_arr); }
	constexpr const_reverse_iterator crend() const noexcept { return rend(); }
	//------------------------------------------------------------------------------
};



MG_END