#include <iostream>
#include <vector>
#include <ctime>

#define RAND rand() % (5 - 1) + 1

using namespace std;

using LL = long long;
using Row = vector<LL>;
using Matrix = vector<vector<LL>>;


Matrix _get_minor(const Matrix &M, const short col)
{ // this will get the minor matrix
  short _Size(M.size());
  short new_Size(_Size - 1);
  Matrix new_M(new_Size);
  short i(0); // iterator

  // allocate memory for every row
  for (; i < new_Size; ++i)
    new_M[i].reserve(new_Size);

  i = 0;

  for (short R(1); R < _Size; ++R, ++i)
    for (short C(0); C < _Size; ++C)
      if (C != col)
        new_M[i].push_back(M[R][C]);

  return new_M;
}

long long determinant(const Matrix &M)
{ // N * N Matrix
  const short _Size(M.size());

  if (_Size == 3) // (3 * 3) determinant
    return M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]) + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
  if (_Size == 2) // (2 * 2) determinant
    return M[0][0] * M[1][1] - M[0][1] * M[1][0];
  if (_Size == 1) // easy
    return M[0][0];

  LL det(0);           // final result
  const Row &mx(M[0]); // always use the first row as a multiplier

  for (short col(0), sgn(1); col < _Size; ++col, sgn = -sgn)
    det += sgn * mx[col] * determinant(_get_minor(M, col));
    
  return det;
}



int main()
{
  srand(time(nullptr));

  short size(5);
  Matrix M(size);
  for (short i(0); i < size; ++i)
    M[i].reserve(size);

  for (short i(0); i < size; ++i)
    for (short j(0); j < size; ++j)
      M[i].emplace_back(RAND);

  for (short i(0); i < size; ++i)
  {
    for (short j(0); j < size; ++j)
      cout << M[i][j] << "  ";
    cout << "\n";
  }

  std::cout << "Det = " << determinant(M) << "\n";
}