#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct book
{
	char name[20];
	int id;
	float price;
}book_t;

void book_data(book_t *b)
{
	printf("\nEnter Book name	:");
	scanf("%s",b->name);
	printf("Enter Book id	:");
	scanf("%d",&b->id);
	printf("Enter Book price	:");
	scanf("%f",&b->price);
}
void accept_record(book_t *b,int size)
{
	int i;
	for(i=0;i<size;i++)
		book_data(&b[i]);
}
void print_record(book_t *b,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("\nBook name %s \nBook id %d\nBook price %f",b[i].name,b[i].id,b[i].price);
}
int compare_name(const void *b1,const void *b2)
{
	book_t *s1=(book_t *)b1;
	book_t *s2=(book_t *)b2;
	return strcmp(s1->name,s2->name);
}

int compare_id(const void * s1, const void * s2)
{
	book_t *b1=(book_t *)s1;
	book_t *b2=(book_t *)s2;
	if((b1->id - b2->id)>0)
		return 1;
	if((b1->id - b2->id)<0)
	    return -1;
	else
		return 0;


}
int main()
{

	book_t b[3];
	accept_record(b,3);
	print_record(b,3);
    qsort(b,3,sizeof(book_t),compare_name);
    printf("\n----------After sorting-------------");
    print_record(b,3);
    printf("\n----------After sorting by id-------------");
    qsort(b,3,sizeof(book_t),compare_id);
    print_record(b,3);
	return 0;
}
