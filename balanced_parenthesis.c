#include<stdio.h>
#include<string.h>
#define MAX 100
char arr[MAX];
int top=-1;
char stack[MAX];

void push(int element)
{
    if(top==MAX-1)
        return;
    else
    {
        top++;
        stack[top]=element;
    }
}

void pop()
{
    int data;
    if(top==-1)
        return;
    else
    {
        data=stack[top];
        top--;
    }
}

int balance(int len)
{
    char c;
    int flag=0;
    for(int i=0;i<len;i++)
    {
        c=arr[i];
        switch(c)
        {
            case '(':
            case '{':
            case '[':
                push(c);
                break;
            case '}':
                if(stack[top]==('{'))
                    pop();
                else
                    flag=1;
                break;
            case ']':
                if(stack[top]==('['))
                    pop();
                else
                    flag=1;
                break;
            case ')':
                if(stack[top]==('('))
                    pop();
                else
                    flag=1;
                break;



        }
    }
    if(flag==1)
        return 1;
    else
        return 0;
}

int main()
{
    int len,value=0;;
    printf("Enter the parenthesis set\n");
    scanf("%s",arr);
    len=strlen(arr);
    value=balance(len);
    if(value==1)
        printf("The set of parenthesis is not balanced\n");
    else
    printf("The set of parenthesis is balanced\n");

}
