#include<stdio.h>
#define MAX 5
int MAT[MAX][MAX],A[MAX],Q[MAX];
int n,r=-1,f=0; 
void DFS(int i,int visited[])
{
  if(i!=n)
    {
      printf("\t%d",A[i]);
      visited[i]=1;
      for(int j=0;j<n;j++)
	if(!visited[j]&&MAT[i][j])
	  DFS(j,visited);
    }
} 
void BFS(int i,int visited[])
  
{
  for(int j=0;j<n;j++)
    if(MAT[i][j] && !visited[j])
      Q[++r]=A[j];
  if(f<=r)
    {
      visited[f]=1;
      BFS(Q[f++],visited);
    }
}
	     
 
  
int main(void)
{
  int i,j,ch;
  int visited[MAX]={0};
  printf("\nEnter the number of nodes: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   printf("\nEnter the elements: ");
   scanf("%d",&A[i]);
  }
  printf("\nEnter the adjacency matrix:\n");
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   {
    scanf("%d",&MAT[i][j]);
   }
  while(1)
  {
     printf("\n\t\tMENU\n\t1.Depth First Search\n\t2.Bredth First Search\n\t3.EXIT\nSelect the mode of traversal: ");
     scanf("%d",&ch);
     for(i=0;i<n;i++)
       visited[i]=0;
     if(ch==3)
	break;
     else if(ch==1)
	DFS(0,visited);
     else if(ch==2)
     {
       BFS(0,visited);
       for(i=0;i<n;i++)
       {
         if(visited[i])
	 {
	   printf("\t%d",A[i]);
	 }
       }
     }
     else
      printf("\nInavalid choice");
  }
}
