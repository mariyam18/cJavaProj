#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct book
{
	char code[20];
	 char name[20];
	 char date[20];
	 int cost;
	 
	 
};

void insert_details();
void find();
void viewAll();
void book_ticket();
void old_record();


int main()
{
int ch;

 	do{
	printf("\n====================================================================");
	printf("\n");
	printf("\t Moive Ticket booking ");
	printf("\n");
	printf("\n====================================================================");

	printf("\nPress <1> Insert Movie");
   	printf("\nPress <2> View All Movie");
	printf("\nPress <3> Find Movie ");
	printf("\nPress <4> Book Ticket");
	printf("\nPress <5> View All Transections");
   	printf("\nPress <0> Exit ");

   	printf("\nEnter your Choice ::");
   	scanf("%d",&ch);

   	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;

		case 3:
    		find();
   		break;

		case 4:
		book_ticket();
		break;

		case 5:
		old_record();
		break;

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);

return 0;


}


void insert_details()
{

	FILE *fp;
	struct book b;
	printf("Enter movie code :- ");
	scanf("%s",b.code);
	printf("Enter  name :- ");
	scanf("%s",b.name);
	printf("Enter Relice Date:- ");
	scanf("%s",b.date);
	printf("Enter Ticket Price:- ");
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Record insert Sucessfull");
	}
		printf("\n");
	fclose(fp);
}
void find() //find details
{
	struct book b;
	FILE *fp;

	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s%s%s%d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d",b.cost);
				break;
			}
		}

	}

	fclose(fp);
}
void viewAll()
{
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		//system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);
}
//for ticket booking
void book_ticket()
{
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char name[20];


	char ch; //used in display all movies
	char movie_code[20]; //for searching

	// disply all moives by default for movie code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		//system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);

	//display ends
	printf("\n For Book ticket Choise Movie(Enter Movie Code First Latter Of Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}

	}
	printf("\n* Fill Deatails  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);


	total_amount = b.cost * total_seat;

	printf("\n ***** ENJOY MOVIE ****\n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %d",mobile);
	printf("\n\t\tmovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);


	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record insert Sucessfull to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);

}
//for view all user transections
void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");

	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		//system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);


}

/*Output

====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::1
Enter movie code :- 10
Enter  name :- judwa
Enter Relice Date:- 20/11/16
Enter Ticket Price:- 200
Record insert Sucessfull

====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::1
Enter movie code :- 20
Enter  name :- race
Enter Relice Date:- 20/4/17
Enter Ticket Price:- 300
Record insert Sucessfull

====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::2
10 judwa 20/11/16 200 
20 race 20/4/17 300 

====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::3
Enter movie code :20

 Record Found

		Code ::20
		movie name ::race
		movie date ::20/4/17
		price of ticket ::300
====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::4
10 judwa 20/11/16 200 
20 race 20/4/17 300 

 For Book ticket Choise Movie(Enter Movie Code First Latter Of Movie)

 Enter movie code :10

* Fill Deatails  *
 your name :mariyam

 mobile number :523641

 Total number of tickets :3

 ***** ENJOY MOVIE ****

		name : mariyam
		mobile Number : 523641
		movie name : race
		Total seats : 3
		cost per ticket : 300
		Total Amount : 900
 Record insert Sucessfull to the old record file
====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::4
10 judwa 20/11/16 200 
20 race 20/4/17 300 

 For Book ticket Choise Movie(Enter Movie Code First Latter Of Movie)

 Enter movie code :20

 Record Found

		Code ::20
		Movie name ::race
		date name ::20/4/17
		Price of ticket::300

* Fill Deatails  *
 your name :muskan

 mobile number :458741

 Total number of tickets :4

 ***** ENJOY MOVIE ****

		name : muskan
		mobile Number : 458741
		movie name : race
		Total seats : 4
		cost per ticket : 300
		Total Amount : 1200
 Record insert Sucessfull to the old record file
====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::5
mariyam 523641 3 900 race 300 
muskan 458741 4 1200 race 300 

====================================================================
	 Moive Ticket booking 

====================================================================
Press <1> Insert Movie
Press <2> View All Movie
Press <3> Find Movie 
Press <4> Book Ticket
Press <5> View All Transections
Press <0> Exit 
Enter your Choice ::0
*/
