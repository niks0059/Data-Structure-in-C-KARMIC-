//Program for implementing stack using arrays.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[10],top=-1,ch,j;											//declaring array and variables	
	while(1)																//runnning the code continuosly
	{
		printf("stack program\n");
		printf("1.push\n2.pop\n3.display\n4.exit\n\n");
		
		printf("enter your choice\n");								//taking input from the user to perform perticular operation
		scanf("%d",&ch);
		
		
		switch(ch)
		{
			case 1:
				top++;													//logic for adding the element onto the stack
				printf("enter element to add on stack\n");
				scanf("%d",&arr[top]);
				system("cls");
				break;
				
			case 2:
				arr[top]=0;											//logic for removing the element from the stack
				top--;
				system("cls");
				break;			
				
			case 3:
				if(top<0)											//displaying the stack
				{
					printf("no elements present\n");
				}
				for(j=top;j>=0;j--)
				{
					printf("%d\n",arr[j]);
				}
				sleep(5);
				system("cls");
				break;
				
			case 4:
				printf("THANK YOU!\n");							//logic for exiting the program
				exit(0);
				break;
			
			default:
				printf("something went wrong!\n");					//logic for invalid input from user
				system("cls");
		}		
	}
	return 0;				//sucessful complition of program		
}


