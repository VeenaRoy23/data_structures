#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct priorityQ
{
    int data;
    int priority;
}arr[MAX];

int track=-1;
int top=0;
int cons=0;

void insert()
{   
    
    int temp;
    if(track==(MAX-1))
    {
        printf("Queue full\n");
        

    }
    else
    {   
        track++;
        printf("Enter the data to be inserted: ");
        scanf("%d",&arr[track].data);
        printf("Enter the priority of the element: ");
        scanf("%d",&arr[track].priority);
        for(int i=0;i<track;i++)
        {
            for(int j=0;j<(track-i);j++)
            {
                if(arr[j].priority>arr[j+1].priority)
            {
                temp=arr[j].priority;
                arr[j].priority=arr[j+1].priority;
                arr[j+1].priority=temp;

                temp=arr[j].data;
                arr[j].data=arr[j+1].data;
                arr[j+1].data=temp;

            }
            }
           
        } 
    }
}


void delete()
{
    if((arr[cons].priority==(NULL)&&arr[cons].data==(NULL))||top==track+1)
    {
        printf("Queue empty\n");
        top=0;
        track=-1;

    }
    else
    {
    
        printf("%d deleted\n",arr[top].data);
         for(int i=top+1;i<=track;i++)
         {
             printf("%d  %d\t",arr[i].data,arr[i].priority);
         }
         printf("\n");
         top++;
    }
}

void display()
{
    for(int i=top;i<=track;i++)
    {
        printf("%d  %d\t",arr[i].data,arr[i].priority);
    }
    printf("\n");
}

int main()
{
    int choice;
    do{
        printf("Enter your choice\n");
        printf("1 to enqueue\n");
        printf("2 to dequeue\n");
        printf("3 to display\n");
        printf("4 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                display();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();

        }
        
       
    } while(choice!=4);

}