
#include<stdio.h>
#include<stdlib.h>

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]=".";
    char pass[10]=".";
    do
{
    printf("\n  ++++++++++++++++++++++++++++++  LOGIN PAGE  ++++++++++++++++++++++++++++++ ");
    printf("\n username and password for the ticket booking customers is .(dot)       ;)");
    printf("\n\n .............................ENTER USERNAME:-");
	scanf("%s", &uname);
	printf("\n\n .............................ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	printf("\n  ++++++++++++++++++++++++++++++  ************  ++++++++++++++++++++++++++++++  ");

	pword[i]='\0';
	i=0;
		if(strcmp(uname,"tickets")==0 && strcmp(pword,"123456")==0)
	{
	printf("\n         ;)           WELCOME TO OUR BOOK MY SHOW !!!!");
	printf("\n         ;)               LOGIN IS SUCCESSFUL");
	printf("\n\tPress any button in the keyboard to continue booking...");
	getch();
	break;
	}
	else
	{
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		printf("\n ;)     Sorry ur input was wrong        !!!!");
		printf("\n :)       LOGIN IS UNSUCESSFUL           !!!");
		printf("\n ;)            plz try again ;)          !!!");
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		a++;

		getch();
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		printf("\nSorry your have entered the wrong input in username and password for four times!!!");
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		exit(0);
	}
		system("cls");
}
struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;
int seat = 60 ;
void insert_details();
void viewAll();
void find();
void book_ticket();
void old_record();
void main()
{
    login();
	 int ch;
 	do{
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n");
	printf("\t Moive Ticket booking ");
	printf("\n");
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++");
	printf("\nEnter <1> To Insert Movie for ADMIN's only");
   	printf("\nEnter <2> To View All Movie");
	printf("\nEnter <3> To Book Tickets");
	printf("\nEnter <4> To View All Transactions");
   	printf("\nEnter <0> To Exit ");
   	printf("\nEnter your Choice :-");
   	scanf("%d",&ch);
   	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	   system("cls");

   	switch (ch)
   	{
    	case 1 :
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;
		case 3:
		    book_ticket();
		break;
		case 4:
		    old_record();
		break;
    	case 0:
    		exit(0);
    		break;
    	default:
    		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    		printf("You have entered Wrong choice !");
    		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    		break;
   	}
 }while(ch!=0);
}
void insert_details()
{
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="admin";
    do
{

    printf("\n  ++++++++++++++++++++++++++++++  ADMIN LOGIN PAGE  ++++++++++++++++++++++++++++++  ");
    printf(" \n\n                             ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\n                             ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	printf("\n  ++++++++++++++++++++++++++++++  $$$$$$$$$$$$  ++++++++++++++++++++++++++++++  \n");

	pword[i]='\0';
	i=0;
		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
	{
	printf("\n         :)          WELCOME TO OUR BOOK MY SHOW admin page!!!!");
	printf("\n         ;)                  LOGIN IS SUCCESSFUL\n");
	printf("\n\tPress any button in the keyboard to continue editing the main page...");
	getch();
	break;
	}
	else
	{
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		printf("\n   :)   Sorry ur input was wrong        !!!!");
		printf("\n   :)     LOGIN IS UNSUCESSFUL           !!!");
		printf("\n   :)          plz try again             !!!");
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		a++;

		getch();
	}
}
while(a<=2);
	if (a>2)
	{
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		printf("\nSorry your have entered the wrong input in username and password for four times!!!!");
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		exit(0);
	}
		system("cls");
}
	FILE *fp;
	struct book b;
	printf("Enter movie code:- ");
	scanf("%s",b.code);
	printf("Enter name:- ");
	scanf("%s",b.name);
	printf("Enter Release Date:- ");
	scanf("%s",b.date);
	printf("Enetr Ticket Price:- ");
	scanf("%d",&b.cost);
	fp=fopen("data.txt","a");
	if(fp == NULL)
	{
		printf("FIle not Found here");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Recorded Successfully");
	}
		printf("\n");
	    fclose(fp);
	    system("cls");
}
void viewAll()
{
	char ch;
	FILE *fp;
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not existed !!!");
		exit(1);
	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
}
void book_ticket()
{
 struct book b;
	FILE *fp;
	FILE *ufp;
	int total_seat,mobile,total_amount;
	char name[20];
	char ch;
	char movie_code[20];
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not existed !!!");
		exit(1);
	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
	printf("\n For Book ticket Choice Movie(Enter Movie Code )\n");
	printf("\n Enter movie code:-");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not existed !!!");
		exit(1);
	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}
	}
	printf("\n* Fill Deatails  *");
	printf("\n your name:");
	scanf("%s",name);
	printf("\n mobile number:");
	scanf("%d",&mobile);
	printf("\n Total number of tickets:");
	scanf("%d",&total_seat);
	total_amount = b.cost * total_seat;
	printf("\n######################\n");
	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname: %s",name);
	printf("\n\t\tmobile Number: %d",mobile);
	printf("\n\t\tmovie name: %s",b.name);
	printf("\n\t\tTotal seats: %d",total_seat);
	printf("\n\t\tcost per ticket: %d",b.cost);
	printf("\n\t\tTotal Amount: %d",total_amount);
	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not existed !!!");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record inserted Sucessfull to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);
}
void old_record()
{
	char ch;
	FILE *fp;
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not existed !!!");
		exit(1);
	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
}
