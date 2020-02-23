#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
 

int main(){

int potok_fd;
int deskryptor;
int licznik;             
 char bufor[20];        
			                   
char nazwaPliku[100];     
char *FIFO = "./potok";


mkfifo(FIFO, 0666);
 printf("Utworzylem potok!!!\n");

 while(1)
{
  potok_fd = open(FIFO, O_WRONLY); //otwieram potok
						       
printf("Plik do odczytu: ");
scanf("%s", nazwaPliku);
deskryptor = open(nazwaPliku, O_RDONLY);
								   
	while ((licznik=read(deskryptor, bufor, 20)) > 0)
	{
	      	write(potok_fd, bufor, licznik);
       	}
								
	close(potok_fd); //zamykam potok

}
	return 0;
}
