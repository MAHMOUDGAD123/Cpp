#pragma once
#include "deque.h"


MG_BEGIN


template<typename _Ty, typename _Container = deque<_Ty>>
class istack
{
private:
	_Container _C_;

public:
	// using _Container type aliases
	using value_type = typename _Container::value_type;
	using reference = typename _Container::reference;
	using const_reference = typename _Container::const_reference;
	using rvalue_reference = typename _Container::rvalue_reference;
	using size_type = typename _Container::size_type;

	using iterator = typename _Container::iterator;
	using const_iterator = typename _Container::const_iterator;
	using reverse_iterator = typename _Container::reverse_iterator;
	using const_reverse_iterator = typename _Container::const_reverse_iterator;

	//==============================================================

	// constructor
	constexpr istack() noexcept 
		: _C_() {}

	constexpr istack(const _Container& _Cont) noexcept
		: _C_(_Cont) {}

	constexpr istack(_Container&& _Cont) noexcept
		: _C_(std::move(_Cont)) {}

	constexpr istack(const istack& _Other) noexcept
		: _C_(_Other._C_) {}

	constexpr istack(istack&& _Other) noexcept
		: _C_(std::move(_Other._C_)) {}

	template<typename _Iterator>
	constexpr istack(_Iterator _First, _Iterator _Last) noexcept
		: _C_(_First, _Last) {}


	constexpr istack(std::initializer_list<_Ty> _il) noexcept
		: _C_(_il) {}

	//==============================================================

	// assigment operator =
	constexpr istack& operator=(const _Container& _Cont) noexcept { _C_ = _Cont; return *this; }
	constexpr istack& operator=(_Container&& _Cont) noexcept { _C_ = std::move(_Cont); return *this; }

	constexpr istack& operator=(const istack& _Other) noexcept { _C_ = _Other._C_; return *this; }
	constexpr istack& operator=(istack&& _Other) noexcept { _C_ = std::move(_Other._C_); return *this; }

	constexpr istack& operator=(std::initializer_list<_Ty> _il) noexcept { _C_ = _il; return *this; }

	//==============================================================
	
	// member functions
	constexpr bool empty() const noexcept { return _C_.empty(); }
	constexpr size_type size() const noexcept { return _C_.size(); }

	constexpr reference top() noexcept { return _C_.back(); }
	constexpr const_reference top() const noexcept { return _C_.back(); }

	template<typename... _Val>
	constexpr reference emplace(_Val&&... _val) noexcept { return _C_.emplace_back(std::forward<_Val>(_val)...); }

	constexpr void push(const_reference _val) noexcept { _C_.push_back(_val); }
	constexpr void push(rvalue_reference _val) noexcept { _C_.push_back(std::move(_val)); }
	
	constexpr void swap(istack& _Other) noexcept { _C_.swap(_Other._C_); }

	constexpr void pop() noexcept { _C_.pop_back(); }

	constexpr const _Container& get_container() const noexcept { return _C_; }

	//==============================================================

	// comparsion opertors == / !=
	constexpr bool operator==(const istack& _rhs) const noexcept { return _C_ == _rhs._C_; }
	constexpr bool operator!=(const istack& _rhs) const noexcept { return _C_ != _rhs._C_; }



	// demo
	void print() const noexcept
	{
		std::cout << "\n\n";
		if (empty()) {
			std::cout << "-> Empty :-(";
		}
		else {
			const_reverse_iterator rB = _C_.crbegin();
			const_reverse_iterator rE = _C_.crend();
			for (; rB != rE; ++rB) {
				std::cout << *rB << "  ";
			}
			std::cout << "\n-> Size = " << size()
				<< " - TOS = " << top();
		}
		std::cout << "\n\n";
	}

};


MG_END

