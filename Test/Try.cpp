#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

#define Or ||
#define AND &&

#define print std::cout
#define out <<

template <typename _Container>
static void _Print(const _Container &_Cont)
{
  for (const auto &_Elem : _Cont)
  {
    std::cout << _Elem << "  ";
  }
}

using Pair = std::pair<int, int>;
using iterator = std::vector<Pair>::iterator;

template<typename _Ty>
constexpr void _Swap(_Ty& _Var1, _Ty& _Var2) noexcept
{
  _Ty _Temp = std::move(_Var1);
  _Var1 = std::move(_Var2);
  _Var2 = std::move(_Temp);
}

constexpr bool _is_overlaped(const Pair &P1, const Pair &P2)
{
  return !(P1.second < P2.first || P1.first > P2.second);
}
constexpr bool _is_within(const Pair &P, int N)
{
  return N >= P.first && N <= P.second;
}

constexpr int _overlap_len(Pair &P1, Pair &P2)
{
  if (_is_overlaped(P1, P2))
  {
    int start = _is_within(P2, P1.first) ? P1.first : P2.first;
    int end = _is_within(P2, P1.second) ? P1.second : P2.second;
    return end - start;
  }
  return 0;
}

int _total_overlap(Pair &_Curr, iterator _From, iterator _To)
{
  int _total(0);
  for (; _From != _To; ++_From)
    _total += _overlap_len(_Curr, *_From);

  return _total;
}

// sum of intervals
// https://www.codewars.com/kata/52b7ed099cdc285c300001cd/train/cpp
int sum_intervals(std::vector<Pair> &intervals)
{
  iterator _Curr(intervals.begin()), _End(intervals.end());
  int len(0);

  for (; _Curr != _End; ++_Curr)
  {
    if((*_Curr).first > (*_Curr).second) 
      _Swap((*_Curr).first, (*_Curr).second); // always (second > first)

    len += (*_Curr).second - (*_Curr).first - _total_overlap(*_Curr, intervals.begin(), _Curr);
  }

  return len;
}

int rrand() noexcept
{
  return rand() % (1000000000 + 1000000000 + 1) + -1000000000;
}

int main(void)
{
  /*
   std::cout << ~1 << "\n";             // 1's complement
   std::cout << ~1 + 1 << "\n";         // 2's complement
   std::cout << -(1 + 1) << "\n";       // 1's complement
   std::cout << -(1 + 1) + 1 << "\n\n"; // 2's complement
   */

  srand(time(nullptr));

  int N = 1000000000;
  print out N;

  std::vector<Pair> intervals{{rrand(), rrand()}, {rrand(), rrand()}};

  print out sum_intervals(intervals);

  return 0;
}