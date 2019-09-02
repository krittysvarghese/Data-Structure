#include<stdio.h>
void insertsort(int arr[50],int n)
{
 int i,element,pos;
 for(i=1;i<n;i++)
   {
    element=arr[i];
    pos=i;
    while(pos>0 & arr[pos-1]>element)
     {
      arr[pos]=arr[pos-1];
      pos=pos-1;
     }
     arr[pos]=element;
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
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 insertsort(arr,n);
 return 0;
}
