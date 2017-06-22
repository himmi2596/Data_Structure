#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include"header.h"
void array1()
{
    char ch;
    printf("\n1. ARRAY\n2. VECTORS\n");
    ch=getche();
    switch(ch)
    {
    case '1':
        arr();
        break;
    case '2':
        vectors();
        break;
    default:
        printf("WRONG CHOICE\n");
    }
}
/* ARRAY */
void multi(int p[40][40],int q[40][40],int m,int n,int o)
{
    int i,j,k;
    int c[40][40];
    for(i=0; i<m; i++)
    {
        for(j=0; j<o; j++)
        {
             c[i][j]=0;
            for(k=0; k<n; k++)
            {
                c[i][j]+=p[i][k]*q[k][j];
                printf("%d\n",c[i][k]);
            }
        }
    }
    int d,d1;
    for(d=0; d<m; d++)
    {
        for(d1=0; d1<o; d1++)
        {
            printf("%d ",c[d][d1]);
        }
        printf("\n");
    }
}
void arr()
{
    printf("\nMULTIPLICATION OF 2 MATRICES\n");
     int p[40][40],q[40][40];
     int m,n,o,a,b,a1,b1;
     printf("\nEnter the No. of Rows and Columns of 1st and 2nd matrices\n");
     scanf("%d%d%d",&m,&n,&o);
       printf("Enter 1st array\n");
     for(a=0; a<m; a++)
     {
         for(a1=0; a1<n; a1++)
         {
             scanf("%d",&p[a][a1]);
         }
     }
     printf("Enter 2nd array\n");
      for(b=0; b<n; b++)
     {
         for(b1=0; b1<o; b1++)
         {
             scanf("%d",&p[b][b1]);
         }
     }
     multi(p,q,m,n,o);
}
/* VECTORS */
int n;
int *start;
void insertv(int t)
{
    start=(int *)realloc(start,(n+t)*sizeof(int));
    int i;
    printf("\n");
    for(i=n;i<(n+t);i++)
    {
        printf("Enter the Element::");
        scanf("%d",start+i);
    }
    n+=t;
}
void displayv()
{
    int i=0;
    printf("Elements: ");
    while(i<n)
    {
        printf(" %d ",*(start+i));
        i++;
    }
    getch();
}
void delete_element(int x)
{
    int *ptr=start;
    int j=0,flag=0;
    for(;j<n-1;j++)
    {
        if(*ptr==x)
        {
            flag=1;
            *ptr=*(ptr+1);
            ptr++;
        }
        else if(flag==1)
        {
            *ptr=*(ptr+1);
            ptr++;
        }
        else
            ptr++;
    }
    if(flag==0&&*ptr==x)
        *ptr=*(ptr+1);
    else if(flag==0)
        {
            printf("\nNot Found");
            getch();
        }
    n--;
}
void vectors()
{
    int j;
    char ch;
    start=(int *)malloc(sizeof(int));
    while(1)
    {
        printf("\n1. Insert");
        printf(" 2. Delete");
        printf(" 3. Display");
        printf(" 4. Exit");
        printf("\nEnter your choice: ");
        ch=getche();
        switch(ch)
        {
            case '1':   printf("\nEnter the no. of Elements : ");
                        scanf("%d",&j);
                        insertv(j);
                        break;
            case '2':   printf("\nEnter the no. to be deleted : ");
                        scanf("%d",&j);
                        delete_element(j);
                        displayv();
                        break;
            case '3':   displayv();
                        break;
            case '4':   return;
        }
    }
}


