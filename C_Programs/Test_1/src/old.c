#include<stdio.h>
#include<string.h>
void Student_Info()
{
	printf("\n----------Student Information----------");
	printf("\nName	:Aishwarya Kaware");
	printf("\nRoll Number	:35986");
	printf("\nCenter Name	:Sunbeam");
	printf("\nCourse name	:DAC");
	printf("\n**************************************");
}

typedef enum{Exit,REGISTER_STAFF, STAFF, ADMIN}MAIN;

typedef enum{EXIT,LIST_COURSES,MODULES_PER_COURSES,
	         WORK_ENTRY,PENDING_ENTRIES,APPROVED_ENTRIES}SELECT;

typedef enum{LIST_COURSES_A=1,ADD_COURSES,DISPLAY_MODULE_FILE,
	         FIND_MODULE_BY_NAME,EDIT_MODULE,DELETE_MODULE,PENDING_ENTRIES_A
			 ,APPROVED_ENTRIES_A,APPROVE_ENTRY,ADD_MODULE}ADMIN_ch;

typedef struct staff
{
	char name[50];
	char email[50];
	int mob;
	int id;
}staff_t;

typedef struct module
{
	int id;
	char Module_name[20],course[20];
	int duration_hrs;
}module_t;

void Make_List()
{
	char *arr[10] = {"DAC" , "DMC" , "dESD", "DBDA"};
	FILE *fptr=fopen("Course.txt","w+");

	if(fptr!=NULL)
	{
		fwrite(&arr, sizeof(arr),4,fptr);
		fclose(fptr);
	}

}
void List_Record()
{
	FILE *fptr=fopen("Course.txt","r+");
	if(fptr!=NULL)
	{
		int data;
		while((data=fgetc(fptr))!=EOF)
		printf("%c",data);

			printf("\n");
	}
	fclose(fptr);
}
void write_Modules_per_courses(FILE * fp,module_t *module,int size)
{
	//fp=fopen("Module.db","wb");
	//char course_name[50];
	//printf("\nEnter Course Name");
	//scanf("%s",course_name);
	if(fp!=NULL)
	{
		fwrite(module,sizeof(module_t),size,fp);
		fclose(fp);
	}
}

void Display_Modules_per_courses(module_t *module,int size)
{
	FILE *fp; int i;
	fp=fopen("Module.db","rb");
    if(fp!=NULL)
	{
		for(i=0;i<size;i++)
	  printf("Id:%d Module:%s Course:%s duration:%d Hrs \n",module[i].id,module[i].Module_name,module[i].course,module[i].duration_hrs);
		fclose(fp);
	}
}

void Add_Courses()
{
	char str[20];
	FILE *fptr=fopen("Course.txt","a");
	if(fptr!=NULL)
	{
		printf("Enter course name to add");
		scanf("%s",str);
		fwrite(&str,strlen(str),1,fptr);
		fclose(fptr);
	}
}

void accept_module(module_t *mod)
{
	printf("\n Enter Module ID,  Module name, Course Name, Duration");
	scanf("%d %s %s %d",& mod->id,mod->Module_name,mod->course,&mod->duration_hrs);
}

void Add_Module()
{
	module_t m;
	FILE *fp;
	int n;
	fp= fopen("Module.db","ab");
	if(fp==NULL)
	{
		printf("\n------Failed----------");
		return;
	}
	accept_module(&m);
	n= fwrite(&m,sizeof(module_t),1,fp);
	printf("\nModule added: %d",n);
	fclose(fp);
}

MAIN choice()
{
	int choice;
	printf("\n0.Exit");
	printf("\n1.Register Staff");
	printf("\n2.Staff");
	printf("\n3.Admin");
	printf("\nEnter your choice :");
	scanf("%d",&choice);
	return choice;
}

int Staff_Choice()
{
	int choice;
	printf("----------Staff Work log----------");
	printf("\n0.Return to main menu");
	printf("\n1.List of courses");
	printf("\n2.Modules per Courses");
	printf("\n3.Input a Course");
	printf("\n4.Work Entry :");
	printf("\n5.List of Pending Entries :");
	printf("\n6.List of Approved Entries :");
	scanf("%d",&choice);
    return choice;
}

int Admin_choice()
{
	int choice;
	printf("\n0.Exit");
	printf("\n1.List courses");
	printf("\n2.Add courses");
	printf("\n3.Display modules");
	printf("\n4.Find module by name");
	printf("\n5.Edit module");
	printf("\n6.Delete module");
	printf("\n7.List of Pending entries");
	printf("\n8.List of approved entries");
	printf("\n9Approve entry");
	printf("\n10.Add module");
	scanf("%d",&choice);
	return choice;
}

void NewStaff_Menu()
{
	staff_t n;
	printf("\n-----Enter Informaion-------");
	printf("\nName :");
	scanf("%s",n.name);
	printf("\nEmail :");
	scanf("%s",n.email);
	printf("\nID :");
	scanf("%d",&n.id);
	printf("\nMobile :");
	scanf("%d",&n.mob);
}


int main(void)
{
	Student_Info();
	Make_List();
	int ch,admin_ch,staff_ch;
	module_t module;
	//module_t arr[]={{10,"C","DAC",1},{15,"C++","DAC",2}};
	FILE *filename= fopen("Module.db","wb");
	while((ch=choice())!=Exit)
	{
		switch(ch)
		{
		case REGISTER_STAFF:
				NewStaff_Menu();
			break;
		case STAFF:
			while(( staff_ch=Staff_Choice())!=0)
			{
			  switch(staff_ch)
			  {
				case LIST_COURSES:
					List_Record();
					break;
				case MODULES_PER_COURSES:
					write_Modules_per_courses(filename,module,2);
					Display_Modules_per_courses(filename,2);
					break;
				case WORK_ENTRY:
					break;
				case PENDING_ENTRIES:
					break;
				case APPROVED_ENTRIES:
					break;
			  }
			}
			break;


		case ADMIN:
			while((admin_ch=Admin_choice())!=0)
			{
				switch(admin_ch)
				{

				case LIST_COURSES_A:
					List_Record();
					break;
				case ADD_COURSES:
					Add_Courses();
					break;
				case DISPLAY_MODULE_FILE:
					break;
				case FIND_MODULE_BY_NAME:
					break;
				case EDIT_MODULE:
					break;
				case DELETE_MODULE:
					break;
				case PENDING_ENTRIES_A:
					break;
				case APPROVED_ENTRIES_A:
					break;
				case APPROVE_ENTRY:
					break;
				case ADD_MODULE:
					Add_Module();
					break;
				}
			}
			break;
		}
	}
return 0;
}
