#include<stdio.h>

#define max 100
int top=-1;
int a[max];

void push(int x)
{
 if(top==max)
  printf("\nStack full");
 else
 {
  a[top+1]=x;
  top++;
 }
}

void pop()
{
 if(top==-1)
  printf("\nStack empty");
 else
 {
  printf("\nElement popped is %d",a[top]);
  top--;
 }
}

void display()
{
 if(top==-1)
  printf("\nStack empty");
 else
 {
  for(int i=0;i<=top;i++)
  {
   printf("\t %d",a[i]);
  }
 }
}



int main(void)
{
 printf("\n \t\t MENU \n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT");
 int ch,x;
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  if(ch==4)
   break;
  switch(ch)
  {
   case 1:printf("\nEnter the element to be pushed:");
          scanf("%d",&x);
          push(x);break;
   case 2:pop();break;
   case 3:display();break;
   default:printf("\n Invalid Choice");
  }
 }
}
