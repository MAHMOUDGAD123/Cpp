#pragma once

#include "MG_utility.h"

#ifndef MG_BEGIN
#define MG_BEGIN \
	namespace MG   \
	{
#define MG_END }
#endif

MG_BEGIN

//============================================================================================================
//================================================= Iterators ================================================
//============================================================================================================

// vector const_iterator class
template <typename _Vector>
class vector_const_iterator
{
public:
	using value_type = typename _Vector::value_type;
	using pointer = typename _Vector::const_pointer;
	using reference = typename _Vector::const_reference;
	using size_type = typename _Vector::size_type;
	using ptrdiff_type = typename _Vector::ptrdiff_type;

private:
	pointer _Ptr;

public:
	constexpr vector_const_iterator() : _Ptr(nullptr) {}
	constexpr vector_const_iterator(pointer Data_Ptr) : _Ptr(Data_Ptr) {}

	constexpr pointer _get_data() const noexcept { return _Ptr; }

	constexpr reference operator*() const noexcept
	{
		return *_Ptr;
	}

	constexpr reference operator[](const ptrdiff_type _Off) const noexcept
	{
		return *(_Ptr + _Off);
	}

	constexpr pointer operator->() const noexcept
	{
		return _Ptr;
	}

	constexpr vector_const_iterator &operator++() noexcept
	{
		// pre increament
		++_Ptr;
		return *this;
	}
	constexpr vector_const_iterator operator++(int) noexcept
	{
		// post increament
		vector_const_iterator _temp = *this;
		++_Ptr;
		return _temp;
	}

	constexpr vector_const_iterator &operator--() noexcept
	{
		// pre decreament
		--_Ptr;
		return *this;
	}
	constexpr vector_const_iterator operator--(int) noexcept
	{
		// post decreament
		vector_const_iterator _temp = *this;
		--_Ptr;
		return _temp;
	}

	constexpr vector_const_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Ptr += _Off;
		return *this;
	}

	constexpr vector_const_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Ptr -= _Off;
		return *this;
	}

	constexpr vector_const_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr + _Off};
	}

	constexpr vector_const_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr - _Off};
	}

	constexpr ptrdiff_type operator-(const vector_const_iterator &_Right) const noexcept
	{
		return _Ptr - _Right._Ptr;
	}

	friend constexpr vector_const_iterator operator+(const ptrdiff_type _Off, const vector_const_iterator &_Right) noexcept
	{
		return {_Right + _Off};
	}

	// comparison operators
	//-------------------------------------------------------------------------
	constexpr bool operator==(const vector_const_iterator &other) const noexcept
	{
		return _Ptr == other._Ptr;
	}

	constexpr bool operator!=(const vector_const_iterator &other) const noexcept
	{
		return _Ptr != other._Ptr;
	}

	constexpr bool operator<(const vector_const_iterator &other) const noexcept
	{
		return _Ptr < other._Ptr;
	}

	constexpr bool operator>(const vector_const_iterator &other) const noexcept
	{
		return _Ptr > other._Ptr;
	}

	constexpr bool operator<=(const vector_const_iterator &other) const noexcept
	{
		return _Ptr <= other._Ptr;
	}

	constexpr bool operator>=(const vector_const_iterator &other) const noexcept
	{
		return _Ptr >= other._Ptr;
	}
	//-------------------------------------------------------------------------
};

// vector iterator class
template <typename _Vector>
class vector_iterator : public vector_const_iterator<_Vector>
{
public:
	using _Base = vector_const_iterator<_Vector>;

	using value_type = typename _Vector::value_type;
	using pointer = typename _Vector::pointer;
	using reference = typename _Vector::reference;
	using size_type = typename _Vector::size_type;
	using ptrdiff_type = typename _Vector::ptrdiff_type;

public:
	constexpr vector_iterator() noexcept {}
	constexpr vector_iterator(pointer Data_Ptr) noexcept : _Base(Data_Ptr) {}

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

	constexpr vector_iterator &operator++() noexcept
	{
		_Base::operator++();
		return *this;
	}
	constexpr vector_iterator operator++(int) noexcept
	{
		// post increament
		vector_iterator _temp = *this;
		_Base::operator++();
		return _temp;
	}

	constexpr vector_iterator &operator--() noexcept
	{
		// pre decreament
		_Base::operator--();
		return *this;
	}
	constexpr vector_iterator operator--(int) noexcept
	{
		// post decreament
		vector_iterator _temp = *this;
		_Base::operator--();
		return _temp;
	}

	constexpr vector_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator+=(_Off);
		return *this;
	}

	constexpr vector_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator-=(_Off);
		return *this;
	}

	constexpr vector_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		vector_iterator _temp = *this;
		_temp += _Off;
		return _temp;
	}

	constexpr vector_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		vector_iterator _temp = *this;
		_temp -= _Off;
		return _temp;
	}

	constexpr ptrdiff_type operator-(const vector_iterator &_Right) const noexcept
	{
		return _Base::operator-(_Right);
	}

	friend constexpr vector_iterator operator+(const ptrdiff_type _Off, const vector_iterator &_Right) noexcept
	{
		return {_Right + _Off};
	}
};

//===========================================================================================================

