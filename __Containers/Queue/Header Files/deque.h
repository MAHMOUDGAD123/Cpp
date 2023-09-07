#pragma once
#include <initializer_list>
#include "MG_utility.h"

#ifndef MG_BEGIN
#define MG_BEGIN \
	namespace MG   \
	{
#define MG_END }
#endif

MG_BEGIN

//=====================================================================================================
//=========================================== Froward Iterator ========================================
//=====================================================================================================

// deque const_iterator class
template <typename _Deque>
class deque_const_iterator
{
public:
	using value_type = typename _Deque::value_type;
	using pointer = typename _Deque::const_pointer;
	using reference = typename _Deque::const_reference;
	using size_type = typename _Deque::size_type;
	using ptrdiff_type = typename _Deque::ptrdiff_type;

private:
	pointer _Ptr;

public:
	constexpr deque_const_iterator() : _Ptr(nullptr) {}
	constexpr deque_const_iterator(pointer Data_Ptr) : _Ptr(Data_Ptr) {}

	constexpr reference operator*() const noexcept
	{
		return *_Ptr;
	}

	constexpr pointer operator->() const noexcept
	{
		return _Ptr;
	}

	constexpr reference operator[](const ptrdiff_type _idx) const noexcept
	{
		return *(_Ptr + _idx);
	}

	constexpr deque_const_iterator &operator++() noexcept
	{
		// pre increament
		++_Ptr;
		return *this;
	}
	constexpr deque_const_iterator operator++(int) noexcept
	{
		// post increament
		deque_const_iterator _temp = *this;
		++_Ptr;
		return _temp;
	}

	constexpr deque_const_iterator &operator--() noexcept
	{
		// pre decreament
		--_Ptr;
		return *this;
	}
	constexpr deque_const_iterator operator--(int) noexcept
	{
		// post decreament
		deque_const_iterator _temp = *this;
		--_Ptr;
		return _temp;
	}

	constexpr deque_const_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Ptr += _Off;
		return *this;
	}

	constexpr deque_const_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Ptr -= _Off;
		return *this;
	}

	constexpr deque_const_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr + _Off};
	}

	constexpr deque_const_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr - _Off};
	}

	constexpr ptrdiff_type operator-(const deque_const_iterator &_Right) const noexcept
	{
		return _Ptr - _Right._Ptr;
	}

	friend constexpr deque_const_iterator operator+(const ptrdiff_type _Off, const deque_const_iterator &_Right)
	{
		return {_Right + _Off};
	}

	// comparison operators
	//-------------------------------------------------------------------------
	constexpr bool operator==(const deque_const_iterator &other) const noexcept
	{
		return _Ptr == other._Ptr;
	}

	constexpr bool operator!=(const deque_const_iterator &other) const noexcept
	{
		return _Ptr != other._Ptr;
	}

	constexpr bool operator<(const deque_const_iterator &other) const noexcept
	{
		return _Ptr < other._Ptr;
	}

	constexpr bool operator>(const deque_const_iterator &other) const noexcept
	{
		return _Ptr > other._Ptr;
	}

	constexpr bool operator<=(const deque_const_iterator &other) const noexcept
	{
		return _Ptr <= other._Ptr;
	}

	constexpr bool operator>=(const deque_const_iterator &other) const noexcept
	{
		return _Ptr >= other._Ptr;
	}
	//-------------------------------------------------------------------------
};

// deque iterator class
template <typename _Deque>
class deque_iterator : public deque_const_iterator<_Deque>
{
public:
	using value_type = typename _Deque::value_type;
	using pointer = typename _Deque::pointer;
	using reference = typename _Deque::reference;
	using size_type = typename _Deque::size_type;
	using ptrdiff_type = typename _Deque::ptrdiff_type;

	using _Base = deque_const_iterator<_Deque>;

public:
	constexpr deque_iterator() noexcept {}
	constexpr deque_iterator(pointer Data_Ptr) noexcept : _Base(Data_Ptr) {}

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

	constexpr deque_iterator &operator++() noexcept
	{
		// pre increament
		_Base::operator++();
		return *this;
	}
	constexpr deque_iterator operator++(int) noexcept
	{
		// post increament
		deque_iterator _temp = *this;
		_Base::operator++();
		return _temp;
	}

