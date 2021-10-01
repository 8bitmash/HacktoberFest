#include<stdio.h>
#include<stdlib.h>
#define size 15
int q[size],front=-1,rear=-1;
void insert(int item)
{
  if(rear==size-1)
      printf("Queue is full");
  else
  {
    if(front==-1)
      front++;
    rear++;
    q[rear]=item;
  }
}
void delete()
{
  if(rear==-1)
    printf("Queue is empty");
  else
  {
    printf("Deleted item is %d\n",q[front]);
    if(front==rear)
      front=rear=-1;
    else
      front++;
  }
}
void display()
{
  int i=0;
  if(rear==-1)
    printf("Queue is empty");
  else
  {
    for(i=front;i<=rear;i++)
    {
      printf("%d-->",q[i]);
    }
  }
}
void main()
{
  int item,ch;
  while(1)
  {
    printf("\n1.INSERT 2.DELETE 3.DISPLAY 4.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter item");
            scanf("%d",&item);
            insert(item);
            break;
      case 2:delete();
            break;
      case 3:display();
            break;
      case 4:return;
    }
  }
}