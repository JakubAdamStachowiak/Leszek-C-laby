#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 3

int main()
{
        int shmid,i;
        char *buf;
        shmid = shmget(45281, MAX*sizeof(char), IPC_CREAT|0600);

	if(shmid == -1)
	{
		printf("Error segmentu");
		exit(1);
	}
	
        buf = (char*)shmat(shmid, NULL, 0);
        


	if(buf == NULL)
        {
                printf("Error łączenia");
                exit(1);
        }

	i=1;
	printf("Start\n");
	for(;;)
	{
		sleep(1);
		if(i==1)
		{
		buf[0] = 'h';
		buf[1] = 'o';
		buf[2] = 'o';
                buf[3] = 'o';
                buf[4] = 'o';
		i=0;
		}
		else
		{
		buf[0] = 'h';
                buf[1] = 'a';
                buf[2] = 'a';
                buf[3] = 'a';
                buf[4] = 'a';
		i=1;
		}
	printf("Wysłano \n");
	fflush(stdout);
	}
}


