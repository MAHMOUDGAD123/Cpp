#pragma once

#include "Pair.h"

MG_BEGIN

//================================================ Iterators ==================================================
template <typename _Tree>
struct _tree_const_iterator
{
	using Node_Ptr = typename _Tree::Node_Ptr;
	using size_type = typename _Tree::size_type;
	using ptrdiff_type = typename _Tree::ptrdiff_type;
	using value_type = typename _Tree::value_type;
	using pointer = typename _Tree::const_pointer;
	using reference = typename _Tree::const_reference;

	using _Tree_Search = typename _Tree::_Tree_Search;

	constexpr _tree_const_iterator() noexcept
			: _Ptr(nullptr) {}

	constexpr _tree_const_iterator(Node_Ptr Ptr) noexcept
			: _Ptr(Ptr) {}

	constexpr reference operator*() noexcept
	{
		return _Ptr->_Data;
	}

	constexpr pointer operator->() noexcept
	{
		return _Ptr;
	}

	constexpr _tree_const_iterator &operator++() noexcept
	{
		if (_Ptr->_IsNil)
		{
			return *this;
		}

		if (_Ptr->_Right->_IsNil)
		{
			Node_Ptr _Temp(nullptr);
			while (!(_Temp = _Ptr->_Parent)->_IsNil && _Ptr == _Temp->_Right)
			{
				_Ptr = _Temp;
			}
			_Ptr = _Temp;
		}
		else
		{
			_Ptr = _Tree_Search::_Min(_Ptr->_Right); // min of right subtree
		}
		return *this;
	}
	constexpr _tree_const_iterator operator++(int) noexcept
	{
		_tree_const_iterator _temp = *this;
		++*this;
		return _temp;
	}

	constexpr _tree_const_iterator &operator--() noexcept
	{
		if (_Ptr->_IsNil)
		{
			return *this;
		}

		if (_Ptr->_Left->_IsNil)
		{
			Node_Ptr _Node(nullptr);
			while (!(_Node = _Ptr->_Parent)->_IsNil && _Ptr == _Node->_Left)
			{
				_Ptr = _Node;
			}
			_Ptr = _Node;
		}
		else
		{
			_Ptr = _Tree_Search::_Max(_Ptr->_Left); // max in left subtree
		}
		return *this;
	}
	constexpr _tree_const_iterator operator--(int) noexcept
	{
		_tree_const_iterator _temp = *this;
		--*this;
		return _temp;
	}

	constexpr bool operator==(const _tree_const_iterator &_Right) const noexcept
	{
		return _Ptr == _Right._Ptr;
	}
	constexpr bool operator!=(const _tree_const_iterator &_Right) const noexcept
	{
		return _Ptr != _Right._Ptr;
	}

	Node_Ptr _Ptr; // pointer
};

template <typename _Tree>
struct _tree_iterator final : public _tree_const_iterator<_Tree>
{
	using Node_Ptr = typename _Tree::Node_Ptr;
	using size_type = typename _Tree::size_type;
	using ptrdiff_type = typename _Tree::ptrdiff_type;
	using value_type = typename _Tree::value_type;
	using pointer = typename _Tree::pointer;
	using reference = typename _Tree::reference;

	using _Tree_Search = typename _Tree::_Tree_Search;

	using _Base = _tree_const_iterator<_Tree>;

	constexpr _tree_iterator() noexcept
			: _Base(nullptr)
	{
	}

	constexpr _tree_iterator(Node_Ptr Ptr) noexcept
			: _Base(Ptr)
	{
	}

	constexpr reference operator*() noexcept
	{
		return const_cast<reference>(_Base::operator*());
	}

	constexpr pointer operator->() noexcept
	{
		return const_cast<pointer>(_Base::operator->());
	}

	constexpr _tree_iterator &operator++() noexcept
	{
		_Base::operator++();
		return *this;
	}
	constexpr _tree_iterator operator++(int) noexcept
	{
		_tree_iterator _temp = *this;
		_Base::operator++();
		return _temp;
	}

	constexpr _tree_iterator &operator--() noexcept
	{
		_Base::operator--();
		return *this;
	}
	constexpr _tree_iterator operator--(int) noexcept
	{
		_tree_iterator _temp = *this;
		_Base::operator--();
		return _temp;
	}
};

