#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef struct msgbuf
{
    long type;
    char text[1024];

} msgbuf;


int main(void)
{
	msgbuf my_msg_send, my_msg_recv;
	char buf[1024];
	int mid = msgget(45281, 0600 | IPC_CREAT );
    while(true)
    {
	fgets(buf, 1024, stdin);
        strcpy(my_msg_send.text, buf);
        my_msg_send.type = 6;

        int send = msgsnd(mid, &my_msg_send, strlen(my_msg_send.text)+1, 0);
        int recv = msgrcv(mid, &my_msg_recv, 1024, 6, 0);

        printf("Len: %d, wiadomosc: %s\n", recv, my_msg_recv.text);
    }
	return 0;
}
