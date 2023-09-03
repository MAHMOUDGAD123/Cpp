#pragma once
#include <initializer_list>



namespace MG {

	template<typename _doubly_list>
	class doubly_list_iterator
	{
	public:
		using Node_Ptr = typename _doubly_list::Node_Ptr;
		using value_type = typename _doubly_list::value_type;
		using pointer = value_type*;
		using reference = value_type&;


		Node_Ptr _Ptr; // pointer to node

		// constructors
		constexpr doubly_list_iterator() noexcept
			: _Ptr(nullptr)
		{}
		constexpr doubly_list_iterator(Node_Ptr Nodeptr) noexcept
			: _Ptr(Nodeptr)
		{}


		// operators overloading
		constexpr reference operator*() const noexcept
		{
			return _Ptr->_Data;
		}

		constexpr pointer operator->() const noexcept
		{
			return _Ptr;
		}

		constexpr doubly_list_iterator& operator++() noexcept
		{
			_Ptr = _Ptr->_Next;
			return *this;
		}

		constexpr doubly_list_iterator operator++(int) noexcept
		{
			doubly_list_iterator _temp = *this;
			_Ptr = _Ptr->_Next;
			return _temp;
		}

		constexpr doubly_list_iterator& operator--() noexcept
		{
			_Ptr = _Ptr->_Prev;
			return *this;
		}

		constexpr doubly_list_iterator operator--(int) noexcept
		{
			doubly_list_iterator _temp = *this;
			_Ptr = _Ptr->_Prev;
			return _temp;
		}

		constexpr bool operator ==(const doubly_list_iterator& _Other) const noexcept
		{
			return _Ptr == _Other._Ptr;
		}

		constexpr bool operator !=(const doubly_list_iterator& _Other) const noexcept
		{
			return _Ptr != _Other._Ptr;
		}

	};



	template<typename _doubly_list>
	class doubly_list_reverse_iterator
	{
	public:
		using Node_Ptr = typename _doubly_list::Node_Ptr;
		using value_type = typename _doubly_list::value_type;
		using pointer = value_type*;
		using reference = value_type&;

		Node_Ptr _Ptr; // pointer to node

		// constructors
		constexpr doubly_list_reverse_iterator() noexcept
			: _Ptr(nullptr)
		{}
		constexpr doubly_list_reverse_iterator(Node_Ptr Nodeptr) noexcept
			: _Ptr(Nodeptr)
		{}

		// operators overloading
		constexpr reference operator*() const noexcept
		{
			return _Ptr->_data;
		}

		constexpr pointer operator->() const noexcept
		{
			return _Ptr;
		}

		constexpr doubly_list_reverse_iterator& operator++() noexcept
		{
			_Ptr = _Ptr->_prev;
			return *this;
		}

		constexpr doubly_list_reverse_iterator operator++(int) noexcept
		{
			doubly_list_reverse_iterator _temp = *this;
			_Ptr = _Ptr->_prev;
			return _temp;
		}

		constexpr doubly_list_reverse_iterator& operator--() noexcept
		{
			_Ptr = _Ptr->_next;
			return *this;
		}

		constexpr doubly_list_reverse_iterator operator--(int) noexcept
		{
			doubly_list_reverse_iterator _temp = *this;
			_Ptr = _Ptr->_next;
			return _temp;
		}

		constexpr bool operator ==(const doubly_list_reverse_iterator& _Other) const noexcept
		{
			return _Ptr == _Other._Ptr;
		}

		constexpr bool operator !=(const doubly_list_reverse_iterator& _Other) const noexcept
		{
			return _Ptr != _Other._Ptr;
		}

	};



	template<typename _Type>
	struct stNode
	{
		using Node_Ptr = stNode<_Type>*;

		_Type _Data;
		Node_Ptr _Prev;
		Node_Ptr _Next;

		stNode() = default;
		stNode(const stNode&) = delete;
		stNode& operator=(const stNode&) = delete;
		~stNode() = default;

		template<typename... Args>
		constexpr void _Construct_in_place(Args&&... args) noexcept
		{
			new(&_Data) _Type(std::forward<Args>(args)...);
		}

		constexpr void _Connect_Front(Node_Ptr Next) noexcept
		{
			_Next = Next;
		}
		constexpr void _Connect_Back(Node_Ptr Previous) noexcept
		{
			_Prev = Previous;
		}
		constexpr void _Connect(Node_Ptr Previous, Node_Ptr Next) noexcept
		{
			_Prev = Previous;
			_Next = Next;
		}

		constexpr void _Destruct() noexcept
		{
			_Data.~_Type();
			_Next = nullptr;
			_Prev = nullptr;
		}

