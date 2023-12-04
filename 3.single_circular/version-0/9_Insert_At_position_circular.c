#include<stdio.h>
#include<malloc.h>
struct node
{
    int iData;
    struct node *pNext;
};

int CountNode(struct node * , struct node *);
void DeleteAll(struct node ** ,struct node **);
void Display(struct node * , struct node *);
void InsertLast(struct node **, struct node ** , int);
void InsertFirst(struct node ** , struct node ** , int);
void InsertAtPosition(struct node **,struct node **,int,int);
void WriteLog(char *szLog);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
   
    Display(pFirst,pLast);
    InsertAtPosition(&pFirst,&pLast,10,2);
    Display(pFirst,pLast);
   
    InsertAtPosition(&pFirst,&pLast,10,1);
    Display(pFirst,pLast);

    InsertAtPosition(&pFirst,&pLast,20,2);
    Display(pFirst,pLast);
    
    InsertAtPosition(&pFirst,&pLast,30,3);
    Display(pFirst,pLast);
    
    InsertAtPosition(&pFirst,&pLast,40,3);
    Display(pFirst,pLast);   

    InsertAtPosition(&pFirst,&pLast,50,6);
    Display(pFirst,pLast);
    
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
    printf("entring\n");
    if(NULL == pHead)
    {
        printf("list is empty\n");
        return;
    }
    do
    {
      printf("|%d|->",pHead->iData);
      pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    printf("\n");
    printf("leaving\n");
}
void InsertAtPosition(struct node **ppHead,struct node **ppTail,int iNo , int iPos)
{
    int iCount = 0;

    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCount = CountNode(*ppHead,*ppTail);
    printf("count of node is : %d\n",iCount);

    if(iPos<=0 || iPos>(iCount+1))
    {
        printf("position is invalid\n");
        return;
    }
    
    if(1 == iPos)
    {
        InsertFirst(ppHead , ppTail , iNo);
        return;
    }

    if(iPos == iCount+1)
    {
        InsertLast(ppHead,ppTail,iNo);
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
        pTemp=pTemp->pNext;
        iCount++;
    }
    pNewNode->pNext=pTemp->pNext;
    pTemp->pNext=pNewNode;
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
    
    if(NULL == *ppHead)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = pNewNode;
    }
    pNewNode->pNext = *ppHead;
    (*ppTail)->pNext = pNewNode;
    (*ppTail)=pNewNode;
    (*ppTail)->pNext=*ppHead;
}
int CountNode(struct node *pHead , struct node *pTail) 
{
    int iCount = 0;
    if(NULL == pHead)
        return 0;
    do
    {
        iCount++;
        pHead=pHead->pNext;
    } while(pHead != pTail->pNext);
    return iCount;
}