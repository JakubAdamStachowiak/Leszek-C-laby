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
if (fork() == 0)
{
	close(pdesk[0]);
	write(pdesk[1], "dzien ", 6);
	exit(0);
}
else
{
	if (fork() == 0)
	{
		close(pdesk2[0]);
        	write(pdesk2[1], "dobry", 6);
		exit(0);
	}
	else
	{
	        if (fork() == 0)
        	{
			close(pdesk[1]);
			close(pdesk2[1]);
			char p1 [6];
			char p2 [6];
		        read(pdesk[0], p1, 6);
			read(pdesk2[0], p2, 6);
        		printf("Odczytanie z potoku  %s\n", p1);
			exit(0);
		}
	}

}
return(0);
}

