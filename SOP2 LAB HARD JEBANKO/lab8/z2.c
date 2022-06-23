#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

struct liczby {
int liczba1;
int liczba2;
};

void* suma(void* arg)
{
	struct liczby* x = (struct liczby*) arg;
	int y = x->liczba1;
	y += x->liczba2;
	printf("Suma %d\n", y);
	return NULL;
}

void* roznica(void* arg)
{
        struct liczby* x = (struct liczby*) arg;
        int y = x->liczba1;
        y -= x->liczba2;
	printf("Różnica %d\n", y);
	return NULL;
}


int main(){

pthread_t watek1_id;
pthread_t watek2_id;

struct liczby liczby1;
struct liczby liczby2;

liczby1.liczba1 = 4;
liczby1.liczba2 = 5;

liczby2.liczba1 = 7;
liczby2.liczba2 = 6;

pthread_create (&watek1_id, NULL, &suma, &liczby1);
pthread_join(watek1_id, NULL);

pthread_create (&watek2_id, NULL, &roznica, &liczby2);
pthread_join(watek2_id, NULL);

return 0;
}
