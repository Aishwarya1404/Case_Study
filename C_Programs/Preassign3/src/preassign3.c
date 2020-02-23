#include<stdio.h>
typedef enum {Exit,Insert, Delete,Max,Min,Sum,Display}MENU;
MENU choice();
void insert(int *);
void display(int *);
void max_no(int *);
void min_no(int *);
void delete_no(int *);
void addition(int *);
int main(void)
{
	int a[10]={0};
	MENU ch;

	while((ch=choice())!=Exit)
	{
	switch(ch)
	{
	    case Exit:
	    	break;
		case Insert:
			insert(a);
			break;
		case Delete:
			delete_no(a);
			break;
		case Max:
			max_no(a);
			break;
		case Min:
			min_no(a);
			break;
		case Sum:
			addition(a);
			break;
		case Display:
		     display(a);
			 break;
	}
 }
 return 0;
}
MENU choice()
{
	MENU ch;
	setvbuf(stdout,NULL,_IONBF,0);
		printf("\nEnter your choice:");
	printf("\n 0.Exit");
	printf("\n 1.Insert a number");
	printf("\n 2.Delete a number");
	printf("\n 3.Find Max  number");
	printf("\n 4.Find min  number");
	printf("\n 5.Addition");
	printf("\n 6.Display");
	scanf("%d",&ch);
	return ch;
}
void display(int *d)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("  %d",*(d+i));
	}
}
void insert(int *a)
{
	int i,cnt=0,num=0;
	printf("\nAvailable places are:");
	for(i=0;i<10;i++)
	{
		if(a[i]==0)
		{
			printf("  %d",i);
			cnt++;
		}
	}
	if(cnt==0)
		printf("\n---------Overflow---------");
	else
	{
		printf("\nEnter index");
		scanf("%d",& i);
		printf("\nEnter number to insert");
		scanf("%d",& num);
		a[i]=num;
		printf("\nNumber at index %d is inserted",i);

	}
}

void delete_no(int *a)
{
	int i,cnt=0;
	printf("\nAvailable places are:");
	for(i=0;i<10;i++)
	{
		if(a[i]!=0)
		{
			printf("  %d",i);
			cnt++;
		}
	}
	if(cnt==0)
		printf("\n---------Underflow---------");
	else
	{
		printf("\nEnter index");
		scanf("%d",& i);
		a[i]=0;
		printf("\nNumber at index %d is deleted",i);
    }
}

void max_no(int *a)
{
	int i, j=a[0];
	for(i=1;i<10;i++)
	{
		if(a[i]>j)
		j=a[i];
	}
	for(i=0;i<10;i++)
	{
		if(a[i]==j)
			printf("\nMaximum number is: a[%d]=%d",i,j);
	}
}
void min_no(int *a)
{
	int i, j=a[0];
	for(i=1;i<10;i++)
	{
		if(a[i]<j)
		j=a[i];
	}
	for(i=0;i<10;i++)
	{
		if(a[i]==j)
			printf("\nMinimum number is: a[%d]=%d",i,j);
	}
}

void addition(int *a)
{
	int i, index,sum;
	printf("\nAvailable places are:");
	for(i=0;i<10;i++)
	{
		if(a[i]!=0)

			printf("  %d",i);
	}
	printf("\nEnter first index");
	scanf("%d",& index);
	sum=a[index];
	printf("\nEnter second index");
	scanf("%d",& index);
	sum=sum+a[index];
	printf("\nAddition is:%d",sum);
}
