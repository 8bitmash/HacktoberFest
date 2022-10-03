#include<stdio.h>
#include<stdlib.h>
void toh(int n,char source,char temp,char dest)
{
  if(n==1)
    printf("%c-->%c\n",source,dest);
  else
  {
    toh(n-1,source,dest,temp);
    printf("%c-->%c\n",source,dest);
    toh(n-1,temp,source,dest);
  }
}
void main()
{
  int n;
  printf("Enter the number of disks \n");
  scanf("%d",&n);
  toh(n,'A','B','C');
}