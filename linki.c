#include<stdio.h>
#include"header.h"
#include<conio.h>
#include<malloc.h>
void linki2()
{
    char ch;
    printf("\n1.SINGLE LINKED LIST\n2.DOUBLE LINKED LIST\n3.CIRCULAR LINKED LIST\n");
    ch=getche();
    switch(ch)
    {
    case '1':
        singlelinki();
        break;
    case '2':
        doublelinki();
        break;
    case '3':
        circularlinki();
        break;
     default:
        printf("WRONG CHOICE\n");
    }
}
/* SINGLE */
struct ss
{
 int info;
 struct ss* next;
}*start1;
struct ss *creates(int num)
{
  struct ss*temp=(struct ss*)malloc(sizeof(struct ss));
  if(temp==NULL)
     printf("ERROR\n");
  else
{
   temp->info=num;
    temp->next=NULL;
    return temp;
}
return(temp);
}
void displays()
{
struct ss*temp=start1;
int ct=0;
 while(temp!=NULL)
{
  printf("%d ",temp->info);
 temp=temp->next;
 ct++;
}
printf("\nNo. of Nodes are %d",ct);
}
 void insertatends(int data)
{
struct ss*tempo=NULL;
 struct ss*scopy=start1;
while(scopy->next!=NULL)
scopy=scopy->next;
scopy->next=tempo;
tempo->info=data;
tempo->next=NULL;
}
void insertatbegs(int data)
{
struct ss*temp=(struct ss*)malloc(sizeof(struct ss));
temp->info=data;
temp->next=start1;
start1=temp;
}
void insertinemps(int data)
{
if(start1!=NULL)
printf("List is not Empty\n");
else{
struct ss*temp=(struct ss*)malloc(sizeof(struct ss));
temp->info=data;
temp->next=NULL;
start1=temp;
}
}
void insertafrs(int data)
{
if(start1==NULL){
printf("List is Empty\n"); return; }
int item;
printf("Insertion after which Number\n");
scanf("%d",&item);
struct ss* temp;
struct ss*temp1=(struct ss*)malloc(sizeof(struct ss));
temp=start1;
while(temp!=NULL)
{
if(temp->info==item){
temp1->info=data;
temp1->next=temp->next;
temp->next=temp1;
}
temp=temp->next;
}
printf("%d is not in list\n",item);
}
void insertbefs(int data)
{
struct ss*p,*temp;
temp=(struct ss*)malloc(sizeof(struct ss));
temp->info=data;
if(start1==NULL){
printf("List is Empty\n"); return;}
int item;
printf("Insertion before which Number\n");
scanf("%d",&item);
if(item==start1->info)
{
temp->next=start1;
start1=temp;
return;
}
p=start1;
while(p->next!=NULL)
{
if(p->next->info==item)
{
temp->next=p->next;
p->next=temp;
return;
}
p=p->next;
}
printf("%d is not in list\n",item);
}
void insertps(int data)
{
struct ss*p,*temp;
temp=(struct ss*)malloc(sizeof(struct ss));
temp->info=data;
int i,item;
printf("Insertion at which Position\n");
scanf("%d",&item);
if(item==1)
{
temp->next=start1;
start1=temp;
return;
}
p=start1;
for(i=1; i<item-1 && p!=NULL; i++)
p=p->next;
if(p==NULL)
printf("There are less no. of numbers in list\n");
else{
temp->next=p->next;
p->next=temp;
}
}
void reverses(struct ss*p)
{   struct ss*q;
	if(p->next==NULL){
		start1=p;
		return;
}
	reverses(p->next);
	q=p->next;
	q->next=p;
	p->next=NULL;
}
void searchs(int data)
{
struct ss*temp;
temp=start1;
int ct=1,c=0;
while(temp!=NULL)
{
if(temp->info==data){
 printf("Item %d found at %d position\n",data,ct);
 c++;
}
temp=temp->next;
ct++;
}
if(c==0)
printf("Item not Found\n");
}
void delbegs()
{
struct ss*temp;
temp=start1;
start1=start1->next;
free(temp);
return;
}
void delonlys()
{
struct ss*temp;
temp=start1;
start1=NULL;
free(temp);
return;
}
void delbets()
{
struct ss*p,*temp;
p=start1;
int item;
printf("Deletion of which data\n");
scanf("%d",&item);
while(p->next!=NULL)
{
if(p->next->info==item)
{
temp=p->next;
p->next=temp->next;
free(temp);
return;
}
p=p->next;
}
printf("%d not in the list\n",item);
}
void delends()
{
struct ss*p,*temp;
if(start1==NULL)
{
printf("List is empty\n");
return;
}
p=start1;
while(p->next!=NULL)
{
if(p->next->next==NULL)
{
temp=p->next;
p->next=temp->next;
free(temp);
return;
}
p=p->next;
}
}
void displayrevs(struct ss*st)
{
struct ss*temp=st;
int ct=0;
if(st==NULL)
printf("no reversal possible\n");
else{
 while(temp!=NULL)
{
  printf("%d ",temp->info);
 temp=temp->next;
 ct++;
}
}
}
void singlelinki()
{
start1=NULL;
  int s,n,n1,nn,j,no,l,k;
  printf("\n\t\tFUNCTIONS PERFORMED\n");
while(1)
{
  printf("1.CREATION 2.DISPLAY 3.INSERT 4.REVERSING 5.SEARCHING 6.DISPLAY REVERSE 7.DELETION 8.EXIT\n");
  scanf("%d",&n);
 switch(n)
{
 case 1:
printf("HOW MANY NODES U WANT\n");
scanf("%d",&nn);
printf("ENTER THE VALUES\n");
 for(n1=1; n1<=nn; n1++){
int i;
  scanf("%d",&i);
if(start1==NULL)
  start1= creates(i);
else
{
struct ss*temp1;
temp1=creates(i);
struct ss*temp;
temp=start1;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=temp1;
}
}
 break;
case 2:
displays();
break;
case 3:
printf("insert the no.\n");
scanf("%d",&no);
printf("where to insert 1.at end 2.at beg 3.in empty list 4.in between\n");
scanf("%d",&j);
switch(j)
{
	case 1:
	insertatends(no);  break;
	case 2:
	insertatbegs(no);  break;
	case 3:
	insertinemps(no);  break;
	case 4:
	printf("1.after node 2.before node 3.at given position\n");
	scanf("%d",&k);
	switch(k)
	{
	case 1:
	insertafrs(no); break;
	case 2:
	insertbefs(no); break;
	case 3:
	insertps(no); break;
	}
}
break;
case 4:
reverses(start1);
break;
case 5:
printf("search for\n");
scanf("%d",&s);
searchs(s);
break;
case 6:
displayrevs(start1);
break;
case 7:
printf("where to delete\n1.at beg\n2.at end\n3.deletion of only node\n4.in between\n");
scanf("%d",&l);
switch(l)
{
	case 1:
	delbegs();
	break;
	case 2:
	delends();
	break;
	case 3:
	delonlys();
	break;
	case 4:
	delbets();
	break;
}
break;
case 8:
return;
}
}
}
/* DOUBLE */
struct sd
{
 int info;
 struct sd* next;
 struct sd*prev;
}*start2;
 void insertatendd(int data)
{
struct sd*tempo=(struct sd*)malloc(sizeof(struct sd));
 struct sd*scopy=start2;
while(scopy->next!=NULL)
scopy=scopy->next;
scopy->next=tempo;
tempo->prev=scopy;
tempo->info=data;
tempo->next=NULL;
}
void insertinempd(int data)
{
if(start2!=NULL)
printf("list is not empty");
else{
struct sd*temp=(struct sd*)malloc(sizeof(struct sd));
temp->prev=NULL;
temp->info=data;
temp->next=NULL;
start2=temp;
}
}
void created()
{
	int i,n,data;
	if(start2==NULL)
{
	printf("no. of nodes\n");
	scanf("%d",&n);
}
	if(n==0)
	return ;
	printf("Enter the Element\n");
	scanf("%d",&data);
	insertinempd(data);
	for(i=2; i<=n; i++)
{
	printf("enter the element\n");
	scanf("%d",&data);
	insertatendd(data);
}
	if(start2==NULL)
	printf("error\n\n");
	return ;
}
void displayd()
{
struct sd*temp=start2;
int ct=0;
 while(temp!=NULL)
{
  printf("%d ",temp->info);
 temp=temp->next;
 ct++;
}
printf("\nno. of nodes are %d\n",ct);
}
void insertatbegd(int data)
{
struct sd*temp=(struct sd*)malloc(sizeof(struct sd));
temp->prev=NULL;
temp->info=data;
temp->next=start2;
start2=temp;
}
void insertafrd(int data)
{
if(start2==NULL){
printf("list is empty"); return; }
int item;
printf("insertion after which number\n");
scanf("%d",&item);
struct sd* temp;
struct sd*temp1=(struct sd*)malloc(sizeof(struct sd));
temp=start2;
while(temp!=NULL)
{
if(temp->info==item){
temp1->info=data;
temp1->next=temp->next;
temp1->prev=temp;
temp->next=temp1;
}
temp=temp->next;
}
printf("%d is not in list\n",item);
}
void insertbefd(int data)
{
struct sd*p,*temp;
temp=(struct sd*)malloc(sizeof(struct sd));
temp->info=data;
if(start2==NULL){
printf("list is empty"); return;}
int item;
printf("insertion before which number\n");
scanf("%d",&item);
if(item==start2->info)
{
temp->next=start2;
temp->prev=NULL;
start2=temp;
return;
}
p=start2;
while(p->next!=NULL)
{
if(p->next->info==item)
{
temp->next=p->next;
p->next=temp;
temp->prev=p;
return;
}
p=p->next;
}
printf("%d is not in list\n",item);
}
void insertpd(int data)
{
struct sd*p,*temp;
temp=(struct sd*)malloc(sizeof(struct sd));
temp->info=data;
int i,item;
printf("insertion at which position\n");
scanf("%d",&item);
if(item==1)
{
temp->next=start2;
temp->prev=NULL;
start2=temp;
return;
}
p=start2;
for(i=2; i<item && p!=NULL; i++)
p=p->next;
if(p==NULL)
printf("there are less no. of numbers in list\n");
else{
temp->next=p->next;
temp->prev=p;
p->next=temp;
}
}
void searchd(int data)
{
struct sd*temp;
temp=start2;
int ct=1,c=0;
while(temp!=NULL)
{
if(temp->info==data){
 printf("item %d found at %d position\n",data,ct);
 c++;
}
temp=temp->next;
ct++;
}
if(c==0)
printf("item not found\n");
}
void delbegd()
{
struct sd*temp;
temp=start2;
start2=start2->next;
start2->prev=NULL;
free(temp);
return;
}
void delonlyd()
{
struct sd*temp;
temp=start2;
start2=NULL;
free(temp);
return;
}
void delbetd()
{
struct sd*p,*temp;
p=start2;
int item;
printf("deletion of which data\n");
scanf("%d",&item);
while(p->next!=NULL)
{
if(p->next->info==item)
{
temp=p->next;
p->next=temp->next;
temp->prev=p;
free(temp);
return;
}
p=p->next;
}
printf("%d not in the list\n",item);
}
void delendd()
{
struct sd*p,*temp;
if(start2==NULL)
{
printf("list is empty\n");
return;
}
p=start2;
while(p->next!=NULL)
{
if(p->next->next==NULL)
{
temp=p->next;
p->next=temp->next;
free(temp);
return;
}
p=p->next;
}
}

