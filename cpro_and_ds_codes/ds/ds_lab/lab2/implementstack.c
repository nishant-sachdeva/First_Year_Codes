#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void display();
int size=10;
int stack[10];
int top=-1;
void main()
{
	int value;
	int choice;
	while(1)
	{
		printf("Enter 1-Push,2-Pop,3-Display,4-Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter value to insert\n");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				//printf("Enter value to Delete\n");	
				//scanf("%d",&value);
				pop();
				break;
			case 3:
				//printf("Enter value to Display\n");
				//scanf("%d",value);
				display();
				break;
			case 4: exit(0);
		}
	}
}
void push(int value)
{
	if(top == size-1) printf("Stack is full ,Not Possible\n");
	else
	{
		top++;
		stack[top] = value;
		printf("Insertion Success\n");
	}
}
void pop()
{
	if(top == -1)
		printf("Stack is empty,Not Possible\n");
	else {
		printf("Deleted\n");
		top--;
	}

}
void display()
{
	if(top == -1) printf("Stack is empty\n");
	else {
		printf("Elemens are ---\n");
		for(int i=top;i>=0;i--)
			printf("%d\n",stack[i]);
	}
}	
