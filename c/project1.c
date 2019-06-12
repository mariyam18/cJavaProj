#include<stdio.h>

#include<stdlib.h>

#include<string.h>


struct Sl

{

	int price,seats;
	char date[20];

	char Mname[20];

	struct Sl *next;

};

typedef struct details
{
	char name[100];
	int amount,seat;
	struct details *next;
	
}d;

struct Sl *h,*temp;

int count=0;


void insert()

{

	int pr,s;
	char dy[20];

	char nme[20];

	printf("Enter the name of movie you want to insert\n");

	scanf("%s",nme);
	
	printf("Enter the seat");
	
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

	p1->price=pr;

	strcpy(p1->date,dy);
	
	p1->seats=s;
	
	strcpy(p1->Mname,nme);

	p1->next=NULL;

	if(h==NULL)

		h=p1;

	else

	{

		temp=h;

		while(temp->next!=NULL)

			temp=temp->next;

		temp->next=p1;

	}

	printf("\nMovie added succesfully\n");

}


void search()

{

	char nme[20];

	printf("Enter the name of movie \n");

	scanf("%s",nme)	;

	if(h==NULL)

		printf("Movie not found\n");

	else

	{

		temp=h;

		while(temp!=NULL)

		{

			if(strcmp(nme,temp->Mname)==0)

			{

				printf("movie= %s\n",temp->Mname);

				printf("price = %d\nAvailable seat =%d\nRealice  date = %s\n",temp->price,temp->seats,temp->date);

				return ;

			}

			temp=temp->next;

		}

		if(temp==NULL)

			printf("Details not found\n");

	}

}


/*void printbill(int i,int s)

{
  static struct Sl *p,*q,*t,*r,*k;


	if(i==0)

	{

		switch(count)

		{

			case 1 :

				p=(struct Sl*)malloc(sizeof(struct Sl));

				strcpy(p->name,temp->name);

				p->a=s;

				p->price=s*temp->price;

				p->next=NULL;

				break;

			case 2 :

				q=(struct Sl*)malloc(sizeof(struct Sl));

				strcpy(q->name,temp->name);

				q->a=s;

				q->price=s*temp->price;

				q->next=NULL;

				break;

			case 3 :

				t=(struct Sl*)malloc(sizeof(struct Sl));

				strcpy(t->name,temp->name);

				t->a=s;

				t->price=s*temp->price;

				t->next=NULL;

				break;

			case 4 :

				r=(struct Sl*)malloc(sizeof(struct Sl));

				strcpy(r->name,temp->name);

				r->a=s;

				r->price=s*temp->price;

				r->next=NULL;

				break;

			case 5 :

				k=(struct Sl*)malloc(sizeof(struct Sl));

				strcpy(k->name,temp->name);

				k->a=s;

				k->price=s*temp->price;

				k->next=NULL;

				break;

		}

	}

	if(i==1)

	{

		printf("Your bill is\n");

		printf("Name  \t  Qty\t  Rs.\n");

		if(p!=NULL)

			printf("%s\t  %d  \t  %d\n",p->name,p->a,p->price);

		if(q!=NULL)

			printf("%s\t  %d  \t  %d\n",q->name,q->a,q->price);

		if(t!=NULL)

			printf("%s\t  %d  \t  %d\n",t->name,t->a,t->price);

		if(r!=NULL)

			printf("%s\t  %d  \t  %d\n",r->name,r->a,r->price);

		if(k!=NULL)

			printf("%s\t  %d  \t  %d\n",k->name,k->a,k->price);

		free(p);

		free(q);

		free(t);

		free(r);

		free(k);

		printf("\n\t\t\t THANK YOU ** :)\n\n\n");
        

	}
   

}
*/



void booking()

{

	char nme[20];



	printf("Enter the name of movie\n");

	scanf("%s",nme);

	temp=h;

	while(temp!=NULL)

	{

		if(strcmp(nme,temp->Mname)==0)

		{

			printf("Available seat = %d\nRelice date=%s\nprice=%d",temp->seats,temp->date,temp->price);
			
		    d *u;
		    u=(struct details*)malloc(sizeof(struct details));

			printf("Enter how many seats you want to booked\n ");

			scanf("%d",&u->seat);
				
			temp->seats=temp->seats-u->seat;

			printf("\n");

			printf("**Enter your details**\n");
			printf("Enter your name\n");
			scanf("%s",u->name);
			u->amount=u->seat*temp->price;
			printf("Total amount= %d",u->amount);
			printf("Booked Sucessfully");
		}
		else
			printf("Seat is full");
		
	}
}
	


int main()
{
	int ch;
	struct Sl *p1,*t1;

	p1=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(p1->Mname,"pk");

	p1->price=300;

	p1->seats=100;

	strcpy(p1->date,"12/11/2016");

	t1=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t1->Mname,"run");

	t1->price=250;

	t1->seats=50;

	strcpy(t1->date,"12/10/2017");

/*t2=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t2->name,"Dcold");

	t2->price=26;

	t2->stock=200;

	t2->d=12;

	t2->m=3;

	t2->y=17;

	t2->d1=30;

	t2->m1=8;

	t2->y1=18;

	t3=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t3->name,"Saridon");

	t3->price=50;

	t3->stock=125;

	t3->d=11;

	t3->m=11;

	t3->y=17;

	t3->d1=23;

	t3->m1=01;

	t3->y1=19;

	t4=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t4->name,"Anarcin") ;

	t4->price=30;

	t4->stock=70;

	t4->d=17;

	t4->m=10;

	t4->y=17;

4->next=NULL;

	t3->next=t4;

	t2->next=t3;
*/
	t1->next=NULL;

	p1->next=t1;

	h=p1;

	while(1)

	{

	printf("\n\n*******************MENU*******************\n1:-Insert Movie\n2:-Search\n3:- booking\n4:-Exit\n");

	scanf("%d",&ch);

	switch(ch)

	{

		case 1 : insert();

			break;

		case 2: search();

			break;

		case 3 : booking();

			break;

		case 4 : exit(0);

		default : printf("Invalid choice\n");

	}

	}

	return 0;

}
