#include <signal.h>
#include <unistd.h>

static void
sig_alrm (int signo)
{
  //nothing to do, just return to
}

unsigned int sleep1 (unsigned int seconds)
{
  if(signal (SIGALRM, sig_alrm) == SIG_ERR)   //시그널 핸들러에 등록 못하면 에러 발생
    return(seconds);

  alarm(seconds);    //seconds뒤에 나에게 알람을 보내는 신호, 반환값은 seconds만큼 중에 실행하고 남은 시간을 반환
  pause();           //신호가 발생할 때까지 대기하는
  
  return(alarm(0)); 
}

int main()
{
  unsigned int ret;

  ret = sleep1(5);
  printf("%u \n", ret);

  return 0;
}
