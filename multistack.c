#include<stdio.h>

#define max 4
int top1=-1;
int top2=max;
int a[max];

void pushstack1(int x)
{
 if(top1+1==top2)
  printf("\nStack full");
 else
 {
  a[top1+1]=x;
  top1++;
 }
}

void pushstack2(int x)
{
 if(top1+1==top2)
  printf("\nStack full");
 else
 {
  a[top2+-1]=x;
  top2--;
 }
}

void popstack1()
{
 if(top1==-1)
  printf("\nStack empty");
 else
 {
  printf("\nElement popped from stack 1 is %d",a[top1]);
  top1--;
 }
}

void popstack2()
{
 if(top2==max)
  printf("\nStack empty");
 else
 {
  printf("\nElement popped from stack 2 is %d",a[top2]);
  top2++;
 }
}

void displaystack1()
{
 if(top1==-1)
  printf("\nStack empty");
 else
 {
  for(int i=0;i<=top1;i++)
  {
   printf("\t %d",a[i]);
  }
 }
}

void displaystack2()
{
 if(top2==max)
  printf("\nStack empty");
 else
 {
  for(int i=max-1;i>=top2;i--)
  {
   printf("\t %d",a[i]);
  }
 }
}

int main(void)
{
 printf("\n \t\t MENU \n\t1.PUSH into stack 1\n\t2.PUSH into stack 2\n\t3.POP from stack 1\n\t4.POP from stack 2\n\t5.DISPLAY stack 1\n\t6.DISPLAY stack 2\n\t7.EXIT");
 int ch,x;
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  if(ch==7)
   break;
  switch(ch)
  {
   case 1:printf("\nEnter the element to be pushed into stack 1:");
          scanf("%d",&x);
          pushstack1(x);break;
   case 2:printf("\nEnter the element to be pushed into stack 2:");
          scanf("%d",&x);
          pushstack2(x);break;
   case 3:popstack1();break;
   case 4:popstack2();break;
   case 5:displaystack1();break;
   case 6:displaystack2();break;
   default:printf("\n Invalid Choice");
  }
 }
}
