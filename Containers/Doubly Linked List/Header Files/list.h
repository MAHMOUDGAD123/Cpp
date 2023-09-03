#pragma once
#include <initializer_list>



namespace MG {

	template<typename _list>
	class list_iterator
	{
	public:
		using Node_Ptr = typename _list::Node_Ptr;
		using value_type = typename _list::value_type;
		using pointer = value_type*;
		using reference = value_type&;
		using size_type = size_t;

		Node_Ptr _ptr; // pointer to node

	public:
		constexpr list_iterator() noexcept
			: _ptr(nullptr)
		{}
		constexpr list_iterator(Node_Ptr Nodeptr) noexcept
			: _ptr(Nodeptr)
		{}


		constexpr Node_Ptr get_node() const noexcept
		{
			return _ptr;
		}
		constexpr Node_Ptr& get_node() noexcept
		{
			return _ptr;
		}

		constexpr Node_Ptr get_next_node() const noexcept
		{
			return _ptr->_next;
		}
		constexpr Node_Ptr& get_next_node() noexcept
		{
			return _ptr->_next;
		}

		constexpr reference operator*() const noexcept
		{
			return _ptr->_data;
		}

		constexpr pointer operator->() const noexcept
		{
			return _ptr;
		}

		constexpr list_iterator& operator++() noexcept
		{
			_ptr = _ptr->_next;
			return *this;
		}

		constexpr list_iterator operator++(int) noexcept
		{
			list_iterator _temp = *this;
			_ptr = _ptr->_next;
			return _temp;
		}

		constexpr list_iterator& operator--() noexcept
		{
			_ptr = _ptr->_prev;
			return *this;
		}

		constexpr list_iterator operator--(int) noexcept
		{
			list_iterator _temp = *this;
			_ptr = _ptr->_prev;
			return _temp;
		}

		constexpr bool operator ==(const list_iterator& _Other) const noexcept
		{
			return _ptr == _Other._ptr;
		}

		constexpr bool operator !=(const list_iterator& _Other) const noexcept
		{
			return _ptr != _Other._ptr;
		}

	};

	template<typename _list>
	class list_reverse_iterator
	{
	public:
		using Node_Ptr = typename _list::Node_Ptr;
		using value_type = typename _list::value_type;
		using pointer = value_type*;
		using reference = value_type&;
		using size_type = size_t;

		Node_Ptr _ptr; // pointer to node

	public:
		constexpr list_reverse_iterator() noexcept
			: _ptr(nullptr)
		{}
		constexpr list_reverse_iterator(Node_Ptr Nodeptr) noexcept
			: _ptr(Nodeptr)
		{}


		constexpr reference operator*() const noexcept
		{
			return _ptr->_data;
		}

		constexpr pointer operator->() const noexcept
		{
			return _ptr;
		}

		constexpr list_reverse_iterator& operator++() noexcept
		{
			_ptr = _ptr->_prev;
			return *this;
		}

		constexpr list_reverse_iterator operator++(int) noexcept
		{
			list_reverse_iterator _temp = *this;
			_ptr = _ptr->_prev;
			return _temp;
		}

		constexpr list_reverse_iterator& operator--() noexcept
		{
			_ptr = _ptr->_next;
			return *this;
		}

		constexpr list_reverse_iterator operator--(int) noexcept
		{
			list_reverse_iterator _temp = *this;
			_ptr = _ptr->_next;
			return _temp;
		}

		constexpr bool operator ==(const list_reverse_iterator& _Other) const noexcept
		{
			return _ptr == _Other._ptr;
		}

		constexpr bool operator !=(const list_reverse_iterator& _Other) const noexcept
		{
			return _ptr != _Other._ptr;
		}

	};




	template<typename _Type>
	struct sNode
	{
		using Node_Ptr = sNode<_Type>*;

		_Type _data;
		Node_Ptr _prev;
		Node_Ptr _next;

		sNode() = default;
		sNode(const sNode&) = delete;
		sNode& operator=(const sNode&) = delete;
		~sNode() = default;

		template<typename... Args>
		constexpr void _Construct_in_place(Args&&... args) noexcept
		{
			new(&_data) _Type(std::forward<Args>(args)...);
		}

		constexpr void _Connect_Front(Node_Ptr _Next) noexcept
		{
			_next = _Next;
		}
		constexpr void _Connect_Back(Node_Ptr _Previous) noexcept
		{
			_prev = _Previous;
		}

