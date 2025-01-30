#include<stdio.h>

int main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    int i=0,x,flag=0;

    printf("Enter the number to search for.\n");
    scanf("%d",&x);

    for(i=0;i<10;i++)
    {
        if(x==arr[i])
        {
            printf("Found at %d\n",i+1);
            return 0;
        }
    }
    
    printf("Not Found\n");
    

    return 0;
}