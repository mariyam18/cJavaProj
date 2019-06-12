#include<stdio.h>

#include<stdlib.h>

#include<string.h>


struct Sl

{

    int price,seats;
    char date[20];

    char Mname[100];

    struct Sl *next;

};

typedef struct details
{
    char name[100];
    int amount,seat;
    struct details *next;
  
}d;

struct Sl *h,*temp;

d *u,*tmp;

void insert()

{
	FILE *fp;
    int pr,s;
    char dy[20];

    char nme[20];

    printf("Enter the name of movie you want to insert\n");

    scanf("%s",nme);
  
    printf("Enter the seat= \n");
  
    scanf("%d",&s);
  
    printf("price :-  ");

    scanf("%d",&pr);

    printf("\nRealice date :- ");
  
    scanf("%s",dy);
  

    struct Sl *p1;

    p1=(struct Sl*)malloc(sizeof(struct Sl));

    if(p1==NULL)

    {

        printf("\nNot enough memory in system\n");

        return;

    }
    else
    {
    p1->price=pr;

    strcpy(p1->date,dy);
  
    p1->seats=s;
  
    strcpy(p1->Mname,nme);

    p1->next=NULL;
	
	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %d %d \n",p1->Mname,p1->date,p1->seats,p1->price);
		printf("Record insert Sucessfull");
	}
		printf("\n");
	fclose(fp);

    if(h==NULL)

        h=p1;

    else

    {

        temp=h;

        while(temp->next!=NULL)

            temp=temp->next;

        temp->next=p1;

    }

    printf("\nMovie Added Succesfully\n");
    }
}


void search()

{

    char nme[20];

    printf("Enter the name of movie \n");

    scanf("%s",nme)    ;

    if(h==NULL)

        printf("Movie not found\n");

    else

    {

        temp=h;

        while(temp!=NULL)

        {

            if(strcmp(nme,temp->Mname)==0)

            {

                printf("Movie= %s\n",temp->Mname);

                printf("Price = %d\nAvailable seat =%d\nRealice  date = %s\n",temp->price,temp->seats,temp->date);

                return ;

            }

            temp=temp->next;

        }

        if(temp==NULL)

            printf("Details not found\n");

    }

}

void booking()
{
   
   char nme[20];

    printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*MOVIE BOOKING TICKET*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
    printf("Enter the name of movie\n");

    scanf("%s",nme);

    temp=h;

    while(temp!=NULL)

    {

        if(strcmp(nme,temp->Mname)==0)

        {

            printf("Available seat = %d\nRelice date=%s\nPrice=%d\n",temp->seats,temp->date,temp->price);
          
            
            u=(struct details*)malloc(sizeof(struct details));

            printf("Enter how many seats you want to booked\n ");

            scanf("%d",&u->seat);
			if(temp->seats>=u->seat)
			{
              
            temp->seats=temp->seats-u->seat;

            printf("\n");

            printf("\t\t****Enter your details****\n\n");
            printf("Enter your name\n");
            scanf("%s",u->name);
            u->amount=u->seat*temp->price;
            printf("Total amount= %d\n",u->amount);
            printf("Booked Sucessfully\n");
			printf("\t\t\t\t\tTHANK YOU VISIT AGAIN...\n");
            break;
            }
			else
				printf("SORRY,SEAT IS FULL");
        }
      
        temp=temp->next;
      
    }
  
}
  


int main()
{
    int ch;
    struct Sl *p1,*t1,*t2,*t3,*t4;

    p1=(struct Sl*)malloc(sizeof(struct Sl));

    strcpy(p1->Mname,"pk");

    p1->price=300;

    p1->seats=5;

    strcpy(p1->date,"12/11/2016");

    t1=(struct Sl*)malloc(sizeof(struct Sl));

    strcpy(t1->Mname,"race1");

    t1->price=250;

    t1->seats=50;

    strcpy(t1->date,"12/10/2017");

    t2=(struct Sl*)malloc(sizeof(struct Sl));

    strcpy(t2->Mname,"race2");

    t2->price=120;

    t2->seats=100;

    strcpy(t2->date,"10/8/17");

    t3=(struct Sl*)malloc(sizeof(struct Sl));

    strcpy(t3->Mname,"dangal");

    t3->price=150;

    t3->seats=125;
   
    strcpy(t3->date,"2/4/18");

    t4=(struct Sl*)malloc(sizeof(struct Sl));

    strcpy(t4->Mname,"indian") ;

    t4->price=170;

    t4->seats=70;

    strcpy(t4->date,"5/6/18");

    t4->next=NULL;

    t3->next=t4;
   
    t2->next=t3;

    t1->next=t2;

    p1->next=t1;

    h=p1;

    while(1)

    {

    printf("\n\n*=*=*=*=*=*=*=*=*=*=*MENU*=*=*=*=*=*=*=*=*=*=*\n1:-INSERT MOVIE\n2:-SEARCH A MOVIE\n3:-BOOKING\n4:-EXIT\n");

    scanf("%d",&ch);

    switch(ch)

    {

        case 1 : insert();

            break;

        case 2: search();

            break;

        case 3 : booking();

            break;
		
        case 4: exit(0);

        default : printf("Invalid choice\n");

    }

    }

    return 0;

}