		constexpr void _Connect(Node_Ptr _Previous, Node_Ptr _Next) noexcept
		{
			_prev = _Previous;
			_next = _Next;
		}

		constexpr void _Destruct() noexcept
		{
			_data.~_Type();
			_next = nullptr;
			_prev = nullptr;
		}

		constexpr void _Swap_Data(Node_Ptr& _Other) noexcept
		{
			// only swap the _data
			_Type _temp = std::move(_data);
			_data = std::move(_Other->_data);
			_Other->_data = std::move(_temp);
		}

	};



	template<typename _Ty>
	class list // circular doubly linked list
	{
	private:
		using _Node = sNode<_Ty>;

	public:
		using Node_Ptr = _Node*;
		using value_type = _Ty;
		using size_type = size_t;
		using pointer = _Ty*;
		using const_pointer = const _Ty*;
		using reference = _Ty&;
		using const_reference = const _Ty&;
		using rvalue_reference = _Ty&&;

		using iterator = list_iterator<list<_Ty>>;
		using reverse_iterator = list_reverse_iterator<list<_Ty>>;
		using const_iterator = const iterator;
		using const_reverse_iterator = const reverse_iterator;

	private:
		Node_Ptr _Head; // is (empty node) / _next points to the first node / _prev points to last node
		size_type _Size;

		// node allocation size
		static constexpr const size_type _Node_Size = static_cast<size_type>(sizeof(_Node));

	private:
		constexpr void _Init()
		{
			_Head = _Alloc_Construct(_Ty{});
			_Head->_Connect(_Head, _Head);
			_Size = 0;
		}

		constexpr void _Deallocate(Node_Ptr& _Node)
		{
			::operator delete(_Node, _Node_Size);
			_Node = nullptr;
		}

		constexpr void _Freenode(Node_Ptr& _Node)
		{
			_Node->_Destruct();
			_Deallocate(_Node);
		}

		constexpr Node_Ptr _Release(Node_Ptr& _Node)
		{
			Node_Ptr Taken = _Node;
			_Node = nullptr;
			return Taken;
		}

		template<typename... Args>
		constexpr Node_Ptr _Alloc_Construct(Args&&... args)
		{
			Node_Ptr _Newnode = (Node_Ptr)::operator new(_Node_Size);
			_Newnode->_Construct_in_place(std::forward<Args>(args)...);
			return _Newnode;
		}

		template<typename... Args>
		constexpr void _Construct_n(size_type _Count, const Args&... args)
		{
			_Head = _Alloc_Construct(_Ty{}); // empty node
			Node_Ptr _Newnode = _Alloc_Construct(args...);
			_Head->_Connect_Front(_Newnode);
			_Newnode->_Connect_Back(_Head);
			--_Count;

			Node_Ptr _Prev{ nullptr };
			for (; _Count > 0; --_Count) {
				_Newnode->_Connect_Front(_Alloc_Construct(args...));
				_Prev = _Newnode;
				_Newnode = _Newnode->_next;
				_Newnode->_Connect_Back(_Prev);
			}
			_Newnode->_Connect_Front(_Head);
			_Head->_Connect_Back(_Newnode);
		}

		template<typename _iter>
		constexpr size_type _Get_Range_Len(_iter _First, _iter _Last)
		{
			// _First must be before _Last
			size_type len(0);
			for (; _First != _Last; ++_First) {
				++len;
			}
			return len;
		}

		template<typename _iterator>
		constexpr size_type _Construct_Range(_iterator _First, _iterator _Last)
		{
			_Head = _Alloc_Construct(_Ty{});
			Node_Ptr _Newnode = _Alloc_Construct(*_First);
			_Head->_Connect_Front(_Newnode);
			_Newnode->_Connect_Back(_Head);
			++_First;
			size_type _Count(1);

			Node_Ptr _Prev{ nullptr };
			for (; _First != _Last; ++_First) {
				_Newnode->_Connect_Front(_Alloc_Construct(*_First));
				_Prev = _Newnode;
				_Newnode = _Newnode->_next;
				_Newnode->_Connect_Back(_Prev);
				++_Count;
			}
			_Head->_Connect_Back(_Newnode);
			_Newnode->_Connect_Front(_Head);
			return _Count;
		}

		constexpr void _Steal_Data(list& _list)
		{
			// take data
			_Head = _list._Head;
			_Size = _list._Size;
			_list._Head = nullptr;
			_list._Size = 0;
		}