struct sd* reversed(struct sd*p)
{
  struct sd*p1;
  p1=p->next;
  p1->prev=p;
  p->next=NULL;
 while(p1!=NULL)
{
	p1->prev=p1->next;
	p1->next=p;
	p=p1;
	p1=p1->prev;
}
 return p;
}
void displayrevd(struct sd*st)
{
struct sd*temp=st;
int ct=0;
if(st==NULL)
printf("no reversal possible\n");
else{
 while(temp!=NULL)
{
  printf("%d ",temp->info);
 temp=temp->next;
 ct++;
}
}
}
void doublelinki()
{
struct sd*rev;
rev=NULL;
start2=NULL;
  int s,n,j,no,l,k;
  printf("\n\t\tFUNCTIONS PERFORMED\n");
while(1)
{
  printf("1.CREATION 2.DISPLAY 3.INSERT 4.REVERSING 5.SEARCHING 6.DISPLAY REVERSE 7.DELETION 8.EXIT\n");
  scanf("%d",&n);
 switch(n)
{
 case 1:
created();
 break;
case 2:
displayd();
break;
case 3:
printf("insert the no.\n");
scanf("%d",&no);
printf("where to insert\n1.at end\n2.at beg\n3.in empty list\n4.in between\n");
scanf("%d",&j);
switch(j)
{
	case 1:
	insertatendd(no);  break;
	case 2:
	insertatbegd(no);  break;
	case 3:
	insertinempd(no);  break;
	case 4:
	printf("1.after node 2.before node 3.at given position\n");
	scanf("%d",&k);
	switch(k)
	{
	case 1:
	insertafrd(no); break;
	case 2:
	insertbefd(no); break;
	case 3:
	insertpd(no); break;
	}
}
break;
case 4:
rev=reversed(start2);
break;
case 5:
printf("search for\n");
scanf("%d",&s);
searchd(s);
break;
case 6:
displayrevd(rev);
break;
case 7:
printf("where to delete 1.at beg 2.at end 3.deletion of only node 4.in between\n");
scanf("%d",&l);
switch(l)
{
	case 1:
	delbegd();
	break;
	case 2:
	delendd();
	break;
	case 3:
	delonlyd();
	break;
	case 4:
	delbetd();
	break;
}
break;
case 8:
return;
}
}
}
/* CIRCULAR */
struct s
{
 int info;
 struct s* next;
}*last,*start;
 void insertatend(int data)
{
struct s*temp=(struct s*)malloc(sizeof(struct s));
temp->info=data;
temp->next=last->next;
last->next=temp;
last=temp;
return;
}
void insertinemp(int data)
{
if(last!=NULL)
printf("list is not empty");
else{
struct s*temp=(struct s*)malloc(sizeof(struct s));
last=temp;
last->info=data;
last->next=last;
}
}
void create()
{
  int i,n,data;
	if(last==NULL)
{
	printf("no. of nodes");
	scanf("%d",&n);
}
	if(n==0)
	return ;
	printf("enter the element");
	scanf("%d",&data);
	insertinemp(data);
	for(i=2; i<=n; i++)
{
	printf("enter the element");
	scanf("%d",&data);
	insertatend(data);
}
	if(last==NULL)
	printf("error\n\n");
	return ;
}
void displaycc()
{
if(last==NULL){
printf("list is empty\n");
return;
}
struct s*temp=last->next;
int ct=0;
 do
{
  printf("%d ",temp->info);
 temp=temp->next;
 ct++;
}while(temp!=last->next);
printf("\nno. of nodes are %d",ct);
}
void insertatbeg(int data)
{
struct s*temp=(struct s*)malloc(sizeof(struct s));
temp->info=data;
temp->next=last->next;
last->next=temp;
return;
}
void insertafr(int data)
{
struct s*temp1=(struct s*)malloc(sizeof(struct s));
if(last==NULL){
printf("list is empty"); return; }
int item;
printf("insertion after which number\n");
scanf("%d",&item);
if(item==last->info)
{
temp1->next=last->next;
last->next=temp1;
return;
}
struct s* temp;
temp=last->next;
do
{
if(temp->info==item){
temp1->info=data;
temp1->next=temp->next;
temp->next=temp1;
}
temp=temp->next;
}
while(temp!=last->next);
printf("%d is not in list\n",item);
}
void insertbef(int data)
{
struct s*p,*temp;
temp=(struct s*)malloc(sizeof(struct s));
temp->info=data;
if(last==NULL){
printf("list is empty"); return;}
int item;
printf("insertion before which number\n");
scanf("%d",&item);
p=last->next;
do
{
if(p->next->info==item)
{
temp->next=p->next;
p->next=temp;
return;
}
p=p->next;
}
while(p!=last->next);
printf("%d is not in list\n",item);
}
void insertp(int data)
{
struct s*p,*temp;
temp=(struct s*)malloc(sizeof(struct s));
temp->info=data;
int i,item;
printf("insertion at which position\n");
scanf("%d",&item);
p=last->next;
for(i=1; i<item-1 && p!=NULL; i++)
p=p->next;
if(p==NULL)
printf("there are less no. of numbers in list\n");
else{
temp->next=p->next;
p->next=temp;
}
}
struct s* reverse(struct s*p)
{
  struct s *ptr,*prev,*nex;
  ptr=last->next;
  prev=last;
do
{
	nex=ptr->next;
	ptr->next=prev;
	prev=ptr;
	ptr=nex;
}
 while(prev!=last);
 return prev;
}
void search(int data)
{
struct s*temp;
temp=last->next;
int ct=1,c=0;
do
{
if(temp->info==data){
 printf("item %d found at %d position\n",data,ct);
 c++;
}
temp=temp->next;
ct++;
}
while(temp!=last->next);
if(c==0)
printf("item not found\n");
}
void delbeg()
{
struct s*temp;
temp=last->next;
last->next=temp->next;
free(temp);
return;
}
void delonly()
{
struct s*temp;
temp=last;
last=NULL;
free(temp);
return;
}
void delbet()
{
struct s*p,*temp;
p=last->next;
int item;
printf("deletion of which data\n");
scanf("%d",&item);
do
{
if(p->next->info==item)
{
temp=p->next;
p->next=temp->next;
free(temp);
return;
}
p=p->next;
}
while(p!=last->next);
printf("%d not in the list\n",item);
}

