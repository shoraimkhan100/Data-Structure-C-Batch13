#include<stdio.h>
#include<malloc.h>
#define MAX 5
struct node
{
    int iData;
    int iPriorite;
    struct node *pNext;
};

void InsertFirst(struct node **,int , int );
void EnQueue(struct node **,int ,int);
void Display(struct node *);
int DeQueue(struct node **);
int IsQueueFull(struct node *pHead);
int IsQueueEmpty(struct node *pHead);
int CountNode(struct node *pHead);
void DeleteAll(struct node **ppHead);

int main(void)
{
    int iDelData;
    struct node *pQueue = NULL;
    EnQueue(&pQueue,10,2);
    Display(pQueue);

    EnQueue(&pQueue,20,3);
    Display(pQueue);

    EnQueue(&pQueue,30,1);
    Display(pQueue);

    Display(pQueue);

        iDelData=DeQueue(&pQueue);
            printf("Deleted Data is %d\n",iDelData);
    Display(pQueue);

    if(pQueue != NULL)
    {
        DeleteAll(&pQueue);
        pQueue=NULL;
    }
    Display(pQueue);

    return 0;
}
void EnQueue(struct node **ppHead,int iNo,int iPri)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    if(IsQueueFull(*ppHead))
    {
        printf("Queue is full\n");
        return;
    }
    if(NULL == *ppHead || iPri<(*ppHead)->iPriorite)
    {
        InsertFirst(ppHead,iNo,iPri);
        return;
    }

    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation failed\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->iPriorite=iPri;
    pTemp=*ppHead;
    while(pTemp->pNext != NULL)
    {
        if(iPri>pTemp->pNext->iPriorite)
        {   
            break;
        }
        pTemp=pTemp->pNext;
    }
    pNewNode->pNext=pTemp->pNext;
    pTemp->pNext=pNewNode;
}
void InsertFirst(struct node **ppHead,int iNo , int iPri)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation failed\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->iPriorite=iPri;
    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;
}
void Display(struct node *pHead)
{

    if(pHead == NULL)
    {
        printf("priority qeu is empty.\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|data\tpriority|%d|\n",pHead->iData,pHead->iPriorite);
        pHead=pHead->pNext;
    }
    printf("\n");
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
