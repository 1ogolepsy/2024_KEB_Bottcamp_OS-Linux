#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>

sem_t semaphore;
int num = 1;

void *threadF1(void *arg){
	int i;
	if(num != 0){
		num--;
		sem_wait(&semaphore);
		printf("thread 1 start using toilet. \n");

		for(i=0;i<1000000;i++){}

		printf("thread1 using toilet is done \n");
		num++;
		sem_post(&semaphore);
	}
	else if(num == 0){
		printf("toilet is pull, thread 1 is waiting. \n");

		while(num == 0){}
		num--;
		sem_wait(&semaphore);
		printf("thread1 is used toliet and done \n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void *threadF2(void *arg){
	int i;
	if(num != 0){
		num--;
		sem_wait(&semaphore);
		printf("thread2 start using toilet\n");
	
		for(i=0;i<1000000;i++){}

		printf("thread2 using toilet is done\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num == 0){
		printf("toilet is pull, thread2 is waiting\n");

		while(num == 0){}
		num--;
		sem_wait(&semaphore);
		printf("thread2 is used toilet, and done \n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void *threadF3(void *arg){
	int i;
	if(num != 0){
		num--;
		sem_wait(&semaphore);
		printf("thread3 start using toilet\n");
	
		for(i=0;i<1000000;i++){}
	
		printf("thread3 using toilet is done\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num ==0){
		printf("toilet is pull, thread3 is waiting\n");

		while(num == 0){}
		num--;
		sem_wait(&semaphore);
		printf("thread3 is used toilet and done \n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

int main(){
	pthread_t thread1, thread2, thread3;

	sem_init(&semaphore, 0, num);

	printf("Semaphore test Start\n");

	pthread_create(&thread1, NULL, threadF1, NULL);
	pthread_create(&thread2, NULL, threadF2, NULL);
	pthread_create(&thread3, NULL, threadF3, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("all thread using toilet are done\n");

	sem_destroy(&semaphore);

	return 0;
}

