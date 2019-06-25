// Program for binary trees in C.
#include<stdio.h>
#include<stdlib.h>
typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
}NODE;
NODE* Insert(NODE *root,int data);

void display(NODE* temp)
{
	if(temp!=NULL)
	{
		printf("%d-",temp->data);
		display(temp->left);
		
		display(temp->right);
	}
}

int find_height(NODE* root,int level)						//function for finding height of the tree.
{
	static int height;
	if(root!=NULL)
	{
		find_height(root->left,level+1);
		find_height(root->right,level+1);
	}
		
	if(height<=level)
	{
		height=level;
	}
	return height;
}
NODE* getNewNode(int data)
{
    NODE *newNode;
    newNode=(NODE*)malloc(sizeof(NODE));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void find_min(NODE *root)								//function for finding smallest element in the given tree
{
	int temp1;
	NODE *temp;
	temp=root;
	//temp1=temp->left;
	temp1=temp->data;
	
	while(temp->left!=NULL)
	{	
		if(temp1>=temp->data)
		{
			temp1=temp->data;
		}
	temp=temp->left;
	}
	printf("\nsmallest data int the tree is %d",temp->data);	
}

void find_max(NODE *root)								//function for finding largest element in the given tree
{
	int temp1;
	NODE *temp;
	temp=root;
	temp1=temp->data;
	
	while(temp->right!=NULL)
	{	
		temp=temp->right;
	}
	printf("\nlargest data in the tree is %d\n",temp->data);	
}



NODE* Insert(NODE *root,int data)
{
    NODE *newNode;
    newNode=getNewNode(data);
    if(root == NULL)
    {
        root=newNode;
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}

void pretrav(NODE* temp)
{
	if(temp!=NULL)
	{
		printf("%d-",temp->data);
		pretrav(temp->left);		
		pretrav(temp->right);
	}
}

void posttrav(NODE* temp)
{
	if(temp!=NULL)
	{
		
		pretrav(temp->left);		
		pretrav(temp->right);
		printf("%d-",temp->data);
	}
}

void intrav(NODE* temp)
{
	if(temp!=NULL)
	{
		pretrav(temp->left);
		printf("%d-",temp->data);		
		pretrav(temp->right);
	}
}


void level_order(NODE* root)
{
	NODE* temp=root;
	if(root!=NULL)
	{	
			
			level_order(root->left);	
			level_order(root);
			level_order(root->right);
				
	}
	
}


/*bool Search(BstNode* root,int data)
{
		if(root == NULL) 
			return false;
		else if(root->data == data)
			 return true;
		else if(data<=root->data) 
			return Search(root->left,data);
		else 
			return Search(root->right,data);
}*/
int main()
{
    NODE *root;
    root =NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,5);
    root=Insert(root,25);
    root=Insert(root,16);
    root=Insert(root,12);
    display(root);
    
    find_min(root);
	find_max(root);   
	int a=find_height(root,0); 
    printf("\nheight---%d\n",a);
    
    
    printf("pre-order-->  ");
	pretrav(root);
    printf("\n");
    
    printf("in-order-->  ");
    intrav(root);
    printf("\n");
     
    printf("post-order-->  ");
    posttrav(root);
    printf("\n");
    
    
    level_order(root);
}
