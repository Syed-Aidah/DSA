#include<stdio.h>
void  read(int a[],int n);
void  display(int a[],int n);
void search(int a[],int n);
int  insert(int a[],int n);
void  delete(int a[],int n);
int main()
{
    int a[100],n;
     printf("Enter the no of elements you want to enter");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    search(a,n);
    n=insert(a,n);
    delete(a, n);
}
void  read(int a[],int n)
{
   int i;
   printf("ENTER THE ELEMENTS");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);

}
void  display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d",a[i]);
    printf("\n");

}
void search(int a[],int n)
{
    int x,i,flag;
    printf("Enter the element you want to search for");
    scanf("%d",&x);
     for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            printf("Found at %d \n",i+1);
            flag=1;
        }
       
    }
    if(flag!=1)
        {
            printf("NOT found \n");
        }
    
}
int  insert(int a[],int n)   
{
    int i,x,p;
    for(i=n-1;i>=0;i--)
     {
        a[i+1]=a[i];
     }
        n++;
        printf("Enter the element you want to insert at the begining");
        scanf("%d",&a[0]);
        display(a,n);
        
        printf("Enter the element you want to insert at the end");
        scanf("%d",&a[n]);
        n++;
        display(a,n);

         printf("Enter the position");
         scanf("%d",&p);
         for(i=n-1;i>=p-1;i--)
     {
        a[i+1]=a[i];
     }
        n++;
            printf("Enter the element you want to insert at %d \n",(p));
        scanf("%d",&a[p-1]);
        display(a,n);
        return n;
        
}
void  delete(int a[],int n){
  int i;
  //Deletion at start
  for(i=0;i<(n-1);i++)
  {
    a[i]=a[(i+1)];
  }  
  n--;
  display(a,n);
  printf("\n//Element at start deleted//");

}