		constexpr void _Swap_Data(Node_Ptr& _Other) noexcept
		{
			// only swap the _Data
			_Type _temp = std::move(_Data);
			_Data = std::move(_Other->_Data);
			_Other->_Data = std::move(_temp);
		}

		constexpr void _Update_Data(_Type _New_value) noexcept
		{
			_Data = _New_value;
		}

	};



	template<typename _Ty>
	class doubly_list // doubly linked list
	{
	private:
		using _Node = stNode<_Ty>;

	public:
		using Node_Ptr = _Node*;
		using value_type = _Ty;
		using size_type = size_t;
		using pointer = _Ty*;
		using const_pointer = const _Ty*;
		using reference = _Ty&;
		using const_reference = const _Ty&;
		using rvalue_reference = _Ty&&;

		using iterator = doubly_list_iterator<doubly_list<_Ty>>;
		using const_iterator = const iterator;
		using reverse_iterator = doubly_list_reverse_iterator<doubly_list<_Ty>>;
		using const_reverse_iterator = const reverse_iterator;

	private:
		Node_Ptr _Head; // points to the first node
		Node_Ptr _Tail; // points to the last node
		size_type _Size; // total elements

		// node allocation size
		static constexpr const size_type _Node_Size = static_cast<size_type>(sizeof(_Node));


		constexpr void _Init() noexcept
		{
			_Head = _Tail = nullptr;
			_Size = 0;
		}

		template<typename... Args>
		constexpr Node_Ptr _Allocate_Construct(Args&&... args) noexcept
		{
			// allocate a new memory of size { _Node_Size } and construct the _Data
			Node_Ptr _Newnode{ (Node_Ptr)::operator new(_Node_Size) };
			_Newnode->_Construct_in_place(std::forward<Args>(args)...);
			return _Newnode;
		}

		constexpr void _Deallocate(Node_Ptr& _Node)
		{
			// deallocate the _Node from memory
			::operator delete(_Node, _Node_Size);
			_Node = nullptr;
		}

		constexpr void _Freenode(Node_Ptr& _Node)
		{
			// destruct the _Data then deallocate the memory
			_Node->_Destruct();
			_Deallocate(_Node);
		}

		constexpr void _Steal_Data(doubly_list& _list)
		{
			// take data
			_Head = _list._Head;
			_Tail = _list._Tail;
			_Size = _list._Size;
			_list._Head = nullptr;
			_list._Tail = nullptr;
			_list._Size = 0;
		}

		template<typename _iterator>
		constexpr size_type _Construct_Range(_iterator _First, _iterator _Last)
		{
			// construct the list using iterators range{ _First -> _Last}
			// count the elements and return the total elements
			Node_Ptr _Newnode{ _Allocate_Construct(*_First) };
			_Head = _Newnode; // first node
			_Head->_Connect_Back(nullptr);
			++_First;
			size_type _Count{ 1 }; // Count the elements

			for (Node_Ptr _Prev{ nullptr }; _First != _Last; ++_First) {
				_Newnode->_Connect_Front(_Allocate_Construct(*_First));
				_Prev = _Newnode;
				_Newnode = _Newnode->_Next;
				_Newnode->_Connect_Back(_Prev);
				++_Count;
			}
			_Tail = _Newnode; // last node
			_Tail->_Connect_Front(nullptr);
			return _Count;
		}


		template<typename... Args>
		constexpr void _Emplace_Front(Args&&... args) noexcept
		{
			Node_Ptr _Newnode{ _Allocate_Construct(std::forward<Args>(args)...) };
			_Newnode->_Connect(nullptr, _Head);
			if (_Head) { // list is't empty
				_Head->_Connect_Back(_Newnode);
				_Head = _Newnode;
			}
			else { // list is empty
				_Head = _Tail = _Newnode;
			}
			++_Size;
		}

		template<typename... Args>
		constexpr void _Emplace_Back(Args&&... args) noexcept
		{
			Node_Ptr _Newnode{ _Allocate_Construct(std::forward<Args>(args)...) };
			_Newnode->_Connect(_Tail, nullptr);
			if (_Tail) { // list isn't empty
				_Tail->_Connect_Front(_Newnode);
				_Tail = _Newnode;
			}
			else { // list is empty
				_Head = _Tail = _Newnode;
			}
			++_Size;
		}


		template<typename... Args>
		constexpr iterator _Insert_AFter(Node_Ptr _Position, Args&&... args)
		{
			if (empty() || !_Position) {
				return { nullptr };
			}

			Node_Ptr _Newnode{ _Allocate_Construct(std::forward<Args>(args)...) };
			_Newnode->_Connect(_Position, _Position->_Next);

			if (_Position->_Next) { // _Position != _Tail
				_Position->_Next->_Connect_Back(_Newnode);
			}
			else { // _Position == _Tail
				_Tail = _Newnode;
			}
			_Position->_Connect_Front(_Newnode);
			++_Size;
			// return an iterator to the inserted node
			return { _Newnode };
		}


