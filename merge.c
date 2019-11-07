#include<stdio.h>
#define max 20
int a[max];

void merge(int lb,int mid,int ub)
{
 int temp[max];
 int i,j,k;
 i=lb;
 j=mid+1;
 k=0;
 while(i<=mid && j<=ub)
 {
  if(a[i]<a[j])
  {
   temp[k]=a[i];
   i++;
   k++;
  }
  else
  {
   temp[k]=a[j];
   j++;
   k++;
  }
 }
 while(i<=mid)
 {
  temp[k]=a[i];
  i++;
  k++;
 }
 while(j<=ub)
 {
  temp[k]=a[j];
  j++;
  k++;
 }
 for(i=lb,k=0;i<=ub;i++,k++)
 {
  a[i]=temp[k];
 }
}
void mergesort(int lb,int ub)
{
 int mid;
 if(lb<ub)
 { 
  mid=(lb+ub)/2;
  mergesort(lb,mid);
  mergesort(mid+1,ub);
  merge(lb,mid,ub);
 }
}
int main(void)
{
 int n;
 printf("\nEnter the size of the array:");
 scanf("%d",&n);
 printf("\nEnter the elements:");
 for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
 mergesort(0,n-1);
 printf("\nSorted array:\n");
 for(int i=0;i<n;i++)
  printf("\t%d",a[i]);
 printf("\n");
}
