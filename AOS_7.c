#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char **argv[])
{
	int file=0;
	struct stat info;
	if(argc !=2)
	{
		printf("Enter file name::");
	}
	if((file=open(argv[1],O_RDONLY))<-1)
		return 1;
	if(fstat(file,&info) < 0)
	{
		return 1;
	}
	printf("Information for %s\n",argv[1]);
	printf("File inode number :: %ld\n",(long) info.st_ino);
	printf("File size :: %lld Bytes\n",(long long) info.st_size);
	//printf("Last file access :: %s\n",ctime(&info.st_atime));
	//printf("Last file modification :: %s\n",ctime(&info.st_mtime));
	printf("No of Hard Links :: %ld\n",info.st_nlink);
	printf("FIle Permissions:: \t");
	printf((S_ISDIR(info.st_mode)) ? "d" : "-");
	printf((info.st_mode & S_IRUSR) ? "r" : "-");
	printf((info.st_mode & S_IWUSR) ? "w" : "-");
	printf((info.st_mode & S_IXUSR) ? "x" : "-");
	printf((info.st_mode & S_IRGRP) ? "r" : "-");
	printf((info.st_mode & S_IWGRP) ? "w" : "-");
	printf((info.st_mode & S_IXGRP) ? "x" : "-");
	printf((info.st_mode & S_IROTH) ? "r" : "-");
	printf((info.st_mode & S_IWOTH) ? "w" : "-");
	printf((info.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	close(file);
	return 0;
}
