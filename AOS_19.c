#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char **argv[])
{
	if(argc!=2)
	{
		fprintf(stderr,"Usage : %s <filename>\n",argv[0]);
		return 1;
	}
	char *fn=argv[1];
	struct stat fs;
	if(stat(fn,&fs)==-1)
	{
		perror("Error getting filr status");
		return 1;
	}
	//Extract last access and modification time
	time_t access_time=fs.st_atime;
	time_t modify_time=fs.st_mtime;
	//convert times to human readable format
	char access_time_str[20];
	char modify_time_str[20];
	strftime(access_time_str,sizeof(access_time_str),"%Y-%m-%d %H:%M:%S",localtime(&access_time));
	strftime(modify_time_str,sizeof(modify_time_str),"%Y-%m-%d %H:%M:%S",localtime(&modify_time));
	//display the time
	printf("Last Access Time :: %s\n",access_time_str);
	printf("Last Modification Time :: %s\n",modify_time_str);
	return 0;
}
