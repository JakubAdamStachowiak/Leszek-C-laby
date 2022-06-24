#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char *argv[]){
    int x,y;
    for(int i=1;i<argc;i++){
        x=atoi(argv[i]);
        y=semget(x,1,0);
        if(y==-1){
            printf("\nbłedny klucz semafora (%d) \n",x);
        }
        else{
            semctl(y,1,IPC_RMID);
            printf("Usunieto semafor %d", x);
        }

    }

}