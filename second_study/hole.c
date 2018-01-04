#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {
      int fd;
      int cur_offset;

      // 1.file.hole 파일 생성
      if ((fd = creat( "./file.hole", 0644)) == -1)   //0644 그 파일에 대한 접근 권한
      {
        puts("file create error");       
      }

      if (write(fd, buf1, 10) != 10) 
      {
        puts("buf1 write error");
        close(fd);
        exit(-1);
      }
      /* offset now = 10 */
      cur_offset = lseek(fd, 0, SEEK_CUR);        //seek-cur 현재 위치
      printf("offset after buf1 write: %d\n", cur_offset);
                              
      // 2. 파일의 오프셋을 16384로 변경
      cur_offset = lseek(fd, 16384, SEEK_SET);     //seek_set 파일의 시작
      printf("offset after offset change: %d\n", cur_offset);
      
      /*offset now = 16384 */
      if (write(fd, buf2, 10) != 10) 
      {
        puts("buf2 write error");
        close(fd);
        exit(-1);
      }
      
      /* offset now = 16394 */
      cur_offset = lseek(fd, 0, SEEK_CUR);
      printf("offset after buf1 write: %d\n", cur_offset);
                                             
      exit(0);
}
