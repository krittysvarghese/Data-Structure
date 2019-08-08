#include<stdio.h>

void sort(int arr[],int n)
{
 int temp;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n-1-i;j++)
  {
   if(arr[j+1]<arr[j])
   {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
 }
 printf("\n Sorted array:\n");
  for(int i=0;i<n;i++)
  {
    printf("\t %d",arr[i]);
  }
}
int binarysearch(int arr[],int n,int key,int l,int h)
{
 int mid;
  if(l>h)
   return -1;

  mid=(l+h)/2;
  if(arr[mid]==key)
    return mid;
  else if(key>arr[mid])
    binarysearch(arr,n,key,mid+1,h);
  else
    binarysearch(arr,n,key,l,mid-1);
}


int main(void)
{
  int arr[20],n,k,key,i,j,c;
  int l=0,h;
  printf("\n Enter the number of elements in the array:");
  scanf("%d",&n);
  printf("\n Enter the elements:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
 
  h=n-1;
  sort(arr,n);
   printf("\n Enter the element to be searched:");
  scanf("%d",&key);
  c=binarysearch(arr,n,key,l,h);
  if(c==-1)
   printf("\n Element not found \n");
  else
   printf("\n Element found at posiion %d \n ",c+1);
  
  return 0;
}
