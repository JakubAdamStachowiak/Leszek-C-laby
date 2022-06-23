#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
int pdesk[2];
int wyjscie;

pipe(pdesk);
if(fork()==0)
{
	close(pdesk[0]);
	dup2(pdesk[1], 1);
	execlp("cat", "cat", "/etc/group", NULL);
}
else
{
	close(pdesk[1]);
	dup2(pdesk[0], 0);
	wyjscie=open("grupy.txt", O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR);
	dup2(wyjscie, 1);
	execlp("head", "head", "-5", NULL);
}
exit(0);
}
