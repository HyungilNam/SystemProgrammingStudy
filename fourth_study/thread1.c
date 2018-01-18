#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>

volatile int counter = 0; 
int loops;
pthread_mutex_t mlock = PTHREAD_MUTEX_INITIALIZER;


void* worker(void *arg)                   //function pointer -->return function address(void pointer) , argument is void pointer 여러 인자를 넘기려면 구조체 포인터를 쓰세영
{ 
  int i;

  pthread_mutex_lock(&mlock);
  for (i = 0; i < loops; i++) 
  {
    //pthread_mutex_lock(&mlock);
    counter++;
    //pthread_mutex_unlock(&mlock);
  }
  pthread_mutex_unlock(&mlock);
  return NULL;
}

int main(int argc , char *argv[]) 
{
  if (argc != 2) 
  {
    fprintf(stderr, "usage: threads <value>\n"); 
    exit(1);
  }
  loops = atoi(argv[1]);                               //외부에서 인자로 넘겨 받겠다는 말
  pthread_t p1 , p2;                                  //pthread 포직스...-->어디서든 쓸 수 있어, pthread로 선언 
  printf("Initial value : %d\n ", counter);
  pthread_create(&p1 , NULL , worker , NULL);         //주소값을 넘기고, thread의 속성을 두번째로 인자로 보통 null, 세번째가 처리할 함수, 네번째가 세번째 함수의 인자
  pthread_create(&p2 , NULL , worker , NULL); 
  pthread_join(p1 , NULL);                            //wait의 기능을 가짐, p1이 끝날때까지 기다려라!
  pthread_join(p2 , NULL);
  printf("Final value : %d\n", counter); 
  return 0;
}
