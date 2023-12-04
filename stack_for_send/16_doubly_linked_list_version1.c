#include<stdio.h>
#include<malloc.h>

struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void Display(struct node *);
int CountNode(struct node *);
void InsertFirst(struct node **,int);
void InsertLast(struct node **,int);
void InsertAtPosition(struct node **,int,int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **, int);
int SearchFirstOccurrence(struct node *,int);
int SearchLastOccurrence(struct node *,int);
int SearchAllOccurrence(struct node *,int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void ConcatList(struct node ** ,struct node **);
void ConcatAtPosition(struct node ** ,struct node ** ,int);
void DeleteAll(struct node **);

int main(void)
{
    int iData;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst);//list is empty...
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);
    Display(pFirst);//10 20 30

    InsertLast(&pFirst,40);
    InsertLast(&pFirst,50);
    InsertLast(&pFirst,60);
    Display(pFirst);//10 20 30 40 50 60

    Display(pFirst);
    InsertAtPosition(&pFirst,20,4);
    Display(pFirst);//10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst);
        if(iData != -1)
            printf("Deleted First Data is : %d\n",iData);//10
    Display(pFirst);//20 30 40 50 60

    iData = DeleteLast(&pFirst);
        if(iData != -1)
            printf("Delted Last Data is : %d\n",iData);//60
    Display(pFirst);//20 30 40 50

    iData = DeleteAtPosition(&pFirst,4);
        if(iData != -1)
            printf("Deleted at position is : %d\n",iData);//40

    Display(pFirst);//20 30 20 50

    iData = SearchFirstOccurrence(pFirst,20);
        if(iData != 0)
            printf("First occurrence of %d found at : %d position\n",20,iData);//1
    iData = SearchLastOccurrence(pFirst,20);
        if(iData != 0)
            printf("Last occurrence of %d found at %d position\n",20,iData);
    iData = SearchAllOccurrence(pFirst,20); // 2 times
        printf("%d found %d times\n",20,iData); 

    iData = CountNode(pFirst);
        printf("Total nodes = %d\n",iData);//4
    
    Display(pFirst);//20 30 20 50
    PhysicalReverse(&pFirst);
    Display(pFirst);//50 20 30 20
    PhysicalReverse(&pFirst);
    Display(pFirst);//20 30 20 50

    ReverseDisplay(pFirst);//50 20 30 20
    Display(pFirst);

    InsertLast(&pSecond,100);
    InsertLast(&pSecond,200);
    InsertLast(&pSecond,300);

    Display(pFirst);//20 30 20 50
    Display(pSecond);//100 200 300
    ConcatList(&pFirst,&pSecond);
    Display(pFirst);//20 30 20 50 100 200 300
    Display(pSecond);//list is empty..
    
    
    Display(pFirst);//20 30 20 50 100 200 300
    Display(pSecond);//1000 2000 3000
    ConcatAtPosition(&pFirst,&pSecond,3);
    Display(pFirst);//20 30 20 50 100 200 300 1000 2000 3000
    Display(pSecond);//list is empty..
    
    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst=NULL;
    }
    if(pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }
    Display(pFirst);
    Display(pSecond);
    return 0;
}
void InsertFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pPrev=NULL;
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
void InsertLast(struct node **ppHead,int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pNext=NULL;
    if(NULL == *ppHead)
    {
        pNewNode->pPrev=NULL;
        *ppHead=pNewNode;
        return;
    }
    pTemp = *ppHead;
    while(pTemp->pNext != NULL)
        pTemp = pTemp->pNext;
    pTemp->pNext=pNewNode;
    pNewNode->pPrev=pTemp;
}
void InsertAtPosition(struct node **ppHead,int iNo , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    iCount=CountNode(*ppHead);
    printf("Count of node is %d\n",iCount);

    if(iPos<=0 || iPos>iCount)
    {
        printf("position is invalid\n");
        return;
    }
    if(1 == iPos)
    {
        InsertFirst(ppHead,iNo);
        return;
    }
    if(iPos == iCount + 1)
    {
        InsertLast(ppHead,iNo);
        return;
    }
    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    iCount=1;
    pTemp = *ppHead;
    pNewNode->iData=iNo;
    while(iPos-1>iCount)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    pNewNode->pNext=pTemp->pNext;
    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev=pNewNode;
    pTemp->pNext=pNewNode;
    pNewNode->pPrev=pTemp;
}
int CountNode(struct node *pHead)
{
    int iCount=0;
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
    iDelData = (*ppHead)->iData;
    if(NULL == (*ppHead)->pNext)
    {
        free(*ppHead);
        *ppHead=NULL;
        return iDelData;
    }
    *ppHead=(*ppHead)->pNext;
    (*ppHead)->pPrev->pNext=NULL;
    free((*ppHead)->pPrev);
    (*ppHead)->pPrev=NULL;
    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;
    if(NULL == *ppHead)
        return -1;
    pTemp = *ppHead;
    while(pTemp->pNext != NULL)
        pTemp=pTemp->pNext;
    iDelData=pTemp->iData;
    if(pTemp->pPrev != NULL)
    {
        pTemp->pPrev->pNext=NULL;
        pTemp->pPrev=NULL;
    }
    else
        *ppHead = NULL;
    free(pTemp);
    pTemp = NULL;
    return iDelData;
}
int DeleteAtPosition(struct node **ppHead , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;
    if(NULL == *ppHead)
        return -1;
    iCount = CountNode(*ppHead);
        printf("count of node : %d\n",iCount);
    if(iPos<=0 || iPos>iCount)
    {
        printf("position is invalid\n");
        return -1;
    }
    if(iPos == 1)
        return DeleteFirst(ppHead);
    if(iPos == iCount)
        return DeleteLast(ppHead);
    iCount = 1;
    pTemp=*ppHead;
    while(iPos>iCount)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    pTemp->pPrev->pNext=pTemp->pNext;
    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev=pTemp->pPrev;
    iCount=pTemp->iData;
    pTemp->pNext=pTemp->pPrev=NULL;
    free(pTemp);
    pTemp = NULL;
    return iCount;
}
int SearchFirstOccurrence(struct node *pHead,int iKey)
{
    int iPos = 0;
    while(pHead != NULL)
    {
        iPos++;
        if(iKey == pHead->iData)
            return iPos;
        pHead=pHead->pNext;
    }
}
int SearchLastOccurrence(struct node *pHead,int iKey)
{
    int iPos= 0;
    int iCount=0;
    while(pHead != NULL)
    {
        iPos++;
        if(iKey == pHead->iData)
            iCount = iPos;
        pHead=pHead->pNext;   
    }
    return iCount;
}
int SearchAllOccurrence(struct node *pHead , int iKey)
{
    int iCount=0;
    while(pHead != NULL)
    {
        if(iKey == pHead->iData)
            iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
}
void PhysicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = *ppHead;

    while(pCurrent != NULL)
    {
        pPrev = pCurrent->pPrev;
        
        pCurrent->pPrev=pCurrent->pNext;
        
        pCurrent->pNext=pPrev;
        
        pCurrent=pCurrent->pPrev;
        
    }
    *ppHead=pPrev->pPrev;
}
void ReverseDisplay(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("list is empty..\n");
        return;
    }
    while(pHead->pNext != NULL)
        pHead=pHead->pNext;
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pPrev;
    }
    printf("\n");
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
void ConcatAtPosition(struct node **ppHead1,struct node **ppHead2 , int iPos)
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
    pTemp1 = *ppHead1;
    iCount = 1;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1=pTemp1->pNext;
    }
    pTemp2=*ppHead2;
    while(pTemp2->pNext != NULL)
        pTemp2=pTemp2->pNext;
    pTemp2->pNext=pTemp1->pNext;
    pTemp1->pNext = *ppHead2;
    *ppHead2=NULL;
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