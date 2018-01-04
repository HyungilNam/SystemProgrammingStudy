//swap function

#include <stdio.h>

void Swap(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  int a = 4;
  int b = 5;
  
  printf("%d, %d \n", a, b);

  Swap(&a, &b);

  printf("%d, %d \n", a, b);

  return 0;
}
