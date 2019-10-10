#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *newnode;
struct node *temp;

void enqueue(int x)
{
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==NULL)
  {
    printf("\nNo space"); 
  }
  else
  {
   newnode->data=x;
   newnode->link=NULL;
  if(front==NULL)
   front=rear=newnode;
  else
  {
   rear->link=newnode;
   rear=newnode;
  }
 }
}

void dequeue()
{
  if(front==NULL)
  {
    printf("\nQueue empty");return;
  }
  if(front==rear)
  {
   printf("\nElement deleted is: %d",front->data);
   free(front);
   front=rear=NULL;
  }
  else{
   printf("\nElement deleted is: %d",front->data);
   temp=front;
   front=front->link;
   free(temp);
 }
}

void display()
{
 temp=front;
 if(front==NULL)
 {
    printf("\nQueue empty");
  }
 else
 {
  while(temp!=NULL)
  {
   printf("\t%d",temp->data);
   temp=temp->link;
  }
 }
}


int main (void)
{
 int x,ch;
 while(1)
 {
 printf("\n\n\tMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nEnter your choice:");
 scanf("%d",&ch);
 if(ch==4)
  break;
 switch(ch)
 {
  case 1:printf("\nEnter the element:");
	 scanf("%d",&x);
	 enqueue(x);
	 break;
  case 2:dequeue();
	 break;
  case 3:display();
	 break;
  default:printf("\nInvalid choice:");
 }
 }
}
