#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>



struct sembuf buf1 = { 0, -1, SEM_UNDO};
struct sembuf buf2  = { 0, +1, SEM_UNDO};
struct sembuf buf3 = { 1, -1, SEM_UNDO};
struct sembuf buf4  = { 1, +1, SEM_UNDO};

int main()
{
    int semid = semget(45281, 2, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 0);
    semctl(semid, 1, SETVAL, 1);
    for(int i = 0; i < 5; ++i)
    {
    semop(semid, &buf3, 1);
    printf("%s\n", "produkuje");
    fflush(stdout);
    sleep(2);
    semop(semid, &buf2, 1);
    }
}