//=============================================================================================================

template <typename Value_Type>
struct _Tree_Node
{
	using Node_Ptr = _Tree_Node<Value_Type> *;
	using size_type = unsigned long long;

	Value_Type _Data;
	Node_Ptr _Parent;
	Node_Ptr _Left;
	Node_Ptr _Right;
	bool _IsNil;

	_Tree_Node() = default;
	_Tree_Node(const _Tree_Node &) = delete;
	_Tree_Node &operator=(const _Tree_Node &) = delete;
	~_Tree_Node() = default;

	constexpr void _Connect(Node_Ptr Parent = nullptr, Node_Ptr Left = nullptr, Node_Ptr Right = nullptr) noexcept
	{
		_Parent = Parent, _Left = Left, _Right = Right;
	}
	constexpr void _Connect_Left(Node_Ptr Left) noexcept
	{
		_Left = Left;
	}
	constexpr void _Connect_Right(Node_Ptr Right) noexcept
	{
		_Right = Right;
	}
	constexpr void _Connect_Up(Node_Ptr Parent) noexcept
	{
		_Parent = Parent;
	}

	template <typename... _Args>
	constexpr void _Construct_In_Place(_Args &&...args) noexcept
	{
		::new (&_Data) Value_Type(std::forward<_Args>(args)...);
	}

	constexpr void _Destruct_In_Place() noexcept
	{
		_Data.~Value_Type();
	}

	static Node_Ptr _Release(Node_Ptr &_Node) noexcept
	{
		Node_Ptr _Temp(_Node);
		_Node = nullptr;
		return _Temp;
	}

	static void _Swap_Nodes(Node_Ptr &_Node1, Node_Ptr &_Node2) noexcept
	{
		Node_Ptr _Temp(_Release(_Node1));
		_Node1 = _Release(_Node2);
		_Node2 = _Release(_Temp);
	}
};

template <typename _Node_Ptr>
struct _Find_Bounds_Result
{
	enum class _Put_Location : const char
	{
		_None = '0',
		_Left = 'L',
		_Right = 'R'
	};

	_Node_Ptr _Node;
	_Put_Location _Put_Loc;

	constexpr _Find_Bounds_Result(_Node_Ptr Node, _Put_Location Put_Location)
			: _Node(Node), _Put_Loc(Put_Location) {}
};

template <typename _Tree>
struct _Tree_Search
{
	using Node_Ptr = typename _Tree::Node_Ptr;

	constexpr static Node_Ptr _Max(Node_Ptr _Node) noexcept
	{
		while (_Node->_Right->_IsNil)
		{
			_Node = _Node->_Right;
		}
		return _Node;
	}

	constexpr static Node_Ptr _Min(Node_Ptr _Node) noexcept
	{
		while (!_Node->_Left->_IsNil)
		{
			_Node = _Node->_Left;
		}
		return _Node;
	}
};

template <typename _Tree>
struct _Node_Details
{
	_Node_Details() = delete;
	_Node_Details(const _Node_Details &) = delete;
	_Node_Details &operator=(const _Node_Details &) = delete;

	using Node_Ptr = typename _Tree::Node_Ptr;

	_Node_Details(Node_Ptr _Node) noexcept
			: _Pos(_Left_Or_Right_Or_Head(_Node)), _Kids(_Kids_Info(_Node))
	{
	}

	_Node_Details(_Node_Details &&_Info) noexcept
			: _Pos(std::move(_Info._Pos)), _Kids(_Info._Kids)
	{
	}

	_Node_Details &operator=(_Node_Details &&_Info) noexcept
	{
		_Pos = std::move(_Info._Pos);
		_Kids = std::move(_Info._Kids);
		return *this;
	}

	// used to know if a specific node is a right or a left node of the head of the tree
	enum class _Position : const char
	{
		_Left_ = 'L',
		_Right_ = 'R',
		_Head_ = 'H'
	};

	// LCHO -> left child only
	// RCHO -> right chld only
	// LRCH -> left right child
	// NONE -> no kids
	enum class _Children : const char
	{
		_LCHO,
		_RCHO,
		_LRCH,
		_NONE
	};

