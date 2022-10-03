#include<stdio.h>
#include<stdlib.h>
#define size 12
int binary(int a[],int low,int high,int item)
{
  int mid=(low+high)/2;
  if(low>high)
  {
    return -1;
  }
  else if(a[mid]==item)
  {
    return mid;
  }
  else if(a[mid]<item)
  {
    binary(a,mid+1,high,item);
  }
  else
    binary(a,low,mid-1,item);
}
void main()
{
  int a[size],n,pos,item,i;
  printf("Enter the length of array");
  scanf("%d",&n);
  printf("Enter the elements in ascending order");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the element to be searched");
  scanf("%d",&item);
  pos=binary(a,0,n-1,item);
  if(pos==-1)
    printf("Element not found");
  else
    printf("Element %d found at %d",item,pos+1);

}