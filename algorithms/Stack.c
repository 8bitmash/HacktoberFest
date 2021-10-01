#include<stdio.h>
#include<stdlib.h>
#define size 30
int s[size], top=-1,item,ditem,i;
void push()
{
  if(top==size-1)
    printf("Stack is full");
  else
  {
    printf("Enter the element\n");
    scanf("%d",&item);
    top++;
    s[top]=item;
  }
}
void pop()
{
  if(top==-1)
    printf("Stack is empty");
  else
  {
    ditem=s[top];
    printf("Deleted item is %d",ditem);
    top--;
  }
  
}
void display()
{
  if(top==-1)
    printf("Stack is empty");
  else
  {
      for(i=0;i<=top;i++)
        printf("%d-->",s[i]);
  }
}
void main()
{
  int ch;
  while(1)
  {
    printf("1.PUSH 2.POP 3.DISPLAY 4.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:push();
            break;
      case 2:pop();
            break;
      case 3:display();
            break;
      case 4:return;
    
    }
  }
}
