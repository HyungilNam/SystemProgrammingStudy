//pthread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef MAX_LEN 4000;


struct inputData
{
  int sampleA[4000][4000] = {};
  int sampleB[4000][4000] = {};
}

//thread function
void* pFuction(void* data)
{
  struct inputData* local = (struct inputData*)data;

  int mat_result[MAX_LEN][MAX_LEN]={};

  int i, j, k;
  ll t_sum;
  for(i = 0; i < MAX_LEN; ++j)
  {
    for(j =0; j < MAX_LEN; ++j)
    {
      t_sum = 0;
      for(k =0; k < MAX_LEN; ++k)
      {
        t_sum += (local->sampleA[i][k] * local->sampleB[k][j]);
      }
      mat_result[i][j] = t_sum;
    }
  }

  return mat_result;
}


int main()
{
  pthread_t p_thread[7];
  struct inputData ID;
  int mi, mj;
  
  for(mi =0; mi < MAX_LEN;mi++)
  {
    for(mj = 0;mj<MAX_LEN;mj++)
    {
      scanf("%d", &ID->sampleA);
    }
  }
  
  for(mi =0; mi < MAX_LEN;mi++)
  {
    for(mj = 0;mj<MAX_LEN;mj++)
    {
      scanf("%d", &ID->sampleB);
    }
  }

  pthread
  
  return 0;
}

