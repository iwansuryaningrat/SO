#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define _REENTRANT
//next we create a simple function for out thread

void *ThreadRoutine(int number){
	int i;
	for (i=0; i<10; i++){ //loop to give the thread something to do
		printf("thread %d running %d\n",number,i);
		sleep(number); // sleep for a time passed as a parameter
	}
}

int main(void){
	pthread_t tid1,tid2; // create 2 thread id’s

	//now create two threads
	pthread_create(&tid1,NULL,(void *)ThreadRoutine,(int *)1);
	pthread_create(&tid2,NULL,(void *)ThreadRoutine,(int *)2);
	pthread_detach(tid2); //we will now detach thread 1
	
	if(pthread_join(tid1,NULL)>0) // now try to join it
		printf("unable to join thread 1\n");
	if(pthread_join(tid2,NULL)>0) // and now join thread 2
		printf("unable to join thread 2\n");
	
	printf("parent finished\n");

	exit(1);
}