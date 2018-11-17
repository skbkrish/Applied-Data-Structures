//Program to search for an element with linear or binary search
#include<stdio.h>
#include<stdlib.h>
void linser(int *a,int n, int ser)
{
	int i,f=0;
	for(i=0;i<n;i++)
		if(*(a+i)==ser)
		{
			printf("Element found at position %d\n",i+1);
			f=1;
			break;
		}
	if(f!=1)
		printf("Element not found\n");
}
void binser(int *a,int n,int ser)
{
	int l=0,h=n-1,m,f=0;
	while(h>=l)
	{
		m=(l+h)/2;
		if(*(a+m)==ser)
		{
			printf("Element found at position %d\n",m+1);
			f=1;break;
		}
		else if(*(a+m)>ser)
			h=m;
		else if(*(a+m)<ser)
			l=m;
	}
	if(f!=1)
		printf("Element not found\n");
}
void main()
{
	int *ar,n,ser,ch,i;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	ar=(int*)malloc(n*sizeof(int));
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",ar+i);
	printf("Enter the element to search\n");
	scanf("%d",&ser);
	printf("Enter your choice of the following\n1:linearsearch\n2:binarysearch\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:linser(ar,n,ser);
		       break;
		case 2:binser(ar,n,ser);
		       break;
		default:printf("Exiting\n");
	}
}
