#include<stdio.h>
#define MAX 30
int hash[MAX];
int search(int key,int n)
{
 int pos=key%n,i,flag=0;
 for(i=pos;i<n;i++)
 {
  if(hash[i]==key)
  {
    flag=1;
    break;
  }
 }
 for(i=0;i<pos;i++)
 {
  if(hash[i]==key)
  {
    flag=1;
    break;
  }
 }
 if(flag==1)
  return 1;
 else
  return 0;
}
void insert(int key,int n)
{
 int flag=0,index,z;
 index=key%n;
 if(hash[index]==-1)
 { 
  hash[index]=key;
  return;
 }
 else 
 { 
  z=search(key,n);
  if(z==1)
  {
   printf("\nElement exists");

  }
  else
  {
   int i=index+1,j;
   while(i<n)
   {
    if(hash[i]==-1)
    {
     flag=1;
     hash[i]=key;
     break;
    }i++;
   }
   if(flag==0)
   {
     j=0;
     while(j<index)
     {
     if(hash[j]==-1)
     {
     flag=1;
     hash[j]=key;
     break;
     }j++;
    }
    
   }
  }
 }
 if(flag==0)
  printf("\nTable full");
}
void display(int n)
{
 int i=0;
 while(i<n)
 {
  printf("\nIndex %d:",i);
  if(hash[i]!=-1)
    printf("\t%d",hash[i]);
  i++;
 }
}

int main (void)
{
 int ch,key,n,z;
 printf("\nEnter the size of the hash table: ");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
  hash[i]=-1;
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
          z=search(key,n);
          if(z==1)
           printf("\nElement found");
          else
 	   printf("\nElement not found");
          break;
   default:printf("\nInvalid choice!");
  }
 }
}
