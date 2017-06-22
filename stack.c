#include<stdio.h>
#include"header.h"
#include<conio.h>
#include<malloc.h>
void stack3()
{
    char ch;
    printf("\n1.STACK USING ARRAY\n2.STACK USING LINKED LIST\n3.GETTING SORTED STACK\n");
    ch=getche();
    switch(ch)
    {
    case '1':
        stackarr();
        break;
    case '2':
        stacklinki();
        break;
    case '3':
        sortedstack();
        break;
    default:
        printf("WRONG CHOICE\n");
    }
}
/* USING ARRAY */
#define MAX 20

int ar[MAX];
int topa=-1;

void pusha(int data)
{
	if(topa==-1)      //empty condition
{
	topa++;
	ar[topa]=data;
	return;
}
	else if(topa<MAX)
{
	topa++;
	ar[topa]=data;
	return;
}
	else
{
	printf("Stack Is Full\n");
	return;
}
}
void displaya()
{
	int i=0;
	printf("Eements are:");
	while(i<=topa)
{
	printf("%d ",ar[i]);
	i++;
}
	printf("\n");
}
void popa()
{
	int i;
	if(topa==-1)
{
	printf("List Is Empty\n");
}
	else if(topa<MAX)
{
	i=ar[topa];
	topa--;
	printf("Deleted Data is %d\n",i);
}
	else
{
	printf("Stack Is Full\n");
	return;
}
}
void stackarr()
{
    int i,data;
	printf("\n\t\tFUNCTIONS PERFORMED\n");
while(1)
{
	printf("1.Push 2.Pop 3.Display 4.Exit\n");
	scanf("%d",&i);
	switch(i)
{
	case 1:
		printf("Enter the Element: ");
		scanf("%d",&data);
		pusha(data);
	break;
	case 2:
		popa();
	break;
	case 3:
		displaya();
	break;
	case 4:
		return;
}
}
}
/* USING LINKED LIST */
struct node
{
	int info;
	struct node *next;
}*topl=NULL;
void pushl(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
{
	printf("Stack Is Overflow\n");
	return;
}
	temp->info=data;
	temp->next=topl;
	topl=temp;
}
void displayl()
{
	struct node *ptr;
	ptr=topl;
	if(ptr==NULL)
{
	printf("Stack Is Empty\n");
	return;
}
	printf("Elements Are:");
	while(ptr!=NULL)
{
	printf("%d ",ptr->info);
	ptr=ptr->next;
}
	printf("\n");
}
int popl()
{
	int i;
	if(topl==NULL)
{
	printf("stack is underflow\n");
	return(0);
}
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=topl->info;
	i=temp->info;
	topl=topl->next;
	free(temp);
	return(i);
}
void stacklinki()
{
    int i,data,j;
	printf("\n\t\tFUNCTIONS PERFORMED\n");
while(1)
{
	printf("1.Push 2.Pop 3.Display 4.Exit\n");
	scanf("%d",&i);
	switch(i)
{
	case 1:
		printf("Enter The Element: ");
		scanf("%d",&data);
		printf("\n");
		pushl(data);
	break;
	case 2:
		j=popl();
		printf("Deleted Data is %d\n",j);
	break;
	case 3:
		displayl();
	break;
	case 4:
         return;
}
}
}
/* SORTED STACK */
#define max 10
int top1=-1;
int top2=-1;
int stack[max];
int temp[max];
void push(int item,int i)
{
    if(i==1)
    {
        if(top1==max-1)
        {
             printf("Stack Overflow");
             return;
        }
        stack[++top1]=item;
    }
    else
    {
       if(top2==max-1)
        {
             printf("Stack Overflow");
             return;
        }
        temp[++top2]=item;
    }
}
int pop(int i)
{
    if(i==1)
    {
        if(top1==-1){printf("Stack Underflow");return-1;}
        return stack[top1--];
    }
    else{
        if(top2==-1)
    {
        printf("Stack Underflow");return-1;
    }
        return temp[top2--];}
}
void display(int i)
{
    int j;
    if(i==1)
    {
        for(j=0;j<=top1;j++)
        {
            printf("%d ",stack[j]);
        }
    }
    else
    {
        for(j=0;j<=top2;j++)
        {
            printf("%d ",temp[j]);
        }
    }
    printf("\n");
}
int topst()
{
    return stack[top1];
}
void insert(int item)
{
    int j;
    if(topst()==-1)
        {push(item,1);return;}
    else
    {
      while(topst()>item)
      {
         j=pop(1);
         push(j,2);
      }
      push(item,1);
      while(top2!=-1)
      {
          j=pop(2);
          push(j,1);
      }
    }
}
void sortedstack()
{
        int choice,item;
        printf("\n\t\tFUNCTIONS PERFORMED\n");
          while(1)
          {
                   printf("1.Push 2.Pop  Display all stack elements  4.Quit\n");
                   printf("Enter your choice : ");
                   scanf("%d",&choice);
                   switch(choice)
                   {
                    case 1 :
                             printf("Enter the item to be pushed : ");
                             scanf("%d",&item);
                             insert(item);
                             break;
                    case 2:
                             item = pop(1);
                             printf("Popped item is : %d\n",item );
                             break;
                    case 3:
                             display(1);
                             break;
                    case 4:
                             return;
                             default:
                             printf("Wrong choice\n");
                   }
          }
}
