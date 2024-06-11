#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"fork failed");
		return 1;
	}
	else if(pid==0)
	{
		printf("Child process running\n");
		sleep(2);
		int exit_status=rand()%100;
		printf("Child process exiting with status :: %d\n",exit_status);
		exit(exit_status);
	}
	else
	{
		printf("Parent process waiting for chile is to terminated \n");
		waitpid(pid,&status,0);
		if(WIFEXITED(status))
		{
			printf("Childe process is exited with status :: %d\n",WEXITSTATUS(status));
		}
		else
		{
			printf("Child process exited abnormally\n");
		}
	}
}

