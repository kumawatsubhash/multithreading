#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* checkThreadCreation()
{
		printf("\n Thread Creation Starts... \n");
		sleep(1);
		printf("\n Threads are running Parallel... \n");
		sleep(2);
		printf("\n Threads are Terminating\n");
}

int main(int argc, char* argv)
{
	pthread_t tid1, tid2;

	if( pthread_create(&tid1,NULL,checkThreadCreation,NULL) != 0)
			return 1;
	if( pthread_create(&tid2,NULL,checkThreadCreation,NULL) != 0)
			return 2;

	if( pthread_join(tid1,NULL) != 0)
			return 3;
	if( pthread_join(tid2,NULL) != 0)
			return 4;

	return 0;
}
