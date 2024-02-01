#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t childPid;
	childPid = fork();

	if(childPid > 0) { 
		printf("parents pid : %d\n", getpid());
		sleep(30);
		printf("parents done\n");
		exit(0);
	}
	else if(childPid == 0){
		printf("child\n");
		sleep(1);
		printf("shild done\n");
		exit(0);
	}
	else{
		perror("fork Fail!\n");
		return -1;
	}
	return 0;
}
