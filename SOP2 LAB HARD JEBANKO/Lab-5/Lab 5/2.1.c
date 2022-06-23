#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct msgbuf
{
    long type;
    char text[1024];

} msgbuf;


int main(void)
{
	int del = msgget(45281, 0600 | IPC_CREAT );
	msgctl(del, IPC_RMID, NULL);
	msgbuf my_msg_send, my_msg_recv;
	int mid = msgget(45281, 0600 | IPC_CREAT );
	int start = 1;
	while(1)
	{
	char hello[1024];
	if(start==1)
	{
	strcpy(hello, "-");
	}
	int recv = msgrcv(mid, &my_msg_recv, 1024, 6, 0);
	if(strcmp(my_msg_recv.text,"-")!=1 || start==1)
	{
	start = 0;
	strcpy(hello, my_msg_recv.text);
	int i;
	for(i=0; hello[i]!='\0';i++)
	{
		if(hello[i]>='a' && hello[i]<='z')
		{
		hello[i] -= 32;
		}
	}
	strcpy(my_msg_send.text, hello);
	my_msg_send.type = 6;

	int send = msgsnd(mid, &my_msg_send, strlen(my_msg_send.text)+1, 0);
	}

    }

	return 0;
}
