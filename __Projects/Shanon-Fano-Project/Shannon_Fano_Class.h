#include "Tools.h"

struct _Node // for every symbol
{
  char _Symbol;
  uint16_t _Freq;
  float _Prob;
  string _Code;

  _Node() = default;

  _Node(const _Node &_Other) noexcept
      : _Symbol(_Other._Symbol), _Freq(_Other._Freq), _Prob(_Other._Prob), _Code(_Other._Code)
  {
  }
  _Node(_Node &&_Other) noexcept
      : _Symbol(move(_Other._Symbol)), _Freq(move(_Other._Freq)), _Prob(move(_Other._Prob)), _Code(move(_Other._Code))
  {
  }

  _Node &operator=(const _Node &_Other) noexcept
  {
    _Symbol = _Other._Symbol;
    _Freq = _Other._Freq;
    _Prob = _Other._Prob;
    _Code = _Other._Code;
    return *this;
  }
  _Node &operator=(_Node &&_Other) noexcept
  {
    _Symbol = move(_Other._Symbol);
    _Freq = move(_Other._Freq);
    _Prob = move(_Other._Prob);
    _Code = move(_Other._Code);
    return *this;
  }

  constexpr void _Init(char Symbol = '\0', uint16_t Frequency = 0, float Probability = 0.0f) noexcept
  {
    _Symbol = Symbol;
    _Freq = Frequency;
    _Prob = Probability;
  }

  friend ostream &operator<<(ostream &_Out, const _Node &Node)
  {
    _Out << setprecision(5);
    _Out << "\t"
         << "| " << setw(14) << left << Node._Symbol
         << "| " << setw(14) << left << Node._Freq
         << "| " << setw(14) << left << Node._Prob
         << "| " << setw(22) << left << Node._Freq * -log2f(Node._Prob)
         << "| " << setw(10) << left << Node._Code
         << "| " << setw(10) << left << Node._Freq * Node._Code.size()
         << endl;
    return _Out;
  }

  constexpr bool operator==(const _Node &_rhs) const
  {
    return _Freq == _rhs._Freq;
  }
  constexpr bool operator>(const _Node &_rhs) const
  {
    return _Freq > _rhs._Freq;
  }
  constexpr bool operator<(const _Node &_rhs) const
  {
    return _Freq < _rhs._Freq;
  }
  constexpr bool operator>=(const _Node &_rhs) const
  {
    return _Freq >= _rhs._Freq;
  }
  constexpr bool operator<=(const _Node &_rhs) const
  {
    return _Freq <= _rhs._Freq;
  }
};


// string compression
class Shannon_Fano
{
  using _iterator = vector<_Node>::const_iterator;

private:
  string _String;
  vector<_Node> _Nodes;

  // calculate the frequency and the probability for all nodes(symbol)
  void _Build_Nodes() noexcept
  {
    if (_String.empty())
      return;

    size_t _Size(_String.size()); // total number of characters
    _Nodes.reserve(_Size); // allocate enough space for the nodes

    char _Chr;   // holds the character that will be counted
    _Node _Temp; // a temporary node

    for (size_t _Freq(0), _Found(0); !_String.empty(); _Freq = 0)
    {
      _Chr = _String[0];
      // this loop will count the symbol and remove it from Str
      while ((_Found = _String.find(_Chr)) != string::npos)
      {
        ++_Freq;
        _String.erase(_String.begin() + _Found); // erase the counted char
      }
      _Temp._Init(_Chr, _Freq, _Freq / (float)_Size);
      _Nodes.push_back(_Temp);
    }
  }

  // sort nodes in a descending order by frequency
  void _Sort_Nodes_Descending() noexcept
  {
    size_t _Size(_Nodes.size());

    for (size_t i(0); i < _Size; ++i)
      _Swap(_Nodes[i], _Nodes[_Max(_Nodes, i)]);
  }

  uint32_t _Total_Freq() const noexcept
  {
    uint32_t _Sum(0);
    for (const _Node &Node : _Nodes)
      _Sum += Node._Freq;

    return _Sum;
  }

  float _Total_Prob() const noexcept
  {
    float _Sum(0);
    for (const _Node &Node : _Nodes)
      _Sum += Node._Prob;

    return _Sum;
  }