	_Position _Pos;	 // left or right or head node
	_Children _Kids; // childern

	constexpr static bool _Is_HeadNode(Node_Ptr _Node) noexcept
	{
		return _Node->_Parent->_IsNil;
	}

	constexpr static bool _Is_LeafNode(Node_Ptr _Node) noexcept
	{
		return _Node->_Left->_IsNil && _Node->_Right->_IsNil;
	}

	constexpr static _Position _Left_Or_Right_Or_Head(Node_Ptr _Node) noexcept
	{
		return (_Is_HeadNode(_Node) ? _Position::_Head_ : (_Node->_Parent->_Left == _Node ? _Position::_Left_ : _Position::_Right_));
	}

	constexpr static _Position _Left_Or_Right(Node_Ptr _Node) noexcept
	{
		return _Node->_Parent->_Left == _Node ? _Position::_Left_ : _Position::_Right_;
	}

	constexpr static bool _Has_Left_Child(Node_Ptr _Node) noexcept
	{
		return !_Node->_Left->_IsNil;
	}
	constexpr static bool _Has_Right_Child(Node_Ptr _Node) noexcept
	{
		return !_Node->_Right->_IsNil;
	}

	constexpr static _Children _Kids_Info(Node_Ptr _Node) noexcept
	{
		return (_Is_LeafNode(_Node) ? _Children::_NONE : (_Node->_Left->_IsNil ? _Children::_RCHO : (_Node->_Right->_IsNil ? _Children::_LCHO : _Children::_LRCH)));
	}
};

template <typename _Traits>
class _Tree // ordered tree for single (map & set)
{
public:
	using key_type = typename _Traits::key_type;
	using data_type = typename _Traits::data_type;
	using value_type = typename _Traits::value_type;

	using Node = _Tree_Node<value_type>;
	using Node_Ptr = _Tree_Node<value_type> *;

	using size_type = unsigned long long;
	using ptrdiff_type = long long;

	using pointer = value_type *;
	using const_pointer = const value_type *;
	using reference = value_type &;
	using const_reference = const value_type &;
	using rvalue_reference = value_type &&;

	using _Find_Result = _Find_Bounds_Result<Node_Ptr>;
	using _Put_At = typename _Find_Result::_Put_Location;

	using less = std::less<key_type>;
	using equal = std::equal_to<key_type>;
	using greater = std::greater<key_type>;

	using _Tree_Search = _Tree_Search<_Tree>;

	using _Node_Info = _Node_Details<_Tree>;
	using _POS = typename _Node_Info::_Position;
	using _Kids = typename _Node_Info::_Children;

	using iterator = _tree_iterator<_Tree>;
	using const_iterator = _tree_const_iterator<_Tree>;

protected:
	static constexpr const size_type _Node_Size = static_cast<size_type>(sizeof(Node));

	Node_Ptr _Head; // the main root of the tree
	size_type _Size;
	Node_Ptr _Nil = _BuildNil();

private:
	constexpr void _Init() noexcept
	{
		_Head = _Nil, _Size = 0;
	}

	constexpr void _Steal_Data(_Tree &_Other) noexcept
	{
		Node::_Swap_Nodes(_Nil, _Other._Nil);
		Node::_Swap_Nodes(_Head, _Other._Head);
		MG::algorithm::swap(_Size, _Other._Size);
	}

	constexpr Node_Ptr _Alloc() const noexcept
	{
		return (Node_Ptr)::operator new(_Node_Size);
	}

	constexpr void _Dealloc(Node_Ptr &_Node) const noexcept
	{
		::operator delete(_Node, _Node_Size);
	}

	constexpr Node_Ptr _BuildNil() const noexcept
	{
		Node_Ptr _Nil = _Alloc();
		_Nil->_Construct_In_Place(value_type());
		_Nil->_Connect(_Nil, _Nil, _Nil);
		_Nil->_IsNil = true;
		return _Nil;
	}

