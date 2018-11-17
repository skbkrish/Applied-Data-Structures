//Program to read an array and insert or delete an element from the array
#include<stdio.h>
#include<stdlib.h>
void insrt(int *a,int *m, int ip)
{
	int i=*m,ele;
	printf("enter the element to insert at position %d",ip);
	scanf("%d",&ele);
	a=(int*)realloc(a,(*m+1)*sizeof(int));
	if(ip!=*m)
		while(i>=ip)
		{
			*(a+i+1)=*(a+i);
			i--;
		}
	*(a+ip)=ele;
	*m=*m+1;
	printf("The new array is:\n");
	for(i=0;i<*m;i++)
		printf("%d\t",*(a+i));
}
void deleto(int *a,int *m,int del)
{
	int i=0,c;
	while(i<*m)
	{
		if(*(a+i)==del)
		{
			c=i;
			while(c<(*m))
			{	
				*(a+i)=*(a+i+1);
				c++;
			}
			(*m)--;
		}
		i++;
	}
	a=(int*)realloc(a,(*m)*sizeof(int));
	printf("The new array is:\n");
	for(i=0;i<*m;i++)
		printf("%d\t",*(a+i));
}
void main()
{
	int *ar,n,ip,del,ch,i;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	ar=(int*)malloc(n*sizeof(int));
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",ar+i);
	do
	{
		printf("Choose from the following options:\n1:Insert an element\n2:Delete an element\nAny other number: Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the position to insert the element\n");
		               scanf("%d",&ip);
		       		insrt(ar,&n,ip);
		       		break;
			case 2:printf("Enter the element to delete\n");
		       		scanf("%d",&del);
		       		deleto(ar,&n,del);
		       		break;
			default:printf("Exiting");
				exit(0);
		}
	}while(1);
}