// vector const_reverse_iterator class
template <typename _Vector>
class vector_reverse_const_iterator
{
public:
	using value_type = typename _Vector::value_type;
	using pointer = typename _Vector::const_pointer;
	using reference = typename _Vector::const_reference;
	using size_type = typename _Vector::size_type;
	using ptrdiff_type = typename _Vector::ptrdiff_type;

private:
	pointer _Ptr;

public:
	constexpr vector_reverse_const_iterator() : _Ptr(nullptr) {}
	constexpr vector_reverse_const_iterator(pointer Data_Ptr) : _Ptr(Data_Ptr) {}

	constexpr pointer _get_data() const noexcept { return _Ptr; }

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

	constexpr vector_reverse_const_iterator &operator++() noexcept
	{
		--_Ptr;
		return *this;
	}
	constexpr vector_reverse_const_iterator operator++(int) noexcept
	{
		// post increament
		vector_reverse_const_iterator _temp = *this;
		--_Ptr;
		return _temp;
	}

	constexpr vector_reverse_const_iterator &operator--() noexcept
	{
		// pre decreament
		++_Ptr;
		return *this;
	}
	constexpr vector_reverse_const_iterator operator--(int) noexcept
	{
		// post decreament
		vector_reverse_const_iterator _temp = *this;
		++_Ptr;
		return _temp;
	}

	constexpr vector_reverse_const_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Ptr -= _Off;
		return *this;
	}

	constexpr vector_reverse_const_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Ptr += _Off;
		return *this;
	}

	constexpr vector_reverse_const_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr - _Off};
	}

	constexpr vector_reverse_const_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr + _Off};
	}

	constexpr ptrdiff_type operator-(const vector_reverse_const_iterator &_Right) const noexcept
	{
		return _Right._Ptr - _Ptr;
	}

	friend constexpr vector_reverse_const_iterator operator+(const ptrdiff_type _Off, const vector_reverse_const_iterator &_Right) noexcept
	{
		return {_Right + _Off};
	}

	// comparison operators
	//-------------------------------------------------------------------------
	constexpr bool operator==(const vector_reverse_const_iterator &other) const noexcept
	{
		return _Ptr == other._Ptr;
	}

	constexpr bool operator!=(const vector_reverse_const_iterator &other) const noexcept
	{
		return _Ptr != other._Ptr;
	}

	constexpr bool operator<(const vector_reverse_const_iterator &other) const noexcept
	{
		return _Ptr > other._Ptr;
	}

	constexpr bool operator>(const vector_reverse_const_iterator &other) const noexcept
	{
		return _Ptr < other._Ptr;
	}

	constexpr bool operator<=(const vector_reverse_const_iterator &other) const noexcept
	{
		return _Ptr >= other._Ptr;
	}

	constexpr bool operator>=(const vector_reverse_const_iterator &other) const noexcept
	{
		return _Ptr <= other._Ptr;
	}
	//-------------------------------------------------------------------------
};

// vector const_reverse_iterator class
template <typename _Vector>
class vector_reverse_iterator : public vector_reverse_const_iterator<_Vector>
{
public:
	using _Base = vector_reverse_const_iterator<_Vector>;

	using value_type = typename _Vector::value_type;
	using pointer = typename _Vector::pointer;
	using reference = typename _Vector::reference;
	using size_type = typename _Vector::size_type;
	using ptrdiff_type = typename _Vector::ptrdiff_type;

public:
	constexpr vector_reverse_iterator() noexcept {}
	constexpr vector_reverse_iterator(pointer Data_Ptr) noexcept : _Base(Data_Ptr) {}

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

	constexpr vector_reverse_iterator &operator++() noexcept
	{
		_Base::operator++();
		return *this;
	}
	constexpr vector_reverse_iterator operator++(int) noexcept
	{
		// post increament
		vector_reverse_iterator _temp = *this;
		_Base::operator++();
		return _temp;
	}

	constexpr vector_reverse_iterator &operator--() noexcept
	{
		// pre decreament
		_Base::operator--();
		return *this;
	}
	constexpr vector_reverse_iterator operator--(int) noexcept
	{
		// post decreament
		vector_reverse_iterator _temp = *this;
		_Base::operator--();
		return _temp;
	}

	constexpr vector_reverse_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator+=(_Off);
		return *this;
	}

	constexpr vector_reverse_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator-=(_Off);
		return *this;
	}

	constexpr vector_reverse_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		vector_reverse_iterator _temp = *this;
		_temp += _Off;
		return *this;
	}

	constexpr vector_reverse_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		vector_reverse_iterator _temp = *this;
		_temp -= _Off;
		return *this;
	}

	constexpr ptrdiff_type operator-(const vector_reverse_iterator &_Right) const noexcept
	{
		return _Base::operator-(_Right);
	}

	friend constexpr vector_reverse_iterator operator+(const ptrdiff_type _Off, const vector_reverse_iterator &_Right) noexcept
	{
		return {_Right + _Off};
	}
};

//============================================================================================================
//================================================== Vector ==================================================
//============================================================================================================

// vector class
template <typename Ty>
class vector
{
public:
	using value_type = Ty;
	using reference = Ty &;
	using const_reference = const Ty &;
	using rvalue_reference = Ty &&;
	using pointer = Ty *;
	using const_pointer = const Ty *;
	using size_type = size_t;
	using ptrdiff_type = int64_t;

	using iterator = vector_iterator<vector<Ty>>;
	using const_iterator = vector_const_iterator<vector<Ty>>;
	using reverse_iterator = vector_reverse_iterator<vector<Ty>>;
	using const_reverse_iterator = vector_reverse_const_iterator<vector<Ty>>;

private:
	pointer _Data;
	size_type _Size;
	size_type _Capacity;

private:
	constexpr void _Init(pointer Data = nullptr, size_type Size = 0, size_type Capacity = 0)
	{
		_Data = Data;
		_Size = Size;
		_Capacity = Capacity;
	}

