#include<stdio.h>
#include<malloc.h>
struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node ** , int);
void Display(struct node *);
int CountNode(struct node *);
void ConcatList(struct node ** ,struct node **);
void ConcatAtPosition(struct node ** ,struct node **,int);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst);
    InsertFirst(&pFirst,40);
    Display(pFirst);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,10);
    Display(pFirst);

    Display(pSecond);
    InsertFirst(&pSecond,70);
    Display(pSecond);
    InsertFirst(&pSecond,60);
    Display(pSecond);
    InsertFirst(&pSecond,50);
    Display(pSecond);

    ConcatAtPosition(&pFirst,&pSecond,3);
    Display(pFirst);
    printf("both the list are linked...\n\n");
    Display(pSecond);

    if(NULL != pFirst )
    {
        DeleteAll(&pFirst);
        pFirst=NULL;
    }
    return 0;
}
void InsertFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *) malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;
    if(NULL == *ppHead)
    {
        pNewNode->pNext=NULL;
        *ppHead=pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    (*ppHead)->pPrev=pNewNode;
    *ppHead=pNewNode;
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
void ConcatAtPosition(struct node **ppHead1 , struct node **ppHead2,int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    iCount = CountNode(*ppHead1);

    if(iPos<=0 || iPos>iCount+1)
    {
        printf("position is INVALID\n");
        return;
    }
    if(NULL == *ppHead2)
        return;

    if(1 == iPos)
    {
        ConcatList(ppHead2,ppHead1);
        *ppHead1=*ppHead2;
        *ppHead2=NULL;
        return;
    }
    /*
    if(iPos == iCount +1 )
    {
        ConcatList(ppHead1,ppHead2);
        *ppHead2=NULL;
        return;
    }*/
    pTemp1=*ppHead1;
    iCount = 1;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1=pTemp1->pNext;
    }
    pTemp2=*ppHead2;
    while(pTemp2->pNext != NULL)
        pTemp2=pTemp2->pNext;
    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;
    *ppHead2=NULL;
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
void ConcatList(struct node **ppHead1 , struct node **ppHead2)
{
    struct node *pTemp = NULL;
    
    if(NULL == *ppHead2)
        return;

    if(NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp = *ppHead1;
    while(pTemp->pNext != NULL)
        pTemp=pTemp->pNext;
    
    pTemp->pNext=*ppHead2;
    (*ppHead2)->pPrev=pTemp;
    (*ppHead2)=NULL;
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