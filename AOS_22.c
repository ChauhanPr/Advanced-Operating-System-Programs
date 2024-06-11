#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/times.h>
#include<time.h>
int main(void)
{
	int i,status;
	pid_t pid;
	time_t currentTime;
	struct tms cputime;
	if((pid=fork())==-1)
	{
		perror("\nFork failed..");
		exit(EXIT_FAILURE);
	}
	else if(pid==0)
	{
		time(&currentTime);
		printf("\nChild process started at %s",ctime(&currentTime));
		for(i=0;i<5;i++)
		{
			printf("\nCounting:: %dn",i);
			sleep(1);
		}
		time(&currentTime);
		printf("\nChild process ended at %s",ctime(&currentTime));
		exit(EXIT_SUCCESS);
	}
	else
	{
		time(&currentTime);
		printf("Parent process started at %s ",ctime(&currentTime));
		if(wait(&status)==-1)
			perror("\nWait error");
		if(WIFEXITED(status))
			printf("Child process ended normally");
		else
			printf("Child process did not ended normally");
		if(times(&cputime)<0)
			perror("\nTime Error");
		else
		{
			printf("\nParent Process user time :: %fn",((double)cputime.tms_utime));
			printf("\nParent Process system time :: %fn",((double)cputime.tms_stime));
                        printf("\nChild Process user time :: %fn",((double)cputime.tms_cutime));
                        printf("\nChild Process system time :: %fn",((double)cputime.tms_cstime));
		}
		time(&currentTime);
		printf("\nParent Process end at %s ",ctime(&currentTime));
		exit(EXIT_SUCCESS);
	}
}

