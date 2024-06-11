#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define buffsize 10000
int main()
{
	char sour[25],dest[25],buff[buffsize];	
	ssize_t read_in,write_out;
	printf("\nEnter source file name::");
	scanf("%s",&sour);
	printf("\nSource file::%s",sour);
	int sourcefiledesc=open(sour,O_RDONLY);
	if(sourcefiledesc < 0)
	{
		printf("\nSource file is not exits.");
	}
	else
	{
		printf("\nEnter destination file name::");
		scanf("%s",&dest);
		int destfiledesc=open(dest,O_WRONLY | O_CREAT);
		while((read_in=read(sourcefiledesc,&buff,buffsize)) > 0)
		{
			write_out=write(destfiledesc,&buff,read_in);
		}
		if(remove(sourcefiledesc)==0)
			printf("\nFile deleted successfully.");
		else
			printf("\nUnable to delete the file.");
		close(sourcefiledesc);
		close(destfiledesc);
	}
	return 0;
}