		template<typename... Args>
		constexpr void _Insert(Node_Ptr TNode, Args&&... args)
		{
			Node_Ptr _Newnode = _Alloc_Construct(std::forward<Args>(args)...);
			_Newnode->_Connect(TNode->_prev, TNode);
			TNode->_Connect_Back(_Newnode);
			_Newnode->_prev->_Connect_Front(_Newnode);
		}

		constexpr Node_Ptr _Erase(Node_Ptr TNode) noexcept
		{
			if (TNode == _Head) { // when using end()
				TNode = TNode->_prev; // can't erase _Head
			}
			Node_Ptr _Next_{ TNode->_next };
			// unlink & free TNode
			TNode->_prev->_Connect_Front(_Next_);
			_Next_->_Connect_Back(TNode->_prev);
			_Freenode(TNode);
			--_Size;
			return _Next_;
		}

		constexpr Node_Ptr _Erase_Range(Node_Ptr _First, Node_Ptr _Last) noexcept
		{
			if (_First == _Last) { // do nothing
				return _Last;
			}

			if (_First == _Head) { // to avoid data lose
				// swap
				Node_Ptr _temp = _First;
				_First = _Last;
				_Last = _temp;
			}

			Node_Ptr _Next_{ nullptr };
			for (; _First != _Last; _First = _Next_) {
				_Next_ = _Erase(_First);
			}
			return _Last;
		}

		constexpr iterator _Make_Iter(Node_Ptr _Where) const noexcept
		{
			return iterator(_Where);
		}

		constexpr void _Shrink_To(size_type Newsize) noexcept
		{
			// loop to get the the start point node
			Node_Ptr _First = _Head->_next;
			for (size_type i(0); i < Newsize; ++i) {
				_First = _First->_next;
			}
			// erase from (_First) to (_Head->_prev)
			while (_First != _Head) {
				_First = _Erase(_First);
			}
		}

		template<typename... Args>
		constexpr void _Emplace_Front(Args&&... args) noexcept
		{
			Node_Ptr _Newnode = _Alloc_Construct(std::forward<Args>(args)...);
			_Newnode->_Connect(_Head, _Head->_next);
			_Head->_next->_Connect_Back(_Newnode);
			_Head->_Connect_Front(_Newnode);
			++_Size;
		}

		template<typename... Args>
		constexpr void _Emplace_Back(Args&&... args) noexcept
		{
			Node_Ptr _Newnode = _Alloc_Construct(std::forward<Args>(args)...);
			_Newnode->_Connect(_Head->_prev, _Head);
			_Head->_prev->_Connect_Front(_Newnode);
			_Head->_Connect_Back(_Newnode);
			++_Size;
		}

		template<typename... Args>
		constexpr void _Attach_n(size_type _Count, const Args&... args) noexcept
		{
			// loop to attach (args) to the end
			for (; _Count > 0; --_Count) {
				_Emplace_Back(args...);
			}
		}

		template<typename... Args>
		constexpr void _Resize(size_type Newsize, const Args&... args)
		{
			if (Newsize < _Size) {
				_Shrink_To(Newsize);
			}
			else { // Newsize > _Size
				_Attach_n(Newsize - _Size, args...);
			}
		}


		constexpr void _Splice(Node_Ptr TNode, list& _Other) noexcept
		{
			_Other._Head->_prev->_Connect_Front(TNode);
			_Other._Head->_next->_Connect_Back(TNode->_prev);
			TNode->_prev->_Connect_Front(_Other._Head->_next);
			TNode->_Connect_Back(_Other._Head->_prev);
			_Size += _Other._Size;
			_Other._Init(); // make _Other empty!
		}
		constexpr void _Splice(Node_Ptr TNode, list& _Other, Node_Ptr _Moved) noexcept
		{
			if (TNode != _Moved && TNode != _Moved->_prev) {
				_Moved->_prev->_Connect_Front(_Moved->_next);
				_Moved->_next->_Connect_Back(_Moved->_prev);
				_Moved->_Connect(TNode->_prev, TNode);
				TNode->_prev->_Connect_Front(_Moved);
				TNode->_Connect_Back(_Moved);
				if (this != &_Other) {
					++_Size;
					--_Other._Size;
				}
			}
		}
		constexpr void _Splice(Node_Ptr TNode, list& _Other, Node_Ptr _First, Node_Ptr _Last) noexcept
		{
			if (_First == _Last || TNode == _First) { // do nothing
				return;
			}

			if (this != &_Other) {
				size_type _Count{ _Get_Range_Len(_Make_Iter(_First), _Make_Iter(_Last)) };
				_Size += _Count;
				_Other._Size -= _Count;
			}

			Node_Ptr _Prev_Last{ _Last->_prev }; // last moved element
			// cut the range
			_First->_prev->_Connect_Front(_Last);
			_Last->_Connect_Back(_First->_prev);
			// move
			_First->_Connect_Back(TNode->_prev);
			_Prev_Last->_Connect_Front(TNode);
			TNode->_prev->_Connect_Front(_First);
			TNode->_Connect_Back(_Prev_Last);
		}


