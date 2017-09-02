#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
struct details
{
char name[40];
char pincode[8];
char mobile_number[20];
int age;
char USERNAME[20],PASSWORD[20];
char address[200];
char district[30];
}*user,d;

void newuser();
void existinguser();
void searchbynumber();
void searchbyname();
void list();
void sort();
void update(void);


void newuser(void)
{
//struct details d;
FILE *f;
f=fopen("record.txt","a+b");
if(f==NULL)
	{
	printf("\nFile does not exist. Creating a new file...Please wait:");
	f=fopen("record.txt","w");
	return;
	}
	printf("\n\tEnter your full name:");
	fflush(stdin);
	scanf("%[^\n]s",d.name);
	printf("\n\tEnter your 10 digit mobile number:");
	fflush(stdin);
	scanf("%s",d.mobile_number);
	printf("\n\tEnter your age:");
	scanf("%d",&d.age);
	printf("\n\tPlease enter your full address(max. 200 words):");
	fflush(stdin);
	scanf("%[^\n]s",d.address);
	printf("\n\tEnter your pincode:");
	fflush(stdin);
	scanf("%s",d.pincode);
	printf("\n\tPlease enter your district:");
	fflush(stdin);
	scanf("%s",d.district);
	printf("\n\tEnter your username:");
	fflush(stdin);
	scanf("%[^\n]s",d.USERNAME);
	printf("\n\tEnter your password:");
	fflush(stdin);
	scanf("%[^\n]s",d.PASSWORD);
	fwrite(&d,sizeof(struct details),1,f);
	printf("\n\n You have successfully created your account.\nThank you!");
	printf("\n\nYour username is:%s \n\n Password is:%s",d.USERNAME,d.PASSWORD);
	fclose(f);
}
void existinguser()
{
//struct details d;
FILE *f;
char user_name[20];
char pass_word[20];
int a,b;
int flag=0;
f=fopen("record.txt","r+b");
if(f==NULL)
	{
		printf("\n File not found. Creating a new file...Please wait!");
		f=fopen("record.txt","w+");
		printf("\n File created");
		return;
	}
printf("\n\tEnter your username:");
fflush(stdin);
scanf("%[^\n]s",user_name);
printf("\n\tEnter your password:");
fflush(stdin);
scanf("%[^\n]s",pass_word);
user=(struct details*)malloc(sizeof(struct details));
while(fread(user,sizeof(struct details),1,f)==1)
	{
	a=strcmp(user -> USERNAME,user_name);
	b=strcmp(user -> PASSWORD,pass_word);
	   {
	if(a==0&&b==0)
			{
			printf("\nYou are successfully logged-in. Thank you");
			flag=1;
			}
	    }
	}
	if (flag==0)
	{
		printf("\n Try again username and password do not match\n");

	}
	free(user);
	fclose(f);
}
void searchbynumber()
{
//struct details d;
FILE *f;
int flag=0;
char number[20];
f=fopen("record.txt","r+b");
if(f==NULL)
	{
		printf("\n File not found. Creating a new file...Please wait!");
		f=fopen("record.txt","w+");
		return;
	}
printf("\n Enter the mobile number to search for:\n");
scanf("%s",&number);
while(fread(&d,sizeof(struct details),1,f)!=0)
	{
	if(strcmp(number,d.mobile_number)==0)
		{
			printf("\nRECORD FOUND");
			printf("\nNAME:%s \nMobile Number:%s \nAge:%d \nAddress:%s \nPIN:%s \nDistrict:%s",d.name,d.mobile_number,d.age,d.address,d.pincode,d.district);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
	printf("\n Record not found");
	}
	fclose(f);
}
void searchbyname()
{
//struct details d;
FILE *f;
int flag=0;
char your_name[20];
f=fopen("record.txt","r+b");
if(f==NULL)
	{
		printf("\n File not found. Creating a new file...Please wait!");
		f=fopen("record.txt","w");
		return;
	}
printf("\n Enter the name to search for:\n");
fflush(stdin);
scanf("%[^\n]s",your_name);
while(fread(&d,sizeof(struct details),1,f)!=0)
	{
	if(strcmp(your_name,d.name)==0)
		{
			printf("\nRECORD FOUND-");
			printf("\nNAME:%s \nMobile Number:%s \nAge:%d \nAddress:%s \nPIN:%s \nDistrict:%s",d.name,d.mobile_number,d.age,d.address,d.pincode,d.district);
			flag=1;
		}
	}
	if(flag==0)
	{
	printf("\n Record not found");
	}
	fclose(f);

}
void list()
{
//struct details d;
FILE *f;
f=fopen("record.txt","r+b");
if(f==NULL)
	{
		printf("\n File not found. Creating a new file...Please wait!");
		f=fopen("record.txt","w");
		return;
	}
printf("\n All the records are:\n");
while(fread(&d,sizeof(struct details),1,f)!=0)
		{
printf("\n\nNAME:%s \nMobile Number:%s \nAge:%d \nAddress:%s \nPIN:%s \nDistrict:%s",d.name,d.mobile_number,d.age,d.address,d.pincode,d.district);
		}
       fclose(f);
}

void update()
{
//struct details d;
FILE *f;
char phonenum[20];
int flag=0;
f=fopen("record.txt","r+b");
if(f==NULL)
	{
		printf("\n File not found. Creating a new file...Please wait!");
		f=fopen("record.txt","w");
		return;
	}
printf("\n\nEnter mobile number to edit the details for:\n ");
scanf("%s",phonenum);
while(fread(&d,sizeof(struct details),1,f)!=0)
{
	if(strcmp(phonenum,d.mobile_number)==0)
	{
		printf("\n Record found:");
		printf("\nNAME:%s \nMobile Number:%s \nAge:%d \nAddress:%s \nPIN:%s \nDistrict:%s",d.name,d.mobile_number,d.age,d.address,d.pincode,d.district);
		flag=1;
		break;
	}
}
	if(flag==0)
		{
			printf("\n Record not found");
		}
	else
		{

		fseek(f, (int)-sizeof(struct details), SEEK_CUR);
		printf("\n\tEnter your full name:");
		fflush(stdin);
		scanf("%[^\n]s",d.name);
		printf("\n\tEnter your 10 digit mobile number:");
		fflush(stdin);
		scanf("%s",d.mobile_number);
		printf("\n\tEnter your age:");
		scanf("%d",&d.age);
		printf("\n\tPlease enter your full address(max. 200 words):");
		fflush(stdin);
		scanf("%[^\n]s",d.address);
		printf("\n\tEnter your pincode:");
		fflush(stdin);
		scanf("%s",d.pincode);
		printf("\n\tPlease enter your district:");
		fflush(stdin);
		scanf("%s",d.district);
		printf("\n\tEnter your username:");
		fflush(stdin);
		scanf("%[^\n]s",d.USERNAME);
		printf("\n\tEnter your password:");
		fflush(stdin);
		scanf("%[^\n]s",d.PASSWORD);
		fwrite(&d,sizeof(struct details),1,f);
		printf("\n Data updated successfully");
		}
	fclose(f);
}

void sort()
{
	//struct details d;
	FILE *f;
	int a;
	int flag=0;

	char new_district[20];
	f = fopen("record.txt", "r+b");
	if(f==NULL)
	{
		printf("\n File not found. Creating a new file...Please wait!");
		f=fopen("record.txt","w");
		return;
	}
	printf("\n\n1)Sort by District\n\n2)Sort by name");
	printf("\n\nSelect an option to continue.......:\t");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
		printf("\n Enter the district name:");
		fflush(stdin);
		scanf("%19[^\n]s",new_district);
		strcpy(new_district, strlwr(new_district));
		while(fread(&d,sizeof(struct details),1,f)!=0)
		{
			if(strcmp(new_district,strlwr(d.district))==0)
			{
				printf("\n\nNAME:%s \nMobile Number:%s \nAge:%d \nAddress:%s \nPIN:%s \nDistrict:%s",d.name,d.mobile_number,d.age,d.address,d.pincode,d.district);
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("\n No matches found:");
		}
		break;


	  case 2:              		

	  break;
	  }

}


void main()
{
int choice,a,b;
char c;
do
{
clrscr();
printf("\n\t\t-------- WELCOME TO TELEPHONE DIRECTORY --------\n");
printf("\n MAIN MENU:\n");
printf("\n1) LOGIN TO CONTINUE\n\n2) SEARCH A RECORD\n\n3) LIST ALL RECORDS\n\n4) SORT RECORDS\n\n5) EXIT\n");
printf("\n--------------\n");
printf("\nSelect an option to continue:\n");
scanf("%d",&choice);
switch(choice)
	{
	case 1:
		clrscr();
		printf("\n\n1) New User\n\n2) Existing User\n\n3) GO TO MAIN MENU\n");
		printf("\nPlease select an appropriate option to continue:\n");
		scanf("%d",&a);
		if(a==1)
			{
				newuser();
				printf("\n\nDo you want to edit details(y/n):\n");
				scanf("%s",&c);
				if(c=='y' || c=='Y')
				{
					update();
				}
				else
				{
					main();
				}

			}
		else if(a==2)
			{
				existinguser();
				printf("\n\n Welcome to your account");
				printf("\n\nDo you want to edit details(y/n):\n");
				scanf("%s",&c);
				if(c=='y' || c=='Y')
				{
					update();
				}
				else
				{
					main();
				}
			}
		else if(a==3)
			{
				main();
			}
		else
		{
		printf("\n Invalid option!");
		}
		break;

	case 2: clrscr();
		printf("\n1)Search a record by number\n\n2)Search a record by name");
		printf("\n\nPlease select an appropriate option to continue:\n");
		scanf("%d",&b);
		if(b==1)
		{
		searchbynumber();
		}
			else if(b==2)
			{
				searchbyname();
			}
				else
				{
					printf("\nInvalid choice!");

				}
			break;

	case 3:
			clrscr();
			list();
			break;
	case 4:
			clrscr();
			sort();
			break;

	case 5: exit(0);
		break;
	default: printf("\n Wrong choice!");
		break;

}
printf("\n");
system("pause");
}while(choice !=5);
getch();
}