#include<stdio.h>
void selectsort(int arr[50],int n)
{
 int i,min,pos,j;
 for(i=0;i<n-1;i++)
 {
  min=i;
  for(j=i+1;j<n;j++)
  {
   if(arr[j]<arr[min])
   {
    min=j;
   }
  }
  if(min!=i)
  {
   pos=arr[i];
   arr[i]=arr[min];
   arr[min]=pos;
  }
 }
 printf("the sorted array is");
 for(i=0;i<n;i++)
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
 selectsort(arr,n);
 return 0;
}