	constexpr deque_iterator &operator--() noexcept
	{
		// pre decreament
		_Base::operator--();
		return *this;
	}
	constexpr deque_iterator operator--(int) noexcept
	{
		// post decreament
		deque_iterator _temp = *this;
		_Base::operator--();
		return _temp;
	}

	constexpr deque_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator+=(_Off);
		return *this;
	}

	constexpr deque_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator-=(_Off);
		return *this;
	}

	constexpr deque_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		deque_iterator _temp = *this;
		_temp += _Off;
		return _temp;
	}

	constexpr deque_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		deque_iterator _temp = *this;
		_temp -= _Off;
		return _temp;
	}

	constexpr ptrdiff_type operator-(const deque_iterator &_Right) const noexcept
	{
		return _Base::operator-(_Right);
	}

	friend constexpr deque_iterator operator+(const ptrdiff_type _Off, const deque_iterator &_Right) noexcept
	{
		return {_Right + _Off};
	}
};

//=====================================================================================================
//=========================================== Reverse Iterator ========================================
//=====================================================================================================

// deque const_reverse iterator class
template <typename _Deque>
class deque_const_reverse_iterator
{
public:
	using value_type = typename _Deque::value_type;
	using pointer = typename _Deque::const_pointer;
	using reference = typename _Deque::const_reference;
	using size_type = typename _Deque::size_type;
	using ptrdiff_type = typename _Deque::ptrdiff_type;

private:
	pointer _Ptr;

public:
	constexpr deque_const_reverse_iterator() : _Ptr(nullptr) {}
	constexpr deque_const_reverse_iterator(pointer Data_Ptr) : _Ptr(Data_Ptr) {}

	constexpr reference operator*() const noexcept
	{
		pointer _temp = _Ptr;
		return *--_temp;
	}

	constexpr reference operator[](const ptrdiff_type _idx) const noexcept
	{
		return *(_Ptr - _idx - 1);
	}

	constexpr pointer operator->() const noexcept
	{
		pointer _temp = _Ptr;
		return --_temp;
	}

	constexpr deque_const_reverse_iterator &operator++() noexcept
	{
		--_Ptr;
		return *this;
	}
	constexpr deque_const_reverse_iterator operator++(int) noexcept
	{
		deque_const_reverse_iterator _temp = *this;
		--_Ptr;
		return _temp;
	}

	constexpr deque_const_reverse_iterator &operator--() noexcept
	{
		++_Ptr;
		return *this;
	}
	constexpr deque_const_reverse_iterator operator--(int) noexcept
	{
		deque_const_reverse_iterator _temp = *this;
		++_Ptr;
		return _temp;
	}

	constexpr deque_const_reverse_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Ptr -= _Off;
		return *this;
	}

	constexpr deque_const_reverse_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Ptr += _Off;
		return *this;
	}

	constexpr deque_const_reverse_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr - _Off};
	}

	constexpr deque_const_reverse_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		return {_Ptr + _Off};
	}

	constexpr ptrdiff_type operator-(const deque_const_reverse_iterator &_Right) const noexcept
	{
		return _Right._Ptr - _Ptr;
	}

	friend constexpr deque_const_reverse_iterator operator+(const ptrdiff_type _Off, const deque_const_reverse_iterator &_Right) noexcept
	{
		return {_Right + _Off};
	}

	// comparison operators
	//-------------------------------------------------------------------------
	constexpr bool operator==(const deque_const_reverse_iterator &_rhs) const noexcept
	{
		return _Ptr == _rhs._Ptr;
	}

	constexpr bool operator!=(const deque_const_reverse_iterator &_rhs) const noexcept
	{
		return _Ptr != _rhs._Ptr;
	}

	constexpr bool operator<(const deque_const_reverse_iterator &_rhs) const noexcept
	{
		return _Ptr > _rhs._Ptr;
	}

	constexpr bool operator>(const deque_const_reverse_iterator &_rhs) const noexcept
	{
		return _Ptr < _rhs._Ptr;
	}

	constexpr bool operator<=(const deque_const_reverse_iterator &_rhs) const noexcept
	{
		return _Ptr >= _rhs._Ptr;
	}

	constexpr bool operator>=(const deque_const_reverse_iterator &_rhs) const noexcept
	{
		return _Ptr <= _rhs._Ptr;
	}
	//-------------------------------------------------------------------------
};

