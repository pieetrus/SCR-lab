#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>

int main()
{
   printf("Numer PID procesu: %d\n",getpid());

    struct timespec tim, tim2;

  tim.tv_sec=0;
  tim.tv_nsec=500000000L;

  int it=0;
  for(it=0;;++it)
    {
      nanosleep(&tim,&tim2);
	}
  return 0;
}
