#include <stdio.h>
#include <fcntl.h>


static inline long rivai_syscall(long n, long _a0, long _a1, long _a2, long _a3, long _a4, long _a5, long _a6)
{
   register long a0 asm("a0") = _a0;
   register long a1 asm("a1") = _a1;
   register long a2 asm("a2") = _a2;
   register long a3 asm("a3") = _a3;
   register long a4 asm("a4") = _a4;
   register long a5 asm("a5") = _a5;
   register long a6 asm("a6") = _a6;
   register long a7 asm("a7") = n;
 
   asm volatile ("ecall"
                 : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3),"r"(a4), "r"(a5), "r"(a6), "r"(a7));
 
   if (a0 < 0)
     return __syscall_error (a0);
   else
     return a0;
}


#define SYS_get_wave 600
#define SYS_get_python_image 107
#define SYS_return_values 108


typedef enum wavetype{
	ORIGIN_WAVE,
	MFCC_WAVE}WAVE_TYPE;



void get_wave(WAVE_TYPE type,char* buf)
{
	int ret = -1;
	if(type == MFCC_WAVE)
	{
		ret = rivai_syscall(SYS_get_wave,(long)buf,(long)(490*4),0,0,0,0,0);
		for(int i = 0;i<490*4;i++)
		{
//			float* pdata = (float *)(buf+i*4);
//			printf("cnt %d data %f\n",i,*pdata);
			printf("i %d data %c\n",i,buf[i]);
		}
	}
}

char wavbuf[490*4] = {'a'};
float result[12];

int main (void) {
  int fd = 0;
  int ret = 0;
  char buf[256];


  //get_wave(MFCC_WAVE,wavbuf);
  int start_addr = (int)result;
  int elem_size = 4;
  int depth = 12;
  int mode = 2;

  result[0] = 0.01;
  result[1] = 0.02;
  result[2] = 0.03;
  result[3] = 0.04;
  result[4] = 0.05;
  result[5] = 0.06;
  result[6] = 0.07;
  result[7] = 0.08;
  result[8] = 0.09;
  result[9] = 0.80;
  result[10] = 0.11;
  result[11] = 0.12;
  result[12] = 0.13;

  printf("sizeof float %d\n",sizeof(float));
  while(1)
  { 
  	ret = rivai_syscall(SYS_get_wave,wavbuf,490*4,0,0,0,0,0);
	/*for(int i =0;i<490*4/10;i++)
	{
  		printf("col %d : %x %x %x %x %x %x %x %x %x %x\n",i,
			wavbuf[i+0],wavbuf[i+1],wavbuf[i+2],wavbuf[i+3],wavbuf[i+4],
			wavbuf[i+5],wavbuf[i+6],wavbuf[i+7],wavbuf[i+8],wavbuf[i+9]);
	}
	*/
  	rivai_syscall(SYS_return_values,start_addr,elem_size,depth,mode,0,0,0);
	for(int i =0;i<100000000;i++)
	{
		i = i+1;
		i=i-1;
	}
  }




  return 0;
}