		constexpr Node_Ptr _Remove(Node_Ptr& _Target) noexcept
		{
			if (!_Target->_Prev && !_Target->_Next) { // _Target == _Head == _Tail
				_Freenode(_Target);
				_Head = _Tail = nullptr;
				return nullptr;
			}

			Node_Ptr _Next_{ _Target->_Next };

			if (_Target->_Prev && !_Next_) { // _Target == _Tail
				_Target->_Prev->_Connect_Front(_Next_);
				_Tail = _Target->_Prev;
			}
			else if (!_Target->_Prev && _Next_) { // _Target == _Head
				_Next_->_Connect_Back(_Target->_Prev);
				_Head = _Next_;
			}
			else { // _Target != _Head && _Target != _Tail
				_Target->_Prev->_Connect_Front(_Next_);
				_Next_->_Connect_Back(_Target->_Prev);
			}
			_Freenode(_Target);
			return _Next_;
		}


	public:
		constexpr doubly_list() noexcept
			: _Head(nullptr), _Tail(nullptr), _Size(0)
		{}

		// copy constructor
		constexpr doubly_list(const doubly_list& Other) noexcept
		{
			if (Other.empty()) {
				_Init();
			}
			else {
				_Size = _Construct_Range(Other.begin(), Other.end());
			}
		}

		// move constructor
		constexpr doubly_list(doubly_list&& Other) noexcept
		{
			_Steal_Data(Other);
		}

		constexpr doubly_list(std::initializer_list<_Ty> _il) noexcept
		{
			if (_il.size()) {
				_Size = _Construct_Range(_il.begin(), _il.end());
			}
			else {
				_Init();
			}
		}

		// copy assignment operator
		constexpr doubly_list& operator=(const doubly_list& Other) noexcept
		{
			if (this == &Other) {
				return *this;
			}
			if (Other.empty()) {
				clear();
			}
			else {
				clear();
				_Size = _Construct_Range(Other.begin(), Other.end());
			}
			return *this;
		}

		// move assignment operator
		constexpr doubly_list& operator=(doubly_list&& Other) noexcept
		{
			if (this == &Other) {
				return *this;
			}
			if (Other.empty()) {
				clear();
			}
			else {
				clear();
				_Steal_Data(Other);
			}
			return *this;
		}

		constexpr doubly_list& operator=(std::initializer_list<_Ty> _il) noexcept
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

		~doubly_list() { clear(); }

		constexpr void clear() noexcept
		{
			if (!empty()) { // erase all

				for (Node_Ptr Curr{ _Head }, Next{}; Curr; Curr = Next) {
					Next = Curr->_Next;
					_Freenode(Curr);
				}
				_Head = _Tail = nullptr;
				_Size = 0;
			}
		}

		constexpr bool empty() const noexcept { return _Size == 0; }

		constexpr size_type size() const noexcept { return _Size; }


		constexpr reference front() noexcept
		{
			return _Head->_Data;
			//return *begin();
		}
		constexpr const_reference front() const noexcept
		{
			return _Head->_Data;
			//return *begin();
		}

		constexpr reference back() noexcept
		{
			return _Tail->_Data;
			//return *rbegin();
		}
		constexpr const_reference back() const noexcept
		{
			return _Tail->_Data;
			//return *rbegin();
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
			Node_Ptr _Target = _Head;
			_Head = _Head->_Next;
			if (_Head) {
				_Head->_Connect_Back(nullptr);
			}
			else {
				_Tail = nullptr;
			}
			_Freenode(_Target);
			--_Size;
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
			Node_Ptr _Target = _Tail;
			_Tail = _Tail->_Prev;
			if (_Tail) {
				_Tail->_Connect_Front(nullptr);
			}
			else {
				_Head = nullptr;
			}
			_Freenode(_Target);
			--_Size;
		}



		constexpr void print() const noexcept
		{
			if (empty()) {
				std::cout << "Empty List :-(\n\n";
				return;
			}
			for (Node_Ptr _Curr{ _Head }; _Curr; _Curr = _Curr->_Next) {
				std::cout << _Curr->_Data << "  ";
			}
		}



		constexpr Node_Ptr find(const_reference _val) const noexcept
		{
			for (Node_Ptr _Target{ _Head }; _Target; _Target = _Target->_Next) {
				if (_Target->_Data == _val) {
					return _Target;
				}
			}
			return nullptr;
		}



