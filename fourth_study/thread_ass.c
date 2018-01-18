//연산 병렬과 과제, 행렬 연산을 병렬화

#include <stdio.h>

int main()
{
  

  return 0;
}

void multi()
  int i, j,k;
  long long t_sum;
  for (i = 0; i < MAX_LEN; ++i) 
  {
    for (j = 0; j < MAX_LEN; ++j) 
    {   
      t_sum = 0;
      for (k = 0; k < MAX_LEN; ++k) 
      {
        t_sum += (mat_a[i][k] * mat_b[k][j]);
      }
      mat_c[i][j] = t_sum;
    }
  }
}
