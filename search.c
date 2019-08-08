#include<stdio.h>

int linearsearch(int arr[],int n,int key)
{
 for(int i=0;i<n;i++)
 {
  if(arr[i]==key)
  {
    return i;
  }
 }
  return -1;
}

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
}
int binarysearch(int arr[],int n,int key)
{
 sort(arr,n);
 printf("\n Sorted array:\n ");
 for(int i=0;i<n;i++)
  {
    printf("\t %d",arr[i]);
  }
 int l,h,mid;
 l=0;
 h=n;
 while(l<=h)
 {
  mid=(l+h)/2;
  if(arr[mid]==key)
    return mid;
  else if(key>arr[mid])
    l=mid+1;
  else
    h=mid-1;
 } 
 
 return -1;
}


int main(void)
{
 int arr[20],n,k,key,i,j,c;
 while(1)
 {

  printf("\n\n 1.Linear Search \n 2.Binary Search \n 3.Exit \n Enter your choice:");
  scanf("%d",&k);
  if(k==3)
  {
    break;
  }
  printf("\n Enter the number of elements in the array:");
  scanf("%d",&n);
  printf("\n Enter the elements:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("\n Enter the element to be searched:");
  scanf("%d",&key);
  switch(k)
  {
   case 1:c=linearsearch(arr,n,key);
          if(c==-1)
          {
            printf("\n Element not found");
          }
          else
          {
            printf("\n Element found at index position %d ",c);
          }
          break;
   case 2:c=binarysearch(arr,n,key);
          if(c==-1)
            printf("\n Element not found");
          else
            printf("\n Element found at position %d in the sorted array",c+1);
          break;
   default:printf("\n Invalid choice");
  }
 }
 
}
