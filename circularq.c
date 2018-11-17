//Program to implement a circlular queue 
#include<stdio.h>
#include<stdlib.h>
int *q,f=-1,r=-1,n;
void EncQ()
{
	int tq;
	if(f==(r+1)%n)
	{
		printf("the cqueue is full\n");
		return;
	}
	if(f==-1)
		f++;
	r=(r+1)%n;
	printf("enter the value to store in cq\n");
	scanf("%d",&tq);
	q[r]=tq;
}
void DecQ()
{
	if(f==-1)
	{
		printf("the cq is empty\n");
		return;
	}
	printf("deleting %d\n",*(q+f));
	if(f==r)
		f=r=-1;
	else
		f=(f+1)%n;
}
void DispcQ()
{
	if(f==-1)
	{	
		printf("the cq is empty\n");
		return;
	}
	int i=f;
	while(1)
	{
		printf("%d\t",*(q+i));
		if(i==r)
			break;
		i=(i+1)%n;
	}
	printf("\n");
}
void main()
{
	int ch;
	printf("enter the size of the cque\n");
	scanf("%d",&n);
	q=(int*)malloc(n*sizeof(int));
	do
	{
		printf("enter the choice from the following\n1)encque\n2)decqeu\n3)dispcque\n4)exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				EncQ();
				break;
			case 2:
				DecQ();
				break;
			case 3:
				DispcQ();
				break;
			case 4:
				printf("exiting...\n");
		}
	}while(ch!=4);
}
