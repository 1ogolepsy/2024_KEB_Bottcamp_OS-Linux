#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

void *threadRoutine(void* arg){
	long argument;
	argument = *((long *)arg);
	return (void*)(argument*10);
}

int main(){
	pthread_t threadID;
	printf("Create thread!\n");
	long argument = 100;
	int status;
	void *value;

	status = pthread_create(&threadID, NULL, threadRoutine, (void*)&argument);

	printf("Main Thread is now waiting for Thread!\n");

	pthread_join(threadID, &value);

	printf("Return value (0: success) :: %d\n");
	printf("receive value :: %ld\n", (long)value);

	return 0;
}
