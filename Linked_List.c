#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;

    struct Node *Link;
};

struct Node *Head;
int size;

 void create();
 void read();
 void display();
 void insert_at_end();
 void insert_at_begining();
 void insert_at_position();
 void delete_at_end();
 void delete_at_begining();
 void delete_at_position();
 void search();

int main()

{
      create();
      read();
      display ();
      insert_at_end();
      display();
      insert_at_begining();
      display ();
      insert_at_position();
      display();
      delete_at_end();
      display();
      delete_at_begining();
      display();
      delete_at_position();
      display();
      search();
      
}

void create()

{
  
    int i;

    printf("Enter the number of Nodes.\n");
    scanf("%d",&size);

    struct Node *temp_p;
    for(i=1;i<=size;i++)
    {
        if(i==1)
        {
            struct Node *temp=malloc(sizeof(struct Node));

            Head=temp;
            temp_p=temp;
        }
        else if((i>1)&&(i<size))
        {
            struct Node *temp=malloc(sizeof(struct Node));

            temp_p->Link=temp;
            temp_p=temp;
        }
        else if(i==size)
        {
            struct Node *temp=malloc(sizeof(struct Node));

            temp_p->Link=temp;

            temp->Link=NULL;
        }
    }
}

void read()
{
    int i=1;
    struct Node *temp=Head;

    while(temp!=NULL)
    {
        printf("Enter the Data for Node %d:",i);
        scanf("%d",&temp->Data);

        temp=temp->Link;
        i++;
    }
}



void insert_at_end()
{
      struct Node *temp=Head;
      struct Node *new=malloc(sizeof(struct Node));
      printf("\nEnter data for new last node");
      scanf("%d",&new->Data);

      while(temp->Link!=NULL)
      {
          temp=temp->Link;
      }
      temp->Link=new;
      new->Link =NULL;
      size++;

}


void insert_at_begining()
{
      struct Node *temp=Head;
      struct Node *begin=malloc(sizeof(struct Node));
      printf("\nEnter data for new node");
      scanf("%d",&begin->Data);
        begin->Link = Head;
        Head= begin;
        size++;
}
void insert_at_position()
{
    struct Node* temp=Head;
    struct Node *pos=malloc(sizeof(struct Node));
    printf("\nEnter the data you want to enter at nth position");
    scanf("%d",&pos->Data);
    int n,i=1;
    
    printf("\nEnter the position you want to insert the new node at");
    scanf("%d",&n);
    while(i<(n-1))
      {
        temp=temp->Link;
        i++;
      }
    struct Node *temp2=temp->Link;

    temp->Link=pos;
    pos->Link=temp2;
    size++;
}
void delete_at_end()
{
  struct Node *temp=Head;
  int press;
  printf("\nEnter 1 to delete at end");
    scanf("%d",&press);
    if(press==1)
    { 
      int i=1;
      while(i<size-1)
       {
          temp=temp->Link;
          i++;
        }
        temp->Link=NULL;
      size--;
    }
  else
    {
      printf("Wrong");
    }
}
void delete_at_begining()
{

      printf("\nDeleting a node at begining....\n");
      struct Node *temp=Head;
      
          Head=Head->Link;
          size--;
}
void delete_at_position()
{
    struct Node* temp=Head;
    int n,i=1;
    printf("\nEnter the position you want to delete at:");
    scanf("%d",&n);
    while(i<(n-1))
      {
        temp=temp->Link;
        i++;
      }
      temp->Link=temp->Link->Link;
}

void search()
{
    struct Node* temp=Head;
    int x,i=1,flag=0;
    printf("Enter the no. you want to search for:");
    scanf("%d",&x);
    while(temp!=NULL)
      {
        
        if(temp->Data==x)
          {
              printf("Found at %d",i);
              flag=1;
              
          }
        temp=temp->Link;
        i++;
      }
    if(flag==0)
    {
      printf("Not Found \n");
    }
}


void display()
{
    struct Node* temp=Head;

        while(temp!=NULL)
        {
            printf("%d ",temp->Data);

            temp=temp->Link;

        }
}