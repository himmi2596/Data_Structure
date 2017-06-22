#include <stdio.h>
#include <stdlib.h>
#include<conio.h>    //if we include #include"queue.c" then we dont have to include all the headers in queue.c
void array1();
void  linki2();
void stack3();
void queue4();
void trees5();
int main()
{
    char ch,choice;
    printf("\t***************          DATA STRUCTURE          ***************\n");
    do
    {
        printf("\n\t\t**ENTER YOUR CHOICE**\n1.ARRAY\n2.LINKED LIST\n3.STACK\n4.QUEUE\n5.TREES\n6.EXIT\n");
        choice=getche();
        switch(choice)
        {
        case '1':  system("cls");
            array1();
            break;
        case '2':  system("cls");
           linki2();
            break;
        case '3':  system("cls");
            stack3();
            break;
        case '4':  system("cls");
            queue4();
            break;
        case '5':  system("cls");
            trees5();
            break;
        case '6':
            exit(1);
        default:
            printf("WRONG CHOICE\n");
        }
        printf("\n\nDO YOU WANT TO VISIT THE HOMEPAGE(Y/N)\n");
        ch=getche();
        system("cls");
    }while(ch=='y');
    return(0);
}
