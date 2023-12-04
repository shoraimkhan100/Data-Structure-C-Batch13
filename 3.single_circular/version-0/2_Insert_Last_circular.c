#include<stdio.h>
#include<malloc.h>
struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node ** , struct node ** , int);
void Display(struct node * , struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
    
    Display(pFirst,pLast);
    InsertLast(&pFirst,&pLast,10);
    Display(pFirst,pLast);
    InsertLast(&pFirst,&pLast,20);
    Display(pFirst,pLast);
    InsertLast(&pFirst,&pLast,30);
    Display(pFirst,pLast);
    
    if(pFirst != NULL && pLast != NULL)
    {
        DeleteAll(&pFirst,&pLast);
    }
    pFirst=pLast=NULL;
    Display(pFirst,pLast);
    
    return 0;
}
void InsertLast(struct node **ppHead, struct node **ppTail , int iNo)
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
        (*ppTail)->pNext = pNewNode;
    }
    (*ppTail)->pNext = pNewNode;
    (*ppTail)=pNewNode;
    (*ppTail)->pNext=*ppHead;

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