//Program to convert mathematical infix expression to prefix form and hence evaluate the expression
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
//#include<math.h>
char *stack; // stack for conversion
char *arr;  // array for storing converted value
char *final;// stack for reversing converted values
int *st; // evaluation stack
int top = -1,tp=-1,fn=-1,t=-1;
int n;
char *exp;
char *rev;
void push(char x) // push for input
{
    stack[++top] = x;
}

void stp(int x) // push operation for evaluation
{
    st[++t] = x;
} 

void ph(char x) // push for stack-array
{
    arr[++tp] = x;
}

int fp() //pop for stack final
{
	if(fn == -1)
        return -1;
    else
        return final[fn--];
}
void ps(char x) // push for stack-final
{
	final[++fn]=x;
}
 
int pol() //pop operation of evaluation
{
        return st[t--];
}
 

char pp() // pop for stack-final
{
    if(tp == -1)
        return -1;
    else
        final[++fn]=arr[tp--];
}
 


char pop() // pop for input
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x) // checking priority
{
    if(x == ')')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
	return(3);
}


//for conversion to postfix
void infixtoprefix()
{
   
    char *e, x,*f,l;
    stack=(char*)malloc(50*(sizeof(char)));// allocating stack
    arr=(char*)malloc(50*(sizeof(char))); // allocating array
    final=(char*)malloc(50*(sizeof(char)));// allocating final
    e = rev; // assigning input expression to e
    f=arr;  // assigning stack array  to f
   
    while(*e != '\0')
    {
        if(isalnum(*e))
	{

            printf("%c",*e);
		ph(*e);
	}
        else if(*e == ')')
            push(*e);
        else if(*e == '(')
        {
            	while((x = pop()) != ')'){
                printf("%c", x);
		ph(x);
		}
		
        }
        else
        {
            while(priority(stack[top]) > priority(*e)){  // checking priority for incoming and instack values
		l=pop();
                printf("%c",l);
		ph(l);
		
}
            push(*e);
        }
        e++;
    }
    while(top != -1) // final pop
    {
	l=pop();
        printf("%c",l);
	ph(l);

    }
	printf("\n");
	
	while(1){
		if(pp()==-1){break;}
	
}
	 printf("Prefix expression is:");
	 puts(final);

}


//for evaluation
void evu(){
	 double n1;
	 double n2;
	 double n3;
	int num;
	char a,b;
	st=(int*)malloc(50*(sizeof(int))); // allocating evaluation stack for evaluation
	char e;
	__fpurge(stdin);
	e='0';
	while(e!=-1)

	{
		e=fp();

		if(isalnum(e)){
			printf("Enter the value of %c:",e); // reading operands from evaluation-stack
			scanf("%d",&num);
			stp(num);
		}
		else{
		n1=pol();//poping first value
		n2=pol();//poping second value	
			 switch(e) // checking conditions for operators
            			{
		
				    
					    case '+':
					    {
						    n3 = n1 + n2;
			       			break;
					    }
					    case '-':
					    {
						    n3 = n2 - n1;
						    break;
					    }
					    case '*':
					    {
						    n3 = n1 * n2;
						    break;
					    }
					    case '/':
					    {
						    n3 = n1 / n2;
						    break;
					    }
					     /*case '^':
					    {
						    n3 = pow(n2 , n1);
						    break;
					    }*/
         			   }
            stp(n3);
                                         
                        
	}	
	
	
}
*(st+0)=*(st+0)*(-1);
	printf("\nThe result of expression %s = %d\n\n",exp,*(st+0));	//final output
	
}

void main()
{
	int j;
	exp=(char*)malloc(50*sizeof(char));
	rev=(char*)malloc(50*sizeof(char));
	printf("Enter the expression:");
    	gets(exp);
	n=strlen(exp);
		for(int i=n-1;i>=0;i--)
			{
				
				*(rev+j)=*(exp+i); 
				j++;
			}

	infixtoprefix();//function call for conversion
	evu();		// unction call for evaluation
 
}  
		
	
