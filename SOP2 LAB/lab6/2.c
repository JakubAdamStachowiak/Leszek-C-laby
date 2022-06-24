#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 10

main()
{
	int shmid, i;
	int *buf;
	shmid=shmget(45281, MAX*sizeof(int), IPC_CREAT|0600);

	if(shmid == -1)
	{
		perror("Utworzenie segmentu pamieci wspoldzielonej");
		exit(1);
	}

	buf = (int*)shmat(shmid, NULL, 0);
	if(buf == NULL)
	{
		perror("Przylaczenie segmentu pamieci wspoldzielonej");
		exit(1);
	}
	i=1;
	while(i>0)
	{
		printf("Wartosc: %5d\n", buf[1]);
        	if (buf[1]!=0 && buf[1]!=1){
        		perror("Bledna wartosc w buforze");
			exit(1);
		}
		sleep(1);
	}
}
