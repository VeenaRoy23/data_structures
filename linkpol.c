#include<stdio.h>
#include<stdlib.h>

struct node{
          float coeff;
          int exp;
          struct node*link;
 };
 struct node*insert(struct node *head,float co,int ex)
 {
  struct node*temp;
  struct node* newP=malloc(sizeof(struct node));
  newP->coeff=co;
  newP->exp=ex;
  newP->link=NULL;
  
  if(head==NULL||ex>head->exp)
  {
   newP->link=head;
   head=newP;
  }
  else
  {
    temp=head;
    while(temp->link!=NULL && temp->link->exp>=ex)
      temp=temp->link;
      newP->link=temp->link;
      temp->link=newP;
  }
    return head;
}

struct node* create(struct node*head)
{
  int n,i;
  float coeff;
  int exp;
  printf("enter nuber of terms\n");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    printf("enter coeffecient of the term %d ",i+1);
    scanf("%f",&coeff);
    
    printf("enter exponent of the term %d ",i+1);
    scanf("%d",&exp);
    
    head=insert(head,coeff,exp);
  }
  return head;
}

void print(struct node*head)
{
  if(head==NULL)
   printf("no polynomial");
  else
  {
   struct node*temp=head;
   while(temp!=NULL)
   {
     printf("(%.1fx%d)",temp->coeff,temp->exp);
     temp=temp->link;
     if(temp!=NULL)
     {
      printf(" + ");
     }
     else
     {
       printf("\n");
     }
   }
  }
}

void polyAdd(struct node*head1,struct node* head2)
{
   struct node* ptr1=head1;
   struct node* ptr2=head2;
   struct node* head3=NULL;
   
   while(ptr1!=NULL && ptr2!=NULL)
   {
     if(ptr1->exp==ptr2->exp)
     {
       head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->exp);
       ptr1=ptr1->link;
       ptr2=ptr2->link;
     }
     else if(ptr1->exp>ptr2->exp)
     {
       head3=insert(head3,ptr1->coeff,ptr1->exp);
       ptr1=ptr1->link;
     }
     else if(ptr1->exp<ptr2->exp)
     {
       head3=insert(head3,ptr2->coeff,ptr2->exp);
       ptr2=ptr2->link;
     }
   }
   while(ptr1!=NULL)
   {
     head3=insert(head3,ptr1->coeff,ptr1->exp);
     ptr1=ptr1->link;
   }
   while(ptr2!=NULL)
   {
     head3=insert(head3,ptr2->coeff,ptr2->exp);
     ptr2=ptr2->link;
   }
   printf("added polynomial is: ");
   print(head3);
   
  struct node* ptr3=head3;
  struct node* temp=NULL;
  
  while(ptr3->link!=NULL)
  {
    if(ptr3->exp==ptr3->link->exp)
    {
      ptr3->coeff=ptr3->coeff+ptr3->link->coeff;
      temp=ptr3->link;
      ptr3->link=ptr3->link->link;
      free(temp);
    }
    else
    {
      ptr3=ptr3->link;
    }
  }
   printf("after simplification");
   print(head3);
}

void polyMult(struct node* head1,struct node* head2)
{
  struct node* ptr1=head1;
  struct node* ptr2=head2;
  struct node* head3=NULL;
  int res1,res2;
    
  if(head1==NULL||head2==NULL)
  {
    printf("zero polynomial");
    return;
  }
  
  while(ptr1!=NULL)
  {
     while(ptr2!=NULL)
     {
       res1=ptr1->coeff*ptr2->coeff;
       res2=ptr1->exp+ptr2->exp;
       head3=insert(head3,res1,res2);
       ptr2=ptr2->link;
     }
     ptr1=ptr1->link;
     ptr2=head2;
  }
  printf("multiplied polynomial is ");
  printf("before simplification");
  print(head3);
  
  struct node*ptr3=head3;
  struct node*temp=NULL;
  
  while(ptr3->link!=NULL)
  {
    if(ptr3->exp==ptr3->link->exp)
    {
      ptr3->coeff=ptr3->coeff+ptr3->link->coeff;
      temp=ptr3->link;
      ptr3->link=ptr3->link->link;
      free(temp);
    }
    else
    {
      ptr3=ptr3->link;
    }
  }
   printf("after simplification");
   print(head3);
}

int main()
{
  struct node*head1=NULL;
  struct node*head2=NULL;
  printf("enter the first polynomial \n");
  head1=create(head1);
  print(head1);
  printf("enter the second polynomial \n");
  head2=create(head2);
  print(head2);
  
  polyAdd(head1,head2);
  polyMult(head1,head2);
  return 0;
}
      


       
       
     
