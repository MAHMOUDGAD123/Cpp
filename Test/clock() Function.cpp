/* clock example: frequency of primes */
#include <stdio.h> /* printf */
#include <time.h>  /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>  /* sqrt */

using namespace std;

int frequency_of_primes(int *n)
{
  int *i = new int{0};
  int *j = new int{0};
  int **freq = &n;

  for (*i = 2; *i <= *n; ++*i)
  {
    for (*j = sqrt(*i); *j > 1; --*j)
    {
      if (*i % *j == 0)
      {
        --(**freq);
        break;
      }
    }
  }

  delete i, j;
  return **freq;
}

int main()
{
  clock_t t;
  int n = 1000000;
  int f;
  t = clock();
  printf("Calculating...\n");
  f = frequency_of_primes(&n);
  printf("The number of primes lower than 1000,000 is: %d\n", f);
  t = clock() - t;
  printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
  return 0;
}
