#include<stdio.h>

#include<stdlib.h>

#include<string.h>


struct Sl

{

	int price,seats,d,m,y,a;

	char name[20];

	struct Sl *next;

};


struct Sl *h,*temp;

int count=0;


void insert()

{

	int pr,s,dy,mn,yr;

	char nme[20];

	printf("Enter the name of movie you want to insert\n");

	scanf("%s",nme);

	printf("how many seats you want to insert :-  ");

	scanf("%d",&s);

	printf("price :-  ");

	scanf("%d",&pr);

	printf("\nrealise date :- ");
	
	scanf("%d",&dy);
	if(dy>0 && dy<=31)
	{
	}
	else
	{
		printf("invalid date entered");
		printf("\nEnter a valid date");
	printf("\nrealise date :- ");
		scanf("%d",&dy);
	}

	printf("/");

	scanf("%d",&mn);
if(mn>0 && mn<=12)
	{
	}
	else
	{
		printf("invalid date entered\n");
		printf("enter a valid month");
	printf("\nrealise month :- ");
		scanf("%d",&mn);
	}
	printf("/");

	scanf("%d",&yr);
	if((yr>2016&& yr<=2025) || (yr>=16 && yr<=25))
	{
	}
	else
	{
	printf("invalid date entered\n");
		printf("enter a valid year");
	printf("\nrealise year:- ");
	scanf("%d",&yr);
	}
	}

	struct Sl *p1;

	p1=(struct Sl*)malloc(sizeof(struct Sl));

	if(p1==NULL)

	{

		printf("\nNot enough memory in system\n");

		return;

	}

	p1->price=pr;

	p1->seats=s;

	p1->d=dy;

	p1->m=mn;

	p1->y=yr;

	strcpy(p1->name,nme);

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

	printf("\nMovie added succesfuuly\n");

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

			if(strcmp(nme,temp->name)==0)

			{

				printf("movie= %s\n",temp->name);

				printf("price = %d\nAvailabe seats= %d\nrealise date = %d/%d/%d\n",temp->price,temp->seats,temp->d,temp->m,temp->y);


				return ;

			}

			temp=temp->next;

		}

		if(temp==NULL)

			printf("Details not found\n");

	}

}


void printbill(int i,int s)

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




void book()

{

	char nme[20];

	int s,ck;

	printf("Enter the name of movie\n");

	scanf("%s",nme);

	temp=h;

	while(temp!=NULL)

	{

		if(strcmp(nme,temp->name)==0)

		{

			printf("Available = %d\trealise date= %d/%d/%d\n",temp->seats,temp->d,temp->m,temp->y);

			printf("Enter how many seats you want to book\n ");

			scanf("%d",&s);

			temp->seats=temp->seats-s;

			printf("DONE!!!***!!\n");

			count++;


		}

		temp=temp->next;

	}

	if(temp==NULL)

	{

		printf("Movie not found\n");

		return ;

	}

	printbill(0,s);

	if(count!=5)

	{

		printf("Do you want to checkout.\nPress 1 for checkout\nPress any key to continue\n");

		scanf("%d",&ck);

		if(ck==1)

		{

			count=0;

			printbill(ck,s);

		}

	}

	if(count==5)

	{

		printbill(1,s);

	}

}



int main()

{

	int ch;

	struct Sl **p1,*t1,*t2,*t3,*t4;

	p1=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(p1->name,"Mariyam");

	p1->price=300;

	p1->seats=50;

	p1->d=12;

	p1->m=10;

	p1->y=17;


	t1=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t1->name,"Muskan");

	t1->price=400;

	t1->seats=50;

	t1->d=12;

	t1->m=8;

	t1->y=17;


	t2=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t2->name,"Heena");

	t2->price=400;

	t2->seats=50;

	t2->d=12;

	t2->m=3;

	t2->y=17;

	t3=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t3->name,"Nooras");

	t3->price=300;

	t3->seats=50;

	t3->d=11;

	t3->m=11;

	t3->y=17;


	t4=(struct Sl*)malloc(sizeof(struct Sl));

	strcpy(t4->name,"Ilaf") ;

	t4->price=30;

	t4->seats=70;

	t4->d=17;

	t4->m=10;

	t4->y=17;


	t4->next=NULL;

	t3->next=t4;

	t2->next=t3;

	t1->next=t2;

	p1->next=t1;

	h=p1;

	while(1)

	{

	printf("\n\n*******************MENU*******************\n1:-Insert Movie\n2:-Search\n3:- booking\n5:-Exit\n");

	scanf("%d",&ch);

	switch(ch)

	{

		case 1 : insert();

			break;

		case 2: search();

			break;

		case 3 : book();

			break;
            
		case 5 : exit(0);

		default : printf("Invalid choice\n");

	}

	}

	return 0;

}