	constexpr void _Destruct_All() const noexcept
	{
		for (size_type i(0); i < _Size; ++i)
			_Data[i].~Ty();
	}

	constexpr void _Destruct_Range(size_type _From, const size_type _To) const noexcept
	{
		for (; _From < _To; ++_From)
			_Data[_From].~Ty();
	}

	constexpr pointer _Alloc(size_type newCapacity) const noexcept
	{
		return (Ty *)::operator new(newCapacity * sizeof(Ty));
	}

	constexpr void _Dealloc(size_type Capacity) const noexcept
	{
		::operator delete(_Data, Capacity * sizeof(Ty));
	}

	constexpr void _Realloc(size_type newCapacity) noexcept
	{
		Ty *_new_ = _Alloc(newCapacity);

		for (size_type i(0); i < _Size; ++i)
			new (&_new_[i]) Ty(std::move(_Data[i]));

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_new_, _Size, newCapacity);
		_new_ = nullptr;
	}

	constexpr void _Construct_n(size_type _Count, const_reference _val) noexcept
	{
		_Init(_Alloc(_Count), _Count, _Count);

		for (size_type i(0); i < _Count; ++i)
			new (&_Data[i]) Ty(_val);
	}

	constexpr void _Construct(const vector &_Vec) noexcept
	{
		_Init(_Alloc(_Vec._Capacity), _Vec._Size, _Vec._Capacity);

		for (size_type i(0); i < _Size; ++i)
			new (&_Data[i]) Ty(_Vec._Data[i]);
	}

	template <typename _Iter>
	constexpr size_type _Get_Range_Len(_Iter _First, _Iter _Last) const noexcept
	{
		if (_First == nullptr)
			return 0;

		// if constexpr (std::_Is_ranges_random_iter_v<_Iter>) {
		// 	return static_cast<size_type>(_Last - _First);
		// }

		size_type _Count(0);
		for (; _First != _Last; ++_First)
			++_Count;
		return _Count;
	}

	template <typename _Iter>
	constexpr void _Construct_Range(_Iter _First, _Iter _Last) noexcept
	{
		for (size_type i(0); _First != _Last; ++_First, ++i)
			new (&_Data[i]) Ty(*_First);
	}

	constexpr void _Steal_Data(vector &_Vec) noexcept
	{
		_Init(_Vec._Data, _Vec._Size, _Vec._Capacity);
		_Vec._Init();
	}

	constexpr void _Make_Empty() noexcept
	{
		if (_Data)
		{
			_Destruct_All();
			_Size = 0;
		}
	}

	constexpr void _Clear() noexcept
	{
		if (_Data)
		{
			_Destruct_All();
			_Dealloc(_Capacity);
			_Init();
		}
	}

	constexpr void _Reserve(const size_type newCapacity) noexcept
	{
		vector _Old_;
		_Old_._Steal_Data(*this);

		_Init(_Alloc(newCapacity), _Old_._Size, newCapacity);

		for (size_type i(0); i < _Old_._Size; ++i)
		{
			new (&_Data[i]) Ty(std::move(_Old_._Data[i]));
		}
	}

	constexpr void _Shrink_Capacity_To(const size_type newCapacity) noexcept
	{
		_Destruct_Range(newCapacity, _Capacity);
		_Capacity = newCapacity;
	}

	constexpr iterator _Make_Iter(pointer _Where) const noexcept
	{
		return iterator(_Where);
	}

