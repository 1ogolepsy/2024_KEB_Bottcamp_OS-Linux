#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREADS 3

void runner(void *param){
	printf("Thread runner\n");
	pthread_exit(0);
}

int main(){
	int i, policy;
	pthread_t tid[NUM_THREADS];
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	if(pthread_attr_getschedpolicy(&attr, &policy) != 0)
		fprintf(stderr, "Unable to get policy\n");
	else{
		if(policy == SCHED_OTHER)
			printf("SCHED_OTHER\n");
		else if(policy == SCHED_RR)
			printf("SCHED_RR\n");
		else if(policy == SCHED_FIFO)
			printf("SCHED_FIFO\n");
	}
	if(pthread_attr_setschedpolicy(&attr, SCHED_RR) != 0)
		fprintf(stderr, "Unable to set policy\n");

	if(pthread_attr_getschedpolicy(&attr, &policy) != 0)
		fprintf(stderr, "Unable to get policy\n");
	else{
		if(policy == SCHED_RR)
		printf("RR SET SUCCESS!\n");
		else
			printf("RR SET FAIL \n");
	}

	for(i = 0; i < NUM_THREADS; i++){
		pthread_create(&tid[i], &attr, runner, NULL);
	}
	for(i =0; i < NUM_THREADS; i++){
		pthread_join(tid[i], NULL);
	}
	return 0;
}