		constexpr Node_Ptr _Remove(Node_Ptr& _Target) noexcept
		{
			Node_Ptr _Next_{ _Target->_next };
			_Target->_prev->_Connect_Front(_Next_);
			_Next_->_Connect_Back(_Target->_prev);
			_Freenode(_Target);
			return _Next_;
		}

		template<typename Condition>
		constexpr void _Merge(list& _Other, Condition _Cond) noexcept
		{
			if (this == &_Other || _Other.empty()) { // can't merge a list to itself || merge an empty list
				return;
			}
			if (empty()) { // if *this is empty
				swap(_Other);
				return;
			}

			// data must be sorted in ascending or descending order due to _Cond

			Node_Ptr _this_{ _Head->_next };
			Node_Ptr _Other_{ _Other._Head->_next };

			Node_Ptr _Next_{ _Head }; // used to construct the new merged list

			while (true) {
				if (_this_ == _Head) { // when _this_ reach the end
					_Next_->_Connect_Front(_Other_);
					_Other_->_Connect_Back(_Next_);
					// close the list
					_Head->_Connect_Back(_Other._Head->_prev);
					_Other._Head->_prev->_Connect_Front(_Head);
					break;
				}
				if (_Other_ == _Other._Head) { // when _Other_ reach the end
					_Next_->_Connect_Front(_this_);
					_this_->_Connect_Back(_Next_);
					// here we don't need to close the list
					// because it's already closed
					break;
				}

				if (_Cond(_this_->_data, _Other_->_data)) {
					_Next_->_Connect_Front(_this_);
					_this_->_Connect_Back(_Next_);
					_this_ = _this_->_next;
				}
				else {
					_Next_->_Connect_Front(_Other_);
					_Other_->_Connect_Back(_Next_);
					_Other_ = _Other_->_next;
				}
				_Next_ = _Next_->_next; // advance _Next_ by 1
			}
			_Size += _Other._Size;
			// make sure _Other is empty
			_Other._Head->_Connect(_Other._Head, _Other._Head);
			_Other._Size = 0;
		}

		constexpr Node_Ptr& _Get_Last_Node(Node_Ptr& _Start_Point)
		{
			if (_Start_Point == _Head) {
				return _Head->_prev;
			}

			while (_Start_Point->_next != _Head) {
				_Start_Point = _Start_Point->_next;
			}
			return _Start_Point;
		}

		template<typename Condition>
		constexpr Node_Ptr _Merge(Node_Ptr L1, Node_Ptr L2, Condition _Cond) noexcept
		{
			if (L1 == _Head && L2 == _Head) return _Head;
			if (L1 == _Head) return L2;
			if (L2 == _Head) return L1;

			Node_Ptr _Merged_{ nullptr }; // will hold the new data after merge

			// initialize the _Merged_ node
			if (_Cond(L1->_data, L2->_data)) {
				_Merged_ = L1;
				L1 = L1->_next;
			}
			else {
				_Merged_ = L2;
				L2 = L2->_next;
			}

			Node_Ptr _Next_{ _Merged_ }; // a used node to construct the new _Merged_ node

			while (true) {
				if (L1 == _Head) { // when _this_ reach the end
					_Next_->_Connect_Front(L2);
					L2->_Connect_Back(_Next_);
					_Head->_Connect_Back(_Get_Last_Node(L2));
					break;
				}
				if (L2 == _Head) { // when _Other_ reach the end
					_Next_->_Connect_Front(L1);
					L1->_Connect_Back(_Next_);
					_Head->_Connect_Back(_Get_Last_Node(L1));
					break;
				}

				if (_Cond(L1->_data, L2->_data)) {
					_Next_->_Connect_Front(L1);
					L1->_Connect_Back(_Next_);
					L1 = L1->_next;
				}
				else {
					_Next_->_Connect_Front(L2);
					L2->_Connect_Back(_Next_);
					L2 = L2->_next;
				}
				_Next_ = _Next_->_next; // advance _Next_ by 1
			}
			return _Merged_;
		}


