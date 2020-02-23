# define SIZE 5
#include <stdio.h>
#include <stdlib.h>
typedef enum{EXIT,PUSH,POP}MENU;
struct student
{
	char name[20];
	int roll, std;
	int marks[6];
	char sub[10][20];
};
int rear=-1, front=-1;
struct student s[SIZE];
MENU choice();
int isFull();
int isEmpty();
void Push();
void Pop();
int main(void) {
	MENU ch;

	while((ch=choice())!=EXIT)
	{
		switch(ch)
		{
		case PUSH:
			if(isFull())
				printf("\n--------Overflow----------");
			else
				Push();
			break;
		case POP:
			if(isEmpty())
				printf("\n--------Underflow----------");
			else
				Pop();
			break;
		}

	}
	return EXIT_SUCCESS;
}
int isEmpty()
{
	if(rear=-1&& front==rear)
		return 1;
	else
		return 0;
}
int isFull()
{
	if((rear==SIZE-1 &&front==0) || rear==front-1)
		return 1;
	else
		return 0;
}
void Push()
{
	rear= (rear +1) % SIZE;
	printf("\nEnter student name, Roll number & standard");
	scanf("%s%d%d",&s[rear].name,&s[rear].roll,&s[rear].std);
	int i;
	for(i=0;i<6;i++)
	{
		printf("\nEnter subject%d name & its marks",i+1);
		scanf("%s%d",&s[rear].sub[i],&s[rear].marks[i]);
	}
	if(front==-1)
		front++;
	printf("\nStudent information is added");
}

void Pop()
{
	if(rear==front)
		rear=front=-1;
	else
		front=(front+1)%SIZE;
	printf("\nStudent information is deleted successfully");
}

MENU choice()
{
	MENU ch;
	setvbuf(stdout,NULL,_IONBF,0);
	printf("\nEnter your choice \n 0.Exit \n 1.Push \n 2.Pop");
	scanf("%d",&ch);
	return ch;
}
