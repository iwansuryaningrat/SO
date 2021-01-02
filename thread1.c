#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
// we must make the compiler aware that this program
// is to use threads so the thread safe libraries must be used.
// To do this we define the _REENTERANT flag
#define _REENTRANT
//next we create a simple function for out thread
void *ThreadRoutine(int number){
	while(1){ // loop forever
		printf("pid %d : thread %d running\n",getpid(), number);
		sleep(number); // sleep for a time passed as a parameter
	}
}

int main(void){
	int t;
	pthread_t tid[5]; // an array to keep track of the threads

	// now loop through and create 4 threads passing t as the parameter
	for (t=1; t<5; t++)
		pthread_create(&tid[t],NULL,(void *)ThreadRoutine, &t);

	// now the parent loops and sleeps for 10
	while(1){
		printf("pid %d : parent running\n", getpid());
		sleep(10);
	}

	exit(1);
}