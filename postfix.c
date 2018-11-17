//Program to convert mathematical infix expression to postfix form and hence evaluate the expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio_ext.h>

char *ep,*stack,*output,*rev,*lout;
int top1=-1,top2=-1;
int x=-1;
int max,tp=-1,*out,i=0;

void push1(char val){
	top1++;
	*(stack+top1)=val;
} 

void push2(char val){
	tp++;	
	*(output+tp)=val;
	
} 

void push3(char val){
	top2++;	
	*(lout+top2)=val;
	
} 

void push4(int val){
	x++;	
	*(out+x)=val;
	
} 

int pop4(){
	int a;
	a=*(out+x);
	--x;
	return a;
} 

int pop1(){
	char a;
	a=*(stack+top1);
	--top1;
	return a;
} 

int pop2(){
	
	if(i<=tp){
	char a;
	a=*(output+i);
	i++;
	return a;}
} 




int isp(char val){
	
	switch(val){
		case '^':
				return 3;
				break;
		case '*':
				return 2;
				break;
		case '/':
				return 2;
				break;				
		case '+':
				return 1;
				break;
		case '-':
				return 1;
				break;
		case '(':
				return 0;
				break;			
	}
	
}

int icp(char val){

		switch(val){
		case '^':
				return 4;
				break;
		case  '*':
				return 2;
				break;
		case '/':
				return 2;
				break;				
		case '+':
				return 1;
				break;
		case '-':
				return 1;
				break;
		case '(':
				return 4;
				break;			
	}
	
}




void postfix(){
	char c,e;
	int i=0;	
	push1('(');
	e=ep[i];
	while(e!='\0'){
		c=pop1();
		if(isalnum(e)){		
			push1(c);
			//printf("%c",e);
			push2(e);
		}
		else if(e==')'){
			while(c!='('){
				push2(c);
				c=pop1();
			}
		}
		else if(isp(c)>=icp(e)){
			while(isp(c)>=icp(e)){
				push2(c);
				c=pop1();
			}
			push1(c);
			push1(e);
		}
		else if(isp(c)<icp(e)){
			push1(c);
			push1(e);
		}
			
			
		i++;
		e=ep[i];
		
				
	}
	
	c=pop1();
	while(c!='('){
				push2(c);
				c=pop1();
			}
	
			
}

void eval(){
	char u;
	int z,v,m,x,y;
	
	int i=0;
	while(i<=tp){
		u=pop2();
		
		
		if(isalnum(u)){
			printf("\nEnter value of %c:",u);
			scanf("%d",&z);
			push4(z);
			
		}
		else{
			//printf("%d",top3);
			x=pop4();
			y=pop4();
			
			switch(u){
				
				case '+':
					v=y+x;
					//printf("%d",x);
					push4(v);
					break;
				case '-':
						v=y-x;
					push4(v);
						break;
				case '*':
						v=y*x;
					push4(v);
						break;
				case '/':
						v=y/x;
					push4(v);
						break;
			}			
		}
		i++;
		
	}
	
	m=pop4();
	printf("%d",m);
}

void display()
{
	
	int tos=0;
	
	for(int i=0; i<=tp; i++){
		printf("%c",*(output+i));
	}
	
	
}

void display1()
{
	
	int tos=top2;
	//printf("%d",top2);
	for(; tos>=0; tos--){
		printf("%c",*(lout+tos));
	}
}

int main(){
	
	int code=-1;
	ep=(char *)calloc(50,sizeof(char));
	rev=(char *)calloc(50,sizeof(char));
	stack=(char *)calloc(50,sizeof(char));
	output=(char *)calloc(50,sizeof(char));
	lout=(char *)calloc(50,sizeof(char));
	out=(int *)calloc(50,sizeof(char));
	puts("Enter expression:");
	__fpurge(stdin);
	gets(ep);
	max=strlen(ep);
	//rv();
	do{
		printf("\n\n\nMENU \n****\n 1)Conversion 2)Evaluation 0)Stop\n");
		scanf("%d",&code);
		switch(code){
			case 1:	
				postfix();
				display();
				break;
				
			case 2:
				//display1();
				eval();
				break;
		}
	}while(code!=0);
	exit(1);
}
