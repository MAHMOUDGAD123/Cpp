#pragma once

#include <initializer_list>
#include "MG_utility.h"


namespace MG {


	template<typename _Ty>
	class queue
	{
	public:
		using value_type = _Ty;
		using reference = _Ty&;
		using const_reference = const _Ty&;
		using rvalue_reference = _Ty&&;
		using pointer = _Ty*;
		using const_pointer = const _Ty*;
		using size_type = size_t;
		
	private:
		pointer _Data;
		size_type _Size;
		size_type _Capacity;
		size_type _Start; // index of the first element
		size_type _End; // index of the last element

	private:
		constexpr void _Init(pointer Data = nullptr, size_type Size = 0, size_type Capacity = 0, size_type Start = 0) noexcept
		{
			_Data = Data;
			_Size = Size;
			_Capacity = Capacity;
			_Start = Start;
			_End = (_Size) ? _Size - 1 : _Size;
		}

		constexpr void _Zero_Fill() noexcept
		{
			_Data = nullptr;
			_Size = 0;
			_Capacity = 0;
			_Start = 0;
			_End = 0;
		}

		constexpr void _Steal_Data(queue& _Other) noexcept
		{
			_Data = _Other._Data;
			_Size = _Other._Size;
			_Capacity = _Other._Capacity;
			_Start = _Other._Start;
			_End = _Other._End;

			_Other._Zero_Fill();
		}

		constexpr void _Destruct_All() noexcept
		{
			for (size_type _Last(_Start + _Size); _Start < _Last; ++_Start) {
				_Data[_Start].~_Ty();
			}
		}

		constexpr void _Dealloc(size_type Capacity) noexcept
		{
			::operator delete(_Data, Capacity * sizeof(_Ty));
			_Data = nullptr;
		}

		constexpr pointer _Alloc(size_type _NewCapacity) noexcept
		{
			return (_Ty*)::operator new(_NewCapacity * sizeof(_Ty));
		}

		constexpr void _Realloc(size_type _NewCapacity) noexcept
		{
			pointer _New_ = _Alloc(_NewCapacity);

			for (size_type i(0); i < _Size; ++i) {
				new(&_New_[i]) _Ty(std::move(_Data[_Start + i]));
			}
			_Destruct_All();
			_Dealloc(_Capacity);
			_Init(_New_, _Size, _NewCapacity);
			_New_ = nullptr;
		}

		template<typename _Iter>
		constexpr void _Construct_Range(_Iter _First, _Iter _Last) noexcept
		{
			for (size_type i(0); _First != _Last; ++_First, ++i) {
				new(&_Data[i]) _Ty(*_First);
			}
		}

		constexpr void _Construct(const queue& _Other) noexcept
		{
			for (size_type i(0); i < _Other._Size; ++i) {
				new(&_Data[i]) _Ty(_Other._Data[_Other._Start + i]);
			}
		}

		constexpr void _Clear() noexcept
		{
			if (_Data) {
				_Destruct_All();
				_Dealloc(_Capacity);
				_Size = 0;
				_Capacity = 0;
				_Start = 0;
				_End = 0;
			}
		}

		template<typename _Iter>
		constexpr size_type _Get_Range_Size(_Iter _First, _Iter _Last) noexcept
		{
			if (!_First) return 0;
			size_type _Count{ 0 };
			for (; _First != _Last; ++_First) {
				++_Count;
			}
			return _Count;
		}

	public:
		constexpr queue() noexcept
			: _Data(nullptr), _Size(0), _Capacity(0), _Start(0), _End(0)
		{}

		constexpr queue(const queue& _Other) noexcept
		{
			if (_Other.empty()) {
				_Zero_Fill();
			}
			else {
				_Init(_Alloc(_Other._Capacity), _Other._Size, _Other._Capacity);
				_Construct(_Other);
			}
		}

		constexpr queue(queue&& _Other) noexcept
		{
			if (_Other.empty()) {
				_Zero_Fill();
			}
			else {
				_Steal_Data(_Other);
			}
		}

		constexpr queue(std::initializer_list<_Ty> _il) noexcept
		{
			size_type size{ _il.size() };
			if (size) {
				size_type _NewCapacity{ 2 * size };
				_Init(_Alloc(_NewCapacity), size, _NewCapacity);
				_Construct_Range(_il.begin(), _il.end());
			}
			else {
				_Zero_Fill();
			}
		}

