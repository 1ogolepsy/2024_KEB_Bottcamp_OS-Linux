#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int shmid;
	char *shmptr1, *shmptr2;
	int i;

	shmid = shmget(IPC_PRIVATE, 10*sizeof(char), IPC_CREAT|0666);
	if(shmid == -1){
		printf("shmget failed\n");
		exit(0);
	}

	if(fork() == 0){
		shmptr1 = (char *) shmat(shmid, NULL, 0);
		for(i=0; i < 10; i++)
			shmptr1[i] = i*10;
		shmdt(shmptr1);
		exit(0);
	}
	else{
		wait(NULL);
		shmptr2 = (char *) shmat(shmid, NULL, 0);
		for(i=0; i<10; i++)
			printf("%d\n", shmptr2[i]);
		shmdt(shmptr2);
		if(shmctl(shmid,IPC_RMID,NULL)==-1)
			printf("shmct1 failed\n");
	}
	return 0;
}