		constexpr Node_Ptr _Mid_Point(Node_Ptr& _First)
		{
			// get the mid point of a list
			Node_Ptr _slow = _First;
			Node_Ptr _fast = _First->_next;

			while (_fast != _Head && _fast->_next != _Head) {
				_slow = _slow->_next; // advance by 1
				_fast = _fast->_next->_next; // advance by 2
			}
			return _slow; // which hold the mid point
		}

		template<typename Condition>
		constexpr Node_Ptr _Sort(Node_Ptr _First, Condition _Cond) noexcept
		{
			if (_First == _Head || _First->_next == _Head) return _First;

			Node_Ptr _Mid = _Mid_Point(_First);
			Node_Ptr _L1 = _First;
			Node_Ptr _L2 = _Mid->_next;
			_Mid->_Connect_Front(_Head); // to separate _L1 and _L2

			_L1 = _Sort(_L1, _Cond);
			_L2 = _Sort(_L2, _Cond);

			return _Merge(_L1, _L2, _Cond);
		}

		template<typename Condition>
		constexpr void _Merge_Sort(Condition _Cond) noexcept
		{
			if (_Size == 0 || _Size == 1) return;

			Node_Ptr _Sorted_{ _Sort(_Head->_next, _Cond) };
			_Head->_Connect_Front(_Sorted_);
			_Sorted_->_Connect_Back(_Head);
		}

		template<typename Condition>
		constexpr void _Selection_Sort(Condition _Cond) noexcept
		{
			if (_Size == 0 || _Size == 1) return;
			// O(n^2)
			for (Node_Ptr _Curr{ _Head->_next }; _Curr != _Head; _Curr = _Curr->_next) { // n
				for (Node_Ptr _Next{ _Curr->_next }; _Next != _Head; _Next = _Next->_next) { // n
					if (_Cond(_Next->_data, _Curr->_data)) {
						_Curr->_Swap_Data(_Next);
					}
				}
			}
		}

	public:
		constexpr list() noexcept { _Init(); }

		constexpr explicit list(size_type _Count, const_reference _val) noexcept
		{
			if (_Count) {
				_Construct_n(_Count, _val);
				_Size = _Count;
			}
			else {
				_Init();
			}
		}

		constexpr explicit list(size_type _Count) noexcept
			: list(_Count, _Ty{})
		{}

		// only enable if the typename (_iter) is iterator
		// template <typename _iterator, std::enable_if_t<std::_Is_iterator_v<_iterator>, int> = 0>
		// constexpr list(_iterator _First, _iterator _Last) noexcept
		// {
		// 	if (_First != nullptr) { // if first isn't null
		// 		_Size = _Construct_Range(_First, _Last);
		// 	}
		// 	else {
		// 		_Init();
		// 	}
		// }

		constexpr list(const list& _Other) noexcept
		{
			if (_Other.empty()) {
				_Init();
			}
			else {
				_Size = _Construct_Range(_Other.begin(), _Other.end());
			}
		}

		constexpr list(list&& _Other) noexcept
		{
			_Steal_Data(_Other);
		}

		constexpr list(std::initializer_list<_Ty> _il) noexcept
		{
			if (_il.size()) {
				_Size = _Construct_Range(_il.begin(), _il.end());
			}
			else {
				_Init();
			}
		}

		constexpr list& operator=(const list& _Other) noexcept
		{
			if (this == &_Other) {
				return *this;
			}
			if (_Other.empty()) {
				clear();
			}
			else {
				clear();
				_Size = _Construct_Range(_Other.begin(), _Other.end());
			}
			return *this;
		}

		constexpr list& operator=(list&& _Other) noexcept
		{
			if (this == &_Other) {
				return *this;
			}
			if (_Other.empty()) {
				clear();
			}
			else {
				clear();
				_Steal_Data(_Other);
			}
			return *this;
		}

		constexpr list& operator=(std::initializer_list<_Ty> _il) noexcept
		{
			if (_il.size()) {
				clear();
				_Size = _Construct_Range(_il.begin(), _il.end());
			}
			else {
				clear();
			}
			return *this;
		}

		~list()
		{
			if (_Head) { // if null do nothing
				clear();
				_Freenode(_Head);
			}
		}

		constexpr bool empty() const noexcept
		{
			return _Size == 0;
		}

