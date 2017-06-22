#include<stdio.h>
#include"header.h"
#include<conio.h>
#include<malloc.h>
void queue4()
{
    char ch;
    printf("\n1.QUEUE USING ARRAY\n2.QUEUE USING LINKED LIST\n3.CIRCULAR QUEUE\n4.DEQUE\n");
    ch=getche();
    switch(ch)
    {
    case '1':
        queuearr();
        break;
    case '2':
        queuelinki();
        break;
    case '3':
        cirqueue();
        break;
    case '4':
        dequeue();
        break;
    default:
        printf("WRONG CHOICE\n");
    }
}
/* USING ARRAY */
#define MAX 10
int queue_arr[MAX];
int reara=-1;
int fronta=-1;
int isEmptya()
{
	if( fronta==-1 || fronta==reara+1 )
		return 1;
	else
		return 0;
}
int isFulla()
{
	if( reara==MAX-1 )
		return 1;
	else
		return 0;
}
void inserta(int item)
{
	if( isFulla() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( fronta == -1 )
		fronta=0;
	reara=reara+1;
	queue_arr[reara]=item ;
}
int dela()
{
	int item;
	if( isEmptya() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=queue_arr[fronta];
	fronta=fronta+1;
	return item;
}
int peeka()
{
	if( isEmptya() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return queue_arr[fronta];
}
void displayaq()
{
	int i=fronta;
	if((fronta==-1 && reara==-1) || fronta==reara+1)
{
	printf("Queue is Underflow\n");
	return;
}
	printf("Enter the Elements: ");
	while(i<=reara)
{
	printf("%d ",queue_arr[i]);
	i++;
}
}
void queuearr()
{
    	int choice,item;
    	 printf("\n\t\tFUNCTIONS PERFORMED\n");
	while(1)
	{
		printf("\n1.Enqueue 2.Dequeue 3.Display element at the front 4.Display all elements of the queue 5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			inserta(item);
			break;
		case 2:
			item=dela();
			printf("Deleted element is  %d\n",item);
			break;
		case 3:
			printf("Element at the front is %d\n",peeka());
			break;
		case 4:
			displayaq();
			break;
		case 5:
			return;
		default:
			printf("Wrong choice\n");
		}
	}
}
/* USING LINKED LIST */
struct node
{
	int info;
	struct node *next;
}*frontl=NULL,*rearl=NULL;
void enqueuel(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
{
	printf("Queue is Overflow\n");
	return;
}
	temp->info=data;
	temp->next=NULL;
	if(frontl==NULL)
	frontl=temp;
	else
	rearl->next=temp;
	rearl=temp;
}
void displaylq()
{
	struct node *ptr;
	ptr=frontl;
	if(ptr==NULL)
{
	printf("Queue is Empty\n");
	return;
}
	printf("Elements are:");
	while(ptr!=rearl->next)
{
	printf("%d ",ptr->info);
	ptr=ptr->next;
}
	printf("\n");
}
int dequeuel()
{
	int i;
	if(frontl==NULL)
{
	printf("Queue is Underflow\n");
	return(0);
}
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=frontl->info;
	i=temp->info;
	frontl=frontl->next;
	free(temp);
	return(i);
}
void queuelinki()
{
    int i,data,j;
	printf("\t\t\nFUNCTIONS PERFORMED\n");
while(1)
{
	printf("1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
	scanf("%d",&i);
	switch(i)
{
	case 1:
		printf("Enter the Element: ");
		scanf("%d",&data);
		printf("\n");
		enqueuel(data);
	break;
	case 2:
		j=dequeuel();
		printf("Deleted Data is %d\n",j);
	break;
	case 3:
		displaylq();
	break;
	case 4:
		return;
}
}
}
/* CIRCULAR QUEUE */
int cqueue_arr[MAX];
int frontcq=-1;
int rearcq=-1;
int isEmptycq()
{
	if(frontcq==-1)
		return 1;
	else
		return 0;
}
int isFullcq()
{
	if((frontcq==0 && rearcq==MAX-1) || (frontcq==rearcq+1))
		return 1;
	else
		return 0;
}
void insertcq(int item)
{
	if( isFullcq() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(frontcq == -1 )
		frontcq=0;

	if(rearcq==MAX-1)/*rear is at last position of queue*/
		rearcq=0;
	else
		rearcq=rearcq+1;
	cqueue_arr[rearcq]=item ;
}
int delcq()
{
	int item;
	if( isEmptycq() )
	{
		printf("Queue Underflow\n");
		return(0);
	}
	item=cqueue_arr[frontcq];
	if(frontcq==rearcq)
	{
		frontcq=-1;
		rearcq=-1;
	}
	else if(frontcq==MAX-1)
		frontcq=0;
	else
		frontcq=frontcq+1;
	return item;
}
int peekcq()
{
	if( isEmptycq() )
	{
		printf("Queue Underflow\n");
		return(0);
	}
	return cqueue_arr[frontcq];
}
void displaycq()
{
	int i;
	if(isEmptycq())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=frontcq;
	if( frontcq<=rearcq )
	{
		while(i<=rearcq)
			printf("%d ",cqueue_arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",cqueue_arr[i++]);
		i=0;
		while(i<=rearcq)
			printf("%d ",cqueue_arr[i++]);
	}
	printf("\n");
}
void cirqueue()
{
    	int choice,item;
    	 printf("\n\t\tFUNCTIONS PERFORMED\n");
	while(1)
	{
		printf("1.Insert 2.Delete 3.Peek 4.Display 5.Quit \n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			printf("Input the element for insertion : ");
			scanf("%d",&item);
			insertcq(item);
			break;
		case 2 :
			printf("Element deleted is : %d\n",delcq());
			break;
		case 3:
			printf("Element at the front is  : %d\n",peekcq());
			break;
		case 4:
			displaycq();
			break;
		case 5:
			return;
		default:
			printf("Wrong choice\n");
		}
	}
}
/* DEQUE */
int deque_arr[MAX];
int frontdq=-1;
int reardq=-1;
int isFulldq()
{
	if ( (frontdq==0 && reardq==MAX-1) || (frontdq==reardq+1) )
		return 1;
	else
		return 0;
}
int isEmptydq()
{
	if( frontdq== -1)
		return 1;
	else
		return 0;
}
void insert_frontEnd(int item)
{
	if( isFulldq() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( frontdq==-1 )/*If queue is initially empty*/
	{
		frontdq=0;
		reardq=0;
	}
	else if(frontdq==0)
		frontdq=MAX-1;
	else
		frontdq=frontdq-1;
	deque_arr[frontdq]=item ;
}
void insert_rearEnd(int item)
{
	if( isFulldq() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(frontdq==-1)
	{
		frontdq=0;
		reardq=0;
	}
	else if(reardq==MAX-1)
		reardq=0;
	else
		reardq=reardq+1;
	deque_arr[reardq]=item ;
}
int delete_frontEnd()
{
	int item;
	if( isEmptydq() )
	{
		printf("Queue Underflow\n");
		return(0);
	}
	item=deque_arr[frontdq];
	if(frontdq==reardq)
	{
		frontdq=-1;
		reardq=-1;
	}
	else
		if(frontdq==MAX-1)
			frontdq=0;
		else
			frontdq=frontdq+1;
	return item;
}
int delete_rearEnd()
{
	int item;
	if( isEmptydq() )
	{
		printf("Queue Underflow\n");
		return(0);
	}
	item=deque_arr[reardq];
	if(frontdq==reardq)
	{
		frontdq=-1;
		reardq=-1;
	}
	else if(reardq==0)
		reardq=MAX-1;
	else
		reardq=reardq-1;
	return item;
}
void displaydq()
{
	int i;
	if( isEmptydq() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=frontdq;
	if( frontdq<=reardq )
	{
		while(i<=reardq)
			printf("%d ",deque_arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",deque_arr[i++]);
		i=0;
		while(i<=reardq)
			printf("%d ",deque_arr[i++]);
	}
	printf("\n");
}
void dequeue()
{
    int choice,item;
     printf("\n\t\tFUNCTIONS PERFORMED\n");
	while(1)
	{
		printf("1.Insert at the front end 2.Insert at the rear end 3.Delete from front end 4.Delete from rear end 5.Display 6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert_frontEnd(item);
			break;
		case 2:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert_rearEnd(item);
			break;
		 case 3:
			printf("Element deleted from front end is : %d\n",delete_frontEnd());
			break;
		 case 4:
			printf("Element deleted from rear end is : %d\n",delete_rearEnd());
			break;
		 case 5:
			displaydq();
			break;
		 case 6:
			return;
		 default:
			printf("Wrong choice\n");
		}
		printf("front = %d, rear =%d\n", frontdq, reardq);
		displaydq();
	}
}
