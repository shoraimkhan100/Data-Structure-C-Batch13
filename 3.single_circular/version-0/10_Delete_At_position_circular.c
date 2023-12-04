#include<stdio.h>
#include<malloc.h>

struct node 
{
    int iData;
    struct node *pNext;
};

void Display(struct node *,struct node *);
void InsertFirst(struct node **,struct node ** ,int);
int DeleteAtPosition(struct node **,struct node **,int);
int DeleteFirst(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
int CountNode(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,40);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,30);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,20);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,10);
    Display(pFirst,pLast);
    
    iDelData=DeleteAtPosition(&pFirst,&pLast,3);
    Display(pFirst,pLast);
    
    if(pFirst != NULL && pLast != NULL)
    {
        DeleteAll(&pFirst,&pLast);
    }
    pFirst = pLast = NULL;
    
    Display(pFirst,pLast);

    return 0;
}

void Display(struct node *pHead ,struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("list is empty\n");
        return;
    }
    do
    {
      printf("|%d|->",pHead->iData);
      pHead=pHead->pNext;
    }     while(pHead != pTail->pNext);
    printf("\n");
}
void InsertFirst(struct node **ppHead, struct node **ppTail , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode; 
        *ppTail = pNewNode;
        (*ppTail)->pNext = *ppHead;
        return;
    }
    pNewNode->pNext=*ppHead;
    *ppHead = pNewNode;
    (*ppTail)->pNext = *ppHead;
}
int DeleteAtPosition(struct node **ppHead1,struct node **ppHead2,int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    
    iCount =CountNode(*ppHead1,*ppHead2);

    if(iPos <= 0 || iPos>iCount)
    {
        printf("position is invalid\n");
        return -1;
    }
    if(1 == iPos)
       return DeleteFirst(ppHead1,ppHead2);

    if(iPos == iCount+1)
        return DeleteLast(ppHead1,ppHead2);

    pTemp1 = *ppHead1;
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
int DeleteFirst(struct node **ppHead ,struct node **ppTail)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData=(*ppHead)->iData;
    if(*ppHead == *ppTail)
    {
        (*ppHead)->pNext = NULL;
        free(*ppHead);
        *ppHead = *ppTail = NULL;
        return iDelData;
    }
    *ppHead = (*ppHead)->pNext;
    (*ppTail)->pNext->pNext = NULL;
    free((*ppTail)->pNext);
    (*ppTail)->pNext=*ppHead;
    return iDelData;
}
int DeleteLast(struct node **ppHead , struct node **ppTail)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;
    pTemp = *ppHead;
    while(pTemp->pNext != *ppTail)
        pTemp=pTemp->pNext;
    iDelData = (*ppTail)->iData;
    (*ppTail)->pNext=NULL;
    free(*ppTail);
    if(*ppHead == *ppTail)
    {
        *ppHead = *ppTail = NULL;
    }
    else{
        *ppTail = pTemp;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}
int CountNode(struct node *pHead,struct node *pTail)
{
    int iCount = 0;
    if(NULL == pHead)
        return 0;
    do{
        iCount++;
        pHead=pHead->pNext;
    }while(pHead!= pTail->pNext);
    return iCount;
}
void DeleteAll(struct node **ppHead , struct node **ppTail)
{
    struct node *pTemp = NULL;
    (*ppTail)->pNext=NULL;
    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
    }
    free(pTemp);
    pTemp=NULL;
}