		constexpr size_type size() const noexcept
		{
			return _Size;
		}

		constexpr void clear() noexcept
		{
			if (!empty()) { // erase all
				Node_Ptr _Curr = _Head->_next;
				Node_Ptr _Next = nullptr;

				for (; _Curr != _Head; _Curr = _Next) {
					_Next = _Curr->_next;
					_Freenode(_Curr);
				}
				_Curr = _Next = nullptr;
				_Head->_Connect(_Head, _Head);
				_Size = 0;
			}
		}

		constexpr reference front() noexcept
		{
			return _Head->_next->_data;
			//return *begin();
		}
		constexpr const_reference front() const noexcept
		{
			return _Head->_next->_data;
			//return *begin();
		}

		constexpr reference back() noexcept
		{
			return _Head->_prev->_data;
		}
		constexpr const_reference back() const noexcept
		{
			return _Head->_prev->_data;
		}

		constexpr void assign(size_type _Count, const_reference _val)
		{
			clear();
			if (_Count) {
				_Construct_n(_Count, _val);
				_Size = _Count;
			}
		}
		constexpr void assign(std::initializer_list<_Ty> _il)
		{
			clear();
			if (_il.size()) {
				_Size = _Construct_Range(_il.begin(), _il.end());
			}
		}

		// template<typename _iter, std::enable_if_t<std::_Is_iterator_v<_iter>, int> = 0>
		// constexpr void assign(_iter _First, _iter _Last)
		// {
		// 	clear();
		// 	if (_First != nullptr) {
		// 		_Size = _Construct_Range(_First, _Last);
		// 	}
		// }

		template<typename... Args>
		constexpr iterator emplace(const_iterator _position, Args&&... args)
		{
			if (empty() || _position == nullptr) return nullptr;
			_Insert(_position._ptr, std::forward<Args>(args)...);
			++_Size;
			return _Make_Iter(_position._ptr->_prev);
		}


		constexpr iterator insert(const_iterator _position, const_reference _val)
		{
			return emplace(_position, _val);
		}
		constexpr iterator insert(const_iterator _position, rvalue_reference _val)
		{
			return emplace(_position, std::move(_val));
		}
		constexpr iterator insert(const_iterator _position, size_type _Count, const_reference _val)
		{
			if (empty() || _position == nullptr) return nullptr;
			if (!_Count) return _position; // if _Count == 0
			Node_Ptr _Prev_{ _position._ptr->_prev }; // node before _position

			for (; _Count; --_Count) {
				_Insert(_position._ptr, _val);
			}
			_Size += _Count;
			return _Make_Iter(_Prev_->_next);
		}
		constexpr iterator insert(const_iterator _position, std::initializer_list<_Ty> _il)
		{
			if (!_il.size()) return _position;
			return insert(_position, _il.begin(), _il.end());
		}

		// template<typename _iter, std::enable_if_t<std::_Is_iterator_v<_iter>, int> = 0>
		// constexpr iterator insert(const_iterator _position, _iter _First, _iter _Last)
		// {
		// 	if (empty() || _position == nullptr) return nullptr;
		// 	if (_First == _Last) return _position;
		// 	Node_Ptr _Prev_{ _position._ptr->_prev }; // node before _position

		// 	for (; _First != _Last; ++_First) {
		// 		_Insert(_position._ptr, *_First);
		// 		++_Size;
		// 	}
		// 	return _Make_Iter(_Prev_->_next);
		// }


		constexpr iterator erase(const_iterator _position) noexcept
		{
			if (empty() || _position == nullptr) return _position;
			return _Make_Iter(_Erase(_position._ptr));
		}
		constexpr iterator erase(const_iterator _First, const_iterator _Last) noexcept
		{
			if (empty() || _First == nullptr) return _First;
			return _Make_Iter(_Erase_Range(_First._ptr, _Last._ptr));
		}


		template<typename... Args>
		constexpr reference emplace_front(Args&&... args) noexcept
		{
			_Emplace_Front(std::forward<Args>(args)...);
			return front();
		}

		constexpr void push_front(const_reference _val) noexcept
		{
			_Emplace_Front(_val);
		}
		constexpr void push_front(rvalue_reference _val) noexcept
		{
			_Emplace_Front(std::move(_val));
		}

		constexpr void pop_front() noexcept
		{
			if (empty()) { // do nothing
				return;
			}
			Node_Ptr _Target = _Head->_next;
			_Head->_Connect_Front(_Target->_next);
			_Target->_next->_Connect_Back(_Head);
			_Freenode(_Target);
			--_Size;
		}


