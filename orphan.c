#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int amin(){
	pid_t childPid;
	int i;
	childPid = fork();
	if(childPid > 0){
		printf("parents pid : %d\n", getpid());
		sleep(2);
		printf("parents done\n");
		exit(0);
	}
	else if(childPid == 0){
		printf("child\n");
		for(i = 0; i < 10; i++){
			printf("child pid : %d, qnah pid : %d\n", getpid(), getppid());
			sleep(1);
		}
		printf("child done\n");
		exit(0);
	}
	else{
		return -1;
	}
	return 0;
}
