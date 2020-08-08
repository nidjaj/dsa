#include<stdio.h>
#include<stdlib.h>
#define Size 5
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void Push(int data)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("OverFlow");
		return;
	}
	newnode->data=data;
	newnode->next=top;
	top=newnode;
	
}
int Pop()
{
	int temp;
	struct node *ptr;
	if(top==NULL)
	{
		printf("UnderFlow\n");
		return -9999;
	}
	temp=top->data;
	ptr=top;
	top=top->next;
	ptr->next=NULL;
	free(ptr);
	return temp;
}
int Top()
{
	if(top==NULL)
	{
		printf("UnderFlow\n");
		return -9999;
	}
	return top->data;
}
int IsStackEmpty()
{
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Display()
{
	struct node *ptr=top;
	if(top==NULL)
	{
		printf("Stack is Empty:\n");
		return;
	}
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	
}
int main()
{
	int choice,data;
	do
	{
		printf("Enter Your Choicen\n1.Push\n2.Pop\n3.Top\n4.IsStackEmpty\n5.Display\n6.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Data:");
				scanf("%d",&data);
				Push(data);
				break;
			case 2: 
					Pop();
					break;
			case 3:Top();
					break;
			case 4:
				data=IsStackEmpty();
				break;
			case 5: Display();
					break;
		}
	}while(choice!=6);	
}