public:
	constexpr vector() noexcept { _Init(); }

	constexpr vector(size_type Count, const_reference _val = Ty()) noexcept
	{
		if (Count)
		{
			_Construct_n(Count, _val);
		}
		else
		{
			_Init();
		}
	}

	template <typename _Iterator>
	constexpr vector(_Iterator _First, _Iterator _Last) noexcept
	{
		size_type _len(_Get_Range_Len(_First, _Last));
		if (_len)
		{
			_Init(_Alloc(_len), _len, _len);
			_Construct_Range(_First, _Last);
		}
		else
		{
			_Init();
		}
	}

	constexpr vector(const vector &_Vec) noexcept
	{
		if (_Vec._Size)
		{
			_Construct(_Vec);
		}
		else
		{
			_Init();
		}
	}

	constexpr vector(vector &&_Vec) noexcept
	{
		if (_Vec._Size)
		{
			_Steal_Data(_Vec);
		}
		else
		{
			_Init();
		}
	}

	constexpr vector(std::initializer_list<Ty> _il) noexcept
	{
		size_type Size(_il.size());
		if (Size)
		{
			_Init(_Alloc(Size), Size, Size);
			_Construct_Range(_il.begin(), _il.end());
		}
		else
		{
			_Init();
		}
	}

	~vector() { _Clear(); }

	constexpr vector &operator=(const vector &_Vec) noexcept
	{
		if (this == &_Vec)
			return *this;
		if (_Vec._Size)
		{
			_Clear();
			_Construct(_Vec);
		}
		else
		{
			_Make_Empty();
		}
		return *this;
	}

	constexpr vector &operator=(vector &&_Vec) noexcept
	{
		if (this == &_Vec)
			return *this;
		if (_Vec._Size)
		{
			_Clear();
			_Steal_Data(_Vec);
		}
		else
		{
			_Make_Empty();
		}
		return *this;
	}

	constexpr vector &operator=(std::initializer_list<Ty> _il) noexcept
	{
		size_type Size(_il.size());
		if (Size)
		{
			_Clear();
			_Init(_Alloc(Size), Size, Size);
			_Construct_Range(_il.begin(), _il.end());
		}
		else
		{
			_Make_Empty();
		}
		return *this;
	}

	constexpr reference at(size_type _Off)
	{
		// if (_Size <= _Off) {
		// 	std::_Xout_of_range("_Off - is out_of_range");
		// }
		return _Data[_Off];
	}
	constexpr const_reference at(size_type _Off) const
	{
		// if (_Size <= _Off) {
		// 	std::_Xout_of_range("_Off - is out_of_range");
		// }
		// return _Data[_Off];
	}

	constexpr reference operator[](size_type _Off) noexcept { return _Data[_Off]; }
	constexpr const_reference operator[](size_type _Off) const noexcept { return _Data[_Off]; }

	constexpr reference front() noexcept { return _Data[0]; }
	constexpr const_reference front() const noexcept { return _Data[0]; }

	constexpr reference back() noexcept { return _Data[_Size - 1]; }
	constexpr const_reference back() const noexcept { return _Data[_Size - 1]; }

	constexpr pointer data() noexcept { return _Data[_Size - 1]; }
	constexpr const_pointer data() const noexcept { return _Data[_Size - 1]; }

	constexpr bool empty() const noexcept { return _Size == 0; }

	constexpr size_type size() const noexcept { return _Size; }
	constexpr size_type capacity() const noexcept { return _Capacity; }
	constexpr size_type max_size() const noexcept
	{
		return static_cast<size_type>(std::numeric_limits<ptrdiff_type>::max());
	}

	constexpr void reserve(const size_type newCapacity)
	{
		if (newCapacity > _Capacity)
		{ // if < do nothing
			// if (newCapacity > max_size()) {
			// 	std::_Xlength_error("you can't reserve this capacity");
			// }
			_Reserve(newCapacity);
		}
	}

	constexpr void shrink_to_fit() noexcept
	{
		if (_Capacity > _Size)
		{
			// destruct & reduce _Capacity to _Size
			_Shrink_Capacity_To(_Size);
		}
	}

	constexpr void clear() noexcept { _Clear(); }

