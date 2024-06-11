#include<stdio.h>
#include<sys/stat.h>
#include<malloc.h>
int main()
{
	struct mallinfo mi=mallinfo();
	printf("Total non-mmapped bytes (arena):%d\n",mi.arena);
	printf("# of free chunks (ordblks):%d\n",mi.ordblks);
	printf("# of free fastbin blocks (smblks):%d\n",mi.smblks);
	printf("# of mapped regions (hblks):%d\n",mi.hblks);
	printf("Bytes in mapped mapped regions (hblkhd):%d\n",mi.hblkhd);
	printf("Max. total allocated space (usmblks):%d\n",mi.usmblks);
	printf("Free bytes held in fastbin (fsmblks):%d\n",mi.fsmblks);
	printf("Total allocated space (uordblks):%d\n",mi.uordblks);
	printf("Total free space (fordblks):%d\n",mi.fordblks);
	printf("Topmost releasable block (keepcost):%d\n",mi.keepcost);

	return 0;
}
