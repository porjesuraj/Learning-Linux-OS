#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MQ_KEY	0x4321
#define MSG_LEN	32

struct my_data {
	long type;
	char str[MSG_LEN];
};

int main() {
	int mqid, ret, s;

	// create message queue
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if(mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child -- sender
		struct my_data m1;
		m1.type = 123;
		printf("child: enter a string: ");
		scanf("%s", m1.str);
		printf("child: sending message ...\n");
		// send message in message queue (with type=123).
		msgsnd(mqid, &m1, MSG_LEN, 0);
	}
	else {
		// parent -- receiver
		struct my_data m2;
		printf("parent: waiting for child message.\n");
		// receive message from message queue (with type=123).
		msgrcv(mqid, &m2, MSG_LEN, 123, 0);
		printf("parent: received %s \n", m2.str);

		wait(&s);

		// delete message queue
		msgctl(mqid, IPC_RMID, NULL);
	}
	return 0;
}



            
