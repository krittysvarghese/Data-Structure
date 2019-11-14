#include<stdio.h>
#include<stdlib.h>
#define MAX 30
typedef struct node
{
 int data;
 struct node *link;
}node;
node *head[MAX]={NULL};;
void insert(int key,int n)
{
 int i=key%n;
 node *newnode,*temp;
 newnode=(node *)malloc(sizeof(node));
 newnode->data=key;
 newnode->link=NULL;
 if(head[i]==NULL)
  head[i]=newnode;
 else
 {
  temp=head[i];
  while(temp->link!=NULL)
   temp=temp->link;
  temp->link=newnode;
 }
}
void display(int n)
{
 node *temp;
 int i=0;
 while(i<n)
 {
  printf("\nIndex %d:",i);
  if(head[i]!=NULL)
  {
   temp=head[i];
   while(temp!=NULL)
   {
    printf("\t%d",temp->data);
    temp=temp->link;
   }
   i++;
  }
  else
   i++;
 }
}
void search(int key,int n)
{
 int pos=key%n,flag=0;
 node *temp;
 if(head[pos]==NULL)
   printf("\nKey not found");
 else
   temp=head[pos];
 while(temp!=NULL)
 {
  if(temp->data==key)
  {
    flag=1;
    break;
  }
  temp=temp->link;
 }
 if(flag==1)
  printf("\nKey found");
 else
  printf("\nKey not found");
}
int main (void)
{
 int ch,key,n;
 printf("\nEnter the size of the hash table: ");
 scanf("%d",&n);
 printf("\n\t\tMENU\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.EXIT");
 while(1)
 {
  printf("\nEnter your choice: ");
  scanf("%d",&ch);
  if(ch==4)
   break;
  switch(ch)
  {
   case 1:printf("\nEnter the element to be inserted: ");
          scanf("%d",&key);
          insert(key,n);
          break;
   case 2:display(n);
          break;
   case 3:printf("\nEnter the element to be searched: ");
          scanf("%d",&key);
          search(key,n);
          break;
   default:printf("\nInvalid choice!");
  }
 }
}
