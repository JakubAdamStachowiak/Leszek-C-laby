#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 3

int main(void)
{
	int shmid,i;
	char *buf;
	shmid = shmget(45281, MAX*sizeof(char), IPC_CREAT|0600);

	buf = (char*)shmat(shmid, NULL, 0);
	if(buf == NULL)
	{
		printf("Error łączenia");
		exit(1);
	}
	printf("Start\n");
	for(;;)
	{	
		sleep(1);
		if(strcmp(buf, "hoooo")||strcmp(buf, "haaaa"))
		{
		printf("Wiadomość: %s\n", buf);
		}
		else
		{
                printf("Błędna wiadomość! Jej wartość: %s\n", buf);
		}

	}
return 0;
}
