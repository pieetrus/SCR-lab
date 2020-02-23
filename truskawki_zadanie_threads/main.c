#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>


  typedef enum {TRUE = 1, FALSE = 0} bool;



int truskawka_na_krzaczku = 0;
int truskawka_w_koszyku = 0;

bool zebrana = 0;



pthread_mutex_t zbieracz_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t inspektor_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t maciej_mutex = PTHREAD_MUTEX_INITIALIZER;



//Funckja zwracająca błąd
void error(char* msg)
{
  fprintf(stderr,"%s:%s\n",msg,strerror(errno));
  exit(1);
}

  //wylosuje liczbe od 1 do 9
  //ta wartosc wpisywana jest do truskawka_na_krzaczkach
  // flaga zebrana =1
  //usleep 800ms

void* Zbieracz()
{
  while(1)
    {
      pthread_mutex_lock(&zbieracz_mutex);
      truskawka_na_krzaczku = rand()%9 + 1;
      zebrana = 1;
      pthread_mutex_unlock(&zbieracz_mutex);
      usleep(800 * 1000);
    }
  return NULL;
}



 //Jeśli truskawka jest zebrana
  //Czy truskawka na krzaczku > 6
  //tzn ze to dobra truskwaka
  //jesli tak to truskawka_w_koszyczku++;
  //printf dobra truskawa
  //else printf zla truskawa
  //usleep 300ms

  //zawsze flaga zebrana = 0

void* Inspektor()
{
  while(1)
    {
      pthread_mutex_lock(&inspektor_mutex);

      if(zebrana == 1)
	{
	  if(truskawka_na_krzaczku > 6)
	    {
	   
	      truskawka_w_koszyku++;
	      zebrana = 0;
	     
	      printf("Dobra truskawka!\n");
	    }
	  
	  else
	    {
	      zebrana = 0;
	      printf("Słabej jakości truskawka :(\n");
	    }
	}
      pthread_mutex_unlock(&inspektor_mutex);
      usleep(300 * 1000);
    }
  return NULL;
}



//Łasuch który je truskawki

  //Zje tylko jesli w koszyku >=5
  //truskawka_w_koszyku -= 5;
  //usleep 1500ms

  //Jesli zjadl truskawki to printf zjadlem

void* Maciej()
{
  while(1)
    {
      pthread_mutex_lock(&maciej_mutex);

      if(truskawka_w_koszyku >= 5)
	{
	  truskawka_w_koszyku -= 5;
	  printf("Maciej: Zjadalem Twoje truskawki!!!\n");
	}
      
      pthread_mutex_unlock(&maciej_mutex);
      
   
      usleep(1.5 * 1000);
    }

  return NULL;
}





int main()
{

  pthread_t zbieracz;
  pthread_t inspektor;
  pthread_t maciej;


  if(pthread_create(&zbieracz, NULL, Zbieracz, NULL) == -1)
    error("Nie można utworzyć wątku Zbieracza");
  if(pthread_create(&inspektor, NULL, Inspektor, NULL) == -1)
    error("Nie można utworzyć wątku Inspektora");
  if(pthread_create(&maciej, NULL, Maciej, NULL) == -1)
    error("Nie można utworzyć wątku Macieja");


  void* result;

  if(pthread_join(zbieracz,&result)==-1)
    error("Blad oczekiwania na zakonczenie watku Zbieracza");
  if(pthread_join(inspektor,&result)==-1)
    error("Blad oczekiwania na zakonczenie watku Inspektora");
  if(pthread_join(maciej,&result)==-1)
   error("Blad oczekiwania na zakonczenie watku Macieja");

}

