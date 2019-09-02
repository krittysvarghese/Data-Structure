#include<stdio.h>
#include<stdlib.h>
void insert(int X,int pos);
void delete(int pos);
int search(int X);
void traversal();
struct node
{
  int data;
  struct node *link;
};
struct node *newnode;
struct node *head=NULL;
struct node *temp;
struct node *temp1;

struct node *getNode()
{
   struct node *ptr;
   ptr=(struct node *)malloc(sizeof(struct node));
   return ptr;
}    
void main()
{
   int X;
   int pos;
   int ch;
   printf("\n \t MENU \n1. Insertion\n 2. Deletion\n 3. Search\n 4. Traversal\n 5. Exit\n");
   do
   {  
      
      
      printf("Enter the choice:");
      scanf("%d",&ch);
      switch (ch)
      {
         case 1:
             newnode=getNode();
             if(newnode==NULL)
             {
                printf("No space");
                break;
              }
             else
             {  
                
                printf("\nEnter the element and position to be inserted: ");
                scanf("%d %d",&X,&pos);
                insert(X,pos);
               }
              break;
         case 2:
            	printf("\nEnter the position of the element to be deleted: ");
		scanf("%d",&pos);
                delete(pos);
                break;
         case 3:
             
             printf("\nEnter the element to be searched: ");
             scanf("%d",&X);
             pos=search(X);
             if(pos)
             {
                printf("Element is found and the position= %d",pos);
              }
             else
             {
                printf("Element not found");
              }
              break;
         case 4:
             traversal();
             break;
         case 5:
             break;
        }
   }while(ch<5);
}

void insert(int X,int pos)
{  
   int count;
  
   if(pos==1)
   {
      if(head==NULL)
      {
          newnode->data=X;
          newnode->link=NULL;
          head=newnode;
       }
      else
      {
         newnode->data=X;
         newnode->link=head;
         head=newnode;
       }
   }
   while(temp!=NULL)
       {
          count++;
          temp=temp->link;
        }
   if(pos==count+1)
   {
     if(head==NULL)
     {
         newnode->data=X;
         newnode->link=NULL;
         head=newnode;
      }
     else
     {   
         newnode->data=X;
         temp=head;
         while(temp->link!=NULL)
         {
            temp=temp->link;
          }
         temp->link=newnode;
       }
     }
    else
    {  
       
       count=0;
      
       temp=head;
       while(temp!=NULL)
       {
          count++;
          temp=temp->link;
        }
       if(pos>count+1 || pos<1)
       {
          printf("invalid position");
        }  
       else
       {
          newnode->data=X;
          if(pos==1)
          {
             head=newnode;
           }
          else
          {
             int c=1;
             temp=head;
             while(c<pos-1)
             {
                temp=temp->link;
                c++;
              }
             newnode->link=temp->link;
             temp->link=newnode;
           }
          }
        }
	
}
void delete(int pos)
{
   int count=0;
   if(pos==1)
   {
      if(head==NULL)
      {
         printf("List is empty\n");
       }
      else
      {
         temp=head;
         head=head->link;
         free(temp);
       }
     }
    while(temp!=NULL)
       {
          count++;
          temp=temp->link;
        }
    if(pos==count)
    {
      if(head==NULL)
      {
         printf("List is empty\n");
       }
      else
      {
         temp=head;
         while(temp->link!=NULL)
         {
            temp1=temp;
            temp=temp->link;
          }
         temp1->link=NULL;
         free(temp);
       }
      }
     else
     {
       
       temp=head;
       while(temp!=NULL)
       {
          count++;
          temp=temp->link;
        }
       if(pos>=count+1 || pos<1)
       {
          printf("Invalid position");
        }
       else
       {
          if(pos==1)
          {
             temp=head;
             free(temp);
           }
          else
          {
             int c=1;
             temp=head;
             while(c<pos-1)
             {
                temp=temp->link;
                c++;
              }
             temp1=temp->link;
             temp->link=temp1->link;
             free(temp1);
           }
         }
       }
  }
int search(int X)
{
   int pos=1;
   temp=head;
   while(temp!=NULL)
   {
      if(temp->data==X)
      {
         return pos;
       }
      else
      {
         pos++;
         temp=temp->link;
       }
   }
}
void traversal()
{
   temp=head;
   while(temp!=NULL)
   {
       printf("%d\n",temp->data);
       temp=temp->link;
    }
}
