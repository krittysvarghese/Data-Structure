#include<stdio.h>
#define MAX 100
void heapify(int a[],int i,int n)
{
  int largest,lc,rc,temp;
  largest=i;
  lc=2*i+1;
  rc=2*i+2;
  if(a[lc]>a[largest]&&lc<n)
     largest=lc;
  if(a[rc]>a[largest]&&rc<n)
     largest=rc;
  if(i!=largest)
  {
   temp=a[i];
   a[i]=a[largest];
   a[largest]=temp;
   heapify(a,largest,n);
  }
}
void heapsort(int a[],int n)
{
  int i,temp;
 for(i=n/2-1;i>=0;i--)
   heapify(a,i,n);
 for(i=n-1;i>=0;i--)
 {
  temp=a[0];
  a[0]=a[i];
  a[i]=temp;
  heapify(a,0,i);
 }
}

int main(void)
{
  int n,a[MAX];
 printf("\nEnter the size of the array: ");
 scanf("%d",&n);
 printf("\nEnter the elements: ");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 heapsort(a,n);
 printf("\nSorted array: ");
 for(int i=0;i<n;i++)
    printf("\t%d",a[i]);
 printf("\n");

}