	template <typename... Args>
	constexpr Node_Ptr _BuildHead(Args &&...args) const noexcept
	{
		Node_Ptr _Head_ = _Alloc();
		_Head_->_Construct_In_Place(std::forward<Args>(args)...);
		_Head_->_Connect(_Nil, _Nil, _Nil);
		_Head_->_IsNil = false;
		return _Head_;
	}

	template <typename... Args>
	constexpr Node_Ptr _BuyNode(Node_Ptr Parent, Args &&...args) const noexcept
	{
		Node_Ptr _Newnode = _Alloc();
		_Newnode->_Construct_In_Place(std::forward<Args>(args)...);
		_Newnode->_Connect(Parent, _Nil, _Nil);
		_Newnode->_IsNil = false;
		return _Newnode;
	}

	constexpr void _FreeNode(Node_Ptr &_Node) noexcept
	{
		_Node->_Destruct_In_Place();
		_Dealloc(_Node);
		_Node->_Connect();
		_Node = nullptr;
	}

	constexpr void _Erase_Tree(Node_Ptr &_Rootnode) noexcept
	{
		if (!_Rootnode->_IsNil)
		{
			_Erase_Tree(_Rootnode->_Left);
			_Erase_Tree(_Rootnode->_Right);
			_FreeNode(_Rootnode);
		}
	}

	constexpr void _Make_Empty() noexcept
	{
		_Erase_Tree(_Head);
		_Head = _Nil;
		_Size = 0;
	}

	constexpr _Find_Result _Find_Lower_Bound(const key_type &_Key) const noexcept
	{
		Node_Ptr _Location(_Head);

		while (!_Location->_IsNil)
		{
			const key_type &_Loc_Key = _Traits::_Get_Key(_Location->_Data);

			if (equal{}(_Key, _Loc_Key))
			{ // ==
				return {_Location, _Put_At::_None};
			}

			if (greater{}(_Key, _Loc_Key))
			{ // >
				if (_Location->_Right->_IsNil)
				{
					return {_Location, _Put_At::_Right};
				}
				else
				{
					_Location = _Location->_Right;
				}
			}
			else
			{ // <
				if (_Location->_Left->_IsNil)
				{
					return {_Location, _Put_At::_Left};
				}
				else
				{
					_Location = _Location->_Left;
				}
			}
		}
		return {_Nil, _Put_At::_None};
	}

	template <typename... Args>
	constexpr pair<Node_Ptr, bool> _Emplace(Args &&...args) noexcept
	{
		if (_Head->_IsNil)
		{
			_Head = _BuyNode(_Nil, std::forward<Args>(args)...);
			++_Size;
			return {_Head, true};
		}

		_Find_Result _Location{_Find_Lower_Bound(_Traits::_Get_Key({args...}))};

		if (_Location._Put_Loc == _Put_At::_Right)
		{
			_Location._Node->_Connect_Right(_BuyNode(_Location._Node, std::forward<Args>(args)...));
			++_Size;
			return {_Location._Node->_Right, true};
		}
		else if (_Location._Put_Loc == _Put_At::_Left)
		{
			_Location._Node->_Connect_Left(_BuyNode(_Location._Node, std::forward<Args>(args)...));
			++_Size;
			return {_Location._Node->_Left, true};
		}

		return {_Location._Node, false}; // if failed to emplace
	}

	// _Emplace_Hint() { later }

	template <typename _Iterator>
	constexpr void _Insert_Range(_Iterator _First, _Iterator _Last) noexcept
	{
		for (; _First != _Last; ++_First)
		{
			(void)_Emplace(*_First);
		}
	}

	template <typename _Iter>
	constexpr void _Construct_Range(_Iter _First, _Iter _Last) noexcept
	{
		for (; _First != _Last; ++_First)
			(void)_Emplace(*_First);
	}

	constexpr Node_Ptr _Copy_Nodes(Node_Ptr _Rootnode, Node_Ptr _Parent) noexcept
	{
		if (!_Rootnode->_IsNil)
		{
			Node_Ptr _Pnode(_BuyNode(_Parent, _Rootnode->_Data));

			if (_Parent->_IsNil)
			{ // to initialize the _Head at first
				_Head = _Pnode;
			}

			_Pnode->_Connect_Left(_Copy_Nodes(_Rootnode->_Left, _Pnode));
			_Pnode->_Connect_Right(_Copy_Nodes(_Rootnode->_Right, _Pnode));
			return _Pnode;
		}
		return _Rootnode; // will return if _Rootnode is _Nil
	}

