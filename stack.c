//Implementation of the stack data structure
#include<stdio.h>
#include<stdlib.h>
int top=-1,n;
void push(int *a)
{
	if(top==n-1)
		printf("Stack Overflow: The stack is full\n");
	else
	{
		printf("Enter the element\n");
		top++;
		scanf("%d",a+top);
	}
}
void pop(int *a)
{
	if(top==-1)
		printf("Stack Underflow: The satck is empty\n");
	else
		top--;
}
void display(int *a)
{
	int i=0;
	if(top==-1)
		printf("The stack is empty\n");
	else
	{
		while(i<=top)
		{
			printf("%d ",*(a+i));
			i++;
		}
		printf("\n");
	}
}
void main()
{
	int *ar,ch,i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	ar=(int*)malloc(n*sizeof(int));
	do
	{
		printf("Enter your choice to edit the stack:\n1)Push\n2)Pop\n3)Display\n4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push(ar);
			       i=0;
			       while(i<=top)
			       {
				       printf("%d",*(ar+i));
				       i++;
			       }
			       break;
			case 2:pop(ar);
				break;
			case 3:display(ar);
			       break;
			case 4:printf("Exiting\n");
			       break;
			default:printf("Invalid choice, try again\n");
		}
	}while(ch!=4);
}	
