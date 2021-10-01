#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL, *ptr=NULL, *temp=NULL;
int item;
void insert_node()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
}
void count_nodes()
{
	int count=0;
	if(head==NULL)
		printf("List is empty");
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			count++;
			ptr=ptr->link;
		}
	}
	printf("Number of nodes is %d",count);
}
void display()
{
	if(head==NULL)
		printf("List is empty");
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			printf("%d-->",ptr->data);
			ptr=ptr->link;
		}
	}
}
void search_node()
{
	int item,flag=0;
	printf("Enter the item to be searched\n");
	scanf("%d",&item);
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			if(item==ptr->data)
			{	
				printf("Item found");
				flag=1;
				break;
			}	
			else 
				ptr=ptr->link;
		}
		if(flag==0)
			printf("element not found");
	}
}

void insert_beg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		temp->link=head;
		head=temp;
	}
}
void location_based()
{
	int count=0,pos,i;	
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("no. of nodes is %d",count);
	printf("Enter the position");
	scanf("%d",&pos);
	if(pos==1)
		insert_beg();
	else if(pos==count+1)
		insert_node();
	else if(pos>1&&pos<=count)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter the element");
		scanf("%d",&temp->data);
		temp->link=NULL;
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		temp->link=ptr->link;
		ptr->link=temp;
	}
	else
		printf("Invalid position");
}
void del_beg()
{
	if(head==NULL)
		printf("Empty");
	else
	{
		ptr=head;
		head=head->link;	
		free(ptr);
	}
}
void del_end()
{
	if(head==NULL)
		printf("Empty");
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			temp=ptr;
			ptr=ptr->link;
		}
	temp->link=NULL;
	free(ptr);
	}
}
void del_location_based()
{
	int loc,count=0,i;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}

	printf("No. of nodes is %d",count);
	printf("enter the location");
	scanf("%d",&loc);
	if(loc==1)
		del_beg();
	else if(loc==count)
		del_end();
	else if(loc>1&&loc<=count)
	{
		ptr=head;
		for(i=1;i<loc;i++)
		{
			temp=ptr;	
			ptr=ptr->link;
		}
		temp->link=ptr->link;
	}
	else
 		printf("Invalid position");
}
void reverse()
{
	 struct node *current;
	if(head!=NULL)
	{
		ptr=head;
		ptr=ptr->link;		
		temp=head;
		current=head;
		current=current->link;
		temp->link=NULL;
		while(ptr!=NULL)
		{
			ptr=ptr->link;	
			current->link=temp;
			temp=current;
			current=ptr;
		}
		head=temp;

	}
}
void sort()
{   int count=0,i,j;
	temp=(struct node*) malloc(sizeof(struct node));
	if(head==NULL)
		printf("List is Empty\n");
	else
	{   ptr=head;
	    while(ptr!=NULL)
    	{
		    count++;
		    ptr=ptr->link;
    	}
		for(i=0;i<count-1;i++)
		{
			ptr=head;
			for(j=0;j<count-i-1;j++)
			{
				if((ptr->data)>(ptr->link)->data)
				{
					temp->data=ptr->data;
					ptr->data=(ptr->link)->data;
					(ptr->link)->data=temp->data;
				}
				ptr=ptr->link;
			}
		}
		free(temp);
	
	}	
}	

		
	
	
		
void main()
{
	int ch;
	while(1)
	{
		printf("\n1.INSERT  2.COUNT  3.DISPLAY  4.SEARCH  5.INSERT_BEG  6.LOCATION_BASED  7.DELETE_BEG  8.DELETE_END  9.DELETE_LOCATION-BASED  10.REVERSE  11.SORT  12.EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_node();
				break;
			case 2:count_nodes();
				break;
			case 3:display();
				break;
			case 4:search_node();
				break;	
			case 5:insert_beg();
				break;
			case 6:location_based();
				break;
			case 7:del_beg();
				break;
			case 8:del_end();
				break;
			case 9:del_location_based();
				break;
			case 10:reverse();
				break;
			case 11:sort();
			        break;
			case 12:return;
		}
	}
}