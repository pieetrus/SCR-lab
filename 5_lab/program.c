#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
  pid_t pid;
  int mypipefd[2]; //deskryptory potoku 0 - czytanie, 1 - pisanie
  char fileName[30];
  int deskryptor,licznik;
  char buff[300];



  if(pipe(mypipefd) == -1) //potok nie zostal utworzony
    {
      perror ("pipe");
      exit(1);
    }

  pid = fork(); //tworzenie procesu


  if(pid == 0) //podproces - potomek
    {

      printf("Proces dziecko \n");
      close(0); //zamyka stdin do potoku
      close(mypipefd[1]); //zamykam zapisywanie do potoku
      dup(mypipefd[0]); //duplikuje deskryptor do czytania z potoku
      // close(mypipefd[0]);
      execlp("display","",NULL); //wyswietlenie obrazka
      exit(0);
    }
  else if(pid > 0) //proces nadrzedny
    {
       close(mypipefd[0]); //zamykam czytanie z potoku
      printf("Proces nadrzedny o PiD = %d\n",pid);
      usleep(1000); //zawieszam wykonanie na 1ms
      printf("Podaj nazwe pliku z obrazkiem:\n ");
      scanf("%s", fileName);

      deskryptor = open(fileName, O_RDONLY);

      while((licznik = read(deskryptor, buff, 300)) > 0)
	write(mypipefd[1], buff, licznik);      

       close(mypipefd[1]);

       // sleep(1000);
       /* proces potomny zacznie wyswietlac obrazek dopiero
	  gdy proces nadrzedny zamknie potok
	  mozna to sprawdzic tym sleepem tutaj

       */


    }

  else
    {
      printf("Nie utworzono procesu potomnego\n");
      exit(1);
    }
  


  }
