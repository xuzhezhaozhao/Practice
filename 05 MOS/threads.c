#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *printf_hello_world(void *tid)
{
	printf("Hello World, Greetings from thread %d\n", (int)(long)tid);
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;
	for (i = 0; i < NUMBER_OF_THREADS; i++) {
		printf("Main here, Creating thread %d\n", i);
		status = pthread_create(&threads[i], NULL, printf_hello_world, (void *)(long)i);

		if (0 != status) {
			printf("Oops, pthread_create returned error code %d\n", status);
			exit(-1);
		}
	}

	return 0;
}
