#include<stdio.h>
#include<malloc.h>
struct node 
{
    int iData;
    struct node *pNext;
};

void Display(struct node *,struct node *);
void InsertFirst(struct node **,struct node ** ,int);
void DeleteAll(struct node **,struct node **);
void Concatlist(struct node ** ,struct node ** , struct node ** ,struct node **);

int CountNode(struct node *,struct node *);
int main(void)
{
    int iDelData;
    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;
    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    Display(pFirst1,pLast1);
    InsertFirst(&pFirst1,&pLast1,40);
    Display(pFirst1,pLast1);
    InsertFirst(&pFirst1,&pLast1,30);
    Display(pFirst1,pLast1);
    InsertFirst(&pFirst1,&pLast1,20);
    Display(pFirst1,pLast1);
    InsertFirst(&pFirst1,&pLast1,10);
    Display(pFirst1,pLast1);
    
    
    Display(pFirst2,pLast2);
    InsertFirst(&pFirst2,&pLast2,400);
    Display(pFirst2,pLast2);
    InsertFirst(&pFirst2,&pLast2,300);
    Display(pFirst2,pLast2);
    InsertFirst(&pFirst2,&pLast2,200);
    Display(pFirst1,pLast1);
    InsertFirst(&pFirst2,&pLast2,100);
    Display(pFirst2,pLast2);
    
    Concatlist(&pFirst1,&pLast1,&pFirst2,&pLast2);
    Display(pFirst1,pLast1);
    Display(pFirst2,pLast2);

    if(pFirst1 != NULL && pLast1 != NULL)
    {
        DeleteAll(&pFirst1,&pLast1);
    }
    pFirst1 = pLast1 = NULL;
    
    if(pFirst2 != NULL && pLast2 != NULL)
    {
        DeleteAll(&pFirst2,&pLast2);
    }
    pFirst2 = pLast2 = NULL;
    
    Display(pFirst1,pLast1);
    Display(pFirst2,pLast2);

    return 0;
}
void Concatlist(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2,struct node **ppTail2)
{
    if(NULL == *ppHead2)
        return;
    if(NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppTail1=*ppTail2;
    }
    else
    {
        (*ppTail1)->pNext=*ppHead2;
        *ppTail1=*ppTail2;
        (*ppTail1)->pNext=*ppHead1;
    }
    *ppHead2=*ppTail2=NULL;
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
