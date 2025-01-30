#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *Prev;
    int Data;
    struct Node *Next;
};
struct Node *Head;

void create();
void read();
void display();

int main()
{
    create();
    read();
    display();
}
void create()
{
    int i,n;
    struct Node *temp_p;

    printf("Enter the no. of nodes you want to create \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            struct Node *temp=malloc(sizeof(struct Node));    //present node
            temp->Prev=NULL;
            Head=temp;
            temp_p=temp;
        }
        if(i>1&&i<n)
        {
            struct Node *temp=malloc(sizeof(struct Node));
            temp_p->Next=temp;
            temp->Prev=temp_p;
            temp_p=temp;
        }
        if(i==n)
        {
            struct Node *temp=malloc(sizeof(struct Node));
            temp_p->Next=temp;
            temp->Prev=temp_p;
            temp->Next=NULL;
        }

    }

}
void read()
{
    int i=1;
    struct Node *temp=Head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
        i++;
    }
    while(temp->Prev!=NULL)
    {
        temp=temp->Prev;
    

        printf("Enter data for node %d",i);
        scanf("%d",&temp->Data);
        
    }

}
void display()
{
    int i=1;
    struct Node *temp=Head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
        i++;
    }
    while(temp!=NULL)
    {
        temp=temp->Prev;
        printf("%d",temp->Data);
    }
}