#include<stdio.h>
#define PI 3.142
enum main_menu{EXIT,CIRCLE,SQUARE,RECTANGLE};
typedef enum sub_menu{AREA=1,PERI}menu_t;
menu_t sel;
void Circle_Operations()
{
	float rad;
	do
	{
		printf("1.Area\n 2.Perimeter\n");
		printf("\nEnter your choice");
		scanf("%d",&sel);
		switch(sel)
		{
		case AREA:
			printf("\nEnter Radius");
			scanf("%f",&rad);
		printf("\nArea of circle is:%f",(PI*rad*rad));
			break;
		case PERI:
			printf("\nEnter Radius");
			scanf("%f",&rad);
			printf("\nPerimeter of circle is:%f",(PI*2*rad));
			break;
		}

	}while(sel!=0);

}
void Rectangle_Operations()
{
	float l,b;
		do
		{
			printf("1.Area\n 2.Perimeter\n");
			printf("\nEnter your choice");
			scanf("%d",&sel);
			switch(sel)
			{
			case AREA:
				printf("\nEnter length");
				scanf("%f",&l);
				printf("\nEnter bridth");
				scanf("%f",&b);
				printf("\nArea of rectangle: %f",(l*b));
				break;
			case PERI:
				printf("\nEnter length");
				scanf("%f",&l);
				printf("\nEnter bridth");
				scanf("%f",&b);
				printf("\nArea of rectangle: %f",(2*(l+b)));
				break;
			}

		}while(sel!=0);
}
void Square_Operations()
{
		do
		{
			printf("1.Area\n 2.Perimeter\n");
			printf("\nEnter your choice");
			scanf("%d",&sel);
			switch(sel)
			{
			case AREA:

				break;
			case PERI:
				break;
			}

		}while(sel!=0);
}
void main()
{
	enum main_menu choice;
	do{
		printf("\n0.Exit");
		printf("\n1.Circle");
		printf("\n2.Square");
		printf("\n3.Rectangle");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case CIRCLE:
			Circle_Operations();
			break;
		case SQUARE:
			Square_Operations();
			break;
		case RECTANGLE:
			Rectangle_Operations();
			break;
		}

	}while(choice!=0);
}
