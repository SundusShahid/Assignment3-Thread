#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int val[1000];
void *TestThread(void *arg)
{
	int start=(int)arg;
	int end=start+100;
	int sum=0;
	for(int i=start;i<end;i++)
	{

		sum=sum+val[i];
	}

	return ((void*)sum);

}

int main()
{
	
	int status_t[10];
	pthread_t threadsArray[10];
	int value=0;

	for(int z=0;z<1000;z++)	
	{
		val[z]=z;

	}

	for(int i=0;i<10;i++)
	{
		pthread_create(&threadsArray[i], NULL, TestThread,(void*)(value));
		value=value+100;
	}	
	
	for(int j=0;j<10;j++)
	{	
		pthread_join(threadsArray[j],(void**)& status_t[j]);
	}
	int sum=0;
	for(int k=0;k<10;k++)
	{
		sum=sum+status_t[k];
	}
	printf("\nValue returned by thread %d\n",sum);
return 0;


}

