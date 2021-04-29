#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int basic_recursion(int);
int memoized_recursion(int);


int * t;


int main()
{
  int n;

  printf("Please provide a total number of pennies (>=1): ");
  scanf("%d", &n);

  t = malloc(sizeof(int) * (n + 1));

  for (int i = 0; i <= n; ++i) { t[i] = -1; }

  printf("Using Basic Recusion: The number of coins to make exact least change for %d pennies is %d\n", n, basic_recursion(n));
  printf("Using Memoized Recusion: The number of coins to make exact least change for %d pennies is %d\n", n, memoized_recursion(n));
}


int basic_recursion(int n)
{
  int a, b, c, min;

  if (n == 0) { return 0; }
  if (n < 0) { return INT_MAX; }

  a = basic_recursion(n - 1);
  b = basic_recursion(n - 3);
  c = basic_recursion(n - 4);

  min = a;
  if (b < min) { min = b; }
  if (c < min) { min = c; }

  return 1 + min;
}


int memoized_recursion(int n)
{
  int a, b, c, min;

  if (n == 0) { return 0; }
  if (n < 0) { return INT_MAX; }

  if (t[n] != -1) { return t[n]; }

  a = memoized_recursion(n - 1);
  b = memoized_recursion(n - 3);
  c = memoized_recursion(n - 4);

  min = a;
  if (b < min) { min = b; }
  if (c < min) { min = c; }

  t[n] = 1 + min;

  return t[n];
}




