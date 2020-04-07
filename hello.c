#include <stdio.h>
#include <fcntl.h>
#include <assert.h>

int main (void) {
  int fd = 0;
  int ret = 0;
  char buf[256];
  assert(0);
  for(int i= 0;i<256;i++)
  {
  	buf[i]=0;
  }
  printf("Hello World:fd %d\n",fd);
  /*
  fd = open("/home/ours-demo/test.txt",555);
  if(fd > 0)
  {
  	ret = read(fd,buf,10);
	if(ret <= 0)
	{
		printf("ret value: %d \n",ret);
		close(fd);
	}
	else
	{
		buf[ret+1]=0;
		printf("ret %d buf content %s \n",ret,buf);
  		close(fd);
	}
  }
  */

  return 0;
}