void delend()
{
struct s*p,*temp;
if(last==NULL)
{
printf("list is empty\n");
return;
}
p=last->next;
do
{
if(p->next==last)
{
temp=last;
p->next=temp->next;
last=p;
free(temp);
return;
}
p=p->next;
}
while(p!=last->next);
}
void displayrevcc(struct s*st)
{
struct s*temp=st;
int ct=0;
if(st==NULL)
printf("no reversal possible\n");
else{
do
{
  printf("\n%d\n",temp->info);
 temp=temp->next;
 ct++;
}
while(temp!=st);
}
}
void circularlinki()
{
struct s*rev;
rev=NULL;
last=NULL;
  int s,n,j,no,l,k;
  printf("\n\t\tFUNCTIONS PERFORMED\n");
while(1)
{
  printf("1.CREATION 2.DISPLAY 3.INSERT 4.REVERSING 5.SEARCHING 6.DISPLAY REVERSE 7.DELETION 8.EXIT\n");
  scanf("%d",&n);
 switch(n)
{
 case 1:
create();
 break;
case 2:
displaycc();
break;
case 3:
printf("insert the no.\n");
scanf("%d",&no);
printf("where to insert 1.at end 2.at beg 3.in empty list 4.in between\n");
scanf("%d",&j);
switch(j)
{
	case 1:
	insertatend(no);  break;
	case 2:
	insertatbeg(no);  break;
	case 3:
	insertinemp(no);  break;
	case 4:
	printf("1.after node 2.before node 3.at given position\n");
	scanf("%d",&k);
	switch(k)
	{
	case 1:
	insertafr(no); break;
	case 2:
	insertbef(no); break;
	case 3:
	insertp(no); break;
	}
}
break;
case 4:
rev=reverse(start);
break;
case 5:
printf("search for\n");
scanf("%d",&s);
search(s);
break;
case 6:
displayrevcc(rev);
break;
case 7:
printf("where to delete 1.at beg 2.at end 3.deletion of only node 4.in between\n");
scanf("%d",&l);
switch(l)
{
	case 1:
	delbeg();
	break;
	case 2:
	delend();
	break;
	case 3:
	delonly();
	break;
	case 4:
	delbet();
	break;
}
break;
case 8:
return;
}
}
}
