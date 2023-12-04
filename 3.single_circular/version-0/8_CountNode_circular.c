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
int CountNode(struct node *,struct node *);
int main(void)
{
    int iCount;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
    
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,10);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,20);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,30);
    Display(pFirst,pLast);
    
    iCount = CountNode(pFirst,pLast);
    printf("count of node %d\n",iCount);

    if(pFirst != NULL && pLast != NULL)
    {
        DeleteAll(&pFirst,&pLast);
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