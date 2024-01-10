#include <stdio.h>
#include <iostream>

using namespace std;

// Look [stdio.h] ->  https://cplusplus.com/reference/cstdio/

int main(void)
{
  int N1, N2, Result;
  short P, S;
  P = printf("\nPlease Enter 2 Numbers:\n");

  S = scanf("%d%d", &N1, &N2);

  Result = N1 + N2;

  P = printf("\nResult = %d\n\n", Result);
  printf("\nprintf = %d & scanf = %d\n\n", P, S);

  puts("Mahmoud Gad"); // for Printing

  return 0;
}