private:
	constexpr bool _Out_Of_Range(const_iterator _Iter) const noexcept
	{
		return (_Iter < begin() || _Iter > end());
	}

	template <typename... Args>
	constexpr pointer _Emplace_One_Back(Args &&...args) noexcept
	{
		if (_Size >= _Capacity)
		{
			_Realloc(2 * _Capacity);
		}
		new (&_Data[_Size]) Ty(std::forward<Args>(args)...);
		return _Data + _Size++;
	}

	template <typename... Args>
	constexpr pointer _Emplace_One_Back_Unchecked(Args &&...args) noexcept
	{
		new (&_Data[_Size]) Ty(std::forward<Args>(args)...);
		return _Data + _Size++;
	}

	template <typename... Args>
	constexpr pointer _Insert_One_At_Unchecked(size_type _At, Args &&...args) noexcept
	{
		// 1- construct at the end
		new (&_Data[_Size]) Ty(std::forward<Args>(args)...);

		// 2- swap the values of elements from _Size --> _At
		if (_At == _Size - 1)
		{ // _Position is the last index
			algorithm::swap(_Data[_Size], _Data[_Size - 1]);
		}
		else
		{ // not the last index
			for (size_type i(_Size); i > _At; --i)
			{
				algorithm::swap(_Data[i], _Data[i - 1]);
			}
		}
		++_Size;
		return _Data + _At;
	}

	template <typename... Args>
	constexpr pointer _Insert_One_At_Realloc(size_type _At, size_type newCapacity, Args &&...args) noexcept
	{
		Ty *_New_ = _Alloc(newCapacity);

		size_type i(0); // iterator

		if (_At == _Size - 1)
		{ // if _At is the last index
			for (; i < _Size; ++i)
			{ // move data
				new (&_New_[i]) Ty(std::move(_Data[i]));
			}
			// emplace back and swap
			new (&_New_[_Size]) Ty(std::forward<Args>(args)...);
			algorithm::swap(_New_[_Size], _New_[_Size - 1]);
		}
		else
		{ // _At isn't the last index
			// check loop
			for (; i < _Size; ++i)
			{
				if (i == _At)
				{
					new (&_New_[i]) Ty(std::forward<Args>(args)...);
					break;
					// our work here is done move to the free loop
				}
				else
				{
					new (&_New_[i]) Ty(std::move(_Data[i]));
				}
			}

			// free loop (no check) for optimization
			// just adding the rest elements
			for (; i < _Size; ++i)
			{
				new (&_New_[i + 1]) Ty(std::move(_Data[i]));
			}
		}

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_New_, _Size + 1, newCapacity);
		_New_ = nullptr;

		return _Data + _At;
	}

	constexpr pointer _Append_n_Realloc(const size_type _Count, const_reference _val, const size_type newCapacity) noexcept
	{
		pointer _New_(_Alloc(newCapacity));

		size_type i(0); // iterator

		// move old data loop
		for (; i < _Size; ++i)
		{
			new (&_New_[i]) Ty(std::move(_Data[i]));
		}

		const size_type _OldSize(_Size);
		const size_type _NewSize(_Size + _Count);

		// append the new data
		for (; i < _NewSize; ++i)
		{
			new (&_New_[i]) Ty(_val);
		}

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_New_, _NewSize, newCapacity);
		_New_ = nullptr;

		return _Data + _OldSize; // pointer to the first appended element
	}

	constexpr pointer _Append_n(const size_type _Count, const_reference _val) noexcept
	{
		if (_Count + _Size > _Capacity)
		{ // if _Capacity isn't enough
			return _Append_n_Realloc(_Count, _val, 2 * (_Size + _Count));
		}

		size_type _OldSize(_Size);
		_Size += _Count;

		// append the new data
		for (size_type i(_OldSize); i < _Size; ++i)
		{
			new (&_Data[i]) Ty(_val);
		}

		return _Data + _OldSize; // pointer to the first appended element
	}

	constexpr void _Append_n_Unchecked(const size_type _Count, const_reference _val) noexcept
	{
		size_type _OldSize(_Size);
		_Size += _Count;

		// append the new data
		for (size_type i(_OldSize); i < _Size; ++i)
		{
			new (&_Data[i]) Ty(_val);
		}
	}

	constexpr pointer _Insert_n_At_Begin_Realloc(size_type _Count, const_reference _val, const size_type newCapacity) noexcept
	{
		pointer _New_(_Alloc(newCapacity));

		size_type _New_Pos(0); // iterator
		size_type _NewSize(_Size + _Count);

		// add the new elements
		for (; _Count > 0; --_Count, ++_New_Pos)
		{
			new (&_New_[_New_Pos]) Ty(_val);
		}

		// move the old elements
		for (size_type _Old_Pos(0); _New_Pos < _NewSize; ++_New_Pos, ++_Old_Pos)
		{
			new (&_New_[_New_Pos]) Ty(std::move(_Data[_Old_Pos]));
		}

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_New_, _NewSize, newCapacity);
		_New_ = nullptr;

		return _Data;
	}

	constexpr pointer _Insert_n_At_Realloc(size_type _At, size_type _Count, const_reference _val, const size_type newCapacity) noexcept
	{
		if (_At == 0)
		{
			return _Insert_n_At_Begin_Realloc(_Count, _val, newCapacity);
		}

		pointer _New_(_Alloc(newCapacity));

		size_type _New_Pos(0); // iterator
		size_type _NewSize(_Size + _Count);

		// move the old elements before _At
		for (; _New_Pos < _At; ++_New_Pos)
		{
			new (&_New_[_New_Pos]) Ty(std::move(_Data[_New_Pos]));
		}

		// add the new elements
		for (; _Count > 0; --_Count, ++_New_Pos)
		{
			new (&_New_[_New_Pos]) Ty(_val);
		}

		// move the rest old elements
		for (size_type _Old_Pos(_At); _New_Pos < _NewSize; ++_New_Pos, ++_Old_Pos)
		{
			new (&_New_[_New_Pos]) Ty(std::move(_Data[_Old_Pos]));
		}

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_New_, _NewSize, newCapacity);
		_New_ = nullptr;

		return _Data + _At;
	}

	constexpr pointer _Insert_n_At_Unchecked(size_type _At, size_type _Count, const_reference _val) noexcept
	{
		// no memory reallocation at all
		if (_Count == 1)
		{
			return _Insert_One_At_Unchecked(_At, _val);
		}

		// if _At = 2
		// move the elements range (2 -> _Size - 1) to the right (_Count) steps
		// if _Count = 3 for example & the _Size = 5 & _Capacity = 10
		// _val = 7
		// move and assign the new value
		// before move  -> { 1 2 3 4 5 - - - - - }
		// After move   -> { 1 2 3 4 7 - - 5 - - }
		// After move   -> { 1 2 3 7 7 - 4 5 - - }
		// After insert -> { 1 2 7 7 7 3 4 5 - - }

		// number of moved elements = (_Size - _At)
		size_type _From_Pos(_Size - 1), _To_Pos(_From_Pos + _Count);
		size_type _Put_Pos(_At + _Count - 1); // index of start assign the new value
		_Size += _Count;

		for (; _From_Pos >= _At; --_From_Pos, --_To_Pos)
		{
			new (&_Data[_To_Pos]) Ty(std::move(_Data[_From_Pos]));
			if (_From_Pos <= _Put_Pos)
			{
				_Data[_From_Pos] = _val;
				if (_From_Pos == 0)
					break; // to avoid overflow
			}
		}
		return _Data + _At;
	}

public:
	template <typename... Args>
	constexpr iterator emplace(const_iterator _Position, Args &&...args) noexcept
	{
		if (_Out_Of_Range(_Position))
		{
			return nullptr;
		}
		ptrdiff_type _Pos(_Position - begin()); // index of the _Position

		if (_Pos == _Size)
		{ // just push back
			return _Make_Iter(_Emplace_One_Back(std::forward<Args>(args)...));
		}

		if (_Size >= _Capacity)
		{
			return _Make_Iter(_Insert_One_At_Realloc(_Pos, 2 * _Capacity, std::forward<Args>(args)...));
		}
		return _Make_Iter(_Insert_One_At_Unchecked(_Pos, std::forward<Args>(args)...));
	}

	constexpr iterator insert(const_iterator _Position, const_reference _val) noexcept
	{
		return emplace(_Position, _val);
	}
	constexpr iterator insert(const_iterator _Position, rvalue_reference _val) noexcept
	{
		return emplace(_Position, std::move(_val));
	}

	// using index - not used
	constexpr iterator insert(size_type _Index, const_reference _val) noexcept
	{
		return emplace(begin() + _Index, _val);
	}
	constexpr iterator insert(size_type _Index, rvalue_reference _val) noexcept
	{
		return emplace(begin() + _Index, std::move(_val));
	}

	constexpr iterator insert(const_iterator _Position, size_type _Count, const_reference _val)
	{
		if (_Count == 0)
			return const_cast<pointer>(_Position._get_data());
		if (_Out_Of_Range(_Position))
			return nullptr;

		// if (_Count > max_size() - _Size) {
		// 	std::_Xlength_error("_Count is too big");
		// }

		ptrdiff_type _Pos(_Position - begin()); // index of the _Position

		if (_Pos == _Size)
		{ // just append at the end
			return _Make_Iter(_Append_n(_Count, _val));
		}

		if (_Count + _Size > _Capacity)
		{ // if _Capacity isn't enough
			return _Make_Iter(_Insert_n_At_Realloc(_Pos, _Count, _val, 2 * (_Size + _Count)));
		}
		return _Make_Iter(_Insert_n_At_Unchecked(_Pos, _Count, _val));
	}

