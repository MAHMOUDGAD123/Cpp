#pragma once
#include <initializer_list>


//**********************************************************************************
// look here:
// https://codereview.stackexchange.com/questions/255725/forward-list-implementation
//**********************************************************************************





namespace MG {

	template<typename _Flist>
	class Flist_iterator
	{
	public:
		using Node_Ptr = typename _Flist::Node_Ptr;
		using value_type = typename _Flist::value_type;
		using pointer = value_type*;
		using reference = value_type&;
		using size_type = size_t;

		Node_Ptr _ptr; // pointer to node

	public:
		constexpr Flist_iterator() noexcept
			: _ptr(nullptr)
		{}
		constexpr Flist_iterator(Node_Ptr Nodeptr) noexcept
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

		constexpr Flist_iterator& operator++() noexcept
		{
			_ptr = _ptr->_next;
			return *this;
		}

		constexpr Flist_iterator operator++(int) noexcept
		{
			Flist_iterator _temp = *this;
			_ptr = _ptr->_next;
			return _temp;
		}

		constexpr bool operator ==(const Flist_iterator& other) const noexcept
		{
			return _ptr == other._ptr;
		}

		constexpr bool operator !=(const Flist_iterator& other) const noexcept
		{
			return _ptr != other._ptr;
		}

	};




	template<typename _Type>
	struct sNode
	{
		using Node_Ptr = sNode<_Type>*;

		_Type _data;
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

		constexpr void _Connect_with(Node_Ptr other) noexcept
		{
			_next = other;
		}

		constexpr void _Destruct() noexcept
		{
			_data.~_Type();
			_next = nullptr; // we can just make it null
			//_next->~sNode(); // error
		}

		constexpr void _Swap(Node_Ptr& other) noexcept
		{
			// only swap the _data
			_Type _temp = std::move(_data);
			_data = std::move(other->_data);
			other->_data = std::move(_temp);
		}

	};



	template<typename _Ty>
	class forward_list // singly linked list
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

		using iterator = Flist_iterator<forward_list<_Ty>>;
		using const_iterator = const iterator;

	private:
		Node_Ptr _Head; // points to the first node
		Node_Ptr _Tail; // points to the last node
		size_type _Size;

		// node allocation size
		static constexpr const size_type _Node_Size = static_cast<size_type>(sizeof(_Node));