		constexpr iterator insert_after(const_iterator _Position, const_reference _val)
		{
			return _Insert_AFter(_Position._Ptr, _val);
		}
		constexpr iterator insert_after(const_iterator _Position, rvalue_reference _val)
		{
			return _Insert_AFter(_Position._Ptr, std::move(_val));
		}

		constexpr iterator insert_after(Node_Ptr _Position, const_reference _val)
		{
			return _Insert_AFter(_Position, _val);
		}
		constexpr iterator insert_after(Node_Ptr _Position, rvalue_reference _val)
		{
			return _Insert_AFter(_Position, std::move(_val));
		}

		// insert _New_value after the node of _Index 
		constexpr bool insert_after(const_reference _New_value, size_type _Index) noexcept
		{
			Node_Ptr _Target_{ get_node(_Index) };
			if (_Target_) {
				_Insert_AFter(_Target_, _New_value);
				return true;
			}
			return false;
		}
		constexpr bool insert_after(rvalue_reference _New_value, size_type _Index) noexcept
		{
			Node_Ptr _Target_{ get_node(_Index) };
			if (_Target_) {
				_Insert_AFter(_Target_, std::move(_New_value));
				return true;
			}
			return false;
		}


		template<typename Condition>
		constexpr size_type remove_if(Condition _Cond) noexcept
		{
			// remove the nodes that satisfy the Condition (_Cond)
			if (empty()) { // do nothing
				return 0;
			}

			size_type _Removed{ 0 };

			for (Node_Ptr _Curr{ _Head }; _Curr;) {
				if (_Cond(_Curr->_Data)) {
					_Curr = _Remove(_Curr);
					++_Removed;
				}
				else {
					_Curr = _Curr->_Next;
				}
			}
			_Size -= _Removed;
			return _Removed;
		}

		constexpr size_type remove(const_reference _val) noexcept
		{
			// remove all node that have the value of (_val)
			return remove_if([&](const _Ty& _elem) { return _elem == _val; });
		}

		constexpr void remove(Node_Ptr _Target) noexcept
		{
			// remove the (_Target) node only
			if (_Target) {
				(void)_Remove(_Target);
				--_Size;
			}
		}


		constexpr void reverse() noexcept
		{
			if (_Size < 2) return; // if (_Size < 2) no need to reverse

			Node_Ptr _Current{ _Head };
			while (true) {
				_Current->_Connect(_Current->_Next, _Current->_Prev);
				if (!_Current->_Prev) {
					// swap _Head & _Tail
					_Tail = _Head;
					_Head = _Current;
					return;
				}
				_Current = _Current->_Prev;
			}
		}

		constexpr Node_Ptr get_node(size_type _Index) const noexcept
		{
			if (empty() || _Index > _Size - 1) return { nullptr };
			if (_Index == 0) return { _Head }; // first node
			if (_Index == _Size - 1) return { _Tail }; // last node --> O(1)

			Node_Ptr _Current{ _Head };
			for (; _Current; --_Index, _Current = _Current->_Next) {
				if (_Index == 0) return { _Current }; // found
			}
			return { nullptr }; // not used --> dummy compiler
		}

		constexpr value_type get_item(size_type _Index) const noexcept
		{
			// to fix the null problem we check if it's null or not first
			Node_Ptr _item_{ get_node(_Index) };
			if (_item_) return { _item_->_Data };
			return { }; // return an empty object
		}

		constexpr bool update_item(size_type _Index, const_reference _New_value) noexcept
		{
			Node_Ptr _item_{ get_node(_Index) };
			if (_item_) {
				_item_->_Data = _New_value;
				return true;
			}
			return false;
		}




		// iterators functions
		//--------------------------------------------------------------------------------------------------
		// used to iterate in a normal way
		constexpr iterator begin() noexcept
		{
			return iterator(_Head);
		}
		constexpr const_iterator begin() const noexcept
		{
			return const_iterator(_Head);
		}

		constexpr iterator end() noexcept
		{
			return iterator(nullptr);
		}
		constexpr const_iterator end() const noexcept
		{
			return const_iterator(nullptr);
		}

		// used to iterate in a reverse way
		constexpr reverse_iterator rbegin() noexcept
		{
			return reverse_iterator(_Tail);
		}
		constexpr const_reverse_iterator rbegin() const noexcept
		{
			return const_reverse_iterator(_Tail);
		}

		constexpr reverse_iterator rend() noexcept
		{
			return reverse_iterator(nullptr);
		}
		constexpr const_reverse_iterator rend() const noexcept
		{
			return const_reverse_iterator(nullptr);
		}
		//--------------------------------------------------------------------------------------------------


	};



}