	constexpr void _Copy(const _Tree &_Other) noexcept
	{
		(void)_Copy_Nodes(_Other._Head, _Nil);
	}

	constexpr Node_Ptr _Erase(const_iterator _Target, const _Node_Info &_Info) noexcept
	{
		Node_Ptr _Victim(_Target._Ptr);
		++_Target;
		Node_Ptr _Successor(_Target._Ptr);

		switch (_Info._Kids)
		{

		case _Kids::_LRCH:
		{ // [A] _Victim has 2 kids

			if (_Node_Info::_Left_Or_Right(_Successor) == _POS::_Left_)
			{ // _Successor is on left
				_Successor->_Parent->_Connect_Left(_Successor->_Right);
			}
			else
			{ // _Successor is on right
				_Successor->_Parent->_Connect_Right(_Successor->_Right);
			}

			if (!_Successor->_Right->_IsNil)
			{ // connect up right _Successor child if not nil
				_Successor->_Right->_Connect_Up(_Successor->_Parent);
			}

			_Victim->_Left->_Connect_Up(_Successor);
			_Victim->_Right->_Connect_Up(_Successor);

			_Successor->_Connect_Left(_Victim->_Left);
			_Successor->_Connect_Right(_Victim->_Right);
			_Successor->_Connect_Up(_Victim->_Parent);

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Head = _Successor;
				break;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Successor);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Successor);
				break;
			}
			}
			_FreeNode(_Victim);
			break;
		}

		case _Kids::_LCHO:
		{ // [B] _Victim has left kid only
			Node_Ptr _Left_Kid(_Victim->_Left);

			_Left_Kid->_Connect_Up(_Victim->_Parent);

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Head = _Left_Kid;
				break;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Left_Kid);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Left_Kid);
				break;
			}
			}
			_FreeNode(_Victim);
			--_Size;
			return _Left_Kid;
		}

		case _Kids::_RCHO:
		{ // [C] _Victim has right kid only
			Node_Ptr _Right_Kid(_Victim->_Right);

			_Right_Kid->_Connect_Up(_Victim->_Parent);

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Head = _Right_Kid;
				break;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Right_Kid);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Right_Kid);
				break;
			}
			}
			_FreeNode(_Victim);
			--_Size;
			return _Right_Kid;
		}

		case _Kids::_NONE:
		{ // [D] no kids (leaf node)

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Make_Empty();
				return _Nil;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Nil);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Nil);
				break;
			}
			}
			_FreeNode(_Victim);
		}
		}
		--_Size;
		return _Successor;
	}

	constexpr Node_Ptr _Erase_Range(const_iterator _First, const_iterator _Last) noexcept
	{
		if (_First == begin() && _Last._Ptr->_IsNil)
		{
			_Make_Empty();
			return _Last._Ptr;
		}

		while (_First != _Last)
		{
			_Node_Info _Info(_First._Ptr);
			(void)_Erase(_First++, _Info);
		}
		return _Last._Ptr;
	}

	constexpr Node_Ptr _Unlink(const_iterator _Target, const _Node_Info &_Info) noexcept
	{
		Node_Ptr _Victim(_Target._Ptr);
		++_Target;
		Node_Ptr _Successor(_Target._Ptr);

		switch (_Info._Kids)
		{

		case _Kids::_LRCH:
		{ // [A] _Victim has 2 kids

			if (_Node_Info::_Left_Or_Right(_Successor) == _POS::_Left_)
			{ // _Successor is on left
				_Successor->_Parent->_Connect_Left(_Successor->_Right);
			}
			else
			{ // _Successor is on right
				_Successor->_Parent->_Connect_Right(_Successor->_Right);
			}

			if (!_Successor->_Right->_IsNil)
			{ // connect up right _Successor child if not nil
				_Successor->_Right->_Connect_Up(_Successor->_Parent);
			}

			_Victim->_Left->_Connect_Up(_Successor);
			_Victim->_Right->_Connect_Up(_Successor);

			_Successor->_Connect_Left(_Victim->_Left);
			_Successor->_Connect_Right(_Victim->_Right);
			_Successor->_Connect_Up(_Victim->_Parent);

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Head = _Successor;
				break;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Successor);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Successor);
				break;
			}
			}
			break;
		}

		case _Kids::_LCHO:
		{ // [B] _Victim has left kid only
			Node_Ptr _Left_Kid(_Victim->_Left);

			_Left_Kid->_Connect_Up(_Victim->_Parent);

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Head = _Left_Kid;
				break;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Left_Kid);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Left_Kid);
				break;
			}
			}
			break;
		}

		case _Kids::_RCHO:
		{ // [C] _Victim has right kid only
			Node_Ptr _Right_Kid(_Victim->_Right);

			_Right_Kid->_Connect_Up(_Victim->_Parent);

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Head = _Right_Kid;
				break;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Right_Kid);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Right_Kid);
				break;
			}
			}
			break;
		}

		case _Kids::_NONE:
		{ // [D] no kids (leaf node)

			switch (_Info._Pos)
			{

			case _POS::_Head_:
			{ // (1) _Victim is _Head
				_Head = _Nil;
				break;
			}
			case _POS::_Left_:
			{ // (2) _Victim is a node on the left
				_Victim->_Parent->_Connect_Left(_Nil);
				break;
			}
			case _POS::_Right_:
			{ // (3) _Victim is a node on the right
				_Victim->_Parent->_Connect_Right(_Nil);
				break;
			}
			}
		}
		}
		--_Size;
		_Victim->_Connect(_Nil, _Nil, _Nil);
		return _Victim;
	}

	// slow search O(n)
	constexpr Node_Ptr _Search(const key_type &_Key) const noexcept
	{
		const_iterator _B(cbegin()), _E(cend());

		for (; _B != _E; ++_B)
			if (_Traits::_Get_Key(_B._Ptr->_Data) == _Key)
				return _B._Ptr;

		return _Nil;
	}

	// fast search O(log n)
	constexpr Node_Ptr __Search(const key_type &_Key) const noexcept
	{
		Node_Ptr _Location(_Head); // search start point

		while (!_Location->_IsNil)
		{
			const key_type &_Loc_Key = _Traits::_Get_Key(_Location->_Data);

			if (equal{}(_Key, _Loc_Key))
			{
				return {_Location}; // found
			}

			if (greater{}(_Key, _Loc_Key))
			{ // >
				if (_Location->_Right->_IsNil)
					return {_Nil}; // stop
				else
					_Location = _Location->_Right; // move right
			}
			else
			{ // <
				if (_Location->_Left->_IsNil)
					return {_Nil}; // stop
				else
					_Location = _Location->_Left; // move left
			}
		}

		return {_Nil}; // not found
	}