private:
	template <typename _Iter>
	constexpr pointer _Append_Range_Realloc(_Iter _First, const size_type _Count, const size_type newCapacity) noexcept
	{
		pointer _New_(_Alloc(newCapacity));

		size_type i(0); // iterator

		// move old data loop
		for (; i < _Size; ++i)
		{
			new (&_New_[i]) Ty(std::move(_Data[i]));
		}

		const size_type _OldSize(_Size);
		const size_type _NewSize(_Size + _Count);

		// append the new data
		for (; i < _NewSize; ++_First, ++i)
		{
			new (&_New_[i]) Ty(*_First);
		}

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_New_, _NewSize, newCapacity);
		_New_ = nullptr;

		return _Data + _OldSize; // pointer to the first appended element
	}

	template <typename _Iter>
	constexpr pointer _Append_Range(_Iter _First, const size_type _Count) noexcept
	{
		if (_Count + _Size > _Capacity)
		{ // if _Capacity isn't enough
			return _Append_Range_Realloc(_First, _Count, 2 * (_Size + _Count));
		}

		const size_type _OldSize(_Size);
		_Size += _Count;

		// append the new data
		for (size_type i(_OldSize); i < _Size; ++_First, ++i)
		{
			new (&_Data[i]) Ty(*_First);
		}

		return _Data + _OldSize; // pointer to the first appended element
	}

	template <typename _Iter>
	constexpr pointer _Insert_Range_At_Begin_Realloc(size_type _Count, _Iter _First, const size_type newCapacity) noexcept
	{
		pointer _New_(_Alloc(newCapacity));

		size_type _New_Pos(0); // iterator
		size_type _NewSize(_Size + _Count);

		// add the new elements
		for (; _Count > 0; ++_First, --_Count, ++_New_Pos)
		{
			new (&_New_[_New_Pos]) Ty(*_First);
		}

		// move the old elements
		for (size_type _Old_Pos(0); _New_Pos < _NewSize; ++_New_Pos, ++_Old_Pos)
		{
			new (&_New_[_New_Pos]) Ty(std::move(_Data[_Old_Pos]));
		}

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_New_, _NewSize, newCapacity);
		_New_ = nullptr;

		return _Data;
	}

	template <typename _Iter>
	constexpr pointer _Insert_Range_At_Realloc(size_type _At, size_type _Count, _Iter _First, const size_type newCapacity) noexcept
	{
		if (_At == 0)
		{
			return _Insert_Range_At_Begin_Realloc(_Count, _First, newCapacity);
		}

		pointer _New_(_Alloc(newCapacity));

		size_type _New_Pos(0); // iterator
		size_type _NewSize(_Size + _Count);

		// move the old elements before _At
		for (; _New_Pos < _At; ++_New_Pos)
			new (&_New_[_New_Pos]) Ty(std::move(_Data[_New_Pos]));

		// add the new elements
		for (; _Count > 0; --_Count, ++_First, ++_New_Pos)
			new (&_New_[_New_Pos]) Ty(*_First);

		// move the rest old elements
		for (size_type _Old_Pos(_At); _New_Pos < _NewSize; ++_New_Pos, ++_Old_Pos)
			new (&_New_[_New_Pos]) Ty(std::move(_Data[_Old_Pos]));

		_Destruct_All();
		_Dealloc(_Capacity);
		_Data = nullptr;
		_Init(_New_, _NewSize, newCapacity);
		_New_ = nullptr;

		return _Data + _At;
	}

	template <typename _Iter>
	constexpr pointer _Insert_Range_At_Unchecked(size_type _At, size_type _Count, _Iter _Prev_Last) noexcept
	{
		// no memory reallocation at all
		if (_Count == 1)
		{
			return _Insert_One_At_Unchecked(_At, *_Prev_Last);
		}

		// if _At = 2
		// move the elements range (2 -> _Size - 1) to the right (_Count) steps
		// if _Count = 3 for example & the _Size = 5 & _Capacity = 10
		// _val = 7
		// move and assign the new value
		// before move  -> { 1 2 3 4 5 - - - - - }
		// After move   -> { 1 2 3 4 7 - - 5 - - }
		// After move   -> { 1 2 3 7 7 - 4 5 - - }
		// After insert -> { 1 2 7 7 7 3 4 5 - - }

		// number of moved elements = (_Size - _At)
		size_type _From_Pos(_Size - 1), _To_Pos(_From_Pos + _Count);
		size_type _Put_Pos(_At + _Count - 1); // index of start assign the new value
		_Size += _Count;

		for (; _From_Pos >= _At; --_From_Pos, --_To_Pos)
		{
			new (&_Data[_To_Pos]) Ty(std::move(_Data[_From_Pos]));
			if (_From_Pos <= _Put_Pos)
			{
				_Data[_From_Pos] = *_Prev_Last;
				--_Prev_Last;
				if (_From_Pos == 0)
					break; // to avoid overflow
			}
		}
		return _Data + _At;
	}