// deque reverse iterator class
template <typename _Deque>
class deque_reverse_iterator : public deque_const_reverse_iterator<_Deque>
{
public:
	using value_type = typename _Deque::value_type;
	using pointer = typename _Deque::pointer;
	using reference = typename _Deque::reference;
	using size_type = typename _Deque::size_type;
	using ptrdiff_type = typename _Deque::ptrdiff_type;

	using _Base = deque_const_reverse_iterator<_Deque>;

public:
	constexpr deque_reverse_iterator() noexcept {}
	constexpr deque_reverse_iterator(pointer Data_Ptr) noexcept : _Base(Data_Ptr) {}

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

	constexpr deque_reverse_iterator &operator++() noexcept
	{
		_Base::operator++();
		return *this;
	}
	constexpr deque_reverse_iterator operator++(int) noexcept
	{
		deque_reverse_iterator _temp = *this;
		_Base::operator++();
		return _temp;
	}

	constexpr deque_reverse_iterator &operator--() noexcept
	{
		_Base::operator--();
		return *this;
	}
	constexpr deque_reverse_iterator operator--(int) noexcept
	{
		deque_reverse_iterator _temp = *this;
		_Base::operator--();
		return _temp;
	}

	constexpr deque_reverse_iterator &operator+=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator+=(_Off);
		return *this;
	}

	constexpr deque_reverse_iterator &operator-=(const ptrdiff_type _Off) noexcept
	{
		_Base::operator-=(_Off);
		return *this;
	}

	constexpr deque_reverse_iterator operator+(const ptrdiff_type _Off) const noexcept
	{
		deque_reverse_iterator _temp = *this;
		_temp += _Off;
		return _temp;
	}

	constexpr deque_reverse_iterator operator-(const ptrdiff_type _Off) const noexcept
	{
		deque_reverse_iterator _temp = *this;
		_temp -= _Off;
		return _temp;
	}

	constexpr ptrdiff_type operator-(const deque_reverse_iterator &_Right) const noexcept
	{
		return _Base::operator-(_Right);
	}

	friend constexpr deque_reverse_iterator operator+(const ptrdiff_type _Off, const deque_reverse_iterator &_Right)
	{
		return {_Right + _Off};
	}
};

//=====================================================================================================
//================================================ Deque ==============================================
//=====================================================================================================

template <typename _Ty>
class deque
{
public:
	using value_type = _Ty;
	using pointer = _Ty *;
	using const_pointer = const _Ty *;
	using reference = _Ty &;
	using const_reference = const _Ty &;
	using rvalue_reference = _Ty &&;
	using size_type = size_t;
	using ptrdiff_type = int64_t;

	using iterator = deque_iterator<deque<_Ty>>;
	using const_iterator = deque_const_iterator<deque<_Ty>>;
	using reverse_iterator = deque_reverse_iterator<deque<_Ty>>;
	using const_reverse_iterator = deque_const_reverse_iterator<deque<_Ty>>;

private:
	pointer _data;			 // data pointer
	size_type _first;		 // the index of the first element
	size_type _capacity; // total capacity
	size_type _size;		 // current number of elements

	static constexpr int min_capacity = 8; // minimum capacity(_init_)

private:
	void _init(pointer data = nullptr, size_type first = 0, size_type capacity = 0, size_type size = 0)
	{
		_data = data;
		_first = first;
		_capacity = capacity;
		_size = size;
	}

	pointer _alloc(size_type Capacity)
	{
		return (pointer)::operator new(Capacity * sizeof(_Ty));
	}

	void _dealloc(size_type Capacity)
	{
		::operator delete(_data, Capacity * sizeof(value_type));
		_data = nullptr;
	}

	void _realloc(size_type newCapacity)
	{
		pointer _temp = _alloc(newCapacity);
		size_type new_first = newCapacity / 3;

		for (size_t i(0); i < _size; i++)
			new (&_temp[new_first + i]) _Ty(std::move(_data[_first + i]));

		_destruct_all();
		_dealloc(_capacity);
		_init(_temp, new_first, newCapacity, _size);
		// _size => keep the same
	}

