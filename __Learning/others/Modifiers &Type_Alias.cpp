#include <iostream>
#include <limits.h>

using namespace std;

/*
  -- you can use type_Alias to make an Alias to any date_type for yourself

  There is 2 ways to create a type_Alias:

  (1) using 'Identifier' = 'data_type';
  (2) Typedef 'data_type' 'Identifier';

*/

/*
(1) using 'Identifier' = 'data_type';

ex:
  // long == int

  using L = long;
  using LL = long long;
  using UL = unsigned long;
  using ULL = unsigned long long;
  using US = unsigned short;
  using Str = string;
  using CH = char;

*/

/*
(2) Typedef 'data_type' 'Identifier;

ex:
  // long == int

  typedef long L;
  typedef unsigned long UL;
  typedef long long LL;
  typedef unsigned long long ULL;
  typedef unsigned short US;
  typedef string Str;
  typedef char CH;

*/

using ULL = unsigned long long;
using Str = string;
typedef long long LL;

int main(void)
{

  ULL Unsigned_Big_Number = 21215488654864168; // ULL == unsigned long long

  cout << Unsigned_Big_Number << '\n';

  LL Signed_Big_Number = -45646878654665; // LL == long long

  cout << Signed_Big_Number << '\n';

  Str Name = "Mahmoud Abdelrahman Ismail Gad";

  cout << Name << '\n'; 

  return 0;
}
