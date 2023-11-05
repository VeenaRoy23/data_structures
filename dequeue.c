#include<stdio.h>
int front=-1;
int rear=-1;
#define max 100
int dequeue[max];


void addFront(int element)
{
    
    if(front==0||front==-1)
    {
        front=max-1;
        dequeue[front]=element;
    }
    else if(front==rear)
    {
        printf("queue overflow\n");
        return;
     
    }
    else 
    {
        front=front-1;
        dequeue[front]=element;
    }
    
}

void addRear(int element)
{
    if(rear==(max-1))
    {
        rear=0;
        dequeue[rear]=element;
    }
    else if((front==-1)&&(rear==-1))
    {
        rear=0;
        dequeue[rear]=element;
    }
    else if(front==rear)
    {
        printf("queue overflow\n");
        return;
    }
    else
    {
        rear=rear+1;
        dequeue[rear]=element;
    }
}
int  deleteFront()
{
    int data;
    if(front==-1)
    {
        printf("queue underflow\n");
        return 0;
    }
    else if(front==rear)
    {
        data=dequeue[front];
        front=rear=-1;
        
    }
    else if(front==(max-1))
    {
        data=dequeue[front];
        front=0;
    }
    else
    {
        data=dequeue[front];
        front=front+1;
    }
    return data;
}

int deleteRear()
{
    int data;
    if(front==-1)
    {
        printf("queue underflow\n");
        return 0;
    }
    else if(front==rear)
    {
      data=dequeue[rear];
      front=-1;
      rear=-1;
    }
    else if(rear==0)
    {
        data=dequeue[rear];
        rear=max-1;
    }
    else
    {
        data=dequeue[rear];
        rear=rear-1;
    }
   return data; 
}

void display()
{
   for(int i=0;i<=rear;i++)
   {
        printf("%d\t",dequeue[i]);
   }
    if(front>rear)
    {
   for(int i=front;i<max;i++)
   {
        printf("%d\t",dequeue[i]);
   }
    }
   
   printf("\n");
}



int main()
{
    int x;
    int item,choice;
    do{
    printf("Enter your choice\n1 for inserting elements from rear\n2 for inserting elements from front\n3 for deleting elements from front\n4for deleting elements from rear\n5 for displaying elements\n6 to exit\n"); 
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter the element\n");
        scanf("%d",&item);
        addRear(item);
        
        break;
      case 2:
        printf("Enter the element\n");
        scanf("%d",&item);
        addFront(item);
        break;
        
      case 3:
        x=deleteFront();
        printf("%d deleted\n",x);
        break;
        
      case 4:
        x=deleteRear();
        printf("%d deleted\n",x);
        break;
       
      case 5:
        display();
        break;
    }    
   }while(choice!=6);
    
}



