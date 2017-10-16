#include"program.h"

void *ThreadProc(void *arg)
{
	pthread_t tid;
	tid = pthread_self();
	
	printf("ThreadProc: Thread id = %ld\n",tid);	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret;
	
	ret = pthread_create(&thread, NULL, ThreadProc,NULL);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	pthread_join(thread, NULL);
	printf("Threads terminated.\n");
	
	pthread_exit(NULL);
	return 0;
}

