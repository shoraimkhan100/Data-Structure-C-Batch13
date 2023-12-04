#include<stdio.h>
#include<malloc.h>
struct node 
{
    int iData;
    struct node *pNext;
};

void InsertAtPosition(struct node ** ,int,int);
void Display(struct node *);
int iCountNode(struct node *);
void InsertAtLast(struct node **ppHead ,int);
void DeleteAll(struct node **);

int main(void)
{
    int iCount = 0;
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
void InsertAtPosition(struct node **ppHead,int iNo , int iPos)
{
    int iCount = 0;

    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCount = iCountNode(*ppHead);

    if(iPos<=0 || iPos>(iCount+1))
    {
        printf("position is invalid\n");
        return;
    }
    printf("count of node is : %d\n",iCount);
    /*
    if(1==iPos)
    {
        InsertAtFirst(ppHead,iNo);
        return;
    }*/

    if(iPos == iCount+1)
    {
        InsertAtLast(ppHead,iNo);
        return;
    }
    pNewNode=(struct node*)malloc(sizeof(struct node));
    
    if(NULL == pNewNode)
    {
        printf("memory allocation failed\n");
        return;
    }
    pNewNode->iData=iNo;
    pTemp=*ppHead;
    iCount=1;

    while(iCount<iPos-1)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    pNewNode->pNext=pTemp->pNext;
    pTemp->pNext=pNewNode;
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
void InsertAtLast(struct node **ppHead , int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    
    pNewNode = (struct node *)malloc(sizeof(struct node ));

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
        pTemp=pTemp->pNext;
    
    pTemp->pNext = pNewNode; 
}
void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("list is empty...\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
        free(pTemp);
    }
    pTemp=NULL;
}