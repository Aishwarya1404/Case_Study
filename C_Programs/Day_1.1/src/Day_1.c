#include<stdio.h>

/*char *accept_string(char * str)
{
	//char str[50];
	printf("\nEnter string : ");
	scanf("%s",str);
	return str;
}*/

/*void print_string(char *str) {
	printf("String is : %s" , str);
}*/

/*char *accept_char(char *ch)
{
	printf("\nEnter character : ");
	scanf("%c",ch);
	return ch;
}*/
void  my_strtok(char *str,char ch)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=ch)
		{
			printf("%c",str[i]);
			continue;
		}
		else
		{
			printf("\n");
			continue;
		}
	}
}

int main(void)
{
	char str[50];
	char ch;
	printf("\nEnter string : ");
	scanf("%s",str);
	printf("\nEnter character : ");
	scanf("%c",&ch);
	//accept_char(ch);
	my_strtok(str,ch);
	return 0;
}
