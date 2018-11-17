//Implementation of data structure queue
#include<stdio.h>
#include<stdlib.h>
int *q,n,f=-1,r=-1;
void EnQ()
{
	int tq;
	if(r==n-1)
	{
		printf("The queue is full\n");
		return;
	}
	if(f==-1)
		f++;
	printf("Enter the value to store in the queuen\n");
	r++;
	scanf("%d",&tq);
	*(q+r)=tq;
}
void DeQ()
{
	if(f==-1)
	{
		printf("The Qeue is empty\n");
		return;
	}
	printf("Deleting:%d\n",*(q+f));
	if(f==r)
	{
		f=r=-1;
		return;
	}
	f++;
}
void DispQ()
{
	if(f==-1)
	{
		printf("the queue is empty\n");
		return;
	}
	for(int i=f;i<=r;i++)
		printf("%d\t",*(q+i));
	printf("\n");
}
void main()
{
	int ch;
	printf("Enter the size of the queue\n");
	scanf("%d",&n);
	q=(int*)malloc(n*sizeof(int));
	do
	{
		printf("enter the choic:\n1)Enqueue\n2)dequeue\n3)display\n4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:EnQ();
			       break;
			case 2:DeQ();
			       break;
			case 3:DispQ();
			       break;
			case 4:printf("Exiting\n");
			       break;
			default:printf("Invalid choice... Try again\n");
		}
	}while(ch!=4);
}

