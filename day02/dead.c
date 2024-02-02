#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t semaphore[3];

void *threadRoutine(void *argumentPointer){
	long id = (long)argumentPointer;
	int i;
	for(i=0;i<10000;i++){
		printf("sem_wait_%ld is tried\n", id);
		sem_wait(&semaphore[id]);
		printf("sem_wait_%ld success!\n", id);

		printf("sem_wait_%ld is tried\n", 1-id);
		sem_wait(&semaphore[1-id]);
		printf("sem_wait_%ld success!\n", 1-id);

		printf("sem_wait_%ld is tried\n", id);
		sem_wait(&semaphore[id]);
		printf("sem_wait_%ld is success!\n", id);

		printf("sem_wait_%ld is tried\n", 1 - id);
		sem_wait(&semaphore[1-id]);
		printf("sem_wait_%ld success!\n", 1-id);
	}
	return NULL;
}

int main(){
	pthread_t threadDs[3];

	sem_init(&semaphore[0], 0, 1);
	sem_init(&semaphore[1], 0, 1);

	pthread_create(&threadDs[0], NULL, threadRoutine, (void*)0);
	pthread_create(&threadDs[1], NULL, threadRoutine, (void*)0);

	pthread_join(threadDs[0], NULL);
	pthread_join(threadDs[1], NULL);

	printf("No Deadlock!\n");
	return 0;
}

