#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *llink;
  struct node *rlink;
};
struct node *ptr,*start=NULL,*temp;
void insert()
{
  temp=(struct node *)malloc(sizeof(struct node));
  printf("Enter data");
  scanf("%d",&temp->data);
  temp->rlink=NULL;
  temp->llink=NULL;
  if(start==NULL)
  {
    start=temp;
  }
  else
  {
    ptr=start;
    if(temp->data < start->data)
    {
      temp->rlink=start;
      start->llink=temp;
      start=temp;
    }
    else
    {
      while(ptr->rlink!=NULL && temp->data > ptr->data)
      {
        ptr=ptr->rlink;
      }
      if (ptr -> rlink == NULL && ptr->data < temp ->data ) 
      {
        ptr->rlink=temp;
        temp->llink=ptr;
      }
      else 
      {
        temp->llink=ptr->llink;
        temp->rlink=ptr;
        ptr->llink->rlink = temp;
        ptr->llink=temp;
      }
      

    }
  }
}
void display()
{
  ptr=start;
  while (ptr != NULL)
  {
    printf("%d-->", ptr->data);
    ptr = ptr->rlink;
  }
}
void main()
{ 
    int ch;
    while (1)
    {
      printf("\n1: INSERT 2: DISPLAY 3:EXIT");
      scanf("%d", &ch);
      switch(ch)
      {
          case 1: insert();
                  break;
          case 2: display();
                  break;
          case 3: exit(0);
      }
    }
}