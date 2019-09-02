#include<stdio.h>
void bubble(int arr[50],int n)
{
 int i,j,temp;
 for(i=0;i<=n;i++)
 {
  for(j=0;j<=n-i;j++)
  {
   if(arr[j]>arr[j+1])
   {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
 }
 for(i=1;i<=n;i++)
 {
  printf("%d",arr[i]);
 }
}
 

int main()
{
 int arr[50],n,i;
 printf("enter the limit");
 scanf("%d",&n);
 printf("enter the array");
 for(i=0;i<=n;i++)
 {
  scanf("%d",&arr[i]);
 }
 bubble(arr,n);
 return 0;
}
  
