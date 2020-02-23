#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {EXIT,Add_FIRST,Add_LAST,DISPLAY_F,DISPLAY_B,FIND_BY_ID,FIND_BY_NAME}MENU;
typedef struct node
{
	struct node *next;
	struct node *prev;
	int id, balance,acc_holder_contact;
	char account_type[10],acc_holder_nm[20],acc_holder_addr[20];
}NODE;
MENU choice();
NODE*head=NULL;
NODE* AddFirst();
NODE* AddLast();
void DispForward();
void DispBackward();
NODE* CreateNode();
NODE* AcceptInfo();
void FindId();
void FindName();
int main(void) {
    int ch;
    NODE *A;
    while((ch=choice())!=EXIT)
    {
    	switch(ch)
    	{
    	case Add_FIRST:
    	//   A= AcceptInfo();
    	  // printf("hello");
    	    AddFirst();
    		break;
    	case Add_LAST:
    	//	A= AcceptInfo();
    		AddLast();
    		break;
    	case DISPLAY_F:
    		DispForward();
    		break;
    	case DISPLAY_B:
    		DispBackward();
    		break;
    	case FIND_BY_ID:
    		 FindId();
    		break;
    	case FIND_BY_NAME:
    		 FindName();
    		break;
    	}
    }
	return EXIT_SUCCESS;
}
/*NODE* AcceptInfo()
{
	NODE *A;
	printf("hello");

}*/
 NODE* AddFirst()
{
	NODE *Newnode;
	Newnode=CreateNode();
	if(head==NULL)
		head=Newnode;
	else
	{
		Newnode->next=head;
		head=Newnode;
	}
	return Newnode;
}
 NODE* AddLast()
 {
	 NODE *Newnode,*trav;
	 Newnode=CreateNode();
	 if(head==NULL)
		 head=Newnode;
	 else
	 {
		 trav=head;
		 while(trav->next!=NULL)
			 trav=trav->next;
		 trav->next=Newnode;
		 Newnode->prev=trav;
	 }
	 return Newnode;
 }

NODE* CreateNode()
{
	NODE *A;
	A=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter account information: \n Enter Account holder Name");
		    		scanf("%s",A->acc_holder_nm);
		    		printf("\nEnter id");
		    		scanf("%d",&A->id);
		    		printf("\nEnter Address");
		    		scanf("%s",A->acc_holder_addr);
		    		printf("\nEnter contact number");
		    		scanf("%d",&A->acc_holder_contact);
		    		printf("\nEnter Balance");
		    		scanf("%d",&A->balance);
		    		printf("\nEnter Account type");
		    		scanf("%s",A->account_type);
	return A;
}
void DispForward()
{
	NODE *trav;
	if(head==NULL)
		{
		printf("\nlist is empty");
	    return;
		}
	printf("\nlist in forward direction:");
	trav = head;
	while(trav!=NULL)
	{
		printf("\n Account details:");
		printf("\nName=%s \t Address=%s \t Contact=%d\t ID=%d \t Acc_type=%s \t Balance=%d",
				trav->acc_holder_nm,trav->acc_holder_addr,trav->acc_holder_contact,trav->id,trav->account_type,trav->balance);
		trav=trav->next;
	}
}
void DispBackward()
{
	NODE *trav;
	trav =head;
	while(trav->next!=NULL)
	trav=trav->next;
	printf("\n list in Backward direction:");
	while(trav!=NULL)
	{
		printf("\n Account details:");
		printf("\nName=%s \t Address=%s \t Contact=%d\t ID=%d \t Acc_type=%s \t Balance=%d",
				trav->acc_holder_nm,trav->acc_holder_addr,trav->acc_holder_contact,trav->id,trav->account_type,trav->balance);
		trav=trav->prev;
	}
}
void FindName()
{
	NODE *trav;
		char name[20];
		int cnt=0;
		trav=head;
		printf("\nEnter Name of account holder");
		scanf("%s",name);
		while(trav!=NULL)
		{
			if(strcmp(name,trav->acc_holder_nm)==0)
			{
				printf("\n Account details:");
				printf("\nName=%s \t Address=%s \t Contact=%d\t ID=%d \t Acc_type=%s \t Balance=%d",
					trav->acc_holder_nm,trav->acc_holder_addr,trav->acc_holder_contact,trav->id,trav->account_type,trav->balance);
						cnt=1;
			}
						trav=trav->next;
		}
		if(cnt==0)
			printf("\nAccont not found!!!!!!!!!!");

}
void FindId()
{
	NODE *trav;
	int id;;
	int cnt=0;
	trav=head;
	printf("\nEnter id");
	scanf("%d",&id);
	while(trav!=NULL)
	{
		if(id==trav->id)
		{
			printf("\n Account details:");
			printf("\nName=%s \t Address=%s \t Contact=%d\t ID=%d \t Acc_type=%s \t Balance=%d",
				trav->acc_holder_nm,trav->acc_holder_addr,trav->acc_holder_contact,trav->id,trav->account_type,trav->balance);
					cnt=1;
		}
					trav=trav->next;
	}
	if(cnt==0)
		printf("\nAccont not found!!!!!!!!!!");
}
MENU choice()
{
	MENU ch;
	setvbuf(stdout,NULL,_IONBF,0);
	printf("\nEnter your choice \n 0.Exit \n 1.Add at first \n 2.Add at last \n"
			"3.Display in forward \n 4.Display in Backword \n 5.Find account by Id \n 6.Find by name");
	scanf("%d",&ch);
	return ch;
}
