#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>

bool flaga=true;
int counter=0;

void sigAlarmHandler(int sig)
{
  printf("Otrzymany sygnał %d, NA RAZIE!\n ",sig);
  exit(1);
}

void sigTermHandler(int sig)
{
  printf("Otrzymaliśmy sygnał %d . Kontynuujemy pracę!\n",sig);
}

void sigUsr1Handler(int sig)
{
  flaga=false;
  counter=100;
  printf("Otrzymano %d, zaczęto ignorować sygnały!\n",sig);
}

int main()
{
   printf("Numer PID procesu: %d\n",getpid());

  
  signal(SIGUSR2,SIG_IGN); // Ignorowanie sygnału
  struct timespec tim, tim2;

  tim.tv_sec=0;
  tim.tv_nsec=500000000L;

  int it=0;
  for(it=0;;++it)
    {
      // sleep(1);
      nanosleep(&tim,&tim2);
      if(flaga)
	{
	  //Ignorowanie sygnałów
	  signal(SIGALRM, sigAlarmHandler);
	  signal(SIGTERM, sigTermHandler);
	  signal(SIGUSR1, sigUsr1Handler);
	}
      else
	{
	  while(--counter)
	    {
	      signal(SIGALRM, SIG_IGN);
	      signal(SIGTERM, SIG_IGN);
	      signal(SIGUSR1, SIG_IGN);
	      //sleep(1);
	      nanosleep(&tim,&tim2);
	    }
	  flaga=true;
	}
    }
  return 0;
}
