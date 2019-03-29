//Program for stack operation using linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}NODE;

NODE* top=NULL;	

void push(void)									//pusing the element onto the stack.
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	
	printf("Enter the Number\n");
	scanf("%d",&temp->data);
	
	temp->next=top;
	top=temp;
}
void display(void)									//displaying the elements of stack
{
	NODE *temp;
	temp=top;
	if(top!=NULL)
	{
		while(temp!=NULL)
		{
			printf("%d-> ",temp->data);
			temp=temp->next;
		}
		printf("\n");	
	}
	else
	{
			printf("Stack Underflow NO elements to display!\n");
	}
}
void pop(void)														//poping out the stack elements
{
	if(top==NULL)
	{
		printf("Stack Underflow no more elements to pop!\n");
	}
	else
	{
		top=top->next;
	}
}


int main()
{
	int ch;
	while(1)
	{
		printf("Stack operation\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				push();
				break;
				
			case 2 :
				pop();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				exit(0);
				
			default:
				printf("Invalid Choice\n");
			
		}
	}
}

