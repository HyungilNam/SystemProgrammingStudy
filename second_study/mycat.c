#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main(void)
{
  int n;
  char buf[BUFFSIZE];

  while((n=read(STDIN_FILENO, buf, BUFFSIZE))>0)    //내가 키보드로 입력한 거 받아서, 4096만큼을 읽어
  {
    write(STDOUT_FILENO, buf, n);               //fd가 out이니까 모니터에 출력 하는거야, 근데 읽은 만큼만 쓰게 하려고, 뒤를 n으로.. 쓴개수만큼만  반환
  }
  
  if(n<0)
  {
    printf("read error");
    exit(-1);
  }

  exit(0);
}
