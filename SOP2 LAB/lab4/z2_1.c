#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

int pdesk;
char buf[100];

mkfifo("/tmp/fifo", 0600);
mkfifo("/tmp/fifo", 0600);
puts("Zaczynasz rozmowe");
while(1)
{
char odc[100];
    pdesk=open("/tmp/fifo",O_WRONLY);
    if(pdesk==-1)
    {
        perror("otwarcie potoku do zapisu");
        exit(1);
    }
    fgets(buf, 100, stdin);
    puts("");
    if(write(pdesk, buf, 100)==-1)
    {
        perror("Zapis do potoku");
        exit(1);
    }
    close(pdesk);

    pdesk=open("/tmp/fifo2",O_RDONLY);

    if(pdesk==-1)
    {
        perror("otwarcie potoku do zapisu");
        exit(1);
    }
    if(read(pdesk, odc, 100)==-1)
    {
        perror("odczyt z potoku");
        exit(1);
    }
    printf("Wiadomosc: %s\nTwoja kolej na wiadomość:", odc);
    close(pdesk);
}
return 0;
}
