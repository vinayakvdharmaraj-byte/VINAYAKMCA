#include <stdio.h>
#define SIZE 5
int main()
{
	int stack[SIZE],top=-1;
	int choice, value,i;
	do
	{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\n.Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if (top==SIZE-1)
					printf("Stack Overflow ");
				else
				{
					printf("enter value:");
					scanf("%d",&value);
					stack[++top]=value;
					printf("Element pushed");
				}
				break;
			case2:
				if(top==-1)
					printf("stack underflow");
				else
					printf("popped element: %d",stack[top--]);
				break;
			case3:
				if(top==-1)
					printf("stack is empty");
				else
				{
					printf("stack elements:");
					for(i=top;i>=0;i--)
						printf("%d",stack[i]);
				}
				break;
			case4:
				printf("Exit");
				break;
			default:
				printf("invalid choice");
		}
	} while(choice !=4);
		return 0;
	}
		
