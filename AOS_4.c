#include<stdio.h>
#include<string.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
	DIR *d;
	char *pos;
	struct dirent *dir;
	int i=0;
	if(argc!=2)
	{
		printf("\nProvide Sufficiant arguments..\n");
	}
	else
	{
		d=opendir(".");
		if(d)
		{
			while((dir=readdir(d))!=NULL)
			{
				pos=strstr(dir->d_name,argv[1]);
				i=pos - dir->d_name;
				if(i==0)
					printf("%s\n",dir->d_name);
			
			}
			closedir(d);
		}
		return 0;
	}
}
