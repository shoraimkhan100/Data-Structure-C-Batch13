#include<stdio.h>
#include<malloc.h>
struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,int);
void Display(struct node *);
int DeleteAtPosition(struct node ** , int);
int CountNode(struct node *);
int DeleteFirst(struct node **);
int DeleteLast(struct node**);
void DeleteAll(struct node **ppHead);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    Display(pFirst);
    InsertFirst(&pFirst,50);
    Display(pFirst);
    InsertFirst(&pFirst,40);
    Display(pFirst);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,10);
    Display(pFirst);

    iDelData=DeleteAtPosition(&pFirst,4);
	printf("Deleted Data : %d\n",iDelData);
    Display(pFirst);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
	Display(pFirst);
    return 0;
}
void InsertFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode=(struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    } 
    pNewNode->iData=iNo;
    pNewNode->pPrev=NULL;
        
    if(NULL == *ppHead)
    {
        pNewNode->pNext=NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    (*ppHead)->pPrev=pNewNode;   
    (*ppHead)=pNewNode;
}
void Display(struct node *pHead)
{
    if(NULL==pHead)
    {
        printf("list is empty....\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}

int DeleteAtPosition(struct node **ppHead , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount=CountNode(*ppHead);
	printf("count of node : %d\n",iCount);

    if(iPos<=0 || iPos>iCount)
    {
        printf("invalid position");
        return -1;
    }
    if(iPos == 1)
        return DeleteFirst(ppHead);
    if(iCount == iPos)
        return DeleteLast(ppHead);
    pTemp = *ppHead;
    iCount = 1;
    while(iCount<iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }
    pTemp->pPrev->pNext=pTemp->pNext;
    if(pTemp->pNext != NULL)
    {
        pTemp->pNext->pPrev=pTemp->pPrev;
    }
    iCount=pTemp->iData;
    pTemp->pNext=pTemp->pPrev=NULL;
    free(pTemp);
    pTemp= NULL;
    return iCount;
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
int DeleteFirst(struct node **ppHead)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;
    
    iDelData=(*ppHead)->iData;
 
    if(NULL == (*ppHead)->pNext)
    {
        free(*ppHead);
        *ppHead = NULL;
        
        return iDelData;
    }
    (*ppHead)=(*ppHead)->pNext;
    (*ppHead)->pPrev->pNext = NULL;
    free((*ppHead)->pPrev);
    (*ppHead)->pPrev = NULL;
    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;

    struct node *pTemp = NULL;
    if(NULL == *ppHead)
        return -1;
    
    pTemp=*ppHead;
    
    while(pTemp->pNext != NULL)
        pTemp=pTemp->pNext;

    iDelData=pTemp->iData;

    if(pTemp->pPrev != NULL)
    {   
        pTemp->pPrev->pNext=NULL;
        pTemp->pPrev=NULL;
    } 
    else
        *ppHead=NULL;
    free(pTemp);
    pTemp=NULL;

    return iDelData;   
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