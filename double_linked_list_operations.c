#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* head=NULL;

int length(void)
{
    int count=0;
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

   

struct node* newNode(void)
{
	
	int num;
	struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
   
    printf("Enter The Element\n");
    scanf("%d",&num);
    
    temp->prev=NULL;
    temp->data=num;
    temp->next=NULL;
}
void addLast(void)
{

    if(head==NULL)
    {
        head=newNode();
    }
    else
    {
        struct node* temp;
		struct node* temp1;
        temp1=head;
        temp=newNode();
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
    }
}
void addFirst(void)
{
    struct node* temp;
    temp=newNode();
    temp->next=head;
    head=temp;
}
void addPos(void)
{
    int pos,num,len;
    pos=inputIndex();
    len=linkListLength();
    printf("length=%d\n",len);
    
    if(pos==1)
    {
        addFirst();
    }
    else if(len>=pos-1)
    {

        int count=1;
        struct node* temp;
        temp=head;
        while(pos!=count+1)
        {
            count++;
            temp=temp->next;
        }
        struct node* newnode*travnext;
        newnode=newNode();

        newnode->prev=trav;
        newnode->next=trav->next;
        trav->next=newnode;
    }
    else
    {
        printf("Invalid Position\n");
    }
}
int inputIndex(void)
{
    int indx;
    printf("Enter the position\n");
    scanf("%d",&indx);
    return indx;
}
void display(void)
{
    NODE *temp;
    temp=head;
    if(temp!=NULL)
    {

        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("Link List is Empty\n");
    }

}
void deleteFirst(void)
{
    NODE *temp;
    if(head==NULL)
    {
        printf("Link Is Empty\n");
    }
    else
    {
        if(head->next==NULL)
        {
            temp=head;
            printf("%d elememnt deleted\n",temp->data);
            head=NULL;
            free(temp);

        }
        else
        {
            temp=head;
            printf("%d element deleted\n",temp->data);
            head=head->next;
            head->prev=NULL;
            free(temp);
        }
    }
}
void deleteLast(void)
{
    if(head==NULL)
    {
        printf("Link List Is Empty\n");
    }
    else
    {
        if(head->next==NULL)
        {
            printf("%d Element deleted\n",head->data);
            head=NULL;
        }
        else
        {
            NODE *trav,*temp;
            trav=head;
            while(trav->next!=NULL)
            {
                temp=trav;
                trav=trav->next;
            }
            printf("%d Element deleted\n",trav->data);
            temp->next=NULL;
            free(trav);
        }
    }
}
void deletePos(void)
{
    int pos,len,count=1;
    printf("Enter the Pos\n");
    scanf("%d",&pos);
    len=linkListLength();
    if(pos<=len)
    {
        NODE *trav,*temp;
        trav=head;
        while(count!=pos)
        {
            temp=trav;
            trav=trav->next;
            count++;
        }
        printf("%d element is deleted\n",trav->data);
        temp->next=trav->next;
        free(trav);
    }
}
void reverseList(void)
{
    NODE *trav,*temp;
    trav=head;
    while(trav->next!=NULL)
    {
        trav=trav->next;
    }
    while(trav!=NULL)
    {
        printf("%d->",trav->data);
        trav=trav->prev;
    }
    printf("\n");
}


int main()
{
    int choice;
    
    while(1)
    {	
		printf("***********PROGRSM FOR DOUBLE LINKED LIST******************\n");
        printf("1.ADD_AT_BEGIN\n 2.ADD_AT_LAST 3.ADD_AT_MIDDLE\n.");
        printf("4.DEL_FROM_FIRST\n 5.DEL_FROM_LAST 6.DELETE_MIDDLE\n")
        printf("7.REVERSE_LIST\n 8.LENGTH_OF_LIST 9.DISPLAY_THE_LIST\n")
        
		printf("Enter the Your Choice\n");
        scanf("%d",&choice);
       
	    switch(choice)
        {
            
            case 1:
                //linkLen=linkListLength();
                printf("Link List Length is %d\n",linkListLength());
                break;
            case 2:    addLast();
                break;
            case 3: addFirst();
                break;
            case 4: addPos();
                    break;
            case 5: deleteFirst();
                    break;
            case 6: deleteLast();
                    break;
            case 7:
                    deletePos();
                    break;
            case 8:
                    reverseList();
                    break;
            default:
                printf("Invalid Choice\n");
        }
    }while(1);
}

