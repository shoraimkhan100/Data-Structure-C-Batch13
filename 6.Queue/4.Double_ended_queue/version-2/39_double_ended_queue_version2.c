#include<stdio.h>
#include<malloc.h>
#define MAX 20

void EnQueueFront(int *,int);
int DeQueueFront(int*);

void EnQueueAtRear(int *,int);
int DeQueueAtRear(int *);

void Display(const int *);

int IsQueueFull(void);
int IsQueueEmpty(void);

int g_iFront = 0;
int g_iRear = -1;

int main(void)
{
    int iChoice=1;
    int iNum=1;
    int iDelData;
    int Queue[MAX] = {0};
    int iDelete;

    while(iNum != 0)
    {   
    printf("\n\tEnter Your Choice : \n");
    printf("\n\t1. EnQueue At Rear\n");
    printf("\n\t2. EnQueue At Front\n");
    printf("\n\t3. DeQueue At Rear\n");
    printf("\n\t4. DeQueue At Front\n");
    printf("\n\t0. Exit\n");
    scanf("%d",&iChoice);

    switch(iChoice)
    {
    case 1:    
            iDelete = 1;
        while(iDelete != 0 && !IsQueueFull())
        {
            printf("Enter The Value You Want To Enter In Rear : ");
            scanf("%d",&iDelData);
            EnQueueAtRear(Queue,iDelData);
            Display(Queue);
            printf("If You Want To Exit Enter (0) : ");
            scanf("%d",&iDelete);
        }
        break;
        
    case 2:
         iDelete = 1;
         while(iDelete != 0 && !IsQueueFull())
        {
            printf("Enter The Value You Want To Enter In Front : ");
            scanf("%d",&iDelData);
            EnQueueFront(Queue,iDelData);
            Display(Queue);
            printf("If You Want To Exit Enter (0) : ");
            scanf("%d",&iDelete);
        }
        break;

    case 3:
            iDelete = 1;
        while(iDelete != 0 && !IsQueueEmpty())
        {
            iDelData=DeQueueAtRear(Queue);
            if(iDelData != 0)
                printf("Deleted Data from Rear is %d\n",iDelData);
            else
                printf("Deleted Data Not Found\n");
            Display(Queue);
            printf("If You Want To Exit Enter (0) : ");
            scanf("%d",&iDelete);
        }
        break;

    case 4:
            iDelete = 1;
        while(iDelete != 0 && !IsQueueEmpty())
        {
            iDelData=DeQueueFront(Queue);
            if(iDelData != 0)
                printf("Deleted Data from front is %d\n",iDelData);
            else
                printf("Deleted DAta is Not Found\n");
            Display(Queue);            
            printf("If You Want To Exit Enter (0) : ");
            scanf("%d",&iDelete);
        }
        break;
    case 0:
        iNum=0;
        break;
    default:
        printf("Invalid Choice . Please Enter A Valid Choice:\n");
    }
} 
    Display(Queue);
    return 0;
}
void EnQueueAtRear(int *pQueue , int iNo)
{
    if(IsQueueFull())
    {
        printf("Queue is overflow..\n");
        return;
    }
    if(g_iRear == MAX-1)
        g_iRear=0;
    pQueue[++g_iRear]=iNo;
}
int DeQueueAtRear(int *pQueue)
{
    int iDelData;
    if(IsQueueEmpty())
    {
        printf("Queue is Empty..\n"); 
           return -1;
    }
    iDelData=pQueue[g_iRear--];
    if(g_iFront == g_iRear)
    {
        g_iFront=0;
        g_iRear=-1;
    }
    else if(g_iRear == 0)//g_ifront
        g_iRear=MAX-1;//g)ifront

    return iDelData;
}
int DeQueueFront(int *pQueue)
{
    int iDelData;
    if(IsQueueEmpty())
    {
        printf("Queue is empty..\n");
        return -1;
    }
    iDelData=pQueue[g_iFront++];
    if(g_iFront == g_iRear)
    {
        g_iFront=0;
        g_iRear=-1;
    }
    else if(g_iFront == MAX-1)//MAX-1
        g_iFront=0;
    
    return iDelData;
}
void EnQueueFront(int *pQueue , int iNo)
{
    if(IsQueueFull())
    {
        printf("Queue is overflow..\n");
        return;
    }
    if(g_iFront == 0)//0
        g_iFront=MAX-1;//max-1
    
    pQueue[--g_iFront]=iNo;
}
void Display(const int *pQueue)
{
    int iCounter = g_iFront;
    if(g_iRear == -1)
    {
        printf("Queue is empty..\n");
        return;
    }
    if(g_iRear<g_iFront)
    {
    for(;iCounter<=MAX-1;iCounter++)
        printf("|%d|->",pQueue[iCounter]);
    return;
    }
        for(;iCounter<=g_iRear;iCounter++)
            printf("|%d|->",pQueue[iCounter]);
    printf("\n");
}
int IsQueueFull(void)
{
    if((g_iRear==0 && g_iFront==MAX-1))
        return 1;
    return 0;
}
int IsQueueEmpty(void)
{
    if((g_iRear == -1))
        return 1;
    return 0;
}