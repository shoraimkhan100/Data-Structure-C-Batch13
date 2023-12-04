#include<stdio.h>
#include<malloc.h>
struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node ** , struct node ** , int);
void Display(struct node * , struct node *);
void DeleteAll(struct node ** ,struct node **);
void PhysicalReverse(struct node ** ,struct node **);
void ReverseDisplay(struct node * ,struct node *);
int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
    
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,10);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,20);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,30);
    Display(pFirst,pLast);
 
    ReverseDisplay(pFirst,pLast);
    Display(pFirst,pLast);

    if(pFirst != NULL && pLast != NULL)
    {
        DeleteAll( (&pFirst) , (&pLast));
    }
    pFirst = pLast = NULL;
    Display(pFirst,pLast);

    return 0;
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
void PhysicalReverse(struct node **ppHead , struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;
    if(NULL == *ppHead)
        return;
    while(pCurrent != NULL)
    {
        pNext=pCurrent->pNext;
        pCurrent->pNext=pPrev;
        pPrev=pCurrent;
        if(pCurrent==*ppTail)
            break;
        pCurrent=pNext;
    }
    *ppHead=*ppTail;
    *ppTail=pNext;
}
void ReverseDisplay(struct node *pHead,struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("list is empty..\n");
        return;
    }
    PhysicalReverse(&pHead,&pTail);
    Display(pHead,pTail);
    PhysicalReverse(&pHead,&pTail);
}