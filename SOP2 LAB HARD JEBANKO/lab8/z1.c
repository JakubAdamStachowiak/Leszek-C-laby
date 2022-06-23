#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>



void* show_id()
{
	printf("ID procesu %d, ID wątku %ld\n", getpid(), pthread_self());
	return NULL;
}


int main(){

    pthread_t watek1_id;
    pthread_t watek2_id;


    pthread_create (&watek1_id, NULL, &show_id,NULL);
    pthread_create (&watek2_id, NULL, &show_id, NULL);

    pthread_join(watek1_id, NULL);
    pthread_join(watek2_id, NULL);

    return 0;
}
