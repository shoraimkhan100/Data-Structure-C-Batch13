#include<stdio.h>
#include<malloc.h>

struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,struct node ** ,int);
void Display(struct node *,struct node *);
int SearchFirstOccurance(struct node *,struct node * , int);
void DeleteAll(struct node **,struct node **);

int main(void)
{
    int iPos;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
  
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,30);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,20);
    Display(pFirst,pLast);
    InsertFirst(&pFirst,&pLast,10);
    Display(pFirst,pLast);

    iPos=SearchFirstOccurance(pFirst,pLast,30);
    printf("Position of |%d|-> : %d\n",30,iPos);
    iPos=SearchFirstOccurance(pFirst,pLast,20);
    printf("Position of |%d|-> : %d\n",20,iPos);
    iPos=SearchFirstOccurance(pFirst,pLast,10);
    printf("Position of |%d|-> : %d\n",10,iPos);

    if(pFirst != NULL && pLast != NULL)
    {
        DeleteAll(&pFirst,&pLast);
    }
    pFirst=pLast=NULL;
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
int SearchFirstOccurance(struct node *pHead,struct node *pTail , int iKey)
{
    int iPos = 0;
    if(NULL == pHead)
        return -1;
    do{
        iPos++;
        if(iKey == pHead->iData)
            return iPos;
        pHead=pHead->pNext;
    }while(pHead != pTail->pNext);
    return 0;
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