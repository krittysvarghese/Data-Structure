#include<stdio.h>
#define max 4
int q[max];
int front=-1;
int rear=-1;

void enqueue(int x)
{
  if(front==(rear+1)%max)
  {
   printf("\nQueue full");
  }
  else
  {
   if(front==-1)
    front=rear=0;
   else
    rear=(rear+1)%max;
   q[rear]=x;
  }
}

void dequeue()
{
  if(front==-1)
  {
    printf("\nQueue empty");return;
  }
  else if(front==rear)
  {
   printf("\nElement deleted is: %d",q[front]);
   front=-1;
   rear=-1;
  }
  else
 {
   printf("\nElement deleted is: %d",q[front]);
   front=(front+1)%max;
 }
}

void display()
{
 if(front==-1)
 {
    printf("\nQueue empty");
  }
 else if(front<=rear)
 {
  for(int i=front;i<=rear;i++)
  {
   printf("\t%d",q[i]);
  }
 }
 else
 {
 for(int i=front;i<=max-1;i++)
  {
   printf("\t%d",q[i]);
  }
  for(int i=0;i<=rear;i++)
  {
   printf("\t%d",q[i]);
  }
  
 }
}

int main(void)
{
 int x,ch;
 printf("\n\n\tMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
 while(1)
 {
 printf("\nEnter your choice:");
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
