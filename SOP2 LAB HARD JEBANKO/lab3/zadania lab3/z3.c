#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
int pdesk[2];
int pdesk2[2];
pipe(pdesk);
pipe(pdesk2);
int x=1;
while(x < 9)
{
if (fork() == 0)
{
	char buf [1];
	sprintf(buf, "%d", x+1);
	close(pdesk[0]);
	write(pdesk[1], buf, 1); 
	exit(0);
}
else
{
	if (fork() == 0)
	{
		char buf [1];
		sprintf(buf, "%d", x);
		close(pdesk2[0]);
        	write(pdesk2[1], buf, 1);
		exit(0);
	}
	else
	{
	sleep(2);
	        if (fork() == 0)
        	{
			close(pdesk[1]);
			close(pdesk2[1]);
			char p1 [1];
			char p2 [1];
		        read(pdesk[0], p1, 1);
			printf("Parzysta %s\n", p1);
			int s1 = atoi(p1);
			read(pdesk2[0], p2, 1);
			printf("Nieparzysta %s\n", p2);
			int suma = atoi(p2) + s1;
        		printf("Suma %d\n", suma);
			exit(0);
		}
	}

}
x = x + 2;
}
return(0);
}