  float _Total_Info() const noexcept
  {
    float _Sum(0);
    for (const _Node &Node : _Nodes)
      _Sum += Node._Freq * -log2f(Node._Prob);

    return _Sum;
  }

  float _Total_Bits() const noexcept
  {
    float _Sum(0);
    for (const _Node &Node : _Nodes)
      _Sum += Node._Freq * Node._Code.size();

    return _Sum;
  }

  int32_t _Sum_Range(_iterator _First, _iterator _Last) const
  {
    int32_t _Sum(0);
    for (; _First != _Last; ++_First)
    {
      _Sum += (*_First)._Freq;
    }
    return _Sum;
  }

  _iterator _Break_Point(const vector<_Node> &Nodes) const
  {
    _iterator _BP = Nodes.cbegin() + 1;
    _iterator _Begin = Nodes.cbegin();
    _iterator _End = Nodes.cend();

    int32_t _Up, _Down;
    int32_t _Prev_Sub, _Next_Sub;

    _Up = _Sum_Range(_Begin, _BP);
    _Down = _Sum_Range(_BP, _End);
    _Prev_Sub = abs(_Up - _Down);

    while (_BP != _End)
    {
      _Up = _Sum_Range(_Begin, _BP + 1);
      _Down = _Sum_Range(_BP + 1, _End);
      _Next_Sub = abs(_Up - _Down);

      if (_Next_Sub > _Prev_Sub)
        break;
      else
        ++_BP;

      _Prev_Sub = _Next_Sub;
    }
    return _BP;
  }

  vector<_Node> &_Shannon_Engine(vector<_Node> &Nodes) noexcept
  {
    // base case
    if (Nodes.size() == 2)
    {
      Nodes[0]._Code += '0';
      Nodes[1]._Code += '1';
      return Nodes;
    }
    else if (Nodes.size() == 1)
    {
      if (Nodes[0]._Code.empty())
        Nodes[0]._Code += '0';

      return Nodes;
    }

    _iterator _BP = _Break_Point(Nodes);
    vector<_Node> _High(Nodes.cbegin(), _BP);
    vector<_Node> _Low(_BP, Nodes.cend());

    // add "1" to _High nodes
    for (_Node &Node : _High)
      Node._Code += '0';
    // add "0" to _Low nodes
    for (_Node &Node : _Low)
      Node._Code += '1';

    _High = _Shannon_Engine(_High);
    _Low = _Shannon_Engine(_Low);

    Nodes = move(_High);
    for (_Node &Node : _Low)
      Nodes.emplace_back(move(Node));

    return Nodes;
  }

public:
  Shannon_Fano() = delete;
  Shannon_Fano(const Shannon_Fano &) = delete;
  Shannon_Fano(Shannon_Fano &&) = delete;
  Shannon_Fano &operator=(const Shannon_Fano &) = delete;
  Shannon_Fano &operator=(Shannon_Fano &&) = delete;

  Shannon_Fano(const string &_Str) noexcept
      : _String(_Str), _Nodes()
  {
  }

  void Run() noexcept
  {
    _Build_Nodes();
    _Sort_Nodes_Descending();
    _Nodes = _Shannon_Engine(_Nodes);
    cout << *this;
  }

  friend ostream &operator<<(ostream &_Out, const Shannon_Fano &_Data)
  {
    _Out << "\t--------------------------------------------------------------------------------------------------\n";
    _Out << "\t| Symbol"
         << "\t| Frequency"
         << "\t| Probability"
         << "\t| Freq * -log2(Porb)"
         << "\t| Code"
         << "\t    | No. Bits"
         << endl;
    _Out << "\t--------------------------------------------------------------------------------------------------\n";

    for (const _Node &Node : _Data._Nodes)
      _Out << Node;

    _Out << "\t--------------------------------------------------------------------------------------------------\n";
    _Out << setw(17) << "\tTotal:"
         << "| " << setw(14) << _Data._Total_Freq()
         << "| " << setw(14) << _Data._Total_Prob()
         << "| " << setw(34) << _Data._Total_Info()
         << "| " << setw(14) << _Data._Total_Bits()
         << endl;
    _Out << "\t--------------------------------------------------------------------------------------------------\n";

    return _Out;
  }
};