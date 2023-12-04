#include<stdio.h>
#include<malloc.h>

struct node 
{
    int iData;
    struct node *pNext;
};

void Display(struct node *);
void InsertFirst(struct node ** ,int);
int DeleteAtPosition(struct node **,int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int CountNode(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    Display(pFirst);
    InsertFirst(&pFirst,40);
    Display(pFirst);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,10);
    Display(pFirst);
    
    iDelData=DeleteAtPosition(&pFirst,3);
    Display(pFirst);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
    return 0;
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
void InsertFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    if(NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        (*ppHead)=pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;    
}
int DeleteAtPosition(struct node **ppHead,int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    
    iCount =CountNode(*ppHead);

    if(iPos <= 0 || iPos>iCount)
    {
        printf("position is invalid\n");
        return -1;
    }
    if(1 == iPos)
       return DeleteFirst(ppHead);

    if(iPos == iCount)
        return DeleteLast(ppHead);

    pTemp1 = *ppHead;
    iCount = 1;

    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1= pTemp1->pNext;

    }
    pTemp2=pTemp1->pNext;   
    pTemp1->pNext=pTemp2->pNext;
    iCount = pTemp2->iData;
    free(pTemp2);
    pTemp1=pTemp2=NULL;
    return iCount;
}
int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;
    
    if(NULL == *ppHead)
        return -1;

    pTemp = *ppHead;
    *ppHead = pTemp->pNext;
    iDelData = pTemp->iData;
    
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;

    pTemp=*ppHead;

    if(NULL == pTemp->pNext)
    {
        iDelData=pTemp->iData;
        free(pTemp);
        
        *ppHead=NULL;
        pTemp=NULL;

        return iDelData;
    }

    while(pTemp->pNext->pNext != NULL)
    {
            pTemp=pTemp->pNext;
    }

    iDelData=pTemp->pNext->iData;
    
    free(pTemp->pNext);
    pTemp->pNext=NULL;
    
    pTemp=NULL;
    
    return iDelData;
}
int CountNode(struct node *pHead)
{
    int iCount = 0;
    
    while(pHead != NULL)
    {
        iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
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
