//program for circular linked list using head as traversal.

#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node* head=NULL;



void display(void)							//function to display the nodes.
{
	struct node* trav;
	trav=head;
	do
	{
		trav=trav->next;
		printf("%d->",trav->data);
				
	}while(trav!=head);
	printf("\n");
}

int is_empty(void)						//checking whether list is empty or not.
{
	if(head==NULL)
		return 0;
	else
		return 1;	
}
struct node* new_node(void)										// creating a node.
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	return temp;
}
void add_first(void)								//adding node at first.
{
	struct node* temp;
	temp=new_node();
	if(is_empty()==0)
	{
		head=temp;
		temp->next=head;
	}
	else
	{
		temp->next=head->next;
		head->next=temp;
	}
}
void add_last(void)							//adding node at the last.
{
	if(is_empty()==0)
	{
		add_first();
	}
	else
	{
		struct node* temp;
		temp=new_node();
		temp->next=head->next;
		head->next=temp;
		head=temp;
	}
}
int length(void)						//function to give lenfth of the list.
{
	if(is_empty()==0)
	{
		return 0;
	}
	else
	{
		struct node* trav;
		int count=0;
		trav=head;
		do
		{
			trav=trav->next;
			count++;
					
		}while(trav!=head);
		return count;
	}
}
void add_pos(void)							//function to add node at a perticular position.
{
	int pos;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		add_first();
	}
	else if(pos==length()+1)
	{
		add_last();
	}
	else if(pos<=length())
	{	
		struct node *trav,*temp,*prev;
		temp=new_node();
		int count=0;
		trav=head;
		do
		{
			prev=trav;
			trav=trav->next;
			count++;
						
		}while(pos!=count);	
		temp->next=prev->next;
		prev->next=temp;
	}
}
void delete_first(void)						//function to delete the first node.
{
	if(is_empty())
	{
		struct node* temp;
		temp=head->next;
		head->next=head->next->next;
		free(temp);		
	}
	else
	{
		printf("Link List Is Empty\n");
	}
}
void delete_last(void)							//function to delete last node.
{
	if(is_empty())
	{
		struct node *prev,*trav;
		trav=head;
		do
		{
			prev=trav;
			trav=trav->next;
						
		}while(trav!=head);	
		prev->next=head->next;
		head=prev;
		free(trav);
	}
	else
	{
		printf("Link List Is Empty\n");
	}
}
void delete_pos(void)								//deleting node at a perticular position.
{
	int pos;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		delete_first();
	}
	else if(pos==length())
	{
		delete_last();
	}
	else if(pos<length())
	{
		struct node *prev,*trav;
		int count=0;
		trav=head;
		do
		{
			prev=trav;
			trav=trav->next;
			count++;
		}while(count!=pos);
		prev->next=trav->next;
		free(trav);
	}
}


int main()								//main program sstarts from here.
{
	int choice;
	while(1)
	{
		printf("***************CIRCULAR LINKED LIST PROGRAM***********************\n\n");
		printf(" 1.Add_at_First\t2.Add_at_Last\t3.Add_@_Position\n");
		printf(" 4.Delete_First\t5.Delete_Last\t6.Delete_@_Position\n");
		printf(" 7.Length\t8.Display\t9.Exit\n");
		
		
		printf("\nEnter Your Choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				add_first();
				sleep(2);
				system("cls");
				break;
				
			case 2:
				add_last();
				sleep(2);
				system("cls");
				break;
				
			case 3:
				add_pos();
				sleep(2);
				system("cls");
				break;
				
			case 4:
				delete_first();
				sleep(2);
				system("cls");
				break;
				
			case 5:
				delete_last();
				sleep(2);
				system("cls");
				break;
				
			case 6:
				delete_pos();
				sleep(2);
				system("cls");
				break;
				
			case 7:
				length();
				sleep(2);
				system("cls");
				break;
				
			case 8:
				display();
				sleep(2);
				system("cls");
				break;
				
			case 9:
				exit(0);
				
			default:
				printf("Please enter a valid choice\n");
				sleep(2);
				system("cls");
				break;	
		}
	}
return 0;
}											//end of the main program.


/****************************OUTPUT_OF THE_ABOVE_PROGRAM***********************************************************

***************CIRCULAR LINKED LIST PROGRAM***********************

 1.Add_at_First 2.Add_at_Last   3.Add_@_Position
 4.Delete_First 5.Delete_Last   6.Delete_@_Position
 7.Length       8.Display       9.Exit

Enter Your Choice


*/

