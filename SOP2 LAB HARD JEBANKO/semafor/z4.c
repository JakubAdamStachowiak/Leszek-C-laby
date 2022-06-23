#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "sem.c"



struct sembuf x1 = { 0, -1, SEM_UNDO};
struct sembuf x2  = { 0, +1, SEM_UNDO};
struct sembuf x3 = { 1, -1, SEM_UNDO};
struct sembuf x4  = { 1, +1, SEM_UNDO};

int main()
{
    int semid = semget(45281, 2, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 0);
    semctl(semid, 1, SETVAL, 1);

    if(fork()==0)
    {
        char child[8] = "ABCDEFGH";
        for(int i = 0; i < 8; ++i)
        {
            semop(semid, &x1, 1);
            printf("%c", child[i]);
            fflush(stdout);
            semop(semid, &x4, 1);
        }
    }
    else
    {
        char parent[8] = "abcdefgh";
        for(int i = 0; i < 8; ++i)
        {
            semop(semid, &x3, 1);
            printf("%c", parent[i]);
            fflush(stdout);
            semop(semid, &x2, 1);
        }
    }
}