		template<typename _Iterator>
		constexpr queue(_Iterator _First, _Iterator _Last) noexcept
		{
			size_type size{ _Get_Range_Size(_First, _Last) };
			if (size) {
				size_type _NewCapacity{ 2 * size };
				_Init(_Alloc(_NewCapacity), size, _NewCapacity);
				_Construct_Range(_First, _Last);
			}
			else {
				_Zero_Fill();
			}
		}

		constexpr queue& operator=(const queue& _Other) noexcept
		{
			if (this == &_Other) return *this;
			if (_Other.empty()) {
				_Clear();
			}
			else {
				_Clear();
				_Init(_Alloc(_Other._Capacity), _Other._Size, _Other._Capacity);
				_Construct(_Other);
			}
			return *this;
		}

		constexpr queue& operator=(queue&& _Other) noexcept
		{
			if (this == &_Other) return *this;
			if (_Other.empty()) {
				_Clear();
			}
			else {
				_Clear();
				_Steal_Data(_Other);
			}
			return *this;
		}

		constexpr queue& operator=(std::initializer_list<_Ty> _il) noexcept
		{
			size_type size{ _il.size() };
			if (size) {
				_Clear();
				size_type _NewCapacity{ 2 * size };
				_Init(_Alloc(_NewCapacity), size, _NewCapacity);
				_Construct_Range(_il.begin(), _il.end());
			}
			else {
				_Clear();
			}
			return *this;
		}

		~queue() { _Clear(); }


		constexpr size_type size() const noexcept { return _Size; }
		constexpr bool empty() const noexcept { return _Size == 0; }

		constexpr reference front() noexcept { return _Data[_Start]; }
		constexpr const_reference front() const noexcept { return _Data[_Start]; }

		constexpr reference back() noexcept { return _Data[_End]; }
		constexpr const_reference back() const noexcept { return _Data[_End]; }

		template<typename... Args>
		constexpr reference emplace(Args&&... _val) noexcept
		{
			if (!_Data) { // if _Data is null
				// allocate memory for 7 elements
				_Init(_Alloc(7), 1, 7);
				new(&_Data[0]) _Ty(std::forward<Args>(_val)...);
				return _Data[0];
			}
			if (_End >= _Capacity - 1) { // if _End is at the end
				_Realloc(_Size < _Capacity ? _Size * 2 : _Capacity * 2);
			}
			new(&_Data[++_End]) _Ty(std::forward<Args>(_val)...);
			++_Size;
			return _Data[_End]; // return a reference to the pushed element
		}

		constexpr void push(const_reference _val) noexcept { (void)emplace(_val); }
		constexpr void push(rvalue_reference _val) noexcept { (void)emplace(std::move(_val)); }

		constexpr void pop() noexcept
		{
			if (empty()) return;

			_Data[_Start].~_Ty(); // calling the destructor for the first element

			if (--_Size == 0) { // if it was the last element
				_Start = _End = 0;
			}
			else {
				++_Start;
			}
		}

		constexpr void swap(queue& _Other) noexcept
		{
			if (this == &_Other) return;

			queue _Temp{ std::move(*this) };
			_Steal_Data(_Other);
			_Other._Steal_Data(_Temp);
		}

		constexpr void reverse() noexcept
		{
			if (_Size == 0 || _Size == 1) return;

			for (size_type S(_Start), E(_End); S < E; ++S, --E) {
				algorithm::swap(_Data[S], _Data[E]);
			}
		}

		constexpr void clear() noexcept { _Clear(); }


		constexpr bool operator==(const queue& _rhs) const noexcept
		{
			if (this == &_rhs) return true;
			if (_Size != _rhs._Size) return false;

			for (size_type i(_Start); i <= _End; ++i) {
				if (_Data[i] != _rhs._Data[i]) {
					return false;
				}
			}
			return true;
		}

		constexpr bool operator!=(const queue& _rhs) const noexcept
		{
			return !(*this == _rhs);
		}


		void print() const noexcept
		{
			std::cout << "\n\n";
			if (empty()) { // demo purpose
				std::cout << "Empty :-(";
			}
			else {
				for (size_t i(_Start); i <= _End; ++i) {
					std::cout << _Data[i] << "  ";
				}
			}
			std::cout << "\n\n";
		}

		friend constexpr std::ostream& operator<<(std::ostream& Out, const queue<_Ty>& Q)
		{
			std::cout << "\n\n";
			if (Q.empty()) { // demo purpose
				std::cout << "Empty :-(";
			}
			else {
				for (size_t i(Q._Start); i <= Q._End; ++i) {
					std::cout << Q._Data[i] << "  ";
				}
			}
			std::cout << "\n\n";
			return Out;
		}



	};

}