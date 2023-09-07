#pragma once

#include "Tree.h"

MG_BEGIN

template <typename _Key, typename _Val>
struct _Map_Traits
{
	using key_type = _Key;
	using data_type = _Val;
	using value_type = MG::pair<const _Key, _Val>;

	static const key_type &_Get_Key(const value_type &_Value) noexcept
	{
		return _Value._First;
	}

	static data_type &_Get_Data(value_type &_Value) noexcept
	{
		return _Value._Second;
	}
};

template <typename _Key, typename _Val>
class map : public _Tree<_Map_Traits<_Key, _Val>>
{
public:
	using Base = _Tree<_Map_Traits<_Key, _Val>>;
};

MG_END