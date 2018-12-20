//Sorting with bubble or selection
#include<stdio.h>
#include<stdlib.h>
void bubsort(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				a[j]=a[j+1]+a[j];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		for(j=0;j<n;j++)
			printf("%d\t",a[j]);
		printf("\n");
	}
	printf("final array\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	 printf("\n");
}

void selsort(int *a,int n)
{
	int i,j,loc,min;
	for(i=0;i<n;i++)
	{
		loc=i;
		min=a[i];
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				loc=j;
			}
		}
		if(loc!=i)
		{
			a[loc]+=a[i];
			a[i]=a[loc]-a[i];
			a[loc]=a[loc]-a[i];
		}
		for(j=0;j<n;j++)
			printf("%d\t",a[j]);
		printf("\n");
	}
	printf("final array\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void main()
{
	int ch,*b,n,i;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	b=(int*)malloc(n*sizeof(int));
	printf("enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	printf("Sorting\n1)Bubble\n2)Selection\nEnter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			bubsort(b,n);
			break;
		case 2:
			selsort(b,n);
			break;
		default:printf("Invalid\n");
	}
}

