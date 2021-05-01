#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int basic_recursion(int);
int memoized_recursion(int);
int tabular_solution(int);

#define LO_COIN 1
#define MID_COIN 3
#define HI_COIN 4

int * t;
int * h;


int main()
{
  int n;

  printf("Please provide a total number of pennies (>=1): ");
  scanf("%d", &n);

  printf("Using Basic Recusion: The number of coins to make exact least change for %d pennies is %d\n", n, basic_recursion(n));

  // Set up for the memoized solution
  t = malloc(sizeof(int) * (n + 1));
  for (int i = 0; i <= n; ++i) { t[i] = -1; }

  printf("Using Memoized Recusion: The number of coins to make exact least change for %d pennies is %d\n", n, memoized_recursion(n));

  // Set up for the tabular solution
  h = malloc(sizeof(int) * (n + 1));
  // Will need to manually recalculate this section for new coin denominations :/
  // go through the index value of the highest coin denomination - 1
  h[0] = 0;
  h[1] = 1;
  h[2] = 2;
  h[3] = 1;

  printf("Using Tabular Solution: The number of coins to make exact least change for %d pennies is %d\n", n, tabular_solution(n));

  free(t);
  free(h);
}


int basic_recursion(int n)
{
  int a, b, c, min;

  if (n == 0) { return 0; }
  if (n < 0) { return INT_MAX; }

  a = basic_recursion(n - LO_COIN);
  b = basic_recursion(n - MID_COIN);
  c = basic_recursion(n - HI_COIN);

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

  a = memoized_recursion(n - LO_COIN);
  b = memoized_recursion(n - MID_COIN);
  c = memoized_recursion(n - HI_COIN);

  min = a;
  if (b < min) { min = b; }
  if (c < min) { min = c; }

  t[n] = 1 + min;

  return t[n];
}



int tabular_solution(int n)
{
  int a, b, c, min;

  if (n < HI_COIN) { return h[n]; }

  for (int i = HI_COIN; i <= n; ++i) {
    a = h[i - LO_COIN];
    b = h[i - MID_COIN];
    c = h[i - HI_COIN];

    min = a;
    if (b < min) { min = b; }
    if (c < min) { min = c; }

    h[i] = 1 + min;
  }

  return h[n];
}