	void _destruct_all()
	{
		for (size_t i(_first); i < _size; i++)
			_data[i].~value_type();
	}

	void _kill()
	{
		if (_data)
		{
			_destruct_all();
			_dealloc(_capacity);
			_first = _size = _capacity = 0;
		}
	}

	constexpr size_type _get_capacity(size_type size) const noexcept
	{
		// get the suitable capacity
		size_type new_cap = algorithm::next_power_of_2(size);
		return (new_cap < min_capacity) ? min_capacity : new_cap;
	}

	void _copy(const deque &other)
	{
		_init(_alloc(other._capacity), other._first, other._capacity, other._size);

		for (size_type i(0); i < _size; i++)
			new (&_data[_first + i]) value_type(other._data[_first + i]);
	}

	void _ilist(std::initializer_list<_Ty> _il)
	{
		size_type Capacity = _get_capacity(_il.size());
		_init(_alloc(Capacity), 0, Capacity, _il.size());
		_Construct(_il.begin(), _il.end());
	}

	void _move(deque &other)
	{
		_init(other._data, other._first, other._capacity, other._size);

		other._data = nullptr;
		other._size = other._capacity = other._first = 0;
	}

	template <typename Ty>
	void _Construct_n(size_type _Count, const Ty &_val)
	{
		for (size_type i(0); i < _Count; i++)
			new (&_data[i]) value_type(_val);
	}

	template <typename _interator>
	void _Construct(_interator first, _interator last)
	{
		for (size_type i(0); first != last; ++first, ++i)
			new (&_data[i]) value_type(*first);
	}

public:
	deque() noexcept { _init(); }

	deque(size_type _Count, const_reference _val) noexcept
	{
		if (_Count)
		{
			size_type Capacity = _get_capacity(_Count);
			_init(_alloc(Capacity), 0, Capacity, _Count);
			_Construct_n(_Count, _val);
		}
		else
			_init();
	}

	// only enable if the typename (_iter) is iterator
	// template<typename _iter, std::enable_if_t<std::_Is_iterator_v<_iter>, int> = 0>
	template <typename _iter>
	deque(_iter first, _iter last) noexcept
	{
		size_type size = last - first;
		if (size)
		{
			size_type Capacity = _get_capacity(size);
			_init(_alloc(Capacity), 0, Capacity, size);
			_Construct(first, last);
		}
		else
			_init();
	}

	deque(const deque &other) noexcept
	{
		if (!other.empty())
			_copy(other);
		else
			_init();
	}

	deque(deque &&other) noexcept
	{
		if (!other.empty())
			_move(other);
		else
			_init();
	}

	deque(std::initializer_list<_Ty> _il) noexcept
	{
		size_type len(_il.size());
		if (len)
		{
			_ilist(_il);
		}
		else
			_init();
	}

	constexpr deque &operator=(const deque &other) noexcept
	{
		if (this == &other)
			return *this;
		if (!other.empty())
		{
			_kill();
			_copy(other);
		}
		else
		{
			_kill();
		}
		return *this;
	}

	constexpr deque &operator=(deque &&other) noexcept
	{
		if (this == &other)
			return *this;
		if (!other.empty())
		{
			_kill();
			_move(other);
		}
		else
		{
			_kill();
		}
		return *this;
	}

	constexpr deque &operator=(std::initializer_list<_Ty> _il) noexcept
	{
		if (_il.size())
		{
			_kill();
			_ilist(_il);
		}
		else
		{
			_kill();
		}
		return *this;
	}

	~deque() { _kill(); }

	constexpr size_type size() const noexcept { return _size; }

	// demo
	//-------------------------------------------------------------------
	constexpr size_type capacity() const noexcept { return _capacity; }
	constexpr size_type offset() const noexcept { return _first; }
	//-------------------------------------------------------------------

	constexpr bool empty() const noexcept { return _size == 0; }

	constexpr reference operator[](size_type _pos) { return _data[_first + _pos]; }
	constexpr const_reference operator[](size_type _pos) const { return _data[_first + _pos]; }

