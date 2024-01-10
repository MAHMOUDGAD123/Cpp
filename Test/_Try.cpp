// #include <bits/stdc++.h>
#include <iostream>
#include <limits>

#define Or ||
#define AND &&
#define print std::cout
#define out <<
#define NewLine std::cout << std::endl

template <typename _Container>
static void _Print(const _Container &_Cont)
{
  for (const auto &_Elem : _Cont)
    std::cout << "\"" << _Elem << "\" ";
  std::cout << std::endl;
}

template <typename _Ty1, typename _Ty2>
static std::ostream &operator<<(std::ostream &_Out, const std::pair<_Ty1, _Ty2> &_Pair) noexcept
{
  _Out << _Pair.first << " - " << _Pair.second;
  return _Out;
}

template <typename Ty>
static Ty Read_Num(const char *const err_msg = "Invalid Num, Enter Again:  ")
{
  Ty num(0);
  while (!(std::cin >> num))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << err_msg;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return num;
}

/*=============================================================================*/
// test

struct INT final
{
  constexpr INT() noexcept
      : n(0)
  {
  }

  constexpr INT(const INT &x) noexcept
      : n(x.n)
  {
  }

  constexpr INT(const INT &&x) noexcept
      : n(std::move(x.n))
  {
  }

  constexpr INT &operator=(const INT &x) noexcept
  {
    this->n = x.n;
    return *this;
  }

  constexpr INT &operator=(const INT &&x) noexcept
  {
    this->n = std::move(x.n);
    return *this;
  }

  ~INT() = default;

  constexpr INT &operator++() noexcept
  {
    /* pre */
    ++this->n;
    return *this;
  }
  constexpr INT operator++(int) noexcept
  {
    /* post */
    INT temp(*this);
    ++this->n;
    return temp;
  }

  constexpr INT &operator--() noexcept
  {
    /* pre */
    --this->n;
    return *this;
  }
  constexpr INT operator--(int) noexcept
  {
    /* post */
    INT temp(*this);
    --this->n;
    return temp;
  }

  constexpr INT operator+(const INT &x) noexcept
  {
    INT res;
    res.n = this->n + x.n;
    return res;
  }
  constexpr INT operator-(const INT &x) noexcept
  {
    INT res;
    res.n = this->n - x.n;
    return res;
  }

  std::string operator+(const std::string &str) const noexcept
  {
    return std::to_string(n) + str;
  }

  friend std::ostream &operator<<(std::ostream &os, const INT &x) noexcept
  {
    os << x.n;
    return os;
  }

  friend std::string operator+(const std::string &str, INT N)
  {
    return str + std::to_string(N.n);
  }

private:
  int n;
};

/*=============================================================================*/
/* main fun */

int main(int argc, char *argv[])
{
  INT X, Y, Z;

  ++(++(++X));
  ++(++(++Y));
  ++Z;

  std::cout << "\n-> X = " << X;
  std::cout << "\n-> Y = " << Y;
  std::cout << "\n-> Z = " << Z;
  std::cout << "\n-> X + Y = " << X << " + " << Y << " = " << X + Y;
  std::cout << "\n-> X - Z = " << X << " - " << Z << " = " << X - Z;

  NewLine;
  NewLine;

  std::cout << X + " - Mahmoud Gad - " + Y + " - " + Z;

  NewLine;
  NewLine;

  return 0;
}