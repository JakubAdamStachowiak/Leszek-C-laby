#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "sem.c"


main (){
int semid, i;
int *buf;

semid = semget(45281, 2, IPC_CREAT|0600);

semctl(semid, 0, SETVAL, (int)1);

semctl(semid, 1, SETVAL, (int)1);

char dziecko[8] = "abcdefgh";
char parent[8] = "ABCDEFGH";
if(fork()==0)
{
for(int i = 0; i<8; i++)
printf("%c", dziecko[i]);
}
else
{
for(int i = 0; i<8; i++)
printf("%c", parent[i]);
}
}


