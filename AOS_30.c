#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void child_process_handler(int signum)
{
	switch(signum)
	{
		case SIGHUP:
			printf("\nChild: I have recevied SIGHUP");
			break;
		case SIGINT:
                        printf("\nChild: I have recevied SIGINT");
                        break;
		case SIGQUIT:
			printf("\nMy papa has killed me!!!\n");
			exit(0);
			break;
		default:
			printf("\nChild: Recevied Unexpected signal");
	}
}
int main()
{
	pid_t pid;
	int i;
	pid=fork();
	if(pid<0)
	{
		perror("Fork Failed");
		exit(1);
	}
	if(pid==0)
	{
		signal(SIGHUP,child_process_handler);
		signal(SIGINT,child_process_handler);
		signal(SIGQUIT,child_process_handler);

		while(1)
		{
			sleep(1);
		}
	}
	else 
	{
		for(i=1;i<=5;i++)
		{
			sleep(3);
			if(i%2==0)
			{
				printf("\nParent: sending SIGHUP signal");
				kill(pid,SIGHUP);
		  	}
			else
			{
				printf("\nParent: sending SIGINT signal");
				kill(pid,SIGINT);
			}
		}
		sleep(3);
		printf("\nParent: sending SIGQUIT signal to terminate child");	
		kill(pid,SIGQUIT);
	}
	return 0;
}

	

			
