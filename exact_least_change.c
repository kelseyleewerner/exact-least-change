#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int basic_recursion(int);


int main()
{
  int n;

  printf("Please provide a total number of pennies (>=1): ");
  scanf("%d", &n);

  printf("Using Recusion: The number of coins to make exact least change for %d pennies is %d\n", n, basic_recursion(n));
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



