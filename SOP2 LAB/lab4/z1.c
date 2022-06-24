#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
int wyjscie;
int pdesk;
mkfifo("/tmp/fifo", 0600);
switch(fork())
{
case -1:
perror("otwarcie procesu");
exit(1);

case 0:
close(1);
pdesk=open("/tmp/fifo", O_WRONLY);
if(pdesk==-1)
{
	perror("otwarcie potoku do zapisu");
	exit(1);
}
else if(pdesk!=1)
{
	fprintf(stderr, "Niewlasciwy deskryptor do zapisu\n");
	exit(1);
}
execvp("ls", argv);
perror("Uruchomienie programu");
exit(1);


default:
{
	close(0);
	pdesk=open("/tmp/fifo", O_RDONLY);
	if(pdesk==-1)
{
	perror("otwarcie potoku do odczytu");
	exit(1);
}
else if(pdesk!=0)
{
	fprintf(stderr, "niewlasciwy deskryptor pliku do odczytu");
	exit(1);
}


execlp("tr","tr","a-z","A-Z",NULL);
perror("uruchomienie programu");
exit(1);
}
}
exit(0);
}
