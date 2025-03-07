#include <stdio.h>
struct pstruct
{
	int fno;
	int pbit;
}ptable[10];
int pmsize,lmsize,psize,frame,page,ftable[20],frameno;

void info()
{
	printf("\nMEMORY MANAGEMENT USING PAGING\n");
	printf("\nEnter the Size of Physical memory: ");
	scanf("%d",&pmsize);
	printf("\nEnter the size of Logical memory: ");
	scanf("%d",&lmsize);
	printf("\nEnter the partition size: ");
	scanf("%d",&psize);
	frame = (int) pmsize/psize;
	page = (int) lmsize/psize;
	printf("\nThe physical memory is divided into %d no.of frames\n",frame);
	printf("\nThe Logical memory is divided into %d no.of pages",page);
}

void assign()
{
	int i;
	for (i=0;i<page;i++)
	{
	ptable[i].fno = -1;
	ptable[i].pbit= -1;
	}
	for(i=0; i<frame;i++)
		ftable[i] = 32555;
	for (i=0;i<page;i++)
	{
	printf("\nEnter the Frame number where page %d must be placed: ",i);
		scanf("%d",&frameno);
		ftable[frameno] = i;
		if(ptable[i].pbit == -1)
		{
			ptable[i].fno = frameno;
			ptable[i].pbit = 1;
		}
	}



printf("\nPAGE TABLE\n");

	printf("PageAddress  FrameNo. PresenceBit\n");
	for (i=0;i<page;i++)
		printf("%d\t\t%d\t\t%d\n",i,ptable[i].fno,ptable[i].pbit);
}

int main()
{
	//system("clear");
	info();
	assign();
	return 0;
}
