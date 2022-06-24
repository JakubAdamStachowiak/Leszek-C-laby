#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

static struct sembuf op_lock[1] = {0, -1, IPC_NOWAIT};

static struct sembuf op_unlock[1] = {0, 1, 0};

void blokuj(int semid)
{
if (semop(semid, &op_lock[0], 1)<0)
	perror("blad lokowania semafora");
}

void odblokuj(int semid)
{
if (semop(semid, &op_unlock[0], 1) < 0)
    perror("blad odlokowania semafora");
}


main()
{
int semid = -1; // identyfikator semafora
int co;
int jeszcze;
if  ((semid = semget(123, 1, IPC_CREAT | 0666 )) < 0)
    perror("blad tworzenia semafora");

printf("Podaj Polecenie\n 1 - podnies semafor\n 2 - opusc semafor\n 0 - wyjscie\n");    
for (jeszcze = 1;jeszcze;)
    {
    scanf("%d",&co);
    printf("wybrano %d\n",co);
    switch(co)
	{
	case 2:
	    {
	    printf("przed blokuj\n");
	    blokuj(semid);
	    printf("po blokuj\n");
	    break;
	    }
	case 1:
	    {
	    printf("przed odblokuj\n");
	    odblokuj(semid);
	    printf("po odblokuj\n");
	    break;
	    }
	case 0:
	    {
	    jeszcze = 0;
	    break;
	    }
	default:
	    {
	    printf("nie rozpoznana komenda %d\n",co);
	    }
	}
    }
}
