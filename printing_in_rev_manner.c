#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}NODE;

NODE* head=NULL;

int length(void)
{
    NODE* temp;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

void sorting(void)
{
    int count,i,j;
    NODE *temp1,*temp2;
    count=length();
    for(i=1;i<count;i++)
    {
        temp1=head;
        temp2=temp1->next;
        for(j=0;j<count-i;j++)
        {
            temp2=temp1->next;
            if(temp1->data>temp2->data)
            {
                int temp;
                temp=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp;
            }
            temp1=temp2;
        }
    }
}

void printrev(void)
{
    int count,i;
    NODE *temp,*prev;
    temp=head;
    i=linkListLength();
    for(;i>0;i--)
    {
        count=0;
        while(temp!=NULL)
        {
            if(count==i)
            {
                break;
            }
            prev=temp;
            temp=temp->next;
            count++;
        }
        printf("%d->",prev->data);
        temp=head;
    }
    printf("\n");
}

void addnode(void)
{
    int num;
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    
    printf("Enter the Number\n");
    scanf("%d",&num);
    
	temp->data=num;
    temp->next=NULL;
    
	if(head==NULL)
    {
        head=temp;
    }
    else
    {
        NODE* temp1;
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

void display(void)
{
    NODE* temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void rev(void)
{
    NODE *curr,*prev,*next;
    curr=head;
    prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}


int main()																			//main program starts here.
{
    int num,i;
    printf("Enter the 5 number in list\n");
    for(i=0;i<5;i++)
    {
        addnode();
    }
    display();
//    sorting();
//    display();
//    printrev();
    rev();
    display();
    return 0;
}

