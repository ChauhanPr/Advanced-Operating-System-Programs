#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
char b1[]="Welcom";
char b2[]="Computer Science";
int main(void)
{
	int fd;
	if((fd=creat("file_with_hole.txt",0777))<0)
	{
		printf("create error");
	}
	if(write(fd,b1,7)!=7)
		printf("b1 write erroe");
	lseek(fd,100,SEEK_CUR);
	if(write(fd,b2,16)!=16)
		printf("b2 write error");
	exit(0);
}
