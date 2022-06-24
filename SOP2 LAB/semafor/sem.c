#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

static struct sembuf buf;

void podnies(int semid, int semnum){
buf.sem_num = semnum;
buf.sem_op = 1;
buf.sem_flg = 0;
if (semop(semid, &buf, -1))
{
perror("Podnoszenie semafora");
exit(1);
}
}

void opusc(int semid, int semnum){
buf.sem_num = semnum;
buf.sem_op = -1;
buf.sem_flg = 0;
if (semop(semid, &buf, -1))
{
perror("Opuszczenie semafora");
exit(1);
}
}
