#include<stdio.h>
#include<malloc.h>
#define MAX 5

void EnQueue(int *,int);
int DeQueue(int*);
void Display(const int *);
int IsQueueFull(void);
int IsQueueEmpty(void);

int g_iFront = 0;
int g_iRear = -1;

int main(void)
{
    int iDelData;
    int Queue[MAX] = {0};
    EnQueue(Queue,10);
    EnQueue(Queue,20);
    EnQueue(Queue,30);
    Display(Queue);

    iDelData=DeQueue(Queue);
        printf("Deleted Data is %d\n",iDelData);
    Display(Queue);
    return 0;
}
void EnQueue(int *pQueue , int iNo)
{
    if(IsQueueFull())
    {
        printf("Queue is Overflow..\n");
        return;
    }
    pQueue[++g_iRear]=iNo;
}
int DeQueue(int *pQueue)
{
    int iDelData;
    if(IsQueueEmpty())
    {
        printf("Queue is Empty..\n"); 
           return -1;
    }
    iDelData=pQueue[g_iFront];
    if(g_iFront == g_iRear)
    {
        g_iFront=0;
        g_iRear=-1;
    }
    else
        g_iFront++;
    
    return pQueue[g_iRear--];
}
void Display(const int *pQueue)
{
    int iCounter;
    if(IsQueueEmpty())
    {
        printf("Queue is empty..\n");
        return;
    }
    for(iCounter=0;iCounter<=g_iRear;iCounter++)
        printf("|%d|->",pQueue[iCounter]);
    printf("\n");
}
int IsQueueFull(void)
{
    if(g_iRear == MAX-1)
        return 1;
    return 0;
}
int IsQueueEmpty(void)
{
    if(g_iRear == -1)
        return 1;
    return 0;
}