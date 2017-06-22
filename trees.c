#include<stdio.h>
#include"header.h"
#include<conio.h>
#include<malloc.h>
#define MAX 20
#include<math.h>
#include<string.h>
void trees5()
{
    char ch;
    printf("\n1.COMPLETE TREE USING ARRAY\n2.BINARY SEARCH TREE USING LINKED LIST\n3.EXPRESSION TREE\n4.THREADED TREE\n");
    ch=getche();
    switch(ch)
    {
    case '1':
        comptree();
        break;
    case '2':
        bstree();
        break;
    case '3':
        exptree();
        break;
    case '4':
        threadtree();
        break;
    default:
        printf("WRONG CHOICE\n");
    }
}
/* COMPLETE TREE */
void preorder(int ar[],int n,int k)
{
    if(k>n)
        return;
    printf("%d ",ar[k]);
    preorder(ar,n,(2*k));
    preorder(ar,n,((2*k)+1));
}
void inorder(int ar[],int n,int k)
{
    if(k>n)
        return;
    inorder(ar,n,(2*k));
    printf("%d ",ar[k]);
    inorder(ar,n,((2*k)+1));
}
void postorder(int ar[],int n,int k)
{
    if(k>n)
        return;
    postorder(ar,n,(2*k));
    postorder(ar,n,((2*k)+1));
    printf("%d ",ar[k]);
}
void comptree()
{
    int ar[MAX];
    int i,l;
    printf("\nENTER THE NO. OF LEVELS\n");
    scanf("%d",&l);
    l=pow(2,l);
    printf("ENTER THE ELEMENTS OF TREES IN LEVEL ORDER AND ENTER -1 FOR NO NODE\n");
    ar[0]=-1;
    for(i=1; i<l; i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("PREORDER TRAVERSAL: ");
    preorder(ar,l-1,1);
    printf("\nINORDER TRAVERSAL: ");
    inorder(ar,l-1,1);
    printf("\nPOSTORDER TRAVERSAL: ");
    postorder(ar,l-1,1);
}
/* BST */
struct node1
{
    int item;
    struct node1*left1,*right1;
};
struct node1*insert1(struct node1*root,int key)
{
    if(root==NULL)
    {
        struct node1*temp=(struct node1*)malloc(sizeof(struct node1));
        temp->item=key;
        temp->right1=NULL;
        temp->left1=NULL;
        return temp;
    }
    if(root->item>key)
        root->left1=insert1(root->left1,key);
    else if(root->item<key)
        root->right1=insert1(root->right1,key);
        return(root);
};
struct node1*inorder1(struct node1*root)
{
    if(root!=NULL)
    {
        inorder1(root->left1);
        inorder1(root->right1);
        printf("%d  ",root->item);
    }
    return(root);
}
void bstree()
{
    struct node1*root=NULL;
    int n,k;
     printf("\n\t\tFUNCTIONS PERFORMED\n");
    while(1)
    {
    printf("1.Insert   2.Display  3.Exit\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("enter: "); scanf("%d",&k);
        if(root==NULL)
        root=insert1(root,k);
        else
            insert1(root,k);
            break;
    case 2:
        inorder1(root);
    case 3:
        return;
    }
    }
}
/* EXPRESSION TREE */
struct exp_tree* stack[MAX];
int top=-1;
struct exp_tree
{
    char data;
    struct exp_tree* lchild;
    struct exp_tree* rchild;
};
void push2(struct exp_tree* c)
{
  if(top==MAX)
  {
    printf("Stack is full");
    return ;
  }
  stack[++top]=c;
}
struct exp_tree* pop2()
{
  struct exp_tree* c;
  c=stack[top];
  top--;
  return c;
}
struct exp_tree* create2(char x)
{
    struct exp_tree* temp=(struct exp_tree*)malloc(sizeof(struct exp_tree));
    temp->data=x;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
};
struct exp_tree* insert2(struct exp_tree *root,struct exp_tree* opcode,struct exp_tree* a,struct exp_tree* b)
{
    root=opcode;
    root->lchild=b;
    root->rchild=a;
    return root;
}
struct exp_tree* inorder2(struct exp_tree* t)
{
    if(t==NULL)
        return t;
    t->lchild=inorder2(t->lchild);
    printf("%c ",t->data);
    t->rchild=inorder2(t->rchild);
    return(t);
}
void preorder2(struct exp_tree* t)
{
    if(t==NULL)
        return;
    printf("%c ",t->data);
    preorder2(t->lchild);
    preorder2(t->rchild);
}
void exptree()
{
    struct exp_tree* root=NULL;
    struct exp_tree* a;
    struct exp_tree* b;
    int i;
    char exp[15];
    char symbol;
    printf("\nEnter a postfix expression: ");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        symbol=exp[i];
        struct exp_tree* t=create2(symbol);
        switch(t->data)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                    a=pop2();
                    b=pop2();
                    root=insert2(root,t,a,b);
                    push2(root);
                    break;
            default: push2(t);
                    break;
        }
    }
    root=pop2();
    printf("Prefix order is: ");
    preorder2(root);
    printf("\nInfix order is: ");
    inorder2(root);
}
/* THREADED TREE */
typedef enum {true,false} boolean;
struct node
{
    int key;
    struct node *lchild;
    boolean lthread;
    struct node *rchild;
    boolean rthread;
}*root;
struct node *creat(int data)
{
 struct node *tmp=(struct node *)malloc(sizeof(struct node));
 tmp->lthread=true;
 tmp->key=data;
 tmp->rthread=true;
 tmp->lchild=NULL;
 tmp->rchild=NULL;
 return tmp;
}
struct node *casea(struct node* root,struct node* par,struct node* ptr)
{
    if(par==NULL)
        root=NULL;
    if(ptr==par->lchild)
        par->lchild=ptr->lchild;
    else
        par->rchild=ptr->rchild;
    free(ptr);
    return root;
}
struct node *caseb(struct node* root,struct node* par,struct node* ptr)
{
    struct node *child;
    if(ptr->lchild!=NULL)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    if(ptr==par->lchild)
    {
        child->lchild=ptr->lchild;
        par->lchild=child;
    }
    else
    {
        child->rchild=ptr->rchild;
        par->rchild=child;
    }
    return root;
}
struct node* casec(struct node* root,struct node* par,struct node* ptr)
{
    struct node *succ,*presuc;
    presuc=ptr;
    succ=ptr->rchild;
    while(succ->lthread!=true)
    {
        presuc=succ;
        succ=succ->lchild;
    }
    ptr->key=succ->key;
    if(succ->lthread==true&&succ->rthread==true)
        root=casea(root,presuc,succ);
    else
        root=caseb(root,presuc,succ);
    return root;
}
struct node* inser(struct node *root,int d)
{
    struct node *ptr=root,*tmp,*par=NULL;
    while(ptr!=NULL)
    {
        if(d==ptr->key)
        {
            printf("\nduplicate keys");
            break;
        }
        par=ptr;
        if(d<ptr->key)
        {
            if(ptr->lthread==false)
                ptr=ptr->lchild;
            else
                break;
        }
        else
        {
            if(ptr->rthread==false)
                ptr=ptr->rchild;
            else
                break;
        }
    }
     tmp=creat(d);
    if(par==NULL)
        root=tmp;
    else if(d<ptr->key)
    {
        tmp->lchild=par->lchild;
        tmp->rchild=par;
        par->lthread=false;
        par->lchild=tmp;
    }
    else
    {
        tmp->rchild=par->rchild;
        tmp->lchild=par;
        par->rthread=false;
        par->rchild=tmp;
    }
    return root;
}
struct node *succ(struct node *ptr)
{
        if(ptr->rthread==true)
            ptr=ptr->rchild;
        else
        {
            ptr=ptr->rchild;
            while(ptr->lthread==false)
                ptr=ptr->lchild;
        }
        return ptr;
}
struct node *pred(struct node *ptr)
{
        if(ptr->lthread==true)
            ptr=ptr->lchild;
        else
        {
            ptr=ptr->lchild;
            while(ptr->rthread==false)
                ptr=ptr->rchild;
        }
        return ptr;
}
void inorde(struct node *root)
{
    struct node *ptr=root;
    while(ptr->lthread==false)
        ptr=ptr->lchild;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->key);
        ptr=succ(ptr);
    }
}
void preorde(struct node *root)
{
    struct node *ptr=root;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->key);
        if(ptr->lthread==false)
            ptr=ptr->lchild;
        else if(ptr->rthread==false)
            ptr=ptr->rchild;
        else
        {
            while(ptr!=NULL&&ptr->rthread==true)
                ptr=ptr->rchild;
            if(ptr!=NULL)
                ptr=ptr->rchild;
        }
    }
}
void deletet(struct node *root,int dkey)
{
    struct node *ptr=root,*par;
    while(ptr!=NULL)
    {
        if(dkey==ptr->key)
            break;
        par=ptr;
        if(dkey<ptr->key)
        {
            if(ptr->lthread==false)
                ptr=ptr->lchild;
            else
                break;
        }
        else
        {
             if(ptr->rthread==false)
                ptr=ptr->rchild;
            else
                break;
        }
    }
    if(ptr->lthread==true && ptr->rthread==true)
        root=casea(root,par,ptr);
    else if(ptr->lthread==true || ptr->rthread==true)
        root=caseb(root,par,ptr);
    else
        root=casec(root,par,ptr);
}
void threadtree()
{
     int c,d;
    struct node*root=NULL;
     printf("\n\t\tFUNCTIONS PERFORMED\n");
    while(1)
    {
        printf("1.Insert node 2.Preorder 3.Inorder 4.Exit\nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter data to be inserted: ");
                    scanf("%d",&d);
                    root=inser(root,d);
                    break;
            case 2:preorde(root);
                    break;
            case 3:inorde(root);
                    break;
            case 4:return;
        }
    }
}
