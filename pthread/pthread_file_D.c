#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 8
#define MAX_LEN 4000

void *matrix(void *arg);

int mat_a[MAX_LEN][MAX_LEN];
int mat_b[MAX_LEN][MAX_LEN];
int mat_c[MAX_LEN][MAX_LEN];
int frg = MAX_LEN / NUM_THREADS; //분할할 크기

int main() {
    int rc;
    pthread_t threads[NUM_THREADS];
    
   int data = 0;
   for(int i = 0; i < NUM_THREADS; i++) 
   {
     pthread_create(&threads[i], NULL, matrix, (void *)data); 
     //(생성할 스레드 아이디, 스레드 특성 보통 NULL, 실행할 함수, 함수에 전달할 인자)
      sleep(3);
   }
 
   printf("Done!");

}

void *matrix(void *arg) {
  long i, j, k;
  int t_sum;
  long data = (long)arg;

  for(i = data; i < data+frg; i++) {
    for(j = 0; j < MAX_LEN; j++) {
      t_sum = 0;
      for(k = 0; k < MAX_LEN; k++) {
        t_sum += (mat_a[i][k] * mat_b[k][j]);
      }
      mat_c[i][j] = t_sum;
      printf("%d ", mat_c[i][j]);
    }
    printf("\n");
  }
}
