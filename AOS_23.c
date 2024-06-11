#include<stdio.h>
#include<dirent.h>
#include<string.h>
int main()
{
	FILE *in,*out;
	char ch,*txt=".txt";
	struct dirent *d;
	DIR *dir=opendir(".");
	if(dir==NULL)
	{
		printf("\nCant open current directory.");
		return 0;
	}
	while((d=readdir(dir))!=NULL)
	{
		char *fn=d->d_name;
		char *ext=strrchr(fn,'.');
		if(!(!ext || ext==fn))
		{
			if(strcmp(ext,txt)==0)
			{
				out=fopen("output.txt","a+");
				in=fopen(fn,"r");
				while(1)
				{
					ch=fgetc(in);
					if(ch==EOF)
						break;
					putc(ch,out);
				}
				fclose(in);
				fclose(out);
			}
		}
	}
	closedir(dir);
	printf("\nSuccessfully copied contents of all .txt files into output.txt file\n");
	return 0;
}

