#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename _Ty>
constexpr void _Swap(_Ty &Var1, _Ty &Var2)
{
  _Ty temp = std::move(Var1);
  Var1 = std::move(Var2);
  Var2 = std::move(temp);
}

// (get max)
template<typename _Type>
size_t _Max(const vector<_Type> &_Vec, size_t _idx)
{
  size_t max(_idx), _Size(_Vec.size());

  for (size_t i(_idx + 1); i < _Size; i++)
    if (_Vec[i] > _Vec[max])
      max = i;

  return max;
}

template<typename _Ty>
float _Sum(const vector<_Ty>& _Vec)
{
  float _Sum(0);
  for(const _Ty& _Elem : _Vec)
    _Sum += _Elem;
    
  return _Sum;
}


template<typename _Ty>
_Ty abs(const _Ty& _Num)
{
  return _Num > 0 ? _Num : -_Num;
}

