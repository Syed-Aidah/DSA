
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int Data;
  struct Node *Link;
};
struct Node *Head;
void create();
void read();
void display();
void insertion_at_end();
void insertion_at_position();
void deletion();
void search();
int main()
{
  create();
  read();
  display();
  insertion_at_end();
  display();
  insertion_at_position();
  display();
  deletion();
  display();
  search();

}
void create()
{
  int n,i;
  struct Node *temp_p;

  printf("Enter the no. of Nodes you want to create");
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
    if(i==1)
    {
      struct Node *temp= malloc(sizeof(struct Node));
      Head=temp;
      temp_p=temp;

    }
    else if(i>1 && i<n)
    {
      struct Node *temp=malloc(sizeof(struct Node));
      temp_p->Link=temp;
      temp_p=temp;
    }
    else if(i==n)
    {
      struct Node *temp=malloc(sizeof(struct Node));
      temp_p->Link=temp;
      temp->Link=Head;
    }
   }
  }

  void read()
{

    struct Node *temp=Head;
    int i=1;
    do {
        printf("Enter Data for node %d",i);
        scanf("%d",&temp->Data);
        temp=temp->Link;
        i++;
      }
      while(temp!=Head);
  }
  void display()
  {
    struct Node *temp=Head;
      do{
        printf("%d",temp->Data);
        temp=temp->Link;
      }
      while(temp!=Head);
  }
void insertion_at_end()
{
    struct Node *temp=Head;
    struct Node *new=malloc(sizeof(struct Node));
    printf("\nEnter data for new last node");
    scanf("%d",&new->Data);

    while(temp->Link!=Head)
    {
        temp=temp->Link;
    }
    temp->Link=new;
    new->Link =Head;

}
void insertion_at_position()
{
    struct Node *temp=Head;
    int i=1,n;
    struct Node *new=malloc(sizeof(struct Node));

    printf("\nEnter data for the new node");
    scanf("%d",&new->Data);

    printf("Enter the position you want the node to be inserted");
    scanf("%d",&n);
    
    while(i<(n-1))
    {
        temp=temp->Link;
        i++;
    }
    
    struct Node *temp2=temp->Link;
    temp->Link=new;
    new->Link =temp2;
}
void deletion()
{
   struct Node *temp=Head;
   int i=1,n;
   printf("Enter the position you want to delete at ");
   scanf("%d",&n);
   while(i<n-1)
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
 do
    {
      
      if(temp->Data==x)
        {
            printf("Found at %d",i);
            flag=1;
             
        }
      temp=temp->Link;
      i++;
    }while(temp!=Head);
  if(flag==0)
  {
    printf("Not Found \n");
  }
 }                       

