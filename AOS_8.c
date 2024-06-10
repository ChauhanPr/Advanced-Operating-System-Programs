#include<stdio.h>
#include<unistd.h>
int main()
{
	int fds[2];
	int returnstatus;
	char writemsgs[3][20]={"Hello World","Hello SPPU","Linux is funny"};
	char readmsg[20];
	returnstatus=pipe(fds);
	if(returnstatus==-1)
	{
		printf("Unable to create pipe..\n");
		return 1;
	}
	int child=fork();
	if(child==0)
	{
		printf("Child is writing to pipe - Message1 is %s\n",writemsgs[0]);
		write(fds[1],writemsgs[0],sizeof(writemsgs[0]));
		printf("Child is writing to pipe - Message2 is %s\n",writemsgs[1]);
		write(fds[1],writemsgs[1],sizeof(writemsgs[1]));
		printf("Child is writing to pipe - Message3 is %s\n",writemsgs[2]);
		write(fds[1],writemsgs[2],sizeof(writemsgs[2]));
	}
	else
	{
		read(fds[0],readmsg,sizeof(readmsg));
		printf("Parent process is reading from pipe - Message1 is %s\n",readmsg);
		read(fds[0],readmsg,sizeof(readmsg));
		printf("Parent process is reading from pipe - Message2 is %s\n",readmsg);
		read(fds[0],readmsg,sizeof(readmsg));
		printf("Parent process is reading from pipe - Message3 is %s\n",readmsg);
	}
}