	private:
		constexpr void _init()
		{
			_Tail = _Head = nullptr;
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
		constexpr void _Append_n(size_type _Count, const Args&... args)
		{
			Node_Ptr _Newnode = _Alloc_Construct(args...);
			_Head = _Newnode;
			--_Count;

			for (; _Count > 0; --_Count) {
				_Newnode->_Connect_with(_Alloc_Construct(args...));
				_Newnode = _Newnode->_next;
			}
			_Tail = _Newnode;
			_Tail->_Connect_with(nullptr);
			(void)_Release(_Newnode); // (void) ignore the return value
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
		constexpr void _Append_Range(_iterator _First, _iterator _Last)
		{
			Node_Ptr _Newnode = _Alloc_Construct(*_First);
			_Head = _Newnode;
			++_First;

			for (; _First != _Last; ++_First) {
				_Newnode->_Connect_with(_Alloc_Construct(*_First));
				_Newnode = _Newnode->_next;
			}
			_Tail = _Newnode;
			_Tail->_Connect_with(nullptr);
			(void)_Release(_Newnode);
		}

		constexpr void _Steal_Data(forward_list& _list)
		{
			// take data
			_Head = _Release(_list._Head);
			_Tail = _Release(_list._Tail);
			_Size = _list._Size;
			_list._Size = 0;
		}

		template<typename... Args>
		constexpr void _Insert_After(Node_Ptr TNode, Args&&... args)
		{
			Node_Ptr _Newnode = _Alloc_Construct(std::forward<Args>(args)...);
			_Newnode->_Connect_with(TNode->_next);
			if (_Newnode->_next == nullptr) {
				_Tail = _Newnode;
			}
			TNode->_next = _Release(_Newnode);
		}

		constexpr void _Erase_After(Node_Ptr TNode) noexcept
		{
			if (TNode) {
				Node_Ptr _Target = TNode->_next;
				if (_Target) {
					TNode->_Connect_with(_Target->_next);
					_Freenode(_Target);
					if (TNode->_next == nullptr) {
						_Tail = TNode;
					}
				}
			}
		}

		constexpr iterator _Make_Iter(Node_Ptr _Where) const noexcept
		{
			return iterator(_Where);
		}

		constexpr void _Shrink_To(size_type Newsize) noexcept
		{
			iterator it = begin();
			// loop to get the iterator for the start point
			for (size_type i(1); i < Newsize; ++i) it++;
			// erase from (it) to end
			while (it._ptr->_next != nullptr) {
				_Erase_After(it._ptr);
				--_Size;
			}
		}

		template<typename... Args>
		constexpr void _Attach_End(const Args&... args) noexcept
		{
			Node_Ptr Newnode = _Alloc_Construct(args...);
			_Tail->_Connect_with(Newnode);
			_Tail = _Release(Newnode);
			_Tail->_Connect_with(nullptr);
			++_Size;
		}

		template<typename... Args>
		constexpr void _Attach_n(size_type _Count, const Args&... args) noexcept
		{
			// loop to attach (args) to the end
			for (; _Count > 0; --_Count) {
				_Attach_End(args...);
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

		constexpr void _Splice_After(Node_Ptr TNode, forward_list& other) noexcept
		{
			// (1) connect (Other._Tail) with (TNode._next)
			// (2) connect (TNode) with (other._Head)
			other._Tail->_Connect_with(TNode->_next); // (1)
			TNode->_Connect_with(other._Head); // (2)
			_Size += other._Size;
			other._init(); // make other empty!
		}
		constexpr void _Splice_After(Node_Ptr TNode, forward_list& other, Node_Ptr _Prev) noexcept
		{
			if (TNode != _Prev) {
				Node_Ptr _Target = _Prev->_next;
				if (TNode != _Target) {
					_Prev->_Connect_with(_Target->_next); // remove the _Target from other
					_Target->_Connect_with(TNode->_next);
					TNode->_Connect_with(_Target);
					++_Size;
					--other._Size;
				}
			}
		}
		constexpr void _Splice_After(Node_Ptr TNode, forward_list& other, const_iterator _First, const_iterator _Last) noexcept
		{
			// do nothing
			//--------------------------------------
			if (_First == _Last) return;
			iterator _After = _First;
			++_After;
			if (_Last == _After) return;
			//--------------------------------------

			// loop to get the prev element of _Last
			//--------------------------------------
			Node_Ptr _Prev_Last(nullptr);
			size_type _Count(0); // to count the moved elements
			do {
				_Prev_Last = _After._ptr;
				++_After;
				++_Count;

			} while (_After != _Last);
			//--------------------------------------

			// move
			_Prev_Last->_Connect_with(TNode->_next);
			TNode->_Connect_with(_First._ptr->_next);
			_First._ptr->_next = _Last._ptr; // remove the range from other
			if (!_Last._ptr) {
				other._Tail = _First._ptr;
			}
			_Size += _Count;
			other._Size -= _Count;
		}

		// not used { used as a temp in special cases }
		//-----------------------------------------------------
		constexpr iterator _before_begin() noexcept
		{
			Node_Ptr _temp = _Alloc_Construct(_Ty{});
			_temp->_Connect_with(_Head);
			return iterator(_temp);
		}
		constexpr const_iterator _before_begin() const noexcept
		{
			Node_Ptr _temp = _Alloc_Construct(_Ty{});
			_temp->_Connect_with(_Head);
			return const_iterator(_temp);
		}
		constexpr const_iterator _cbefore_begin() const noexcept
		{
			Node_Ptr _temp = _Alloc_Construct(_Ty{});
			_temp->_Connect_with(_Head);
			return const_iterator(_temp);
		}
		//-----------------------------------------------------

		constexpr iterator _Remove(Node_Ptr& _Prev) noexcept
		{
			Node_Ptr _Target(_Prev->_next); // will be removed
			Node_Ptr _Next(_Target->_next);
			if (_Target == _Head) {
				_Head = _Next;
			}
			if (_Target == _Tail) {
				_Tail = (_Head) ? _Prev : _Head;
			}
			_Freenode(_Target);
			_Prev->_Connect_with(_Next);
			return _Make_Iter(_Next);
		}

		constexpr Node_Ptr _Mid_Point(Node_Ptr& _First)
		{
			// get the mid point of a list
			Node_Ptr _slow = _First;
			Node_Ptr _fast = _First->_next;

			while (_fast && _fast->_next) {
				_slow = _slow->_next; // advance by 1
				_fast = _fast->_next->_next; // advance by 2
			}
			return _slow; // which hold the mid point
		}

		constexpr Node_Ptr _Get_Last_Node()
		{
			Node_Ptr _Last{ _Head };
			while (_Last->_next) {
				_Last = _Last->_next;
			}
			return _Last;
		}

		template<typename Condition>
		constexpr void _Merge(forward_list& _Other, Condition _Cond) noexcept
		{
			if (this == &_Other || _Other.empty()) { // can't merge a list to itself || merge an empty list
				return;
			}
			if (empty()) { // if *this is empty
				_Steal_Data(_Other);
				return;
			}

			Node_Ptr _this_{ _Head };
			Node_Ptr _other_{ _Other._Head };
			Node_Ptr _Merged_{ nullptr }; // will hold the new data after merge

			// initialize the _Merged_ node
			if (_Cond(_this_->_data, _other_->_data)) {
				_Merged_ = _this_;
				_this_ = _this_->_next;
			}
			else {
				_Merged_ = _other_;
				_other_ = _other_->_next;
			}

			Node_Ptr _Next_{ _Merged_ }; // a used node to construct the new _Merged_ node

			while (true) {
				if (!_this_) { // when _this_ reach the end
					_Next_->_Connect_with(_other_);
					_Tail = _Other._Tail; // take the _Tail of the _Other
					break;
				}
				if (!_other_) { // when _other_ reach the end
					_Next_->_Connect_with(_this_);
					break;
				}

				if (_Cond(_this_->_data, _other_->_data)) {
					_Next_->_Connect_with(_this_);
					_this_ = _this_->_next;
				}
				else {
					_Next_->_Connect_with(_other_);
					_other_ = _other_->_next;
				}
				_Next_ = _Next_->_next; // advance _Next_ by 1
			}
			_Head = _Merged_, _Size += _Other._Size;
			_Other._init(); // make sure that _Other is empty
		}

		template<typename Condition>
		constexpr Node_Ptr _Merge(Node_Ptr L1, Node_Ptr L2, Condition _Cond) noexcept
		{
			if (!L1 && !L2) return nullptr;
			if (!L1) return L2;
			if (!L2) return L1;

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
				if (!L1) { // when _this_ reach the end
					_Next_->_Connect_with(L2);
					break;
				}
				if (!L2) { // when _other_ reach the end
					_Next_->_Connect_with(L1);
					break;
				}

				if (_Cond(L1->_data, L2->_data)) {
					_Next_->_Connect_with(L1);
					L1 = L1->_next;
				}
				else {
					_Next_->_Connect_with(L2);
					L2 = L2->_next;
				}
				_Next_ = _Next_->_next; // advance _Next_ by 1
			}
			return _Merged_;
		}

		template<typename Condition>
		constexpr Node_Ptr _Sort(Node_Ptr _First, Condition _Cond) noexcept
		{
			if (!_First || !_First->_next) return _First;

			Node_Ptr _Mid = _Mid_Point(_First);
			Node_Ptr _L1 = _First;
			Node_Ptr _L2 = _Mid->_next;
			_Mid->_Connect_with(nullptr); // to separate _L1 and _L2

			_L1 = _Sort(_L1, _Cond);
			_L2 = _Sort(_L2, _Cond);

			return _Merge(_L1, _L2, _Cond);
		}

		template<typename Condition>
		constexpr void _Merge_Sort(Condition _Cond) noexcept
		{
			_Head = _Sort(_Head, _Cond);
			_Tail = _Get_Last_Node(); // bad idea :-(
		}


		template<typename Condition>
		constexpr void _Selection_Sort(Condition _Cond) noexcept
		{
			if (empty() || !_Head->_next) return;

			for (Node_Ptr _Curr{ _Head }; _Curr; _Curr = _Curr->_next) // n
				for (Node_Ptr _Next{ _Curr->_next }; _Next; _Next = _Next->_next) // n
					if (_Cond(_Next->_data, _Curr->_data)) _Curr->_Swap(_Next);
		}

	public:
		constexpr forward_list() noexcept
			: _Head(nullptr), _Tail(nullptr), _Size(0)
		{}

		constexpr explicit forward_list(size_type _Count, const_reference _val) noexcept
		{
			if (_Count) {
				_Append_n(_Count, _val);
				_Size = _Count;
			}
			else {
				_init();
			}
		}

		constexpr explicit forward_list(size_type _Count) noexcept
			: forward_list(_Count, _Ty{})
		{}

		// only enable if the typename (_iter) is iterator
		// template <typename _iterator, std::enable_if_t<std::_Is_iterator_v<_iterator>, int> = 0>
		template <typename _iterator>
		constexpr forward_list(_iterator _First, _iterator _Last) noexcept
		{
			size_type size(_Get_Range_Len(_First, _Last));
			if (size) {
				_Append_Range(_First, _Last);
				_Size = size;
			}
			else {
				_init();
			}
		}

		constexpr forward_list(const forward_list& other) noexcept
			: forward_list(other.begin(), other.end())
		{}

		constexpr forward_list(forward_list&& other) noexcept
		{
			_Steal_Data(std::move(other));
		}

		constexpr forward_list(std::initializer_list<_Ty> _il) noexcept
			: forward_list(_il.begin(), _il.end())
		{}

		constexpr forward_list& operator=(const forward_list& other) noexcept
		{
			if (this == &other) {
				return *this;
			}
			if (!other.empty()) {
				clear();
				forward_list _temp(other.begin(), other.end());
				_Steal_Data(_temp);
			}
			else {
				clear();
			}
			return *this;
		}

		constexpr forward_list& operator=(forward_list&& other) noexcept
		{
			if (this == &other) {
				return *this;
			}
			if (!other.empty()) {
				clear();
				_Steal_Data(std::move(other));
			}
			else {
				clear();
			}
			return *this;
		}

		constexpr forward_list& operator=(std::initializer_list<_Ty> _il) noexcept
		{
			if (_il.size()) {
				clear();
				forward_list _temp(_il.begin(), _il.end());
				_Steal_Data(_temp);
			}
			else {
				clear();
			}
			return *this;
		}

		~forward_list()
		{
			clear();
		}

		constexpr bool empty() const noexcept
		{
			return _Head == nullptr;
			//return !_Size;
		}

		constexpr void clear() noexcept
		{
			if (!empty()) { // erase all
				Node_Ptr _Pnext = nullptr;
				Node_Ptr _Pnode = _Release(_Head); // _Head =  nullptr

				for (; _Pnode; _Pnode = _Pnext) {
					_Pnext = _Pnode->_next;
					_Freenode(_Pnode);
				}
				_Tail = nullptr;
				_Size = 0;
			}
		}

		constexpr reference front() noexcept
		{
			return _Head->_data;
			//return *begin();
		}
		constexpr const_reference front() const noexcept
		{
			return _Head->_data;
			//return *begin();
		}

		constexpr void assign(size_type _Count, const_reference _val)
		{
			clear();
			if (_Count) {
				_Append_n(_Count, _val);
				_Size = _Count;
			}
		}
		constexpr void assign(std::initializer_list<_Ty> _il)
		{
			clear();
			size_type size(_il.size());
			if (size) {
				_Append_Range(_il.begin(), _il.end());
				_Size = size;
			}
		}

		// template<typename _iter, std::enable_if_t<std::_Is_iterator_v<_iter>, int> = 0>
		// constexpr void assign(_iter _First, _iter _Last)
		// {
		// 	clear();
		// 	size_type size(_Get_Range_Len(_First, _Last));
		// 	if (size) {
		// 		_Append_Range(_First, _Last);
		// 		_Size = size;
		// 	}
		// }

		template<typename... Args>
		constexpr iterator emplace_after(const_iterator _position, Args&&... args)
		{
			if (empty() || _position == nullptr) return nullptr;
			_Insert_After(_position._ptr, std::forward<Args>(args)...);
			++_Size;
			return _Make_Iter(_position._ptr->_next);
		}

		constexpr iterator insert_after(const_iterator _position, const_reference _val)
		{
			emplace_after(_position, _val);
		}
		constexpr iterator insert_after(const_iterator _position, rvalue_reference _val)
		{
			emplace_after(_position, std::move(_val));
		}
		constexpr iterator insert_after(const_iterator _position, size_type _Count, const_reference _val)
		{
			if (empty() || _position == nullptr) return nullptr;
			iterator it = _position;
			for (; _Count; --_Count) {
				_Insert_After(it._ptr, _val);
				it++;
			}
			_Size += _Count;
			return _Make_Iter(it._ptr);
		}
		constexpr iterator insert_after(const_iterator _position, std::initializer_list<_Ty> _il)
		{
			return insert_after(_position, _il.begin(), _il.end());
		}

		// template<typename _iter, std::enable_if_t<std::_Is_iterator_v<_iter>, int> = 0>
		// constexpr iterator insert_after(const_iterator _position, _iter _First, _iter _Last)
		// {
		// 	if (empty() || _position == nullptr) return nullptr;
		// 	iterator it = _position;
		// 	for (; _First != _Last; ++_First) {
		// 		_Insert_After(it._ptr, *_First);
		// 		it++;
		// 		++_Size;
		// 	}
		// 	return _Make_Iter(it._ptr);
		// }

		constexpr iterator erase_after(const_iterator _position) noexcept
		{
			if (empty() || _position == nullptr) return nullptr;
			_Erase_After(_position._ptr);
			--_Size;
			return _Make_Iter(_position._ptr->_next);
		}
		constexpr iterator erase_after(const_iterator _First, const_iterator _Last) noexcept
		{
			/*if (_First != _Last) {
				Node_Ptr _Before = _First._ptr;
				Node_Ptr _Target = nullptr;
				while (true) {
					_Target = _Before->_next;
					if (_Target == _Last._ptr) {
						break;
					}
					_Before->_Connect_with(_Target->_next);
					_Freenode(_Target);
				}
			}*/
			if (empty() || _First == nullptr) return nullptr;
			if (_First != _Last) {
				while (_First._ptr->_next != _Last._ptr) {
					_Erase_After(_First._ptr);
					--_Size;
				}
			}
			return _Make_Iter(_Last._ptr);
		}

		template<typename... Args>
		constexpr reference emplace_front(Args&&... args) noexcept
		{
			Node_Ptr _Newnode = _Alloc_Construct(std::forward<Args>(args)...);
			_Newnode->_Connect_with(_Head);
			if (empty()) {
				_Head = _Tail = _Newnode;
			}
			else {
				_Head = _Release(_Newnode);
			}
			++_Size;
			return front();
		}

		constexpr void push_front(const_reference _val) noexcept
		{
			emplace_front(_val);
		}
		constexpr void push_front(rvalue_reference _val) noexcept
		{
			emplace_front(std::move(_val));
		}

		constexpr void pop_front() noexcept
		{
			if (empty()) return;
			Node_Ptr _Target = _Head;
			if (_Head->_next == nullptr) {
				_Tail = nullptr; // to avoid error
			}
			_Head = _Head->_next;
			_Freenode(_Target);
			--_Size;
		}

		constexpr void resize(size_type _Count, const_reference _val) noexcept
		{
			if (_Count && empty()) {
				_Append_n(_Count, _val);
				_Size = _Count;
				return;
			}
			if (!_Count) { // clear if (_Count = 0)
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

		constexpr void swap(forward_list& other) noexcept
		{
			if (this == &other) return;
			forward_list _temp;
			_temp._Steal_Data(*this);
			_Steal_Data(other);
			other._Steal_Data(_temp);
		}

		constexpr void splice_after(const_iterator _pos, forward_list& other) noexcept
		{
			if (this == &other || !_pos._ptr || other.empty()) { // do nothing
				return;
			}
			_Splice_After(_pos._ptr, other);
		}
		constexpr void splice_after(const_iterator _pos, forward_list&& other) noexcept
		{
			splice_after(_pos, other);
		}
		constexpr void splice_after(const_iterator _pos, forward_list& other, const_iterator it) noexcept
		{
			// move the next node after (it) to *this
			if (this == &other || !_pos._ptr || other.empty()) { // do nothing
				return;
			}
			_Splice_After(_pos._ptr, other, it._ptr);
		}
		constexpr void splice_after(const_iterator _pos, forward_list&& other, const_iterator _elem) noexcept
		{
			splice_after(_pos, other, _elem);
		}
		constexpr void splice_after(const_iterator _pos, forward_list& other, const_iterator _First, const_iterator _Last) noexcept
		{
			// move range(_First, _Last) to *this
			if (this == &other || !_pos._ptr || other.empty()) { // do nothing
				return;
			}
			_Splice_After(_pos._ptr, other, _First, _Last);
		}
		constexpr void splice_after(const_iterator _pos, forward_list&& other, const_iterator _First, const_iterator _Last) noexcept
		{
			splice_after(_pos, other, _First, _Last);
		}


		template<typename Condition>
		constexpr size_type remove_if(Condition _Cond) noexcept
		{
			if (empty()) return 0;

			size_type _Removed(0);
			iterator _Before_Head{ _before_begin() };

			for (iterator _iter{ begin() }, _Prev{ _Before_Head }; _iter._ptr;) {
				if (_Cond(*_iter)) {
					_iter = _Remove(_Prev._ptr);
					++_Removed;
				}
				else {
					_Prev = _iter;
					++_iter;
				}
			}
			_Freenode(_Before_Head._ptr); // free the _Before_Head node
			_Size -= _Removed;
			return _Removed;
		}

		constexpr size_type remove(const_reference _val) noexcept
		{
			return remove_if([&](const _Ty& _elem) { return _elem == _val; });
		}

		constexpr void reverse() noexcept
		{
			if (empty() || !_Head->_next) return;

			Node_Ptr _Current(_Head);
			Node_Ptr _Prev{}, _Next{};

			while (true) {
				_Next = _Current->_next;
				_Current->_Connect_with(_Prev);
				if (!_Next) {
					_Tail = _Head;
					_Head = _Current;
					return;
				}
				_Prev = _Current;
				_Current = _Next;
			}
		}

		template<typename Condition>
		constexpr size_type unique(Condition _Cond) noexcept
		{
			if (empty() || !_Head->_next) return 0;

			size_type _Removed(0);
			iterator _Curr(begin());
			iterator _After = _Curr;
			++_After;
			while (_After._ptr) {
				if (_Cond(*_Curr, *_After)) {
					_After = _Remove(_Curr._ptr);
					++_Removed;
				}
				else {
					_Curr = _After;
					++_After;
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
		constexpr void merge(forward_list& _Other, Condition _Cond) noexcept
		{
			_Merge(_Other, _Cond);
		}
		template<typename Condition>
		constexpr void merge(forward_list&& _Other, Condition _Cond) noexcept
		{
			_Merge(_Other, _Cond);
		}

		constexpr void merge(forward_list& _Other) noexcept
		{
			_Merge(_Other, [&](const _Ty& lhs, const _Ty& rhs) { return lhs < rhs; });
		}
		constexpr void merge(forward_list&& _Other) noexcept
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
			return iterator(_Head);
		}
		constexpr const_iterator begin() const noexcept
		{
			return const_iterator(_Head);
		}
		constexpr const_iterator cbegin() const noexcept
		{
			return begin();
		}

		constexpr iterator end() noexcept
		{
			if (!_Tail) return nullptr;
			return iterator(_Tail->_next);
		}
		constexpr const_iterator end() const noexcept
		{
			if (!_Tail) return nullptr;
			return const_iterator(_Tail->_next);
		}
		constexpr const_iterator cend() const noexcept
		{
			return end();
		}
		//--------------------------------------------------------------------------------------------------

		constexpr bool operator==(const forward_list<_Ty>& _Other) const noexcept
		{
			if (_Size != _Other._Size) return false;

			for (Node_Ptr LHS{ _Head }, RHS{ _Other._Head }; LHS; LHS = LHS->_next, RHS = RHS->_next) {
				if (LHS->_data != RHS->_data) {
					return false;
				}
			}
			return true;
		}

		constexpr bool operator<(const forward_list<_Ty>& _Other) const noexcept
		{
			if (_Size < _Other._Size) return true;
			else if (_Size > _Other._Size) return false;
			
			size_type _this_points(0), _other_points(0);
			for (Node_Ptr LHS{ _Head }, RHS{ _Other._Head }; LHS; LHS = LHS->_next, RHS = RHS->_next) {
				if(LHS->_data < RHS->_data) ++_other_points;
				else if(LHS->_data > RHS->_data) ++_this_points;
			}
			return _this_points < _other_points;
		}

		constexpr bool operator!=(const forward_list<_Ty>& _Other) const noexcept
		{
			return !(*this == _Other);
		}

		constexpr bool operator>(const forward_list<_Ty>& _Other) const noexcept
		{
			return _Other < *this;
		}

		constexpr bool operator<=(const forward_list<_Ty>& _Other) const noexcept
		{
			return !(*this > _Other);
		}

		constexpr bool operator>=(const forward_list<_Ty>& _Other) const noexcept
		{
			return !(*this < _Other);
		}

	};



}