	void push_back(const_reference _val)
	{
		(void)emplace_back(_val);
	}
	void push_back(rvalue_reference _val)
	{
		(void)emplace_back(std::move(_val));
	}

	template <typename... Args>
	constexpr reference emplace_back(Args &&...args)
	{
		if (!_data)
		{ // if _data is null
			_init(_alloc(min_capacity), 3, min_capacity, 0);
		}
		else if (_first + _size == _capacity)
		{
			_realloc(_capacity * 2);
		}

		new (&_data[_first + _size]) value_type(std::forward<Args>(args)...);
		return _data[_first + _size++];
	}

	void push_front(const_reference _val)
	{
		(void)emplace_front(_val);
	}
	void push_front(rvalue_reference _val)
	{
		(void)emplace_front(std::move(_val));
	}

	template <typename... Args>
	constexpr reference emplace_front(Args &&...args)
	{
		if (!_data)
		{ // if _data is null
			_init(_alloc(min_capacity), 3, min_capacity, 0);
		}
		else if (!_first)
		{ // reallocate if (_first == 0)
			_realloc(_capacity ? _capacity * 2 : min_capacity);
		}

		new (&_data[--_first]) value_type(std::forward<Args>(args)...);
		++_size;
		return _data[_first];
	}

	void pop_back()
	{
		if (!empty())
		{
			_data[_first + --_size].~value_type();
		}
	}

	void pop_front()
	{
		if (!empty())
		{
			_data[_first].~value_type();
			++_first, --_size;
		}
	}

	void clear() noexcept
	{
		if (!empty())
		{
			_kill();
		}
	}

	void resize(size_type _newSize)
	{
		if (!_newSize)
			_kill();
		while (_size < _newSize)
		{
			emplace_back();
		}
		while (_size > _newSize)
		{
			pop_back();
		}
	}
	void resize(size_type _newSize, const_reference _val)
	{
		if (!_newSize)
			_kill();
		while (_size < _newSize)
		{
			emplace_back(_val);
		}
		while (_size > _newSize)
		{
			pop_back();
		}
	}

	void shrink_to_fit()
	{
		if (!empty())
			return;

		size_type _newCapacity = _get_capacity(_size);

		if (_newCapacity != _capacity)
		{
			deque _temp(begin(), end());
			swap(_temp);
		}
	}

	void swap(deque &other) noexcept
	{
		if (this != &other)
		{
			std::swap(_data, other._data);
			std::swap(_capacity, other._capacity);
			std::swap(_size, other._size);
			std::swap(_first, other._first);
		}
	}

	constexpr reference front() { return _data[_first]; }
	constexpr const_reference front() const { return _data[_first]; }

	constexpr reference back() { return _data[_first + _size - 1]; }
	constexpr const_reference back() const { return _data[_first + _size - 1]; }

	// iterators
	//---------------------------------------------------------------------------------
	// forward iterator
	constexpr iterator begin() noexcept { return iterator(_data + _first); }
	constexpr const_iterator begin() const noexcept { return const_iterator(_data + _first); }
	constexpr const_iterator cbegin() const noexcept { return begin(); }

	constexpr iterator end() noexcept { return iterator(_data + _first + _size); }
	constexpr const_iterator end() const noexcept { return const_iterator(_data + _first + _size); }
	constexpr const_iterator cend() const noexcept { return end(); }

	// reverse iterator
	constexpr reverse_iterator rbegin() noexcept { return reverse_iterator(_data + _first + _size); }
	constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(_data + _first + _size); }
	constexpr const_reverse_iterator crbegin() const noexcept { return rbegin(); }

	constexpr reverse_iterator rend() noexcept { return reverse_iterator(_data + _first); }
	constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator(_data + _first); }
	constexpr const_reverse_iterator crend() const noexcept { return rend(); }
	//---------------------------------------------------------------------------------

	constexpr bool operator==(const deque &_rhs) const noexcept
	{
		if (this == &_rhs)
			return true;
		if (_size != _rhs._size)
			return false;

		for (size_type i(0); i < _size; ++i)
		{
			if (_data[i] != _rhs._data[i])
			{
				return false;
			}
		}
		return true;
	}

	constexpr bool operator!=(const deque &_rhs) const noexcept
	{
		return !(*this == _rhs);
	}
};

MG_END