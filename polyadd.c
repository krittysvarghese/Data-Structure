#include<stdio.h>
#include<stdlib.h>
struct node
{
  int coeff,exp;
  struct node *link;
}p,q,r;
struct node *newnode;
struct node *phead=NULL;
struct node *qhead=NULL;
struct node *rhead=NULL;

struct node *ptr;
struct node *temp;

struct node *getNode()
{
   struct node *ptr;
   ptr=(struct node *)malloc(sizeof(struct node));
   return ptr;
}    

void insert(int exp,int coeff,int deg,struct node *head)
{  
   newnode=getNode();
   struct node *ptr;
   ptr=getNode();
  
   struct node *temp;
   temp=getNode();
   ptr=head;
   int count;
   
   if(exp==deg)
   {
          newnode->coeff=coeff;
	  newnode->exp=exp;
          newnode->link=NULL;
          head=newnode;
   }
   else
   {
   	 ptr=ptr->link;
	 temp=head;
         while(ptr!=NULL)
         {
            ptr=ptr->link;
	    temp=temp->link;
         }
         ptr->coeff=coeff;
	 ptr->exp=exp;
         temp->link=ptr;
         
   }
    
}

void traversal(struct node *head)
{
   struct node *temp;
   temp=head;
   while(temp!=NULL)
   {
       printf("%dx^%d",temp->coeff,temp->exp);
       temp=temp->link;
    }
}

int main(void)
{
   int d1,d2,data;
   printf("\n Enter the degree of the 1st polynomial:");
   scanf("%d",&d1);
   for(int i=d1;i>=0;i--)
   {
	printf("\n Enter the coefficient of x^%d :",i);
	scanf("%d",&data);
	if(data!=0)
	  insert(i,data,d1,phead);
   }
   printf("\n Enter the degree of the 2nd polynomial:");
   scanf("%d",&d2);
   for(int i=d2;i>=0;i--)
   {
	printf("\n Enter the coefficient of x^%d :",i);
	scanf("%d",&data);
	if(data!=0)
	  insert(i,data,d2,qhead);
   }
   traversal(phead);
   traversal(qhead);
   
}
   












