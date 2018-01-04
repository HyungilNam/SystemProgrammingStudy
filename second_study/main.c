#include "swap.h"
#include <stdio.h>

int main()
{
  int a = 5;
  int b = 6;

  printf("%d %d\n", a, b);
  Swap(&a, &b);
  printf("%d %d\n", a, b);

  return 0;
}
