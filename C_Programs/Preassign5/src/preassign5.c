#include <stdio.h>
#include <stdlib.h>
//void accept_info();

struct Empoyee
{
	int id;
	int salary;
	char Addr[20], name[20];
}E1;
struct Date
	{
	int dd,mm,yyyy;
	};

    struct Date accept_dob();
	struct Date joining_date();
	struct Date person_age(struct Date dob,struct Date d2);
	void print_Probation_date(struct Date d1);
	void print_experience(struct Date d2);


	int main(void)
{
		struct Date dob,d2;
		setvbuf(stdout,NULL,_IONBF,0);
		printf("-------Enter Employee Information-------");
		printf("\n Enter name, employee id, address,salary");
		scanf("%s%d%s%d",&E1.name,&E1.id,&E1.Addr,&E1.salary);
				dob=accept_dob();
				d2=joining_date();
			    person_age(dob,d2);
			    print_Probation_date(d2);
			    print_experience(d2);
			return EXIT_SUCCESS;
}
			struct Date accept_dob()
			{
				struct Date dob;
				printf("\n Enter DOB(dd/mm/yyyy)");
				scanf("%d%d%d",&dob.dd,&dob.mm,&dob.yyyy);
				return dob;
			}
			struct Date joining_date()
				{
					struct Date d2;
					printf("\n Enter date of joining (dd/mm/yyyy)");
					scanf("%d%d%d",&d2.dd,&d2.mm,&d2.yyyy);
					return d2;
				}
			struct Date person_age(struct Date dob,struct Date d2)
			{
				int age;
				age= d2.yyyy-dob.yyyy;
				printf("\nAge of person is %d",age);
			}
			void print_experience(struct Date d2)
			{
				struct Date cur;
				int cnt=0;
				printf("\n Enter Current date:(dd/mm/yyyy)");
				scanf("%d%d%d",&cur.dd,&cur.mm,&cur.yyyy);
				while(d2.yyyy<=cur.yyyy)
						{
							while(d2.mm<=12 && d2.mm!=cur.mm)
							{
								d2.mm++;
								cnt++;
							}
							if(d2.mm>12)
							{
								d2.yyyy++;
								d2.mm=1;
							}
							else if(d2.mm==cur.mm && d2.yyyy!=cur.yyyy)
							  {d2.mm++;
							  }
							else
								 break;
						}
				      printf("\nExperience of person is %d months",cnt);

			}

			void print_Probation_date(struct Date d2)
			{
				struct Date d;
						d.dd=d2.dd;
						d.yyyy=d2.yyyy;
						d.mm=d2.mm;
						switch(d2.mm)
						{
						case 10:
							d.yyyy++;
							d.mm=1;
						break;
						case 11:
							d.yyyy++;
							d.mm=2;
						break;
						case 12:
							d.yyyy++;
							d.mm=3;
						break;
						default:
							d.mm=d2.mm+3;
						}
				printf("\nProbation Period over date is %d/%d/%d",d.dd,d.mm,d.yyyy);
			}