		template<typename... Args>
		constexpr reference emplace_back(Args&&... args) noexcept
		{
			_Emplace_Back(std::forward<Args>(args)...);
			return back();
		}

		constexpr void push_back(const_reference _val) noexcept
		{
			_Emplace_Back(_val);
		}
		constexpr void push_back(rvalue_reference _val) noexcept
		{
			_Emplace_Back(std::move(_val));
		}

		constexpr void pop_back() noexcept
		{
			if (empty()) { // do nothing
				return;
			}
			Node_Ptr _Target = _Head->_prev;
			_Head->_Connect_Back(_Target->_prev);
			_Target->_prev->_Connect_Front(_Head);
			_Freenode(_Target);
			--_Size;
		}


		constexpr void resize(size_type _Count, const_reference _val) noexcept
		{
			if (_Count && empty()) {
				_Construct_n(_Count, _val);
				_Size = _Count;
				return;
			}
			if (_Count == 0) { // erase all if (_Count = 0)
				clear();
				return;
			}
			if (_Count == _Size) { // do nothing
				return;
			}
			_Resize(_Count, _val);
		}
		constexpr void resize(size_type _Count) noexcept
		{
			resize(_Count, _Ty{});
		}


		constexpr void swap(list& _Other) noexcept
		{
			if (this == &_Other) return;
			list _temp{ std::move(*this) };
			_Steal_Data(_Other);
			_Other._Steal_Data(_temp);
		}


		constexpr void splice(const_iterator _pos, list& _Other) noexcept
		{
			if (this == &_Other || !_pos._ptr || _Other.empty()) { // do nothing
				return;
			}
			_Splice(_pos._ptr, _Other);
		}
		constexpr void splice(const_iterator _pos, list&& _Other) noexcept
		{
			splice(_pos, _Other);
		}
		constexpr void splice(const_iterator _pos, list& _Other, const_iterator _elem) noexcept
		{
			// move the next node after (_elem) to *this
			if (!_pos._ptr || !_elem._ptr || _Other.empty()) { // do nothing
				return;
			}
			_Splice(_pos._ptr, _Other, _elem._ptr);
		}
		constexpr void splice(const_iterator _pos, list&& _Other, const_iterator _elem) noexcept
		{
			splice(_pos, _Other, _elem);
		}
		constexpr void splice(const_iterator _pos, list& _Other, const_iterator _First, const_iterator _Last) noexcept
		{
			// move range(_First, _Last) to *this
			if (!_pos._ptr || !_First._ptr || !_Last._ptr || _Other.empty()) { // do nothing
				return;
			}
			_Splice(_pos._ptr, _Other, _First._ptr, _Last._ptr);
		}
		constexpr void splice(const_iterator _pos, list&& _Other, const_iterator _First, const_iterator _Last) noexcept
		{
			splice(_pos, _Other, _First, _Last);
		}


		template<typename Condition>
		constexpr size_type remove_if(Condition _Cond) noexcept
		{
			if (empty()) return 0;

			size_type _Removed(0);

			for (Node_Ptr _Pnode{ _Head->_next }; _Pnode != _Head;) {
				if (_Cond(_Pnode->_data)) {
					_Pnode = _Remove(_Pnode);
					++_Removed;
				}
				else {
					_Pnode = _Pnode->_next;
				}
			}
			_Size -= _Removed;
			return _Removed;
		}

		constexpr size_type remove(const_reference _val) noexcept
		{
			return remove_if([&](const _Ty& _elem) { return _elem == _val; });
		}


		constexpr void reverse() noexcept
		{
			if (empty()) return;

			Node_Ptr _Current{ _Head };

			while (true) {
				_Current->_Connect(_Current->_next, _Current->_prev);
				if (_Current->_prev == _Head) return;
				_Current = _Current->_prev;
			}
		}


		template<typename Condition>
		constexpr size_type unique(Condition _Cond) noexcept
		{
			if (empty()) return 0;

			size_type _Removed(0);

			for (Node_Ptr _Pnode{ _Head->_next }; _Pnode != _Head; ) {
				if (_Cond(_Pnode->_data, _Pnode->_next->_data)) {
					_Pnode = _Remove(_Pnode);
					++_Removed;
				}
				else {
					_Pnode = _Pnode->_next;
				}
			}
			_Size -= _Removed;
			return _Removed;
		}
		constexpr size_type unique() noexcept
		{
			// Removes all consecutive duplicate elements from the container.
			// Only the first element in each group of equal elements is left.
			// 1, 1, 1, 2, 1, 3, 3, 5, 8, 6, 6, 7, 9 (before unique)
			// 1, 2, 1, 3, 5, 8, 6, 7, 9 (after unique)
			return unique([&](const _Ty& _Curr, const _Ty& _After) { return _Curr == _After; });
		}


