#include<stdio.h>
#include<malloc.h>
struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertAtPosition(struct node ** ,int,int);
int iCountNode(struct node *);
void Display(struct node *);
void InsertAtLast(struct node ** , int);
void InsertAtFirst(struct node ** , int);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    
    Display(pFirst);
    InsertAtPosition(&pFirst,10,2);
    Display(pFirst);
    InsertAtPosition(&pFirst,10,1);
    Display(pFirst);
    InsertAtPosition(&pFirst,20,2);
    Display(pFirst);
    InsertAtPosition(&pFirst,30,3);
    Display(pFirst);
    InsertAtPosition(&pFirst,40,3);
    Display(pFirst);
    InsertAtPosition(&pFirst,50,6);
    Display(pFirst);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst=NULL;
    }
	Display(pFirst);
    return 0;
}
void InsertAtPosition(struct node **ppHead , int iNo ,int iPos)
{
    int iCount = 0;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCount = iCountNode(*ppHead);
    printf("Count of node is %d\n",iCount);
    
    if(iPos<=0 || iPos > iCount+1)
    {
        printf("Position is Invalid\n");
        return;
    }
   
    if(1 == iPos)
    {
        InsertAtFirst(ppHead,iNo);
        return;
    }
    
    if(iPos == iCount + 1)
    {
        InsertAtLast(ppHead,iNo);
        return;
    }
    pNewNode=(struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    iCount=1;
    pTemp=*ppHead;
    pNewNode->iData=iNo;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    pNewNode->pNext=pTemp->pNext;
    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev=pNewNode;
    pTemp->pNext=pNewNode;
    pTemp->pPrev=pTemp;
}
int iCountNode(struct node *pHead)
{
    int iCount = 0;
    while(pHead != NULL)
    {
        iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
}
void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("list is empty\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}
void InsertAtLast(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == ppHead)
    {
        printf("Memory allocation FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pNext=NULL;
    
    pTemp=*ppHead;
    while(pTemp->pNext != NULL)
        pTemp = pTemp->pNext;
    pTemp->pNext=pNewNode;
}
void InsertAtFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pPrev=NULL;
    if(NULL == *ppHead)
    {
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    (*ppHead)->pPrev=pNewNode;   
    (*ppHead)=pNewNode;
}
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;
    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
    }
    free(pTemp);
    pTemp = NULL; 
}