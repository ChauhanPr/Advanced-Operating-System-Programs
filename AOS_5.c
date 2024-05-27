#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
	int n1,n2,sum=0;
	int input_fds=open("./input.txt",O_RDONLY);
	if(dup2(input_fds,STDIN_FILENO)<0)
	{
		printf("Unable to duplicate the file description");
		exit(EXIT_FAILURE);

		
	}
	scanf("%d %d",&n1,&n2);
	sum=n1+n2;
	printf("%d + %d = %d",n1,n2,sum);
	return EXIT_SUCCESS;
}

