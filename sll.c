#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *link;
};
struct node *top=NULL;
struct node *newnode;
struct node *temp;

void push(int x)
{
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==NULL)
  {
    printf("\nNo space"); 
  }
  else
  {
   newnode->data=x;
  if(top==NULL)
   newnode->link=NULL;
  else
   newnode->link=top;
  top=newnode;
 }
}

void pop()
{
  if(top==NULL)
  {
    printf("\nStack empty");
  }
  else{
   printf("\nElement popped is: %d",top->data);
   temp=top;
   top=top->link;
   free(temp);
 }
}

void display()
{
 temp=top;
 if(top==NULL)
 {
    printf("\nStack empty");
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
 printf("\n\n\tMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter your choice:");
 scanf("%d",&ch);
 if(ch==4)
  break;
 switch(ch)
 {
  case 1:printf("\nEnter the element to be pushed into the stack:");
	 scanf("%d",&x);
	 push(x);
	 break;
  case 2:pop();
	 break;
  case 3:display();
	 break;
  default:printf("\nInvalid choice:");
 }
 }
}
	
 
