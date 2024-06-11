#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main()
{
	struct dirent **namelist;
	int n,i=0;
	n=scandir(".",&namelist,0,alphasort);
	if(n<0)
		perror("Scandir");
	else
	{
		while(i<n)
		{
			printf("%s\n",namelist[i]->d_name);
			free(namelist[i]);
			i++;
		}
		free(namelist);
	}
}
