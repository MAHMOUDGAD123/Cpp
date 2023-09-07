#pragma once

#include "deque"
#include "vector"

#define MG_BEGIN \
	namespace MG   \
	{
#define MG_END }

MG_BEGIN

// by default as a (deque)
// template <typename _Ty, typename _Container = MG::deque<_Ty>>
template <typename _Ty, typename _Container>
class iqueue
{
private:
	_Container _C_; // the container

public:
	// use the _Container type aliases
	using value_type = typename _Container::value_type;
	using reference = typename _Container::reference;
	using const_reference = typename _Container::const_reference;
	using size_type = typename _Container::size_type;
	using rvalue_reference = typename _Container::rvalue_reference; // not in the STL

	//======================================================================

	// Constructors
	constexpr iqueue() noexcept
			: _C_() {}

	// copy
	constexpr iqueue(const _Container &_Cont) noexcept
			: _C_(_Cont) {}

	// move
	constexpr iqueue(_Container &&_Cont) noexcept
			: _C_(std::move(_Cont)) {}

	// copy
	constexpr iqueue(const iqueue &_Other) noexcept
			: _C_(_Other._C_) {}

	// move
	constexpr iqueue(iqueue &&_Other) noexcept
			: _C_(std::move(_Other._C_)) {}

	// std::initializer_list
	constexpr iqueue(std::initializer_list<_Ty> _il) noexcept
			: _C_(_il) {}

	// iterators
	template <typename _Iterator>
	constexpr iqueue(_Iterator _First, _Iterator _Last) noexcept
			: _C_(_First, _Last) {}

	//======================================================================

	// assignment operator

	// copy
	constexpr iqueue &operator=(const _Container &_Cont) noexcept
	{
		_C_ = _Cont;
		return *this;
	}
	constexpr iqueue &operator=(const iqueue &_Other) noexcept
	{
		_C_ = _Other._C_;
		return *this;
	}

	// move
	constexpr iqueue &operator=(_Container &&_Cont) noexcept
	{
		_C_ = std::move(_Cont);
		return *this;
	}
	constexpr iqueue &operator=(iqueue &&_Other) noexcept
	{
		_C_ = std::move(_Other._C_);
		return *this;
	}

	constexpr iqueue &operator=(std::initializer_list<_Ty> _il) noexcept
	{
		_C_ = _il;
		return *this;
	}

	//======================================================================

	// member functions
	constexpr bool empty() const noexcept { return _C_.empty(); }
	constexpr size_type size() const noexcept { return _C_.size(); }

	constexpr reference front() noexcept { return _C_.front(); }
	constexpr const_reference front() const noexcept { return _C_.front(); }

	constexpr reference back() noexcept { return _C_.back(); }
	constexpr const_reference back() const noexcept { return _C_.back(); }

	// emplace_back()
	template <typename... Args>
	constexpr reference emplace(Args &&...args) noexcept { return _C_.emplace_back(std::forward<_Ty>(args)...); }

	// push_back()
	constexpr void push(const_reference _val) noexcept { _C_.push_back(_val); }
	constexpr void push(rvalue_reference _val) noexcept { _C_.push_back(std::move(_val)); }

	constexpr void pop() noexcept { _C_.pop_front(); }

	constexpr void swap(iqueue &_Other) noexcept { _C_.swap(_Other._C_); }

	// returns a const reference of the container
	constexpr const _Container &get_container() const noexcept { return _C_; }

	// comparsion operators == / !=
	constexpr bool operator==(const iqueue &_rhs) const noexcept { return _C_ == _rhs._C_; }
	constexpr bool operator!=(const iqueue &_rhs) const noexcept { return _C_ != _rhs._C_; }

	// demo
	constexpr void print() noexcept
	{
		std::cout << "\n\n";
		if (empty())
		{
			std::cout << "-> Empty :-(";
		}
		else
		{
			for (const _Ty &_elem : _C_)
			{
				std::cout << _elem << "  ";
			}
			std::cout << "\n-> Front = " << front();
			std::cout << "\n-> Back = " << back();
		}
		std::cout << "\n\n";
	}
};

MG_END