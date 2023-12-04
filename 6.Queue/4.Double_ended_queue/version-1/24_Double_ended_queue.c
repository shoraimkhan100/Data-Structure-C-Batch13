#include<stdio.h>
#include<malloc.h>
#define MAX 6

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
    int iDelData;
    int Queue[MAX] = {0};
    Display(Queue);
    EnQueueAtRear(Queue,10);
    EnQueueAtRear(Queue,20);
    EnQueueAtRear(Queue,30);
    Display(Queue);

    EnQueueFront(Queue,40);
    EnQueueFront(Queue,50);
    EnQueueFront(Queue,60);
    Display(Queue);
    

    iDelData=DeQueueAtRear(Queue);
    if(iDelData != -1)
        printf("Deleted Data from Rear is %d\n",iDelData);
    Display(Queue);

    iDelData=DeQueueFront(Queue);
    if(iDelData != -1)
        printf("Deleted Data from front is %d\n",iDelData);
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