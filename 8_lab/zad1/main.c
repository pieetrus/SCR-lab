#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void * printHello(void * IDwatku)
{
    int ID = (int) IDwatku;

    printf("hello world from thread %d!\n", ID);
		 
    pthread_exit(NULL);
		    
}
 
int main()
{
	pthread_t watki[5];
	     
	int i,j;
	for(i=0; i<5; i++)
	{
		if(pthread_create(watki+i, NULL, printHello,(void *) i))
		{
			puts("Cos nie tak!");	
		}
	}		     
	
	pthread_exit(NULL);
			 
	return 0;
}
