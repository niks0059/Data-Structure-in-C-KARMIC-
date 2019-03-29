//A Simple Program to demonstrate simple concept of Abstract data type(QUEUE) in C.

#include<stdio.h>					//including header file for std i.p o/p operations.			
#define SIZE 5						//definning the necessary micros.									
#define MINUS_ONE -1

int arr[SIZE],front=MINUS_ONE,rear=MINUS_ONE;			//initializing the array with front and rear as references.(globally)

void enq(int x)										//function for entering element onto the queue.
{
	if(isfull())							
	{
		printf("queue is full\n");					//checking whether queue is full or not.
	}
	else
	{
		if(isempty())							//check for queue empty
		{
			rear=0;
			front=0;
			arr[rear]=x;
		}
		else
		{
			rear++;
			if(isfull())
				printf("queue is full\n");			
			else
				arr[rear]=x;									//inserting element into the queue at rear end.
		
		}
	}
}


int isempty()															//function to checck whether queue is empty or not.
{
	if(front==MINUS_ONE && rear==MINUS_ONE)
		return 1;
	else
		return 0;
}

void display()											//function for displaying the queue.
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}


int isfull()								//function to check whether queue is full or not.
{
	if(rear+1>=SIZE)
		return 1;
	else
		return 0;
}

void deq(void)												//function to delete element from the queue.
{
	if(isempty())
	{
		printf("no more elements to dequeue\n");
	}
	else
	{
		arr[front]=0;
		front++;
	}
	
}


int main()										//main program starts from here.
{
	enq(5);
	enq(4);
	enq(2);										//function calls.
	enq(1);								
	display();
	deq();
	display();
	
return 0;									//end of main sucessfully if returned 0. 
}