public:
	constexpr _Tree() noexcept { _Init(); }

	constexpr _Tree(std::initializer_list<value_type> _il) noexcept
	{
		size_type __Size(_il.size());
		if (__Size)
		{
			_Init();
			const_pointer _First_Elem(_il.begin());
			_Head = _BuildHead(*_First_Elem), ++_Size;
			_Construct_Range(_First_Elem + 1, _il.end());
		}
		else
		{
			_Init();
		}
	}

	constexpr _Tree(const _Tree &_Other) noexcept
	{
		if (_Other.empty())
		{
			_Init();
		}
		else
		{
			_Init();
			_Copy(_Other);
		}
	}

	constexpr _Tree(_Tree &&_Other) noexcept
	{
		_Init();
		_Steal_Data(_Other);
	}

	constexpr _Tree &operator=(const _Tree &_Other) noexcept
	{
		if (this == &_Other)
		{
			return *this;
		}

		if (_Head->_IsNil)
		{
			_Copy(_Other);
		}
		else
		{
			_Make_Empty();
			_Copy(_Other);
		}
	}

	constexpr _Tree &operator=(_Tree &&_Other) noexcept
	{
		if (this == &_Other)
		{
			return *this;
		}

		if (_Head->_IsNil)
		{
			_Steal_Data();
		}
		else
		{
			_Make_Empty();
			_Steal_Data();
		}
	}

	~_Tree()
	{
		_Erase_Tree(_Head);
		_FreeNode(_Nil);
		_Head = nullptr;
		_Size = 0;
	}

	constexpr size_type size() const noexcept { return _Size; }
	constexpr bool empty() const noexcept { return _Size == 0; }

	constexpr void clear() noexcept { _Make_Empty(); }

	template <typename... Args>
	constexpr pair<Node_Ptr, bool> emplace(Args &&...args) noexcept
	{
		return _Emplace(std::forward<Args>(args)...);
	}

	constexpr pair<Node_Ptr, bool> insert(const value_type &_Val)
	{
		return _Emplace(_Val);
	}
	constexpr pair<Node_Ptr, bool> insert(value_type &&_Val)
	{
		return _Emplace(std::move(_Val));
	}

	template <typename _Iterator>
	constexpr void insert(_Iterator _First, _Iterator _Last)
	{
		_Insert_Range(_First, _Last);
	}

	constexpr void insert(std::initializer_list<value_type> _il)
	{
		_Insert_Range(_il.begin(), _il.end());
	}

	constexpr iterator erase(const_iterator _Target) noexcept
	{
		if (_Target._Ptr->_IsNil)
			return {_Nil};
		return {_Erase(_Target, _Node_Info(_Target._Ptr))};
	}
	constexpr iterator erase(const_iterator _First, const_iterator _Last) noexcept
	{
		return {_Erase_Range(_First, _Last)};
	}
	constexpr iterator erase(const key_type &_Key) noexcept
	{
		return erase(__Search(_Key));
	}

	constexpr iterator find(const key_type &_Key) noexcept
	{
		return {__Search(_Key)};
	}
	constexpr const_iterator find(const key_type &_Key) const noexcept
	{
		return {__Search(_Key)};
	}

	constexpr pair<Node_Ptr, bool> extract(const_iterator _Target) noexcept
	{
		Node_Ptr _Result(__Search(_Traits::_Get_Key(_Target._Ptr->_Data)));

		if (_Result->_IsNil)
		{
			return {_Result, false};
		}

		return {_Unlink(_Target, _Node_Info(_Result)), true};
	}
	constexpr pair<Node_Ptr, bool> extract(const key_type &_Key) noexcept
	{
		Node_Ptr _Result(__Search(_Key));

		if (_Result->_IsNil)
		{
			return {_Result, false};
		}

		return {_Unlink({_Result}, _Node_Info(_Result)), true};
	}
	constexpr pair<Node_Ptr, bool> extract(key_type &&_Key) noexcept
	{
		Node_Ptr _Result(__Search(_Key));

		if (_Result->_IsNil)
		{
			return {_Result, false};
		}

		return {_Unlink({_Result}, _Node_Info(_Result)), true};
	}

	constexpr bool contains(const key_type &_Key) const noexcept
	{
		return !__Search(_Key)->_IsNil;
	}

	constexpr data_type &operator[](const key_type &_Key) noexcept
	{
		return _Traits::_Get_Data(insert(std::forward<value_type>({_Key, data_type()}))._First->_Data);
	}

	constexpr value_type &at(const key_type &_Key) noexcept
	{
		return __Search(_Key)->_Data;
	}
	constexpr const value_type &at(const key_type &_Key) const noexcept
	{
		return __Search(_Key)->_Data;
	}

	// iterators
	constexpr iterator begin() noexcept
	{
		if (_Head->_IsNil)
		{
			return {_Nil};
		}
		return iterator(_Tree_Search::_Min(_Head));
	}
	constexpr const_iterator begin() const noexcept
	{
		if (_Head->_IsNil)
		{
			return {_Nil};
		}
		return const_iterator(_Tree_Search::_Min(_Head));
	}
	constexpr const_iterator cbegin() const noexcept
	{
		return begin();
	}

	constexpr iterator end() noexcept
	{
		return iterator(_Nil);
	}
	constexpr const_iterator end() const noexcept
	{
		return const_iterator(_Nil);
	}
	constexpr const_iterator cend() const noexcept
	{
		return end();
	}
};

MG_END