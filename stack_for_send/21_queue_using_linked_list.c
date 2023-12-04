#include<stdio.h>
#include<malloc.h>
#define MAX 5

struct node 
{
    int iData;
    struct node *pNext;
};

void EnQueue(struct node **,int);
int DeQueue(struct node **);
void Display(struct node *);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
int CountNode(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pQueue = NULL;
    EnQueue(&pQueue,10);
    EnQueue(&pQueue,20);
    EnQueue(&pQueue,30);
    Display(pQueue);

    iDelData=DeQueue(&pQueue);
        printf("Deleted Data %d\n",iDelData);
    Display(pQueue);

    if(pQueue != NULL)
    {
        DeleteAll(&pQueue);
        pQueue=NULL;
    }
    Display(pQueue);
    return 0;
}
void EnQueue(struct node **ppHead , int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    if(IsQueueFull(*ppHead))
    {
        printf("Queue is Full...\n");
        return;
    }
    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pNext=NULL;
    if(NULL == *ppHead)
    {
        *ppHead=pNewNode;
        return;
    }
    pTemp=*ppHead;
    while(pTemp->pNext != NULL)
        pTemp = pTemp->pNext;
    pTemp->pNext=pNewNode;
}
int DeQueue(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;
    if(IsQueueEmpty(*ppHead))
    {
        printf("Queue is Empty...\n");
        return -1;
    }

    pTemp = *ppHead;
    iDelData=pTemp->iData;
    *ppHead=pTemp->pNext;
    pTemp->pNext=NULL;
    
    free(pTemp);
    pTemp=NULL;
    return iDelData;
}
void Display(struct node *pHead)
{
    if(IsQueueEmpty(pHead))
    {
        printf("Queue is empty..\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}
int IsQueueFull(struct node *pHead)
{
    if(MAX == CountNode(pHead))
        return 1;
    return 0;
}
int IsQueueEmpty(struct node *pHead)
{
    if(NULL == pHead)
        return 1;
    return 0;
}
int CountNode(struct node *pHead)
{
    int iCount=0;
    while(pHead != NULL)
    {
        iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
}
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp =NULL;
    if(IsQueueEmpty(*ppHead))
        return;
    pTemp=*ppHead;
    while(pTemp != NULL)
    {
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
        free(pTemp);
    pTemp=NULL;
    }
}
