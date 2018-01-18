#include <signal.h> 
#include <unistd.h> 

void sig_handler(int signo); // 비프음 발생 함수

int main()
{
  int i = 0;
  signal(SIGINT, (void *)sig_handler);    //시그널 핸들러를 새로정의된걸, SIGINT 가 들어왔을때, 우리가 재정의한걸 실행하라!!

  while(1)
  {
    printf("%d\n", i);
    i++;
    sleep(1);
  }

  return 1;
}


void sig_handler(int signo)
{
  printf("\a");
}
