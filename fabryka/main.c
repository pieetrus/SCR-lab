#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>



pthread_mutex_t belka_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t deska_mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t licznik_mutex = PTHREAD_MUTEX_INITIALIZER;


int belka = 100;
int deska = 0;
//int licznik = 3000000;




//void* wykonaj1(void* a)
//{
//  int i;
//  pthread_mutex_lock(&licznik_mutex);
//  for(i=0;i<1000000;i++)
//    licznik = licznik -1;
//  pthread_mutex_unlock(&licznik_mutex);
//  return NULL;
//}

void error(char *msg)
{
  fprintf(stderr, "%s:%s\n",msg, strerror(errno));
  exit(1);
}



void* drwal()
{

  while(1)
    {
  pthread_mutex_lock(&belka_mutex);
  belka+= 5;
  pthread_mutex_unlock(&belka_mutex);
  printf("Drwal: Wyprodukowalem %d belek\n", belka);

  usleep(1 * 1000000);

    }

  return NULL;
}



void* tracz(int liczba)
{

  while(1)
    {
  pthread_mutex_lock(&deska_mutex);
  belka-= liczba;
  pthread_mutex_unlock(&deska_mutex);


  pthread_mutex_lock(&deska_mutex);
  deska += 1;
  pthread_mutex_unlock(&deska_mutex);

  printf("Tracz: Wyprodukowalem %d desek\n", deska);

  usleep(1.5 * 1000000);

    }

  return NULL;
}



int main()
{

  //  pthread_t t0;
  // pthread_t t1;

  pthread_t drwal_thread;
  pthread_t tartak_thread;



  // if(pthread_create(&t0,NULL,wykonaj1,NULL)==-1)
  //  error("Nie mozna utworzyc watku t0");
  // if(pthread_create(&t1,NULL,wykonaj1,NULL)==-1)
  //  error("Nie mozna utworzyc watku t1");
   


  // void* result;
  // if(pthread_join(t0,&result)==-1)
  //  error("Blad oczekiwania na zakonczenie watku t0");
  // if(pthread_join(t1,&result)==-1)
  //  error("Blad oczekiwania na zakonczenie watku t0");
 
  //  printf("licznk na koniec ma wartosc = %i ", licznik);

  
    pthread_create(&drwal_thread, NULL, drwal, NULL);
    pthread_create(&tartak_thread, NULL, tracz(10), NULL);
  

   void* result;

   pthread_join(drwal_thread, &result);
   pthread_join(tartak_thread, &result);


}