public:
	// template<typename _Iter, std::enable_if_t<std::_Is_iterator_v<_Iter>, int> = 0>
	template <typename _Iter>
	constexpr iterator insert(const_iterator _Position, _Iter _First, _Iter _Last)
	{
		if (_First == _Last)
			return const_cast<pointer>(_Position._get_data());
		if (_Out_Of_Range(_Position))
			return nullptr;

		size_type _Count(_Get_Range_Len(_First, _Last));

		// if (_Count > max_size() - _Size)
		// 	std::_Xlength_error("_Count is too big");

		ptrdiff_type _Pos(_Position - begin()); // index of the _Position

		if (_Pos == _Size)
		{ // just append at the end
			return _Make_Iter(_Append_Range(_First, _Count));
		}

		if (_Count + _Size > _Capacity)
		{ // if _Capacity isn't enough
			return _Make_Iter(_Insert_Range_At_Realloc(_Pos, _Count, _First, 2 * (_Size + _Count)));
		}
		return _Make_Iter(_Insert_Range_At_Unchecked(_Pos, _Count, _Last - 1));
	}

	constexpr iterator insert(const_iterator _Position, std::initializer_list<Ty> _il)
	{
		size_type _ilSize(_il.size());
		if (_ilSize == 0)
			return const_cast<pointer>(_Position._get_data());
		if (_Out_Of_Range(_Position))
			return nullptr;

		// if (_ilSize > max_size() - _Size)
		// 	std::_Xlength_error("_Count is too big");

		ptrdiff_type _Pos(_Position - begin()); // index of the _Position

		if (_Pos == _Size)
		{ // just append at the end
			return _Make_Iter(_Append_Range(_il.begin(), _ilSize));
		}

		if (_ilSize + _Size > _Capacity)
		{ // if _Capacity isn't enough
			return _Make_Iter(_Insert_Range_At_Realloc(_Pos, _ilSize, _il.begin(), 2 * (_Size + _ilSize)));
		}
		return _Make_Iter(_Insert_Range_At_Unchecked(_Pos, _ilSize, _il.end() - 1));
	}

private:
	constexpr bool _In_Valid_Range(const_iterator _Iter) const noexcept
	{
		return (_Iter >= begin() && _Iter < end());
	}

	constexpr bool _In_Range(const_iterator _Iter, const_iterator _From, const_iterator _To) const noexcept
	{
		return (_Iter >= _From && _Iter <= _To);
	}

	constexpr pointer _Erase_One_At(const size_type _At) noexcept
	{
		if (_At == _Size - 1)
		{
			_Data[--_Size].~Ty(); // just pop_back
			return _Data + _Size;
		}

		_Data[_At].~Ty(); // destruct

		// move all ellemnts after _At one step backward
		for (size_type _From_Pos(_At + 1), _To_Pos(_At); _From_Pos < _Size; ++_From_Pos, ++_To_Pos)
		{
			algorithm::swap(_Data[_From_Pos], _Data[_To_Pos]);
		}

		--_Size;
		return _Data + _At;
	}

	constexpr pointer _Erase_All() noexcept
	{
		for (size_type i(0); i < _Size; ++i)
		{
			_Data[i].~Ty();
		}
		_Size = 0;
		return _Data;
	}

	constexpr pointer _Erase_Range(const size_type _From, size_type _To) noexcept
	{
		if (_From == _To)
		{ // empty range
			return _Data + _To;
		}

		if (_From == 0 && _To == _Size)
		{
			return _Erase_All();
		}

		size_type _Count(_To - _From); // total erased elements

		if (_Count == 1)
		{
			return _Erase_One_At(_From);
		}

		size_type _First(_From);

		// erase loop
		for (; _First < _To; ++_First)
		{
			_Data[_First].~Ty();
		}

		_First = _From; // index of the first erased element

		// move the range (_To -> _Size - 1) to left
		for (; _To < _Size; ++_First, ++_To)
		{
			algorithm::swap(_Data[_First], _Data[_To]);
		}

		_Size -= _Count;
		return _Data + _From;
	}

public:
	constexpr iterator erase(const_iterator _Position) noexcept
	{
		if (!_In_Valid_Range(_Position))
		{
			return nullptr;
		}
		return _Make_Iter(_Erase_One_At(_Position - begin()));
	}
	constexpr iterator erase(const_iterator _First, const_iterator _Last) noexcept
	{
		if (!_In_Valid_Range(_First) || !_In_Range(_Last, _First, end()))
		{
			return nullptr;
		}
		return _Make_Iter(_Erase_Range(_First - begin(), _Last - begin()));
	}

	template <typename... Args>
	constexpr reference emplace_back(Args &&...args) noexcept
	{
		if (!_Data)
		{ // if no allocation
			// allocate memory for 21 elements
			_Init(_Alloc(21), 0, 21);
		}
		return *_Emplace_One_Back(std::forward<Args>(args)...);
	}

	constexpr void push_back(const_reference _val) noexcept
	{
		(void)emplace_back(_val);
	}
	constexpr void push_back(rvalue_reference _val) noexcept
	{
		(void)emplace_back(std::move(_val));
	}

	constexpr void pop_back() noexcept
	{
		if (empty())
			return;
		_Data[--_Size].~Ty();
	}

