#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int mails = 0;

pthread_mutex_t mLock;

void* checkThreadCreation()
{
			
		pthread_mutex_lock(&mLock);
		for (int i =0; i<1000;i++)
		{
			mails++;
			usleep(1);

		}
		pthread_mutex_unlock(&mLock);

		sleep(10);
		printf("\n Thread Creation Starts... \n");
		sleep(1);
		printf("\n Threads are running Parallel... \n");
		sleep(2);
		printf("\n Threads are Terminating\n");
}

int main(int argc, char* argv)
{
	pthread_t tid[10];

	pthread_mutex_init(&mLock, NULL);
	for (int i = 0;i<5;i++)
	{
		if( pthread_create(&tid[i],NULL,checkThreadCreation,NULL) != 0)
				return 1;
	}

	for (int i = 0;i<5;i++)
	{
			if( pthread_join(tid[i],NULL) != 0)
			return 2;
	}
	
	pthread_mutex_destroy(&mLock);

	printf("\n mails :- %d\n",mails);
	return 0;
}
