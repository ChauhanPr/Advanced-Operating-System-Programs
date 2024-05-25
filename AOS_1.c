#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	if(access(argv[1],F_OK)==0)
		printf("\nFile %s exits\n",argv[1]);
	else
		printf("\nFile %s not exits\n",argv[1]);
}
