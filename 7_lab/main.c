#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>





int main()
{

	char nazwaObrazu[100];
	


	if(fork()==0)
	{
		sleep(4);
		execlp("display", "display", "-update", "1", "obrazek.jpg", NULL);

	}
	
	while(1)
	{
		printf("Podaj nazwe obrazu: ");
		scanf("%s", nazwaObrazu);

	int fd;
	int fdOdwz; 
		
	fd=open(nazwaObrazu, O_RDWR);
	
	fdOdwz = open("obrazek.jpg", O_RDWR | O_CREAT, S_IWUSR | S_IRUSR);

	struct stat danePliku;

	fstat(fd, &danePliku);

	//Obcinam plik
	truncate("obrazek.jpg", danePliku.st_size);


	char * adrMap;

	//mapowanie
	adrMap = mmap( NULL , danePliku.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdOdwz, 0 ); 

	read(fd, adrMap, danePliku.st_size);
	
	//synchronizuje plik z mapa pamieci
	msync( adrMap, danePliku.st_size, MS_SYNC);

	munmap( adrMap, danePliku.st_size);

	
	close(fd);
	close(fdOdwz);
	


	}


	return 0;
}
