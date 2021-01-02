#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _REENTRANT
//next we create a simple function for out thread

void *ThreadRoutine(int number){
	printf("thread %d running\n",number);
	sleep(number); // sleep for a time passed as a parameter
	printf("thread %d finish, joining... \n",number);
}

int main(void){
	int t;
	pthread_t tid; // an array to keep track of the threads

	// now loop through and create 4 threads passing t as the parameter
	for (t=1; t<5; t++)
		pthread_create(&tid,NULL,(void *)ThreadRoutine,(int *)t);

	// now the calling process waits for the thread to finish
	pthread_join(tid,NULL);
	printf("All kids joined, parent running\n");

	exit(1);
}