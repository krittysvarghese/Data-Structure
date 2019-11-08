#include<stdio.h> 
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *lchild, *rchild;
}node;
struct node *root=NULL;
struct node *newnode;
struct node *ptr;
struct node *p, *parent;

 
void preorder(node *p)
{
  if(p!=NULL)
    {
      printf("\t%d",p->data);
      preorder(p->lchild);
      preorder(p->rchild);
    }
}
 
void inorder(node *p)
{
  if(p!=NULL)
    {
      inorder(p->lchild);
      printf("\t%d",p->data);
      inorder(p->rchild);
    }
}
 
void postorder(node *p)
{
  if(p!=NULL)
    {
      postorder(p->lchild);
      postorder(p->rchild);
      printf("\t%d",p->data);
    }
}
 
void search(int key)
{
 ptr=root;
 int flag=0;
 while((ptr!=NULL)&&(flag==0))
 {
  if(key<ptr->data)
   ptr=ptr->lchild;
  else if(key>ptr->data)
   ptr=ptr->rchild;
  else
   flag=1;
 } 
 if(flag==1)
  printf("\nKey found");
 else
  printf("\nKey not found");
}

void insert(int key)
{
 node*newnode,*parent;
 newnode=(node *)malloc(sizeof(node));
 if(newnode==NULL)
 {
  printf("\nNo space");
  return;
 }
 else
 {
 newnode->data=key;
 newnode->lchild=NULL;
 newnode->rchild=NULL;
 if(root==NULL)
 {
  root=newnode;
  return;
 }
 else
 {
 ptr=root;
 int flag=0;
 while((ptr!=NULL)&&(flag==0))
 {
  if(key<ptr->data)
  {
   parent=ptr;
   ptr=ptr->lchild;
  }
  else if(key>ptr->data)
  {
   parent=ptr;
   ptr=ptr->rchild;
  }
  else
   flag=1;
 } 
 if(flag==1)
  printf("\nValue exists");
 else
 {
  if(key>parent->data)
  {
   parent->rchild=newnode;
  }
  else
   parent->lchild=newnode;
 }
 }
 }
}
 


void delete(int key)
{
  int flag=0;
  node*ptr=root,*parent=root;
  if(root==NULL)
  {
  printf("\nBST Empty");
  return;
  }
  while (ptr!=NULL){
    if(key==ptr->data){
      flag=1;
      break;
    }
    else if(key<ptr->data){
      parent=ptr;
      ptr=ptr->lchild;
    }
    else{
      parent=ptr;
      ptr=ptr->rchild;
    }
  }
  if (flag==0)
    printf("Element not found\n");
  else{
    
    if (ptr->lchild==NULL&&ptr->rchild==NULL){
      if(ptr==root){
	root=NULL;
      }
      else{
	if (parent->lchild==NULL){
	  parent->rchild=NULL;
	}
	else if ((parent->lchild)->data==ptr->data){
	  parent->lchild=NULL;
	}
	else{
	  parent->rchild=NULL;
	}
      }
    }
    else if(ptr->lchild!=NULL&&ptr->rchild==NULL){
      if ((parent->lchild)->data==ptr->data){
	parent->lchild=ptr->lchild;
      }
      else{
	parent->rchild=ptr->lchild;
      }
    }
    else if(ptr->lchild==NULL&&ptr->rchild!=NULL){
      if ((parent->lchild)->data==ptr->data){
	parent->lchild=ptr->rchild;
      }
      else{
	parent->rchild=ptr->rchild;
      }
    }
    else{
      int i;
      node*succ;
      succ=ptr->rchild;
      while(succ->lchild!=NULL){
	succ=succ->lchild;
      }
      i=succ->data;
      delete(succ->data);
      ptr->data=i;
    }
  }
 
}

int main(void)
{
 int ch,x;
 printf("\n\t\tMENU\n1.INSERT\n2.SEARCH\n3.DELETE\n4.TRAVERSE\n5.EXIT"); 
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  if(ch==5)
   break;
  switch(ch)
  {
   case 1: printf("\nEnter the element to be inserted:");
           scanf("%d",&x);
           insert(x);
           break;
   case 2: printf("\nEnter the element to be searched:");
           scanf("%d",&x);
           search(x);
           break;
   case 3: printf("\nEnter the element to be deleted:");
           scanf("%d",&x);
           delete(x);
           break;
   case 4: printf("\n1.Preorder traversal\n2.Inorder traversal\n3.Postorder traversal\nEnter your choice:");
           scanf("%d",&x);
           p=root;
           if(root==NULL)
             printf("\nTree empty");
           else if(x==1)
            preorder(root);
           else if(x==2)
            inorder(root);
           else
            postorder(root);
           break;
   default:printf("\nInvalid choice!");
  }
 }
}


 

 
