#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;

void push(int element)
{
	if(top==(MAX-1))
	{
		return;
	}
	else
	{
		top=top+1;
		stack[top]=element;
	}
}

int pop()
{
	int data;
	if(top==-1)
	{
		return 0;
	}
	else
	{
		data=stack[top];
		top--;
	}
	return data;
}

void conversion(int num)
{
	int rem;
	while(num!=0)
	{
		rem=num%2;
		push(rem);
		num=num/2;
	}
	
}

void display(int n)
{
	printf("The binary equivalent of %d is\t",n);
	while(top!=-1)
	{
	printf("%d",pop());
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the number to be converted\n");
	scanf("%d",&n);
	conversion(n);
	display(n);
}
		