private:
	constexpr void _Resize(size_type _NewSize, const_reference _val = Ty()) noexcept
	{
		if (_NewSize > _Size)
		{ // grow _Size
			if (_NewSize > _Capacity)
			{ // allocate new memory
				(void)_Append_n_Realloc(_NewSize - _Size, _val, _NewSize);
			}
			else
			{ // no memory allocation
				_Append_n_Unchecked(_NewSize, _val);
			}
		}
		else
		{ // reduce _Size
			while (_Size > _NewSize)
			{
				_Data[--_Size].~Ty();
			}
		}
	}

public:
	constexpr void resize(size_type _NewSize, const_reference _val) noexcept
	{
		if (_NewSize == _Size || _NewSize > max_size())
		{ // do nothing
			return;
		}
		_Resize(_NewSize);
	}
	constexpr void resize(size_type _NewSize) noexcept
	{
		resize(_NewSize, Ty());
	}

	template <typename _Condition>
	constexpr size_type remove_if(_Condition _Cond) noexcept
	{
		if (empty())
			return 0;

		size_type _OldSize(_Size);

		for (size_type i(0); i < _Size;)
		{
			if (_Cond(_Data[i]))
			{
				(void)_Erase_One_At(i);
			}
			else
			{
				++i;
			}
		}
		return _OldSize - _Size;
	}
	constexpr size_type remove(const_reference _val) noexcept
	{
		return remove_if([&](const Ty &_elem)
										 { return _elem == _val; });
	}

	constexpr void swap(vector &_Vec) noexcept
	{
		if (this == &_Vec)
			return;

		vector _temp(std::move(*this));
		_Steal_Data(_Vec);
		_Vec._Steal_Data(_temp);
	}

	constexpr void reverse() const noexcept
	{
		if (_Size < 2)
			return;

		for (size_type S(0), E(_Size - 1); S < E; ++S, --E)
		{
			algorithm::swap(_Data[S], _Data[E]);
		}
	}

	// ascending sort
	constexpr void sort() const noexcept
	{
		utility::arr_util::sort(_Data, _Size);
	}

	// for the(_Not_Sorted) parameter:
	//   - (false) if the vector is sorted function will use --> binary search (fast)
	//   - (true) if the vector isn't sorted function will use --> linear search (slow) by default
	constexpr size_type find(const_reference _val, bool _Not_Sorted = true) const noexcept
	{
		return utility::arr_util::binary_search(_Data, _Size, _val, _Not_Sorted);
	}

	// iterator methods
	//------------------------------------------------------------------------------
	constexpr iterator begin() noexcept { return iterator(_Data); }
	constexpr const_iterator begin() const noexcept { return const_iterator(_Data); }
	constexpr const_iterator cbegin() const noexcept { return begin(); }

	constexpr iterator end() noexcept { return iterator(_Data + _Size); }
	constexpr const_iterator end() const noexcept { return const_iterator(_Data + _Size); }
	constexpr const_iterator cend() const noexcept { return end(); }

	constexpr reverse_iterator rbegin() noexcept { return reverse_iterator(_Data + _Size); }
	constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(_Data + _Size); }
	constexpr const_reverse_iterator crbegin() const noexcept { return rbegin(); }

	constexpr reverse_iterator rend() noexcept { return reverse_iterator(_Data); }
	constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator(_Data); }
	constexpr const_reverse_iterator crend() const noexcept { return rend(); }
	//------------------------------------------------------------------------------

	// comparison operators
	//------------------------------------------------------------------------------
	constexpr bool operator==(const vector &_rhs) const noexcept
	{
		if (this == &_rhs)
			return true;
		if (_Size != _rhs._Size)
			return false;

		for (size_type i(0); i < _Size; ++i)
		{
			if (_Data[i] != _rhs._Data[i])
				return false;
		}
		return true;
	}

	constexpr bool operator!=(const vector &_rhs) const noexcept
	{
		return !(*this == _rhs);
	}

	constexpr bool operator<(const vector &_rhs) const noexcept
	{
		if (_Size < _rhs._Size)
			return true;
		if (_Size > _rhs._Size)
			return false;

		size_type this_points(0), other_points(0);

		for (size_type i(0); i < _Size; ++i)
		{
			if (_Data[i] > _rhs._Data[i])
				++this_points;
			else if (_Data[i] < _rhs._Data[i])
				++other_points;
		}
		return this_points < other_points;
	}

	constexpr bool operator>(const vector &_rhs) const noexcept
	{
		return _rhs < *this;
	}

	constexpr bool operator<=(const vector &_rhs) const noexcept
	{
		return !(*this > _rhs);
	}

	constexpr bool operator>=(const vector &_rhs) const noexcept
	{
		return !(*this < _rhs);
	}
	//------------------------------------------------------------------------------

	void print() const noexcept
	{
		std::cout << "\n\n";
		for (size_type i(0); i < _Size; ++i)
		{
			std::cout << "\"" << _Data[i] << "\""
								<< "  ";
		}
		std::cout << "\n- Size = " << _Size;
		std::cout << "\n- Capacity = " << _Capacity;
		std::cout << "\n\n";
	}
};

MG_END