		template<typename Condition>
		constexpr void merge(list& _Other, Condition _Cond) noexcept
		{
			_Merge(_Other, _Cond);
		}
		template<typename Condition>
		constexpr void merge(list&& _Other, Condition _Cond) noexcept
		{
			_Merge(_Other, _Cond);
		}

		constexpr void merge(list& _Other) noexcept
		{
			_Merge(_Other, [&](const _Ty& lhs, const _Ty& rhs) { return lhs < rhs; });
		}
		constexpr void merge(list&& _Other) noexcept
		{
			_Merge(_Other, [&](const _Ty& lhs, const _Ty& rhs) { return lhs < rhs; });
		}


		template<typename Condition>
		constexpr void sort(Condition _Cond) noexcept
		{
			//_Selection_Sort(_Cond); // O(n^2)
			_Merge_Sort(_Cond); // O(n log n)
		}

		constexpr void sort() noexcept
		{
			// ascending by default
			//_Selection_Sort([&](const _Ty& E1, const _Ty& E2) { return E1 < E2; }); // O(n^2)
			_Merge_Sort([&](const _Ty& E1, const _Ty& E2) { return E1 < E2; }); // O(n log n)
		}

		// iterators
		//--------------------------------------------------------------------------------------------------
		constexpr iterator begin() noexcept
		{
			return iterator(_Head->_next);
		}
		constexpr const_iterator begin() const noexcept
		{
			return const_iterator(_Head->_next);
		}
		constexpr const_iterator cbegin() const noexcept
		{
			return begin();
		}

		constexpr iterator end() noexcept
		{
			return iterator(_Head);
		}
		constexpr const_iterator end() const noexcept
		{
			return const_iterator(_Head);
		}
		constexpr const_iterator cend() const noexcept
		{
			return end();
		}



		constexpr reverse_iterator rbegin() noexcept
		{
			return reverse_iterator(_Head->_prev);
		}
		constexpr const_reverse_iterator rbegin() const noexcept
		{
			return const_reverse_iterator(_Head->_prev);
		}
		constexpr const_reverse_iterator crbegin() const noexcept
		{
			return rbegin();
		}

		constexpr reverse_iterator rend() noexcept
		{
			return reverse_iterator(_Head);
		}
		constexpr const_reverse_iterator rend() const noexcept
		{
			return const_iterator(_Head);
		}
		constexpr const_reverse_iterator crend() const noexcept
		{
			return rend();
		}
		//--------------------------------------------------------------------------------------------------

		constexpr bool operator==(const list<_Ty>& _Other) const noexcept
		{
			if (_Size != _Other._Size) return false;

			for (Node_Ptr LHS{ _Head->_next }, RHS{ _Other._Head->_next }; (LHS != _Head); LHS = LHS->_next, RHS = RHS->_next) {
				if (LHS->_data != RHS->_data) {
					return false;
				}
			}
			return true;
		}

		constexpr bool operator<(const list<_Ty>& _Other) const noexcept
		{
			if (_Size < _Other._Size) return true;
			else if (_Size > _Other._Size) return false;

			size_type _this_points(0), _Other_points(0);
			for (Node_Ptr LHS{ _Head->_next }, RHS{ _Other._Head->_next }; (LHS != _Head); LHS = LHS->_next, RHS = RHS->_next) {
				if (LHS->_data < RHS->_data) ++_Other_points;
				else if (LHS->_data > RHS->_data) ++_this_points;
			}
			return _this_points < _Other_points;
		}

		constexpr bool operator!=(const list<_Ty>& _Other) const noexcept
		{
			return !(*this == _Other);
		}

		constexpr bool operator>(const list<_Ty>& _Other) const noexcept
		{
			return _Other < *this;
		}

		constexpr bool operator<=(const list<_Ty>& _Other) const noexcept
		{
			return !(*this > _Other);
		}

		constexpr bool operator>=(const list<_Ty>& _Other) const noexcept
		{
			return !(*this < _Other);
		}

	};



}
