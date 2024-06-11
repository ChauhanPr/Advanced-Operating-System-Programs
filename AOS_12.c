#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* currentpath=getenv("PATH");
	if(currentpath != NULL)
	{
		printf("current PATH: %s\n", currentpath);
	}
	else
	{
		printf("path environment variable not set.\n");
	}

	char newpath[]="/new/path:/another/path";
	if(setenv("PATH", newpath,1)==0)
	{
		printf("PATH reset successfully.\n");

		char* updatedpath=getenv("PATH");
		if(updatedpath !=NULL)
		{
			printf("Updated PATH: %s\n",updatedpath);
		}
		else
		{
			printf("PATH environment variable not set.\n");
		}
	}
	else
	{
		printf("Failed to reset PATH.\n");
	}

	//HOME
	
	char* currenthome=getenv("HOME");
	if(currenthome != NULL)
	{
		printf("current HOME: %s\n", currenthome);
	}
	else
	{
		printf("home environment variable not set.\n");
	}

	char newhome[]="/new/home:/directory";
	if(setenv("HOME", newhome,1)==0)
	{
		printf("HOME reset successfully.\n");

		char* updatedhome=getenv("HOME");
		if(updatedhome !=NULL)
		{
			printf("Updated HOME: %s\n",updatedhome);
		}
		else
		{
			printf("HOME environment variable not set.\n");
		}
	}
	else
	{
		printf("Failed to reset Home.\n");
	}

	//ROOT

	char* currentroot=getenv("ROOT");
	if(currentroot != NULL)
	{
		printf("current ROOT: %s\n", currentroot);
	}
	else
	{
		printf("root environment variable not set.\n");
	}

	char newroot[]="/new/root/directory";
	if(setenv("ROOT", newroot,1)==0)
	{
		printf("ROOT reset successfully.\n");

		char* updatedroot=getenv("ROOT");
		if(updatedroot !=NULL)
		{
			printf("Updated ROOT: %s\n",updatedroot);
		}
		else
		{
			printf("ROOT environment variable not set.\n");
		}
	}
	else
	{
		printf("Failed to reset ROOT.\n");
	}
	return 0;
}


