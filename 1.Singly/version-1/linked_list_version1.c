#include<stdio.h>
#include<malloc.h>

struct node 
{
    int iData;
    struct node *pNext;
};

void Display(struct node *);
void InsertFirst(struct node ** , int);
void InsertLast(struct node ** , int);
void InsertAtPosition(struct node ** , int , int);
int CountNode(struct node *);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node ** , int);
int SearchFirstOccurance(struct node * , int);
int SearchLastOccurance(struct node * , int);
int SearchAllOccurance(struct node * , int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void ConcatList(struct node ** , struct node **);
void ConcatAtPosition(struct node ** , struct node ** , int);
void DeleteAll(struct node **);

int main(void)
{
    int iData;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst); 

    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);

    Display(pFirst);

    InsertLast(&pFirst,40);
    InsertLast(&pFirst,50);
    InsertLast(&pFirst,60);

    Display(pFirst);

    InsertAtPosition(&pFirst,20,4);

    Display(pFirst);

    iData = DeleteFirst(&pFirst);
    if(iData != -1)
    {
        printf("Proof of deleted data : %d\n",iData);
    }

    Display(pFirst);

    iData = DeleteLast(&pFirst);
    if(iData != -1)
    {
        printf("Proof of delected data : %d\n",iData);
    }

    Display(pFirst);

    iData = DeleteAtPosition(&pFirst,4);
    if(iData != -1)
    {
        printf("Proof of delected data : %d\n",iData);
    }

    Display(pFirst);

    iData = SearchFirstOccurance(pFirst,20);
    if(iData != 0)
        printf("First occurrence of %d found at %d position\n",20,iData);
    
    Display(pFirst);

    iData = SearchLastOccurance(pFirst,20);
    if(iData != 0)
        printf("last occurrence of %d found at %d position\n",20,iData);
    
    Display(pFirst);

    iData = SearchAllOccurance(pFirst,20);
        printf("%d found %d times\n",20,iData);
    
    Display(pFirst);
    
    iData = CountNode(pFirst);
        printf("Total Node is : %d\n",iData);

    Display(pFirst);

    PhysicalReverse(&pFirst);
    Display(pFirst);

    PhysicalReverse(&pFirst);   
    Display(pFirst);

    ReverseDisplay(pFirst);
    Display(pFirst);

    InsertLast(&pSecond,100);
    InsertLast(&pSecond,200);
    InsertLast(&pSecond,300);

    Display(pFirst);
    Display(pSecond);
    ConcatList(&pFirst,&pSecond);
    Display(pFirst);
    Display(pSecond);

    InsertLast(&pSecond,1000);
    InsertLast(&pSecond,2000);
    InsertLast(&pSecond,3000);

    Display(pFirst);
    Display(pSecond);
    ConcatAtPosition(&pFirst,&pSecond,3);
    Display(pFirst);
    Display(pSecond);
    
    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst=NULL;
    }
    if(pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond=NULL;
    }
  
    Display(pFirst);
    Display(pSecond);
    
    return 0;
}
void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\n\tlist is empty..\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}
void InsertFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\n\tmemory allocation FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    if(NULL == *ppHead)
    {
        pNewNode->pNext=NULL;
        *ppHead=pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;
}
void InsertLast(struct node **ppHead , int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\n\tlist is empty..\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pNext=NULL;
    if(NULL == *ppHead)
    {
        *ppHead=pNewNode;
        return;
    }
    pTemp = *ppHead;
    while(pTemp->pNext != NULL)
    {
        pTemp=pTemp->pNext;
    }
    pTemp->pNext=pNewNode;
}
void InsertAtPosition(struct node **ppHead , int iNo , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNode(*ppHead);
    if(iPos<=0 || iPos>iCount+1)
    {
        printf("\n\tposition invalid...\n");
        return;
    }
    /*
    if(1 == iPos)
    {
        InsertFirst(ppHead,iNo);
        return;
    }
    */
    if(iPos == iCount+1)
    {
        InsertLast(ppHead,iNo);
        return;
    }
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pTemp = *ppHead;
    pNewNode->iData=iNo;
    iCount = 1;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
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
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;

    pTemp = *ppHead;
    iDelData=(*ppHead)->iData;
    *ppHead = pTemp->pNext;
    pTemp->pNext=NULL;
    free(pTemp);
    pTemp=NULL;
    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;
    
    pTemp=*ppHead;
    if(pTemp->pNext == NULL)
    {
        iDelData=pTemp->iData;
        free(pTemp);
        pTemp=NULL;
        return iDelData;
    }
    while(pTemp->pNext->pNext != NULL)
    {
        pTemp=pTemp->pNext;
    }
    iDelData=pTemp->pNext->iData;
    free(pTemp->pNext);
    pTemp->pNext=NULL;

    return iDelData;
}
int DeleteAtPosition(struct node **ppHead , int iPos)
{
    int iDelData;
    
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iDelData=CountNode(*ppHead);

    if(iPos<=0 || iPos>=iDelData)
    {
        printf("position is invalid..\n");
        return -1;
    }
    if(1 == iPos)
        return DeleteFirst(ppHead);
    if(iPos == iDelData)
        return DeleteLast(ppHead);
    pTemp1 = *ppHead;
    iDelData=1;
    while(iDelData<iPos-1)
    {   
        iDelData++;
        pTemp1=pTemp1->pNext;
    }
    pTemp2=pTemp1->pNext;
    pTemp1->pNext=pTemp2->pNext;
    iDelData=pTemp2->iData;
    pTemp2->pNext = NULL;
    free(pTemp2);
    pTemp1=pTemp2=NULL;
    return iDelData;
}
int SearchFirstOccurance(struct node *pHead , int iKey)
{
    int iPos=0;
    while(pHead != NULL)
    {
        iPos++;
        if(iKey == pHead->iData)
            return iPos;
        pHead=pHead->pNext;
    }
    return iPos;
}
int SearchLastOccurance(struct node *pHead , int iKey)
{
    int iPos = 0;
    int iLast = 0;

    while(pHead != NULL)
    {
        iPos++;
            if(iKey == pHead->iData)
            {
                iLast = iPos;
            }
        pHead=pHead->pNext;
    }
    return iLast;
}
int SearchAllOccurance(struct node *pHead , int iKey)
{
    int iPos = 0;
    while(pHead != NULL)
    {
        if(iKey == pHead->iData)
        {
            iPos++;
        }
        pHead=pHead->pNext;
    }
    return iPos;
}
void PhysicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = NULL;
    struct node *pNext = NULL;

    pCurrent = *ppHead;
    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext=pPrev;
        pPrev=pCurrent;
        pCurrent=pNext;
    }
    *ppHead=pPrev;   
}
void ReverseDisplay(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\n\tlist is empty...\n");
        return;
    }
    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
}
void ConcatList(struct node **ppHead1, struct node **ppHead2)
{   
    struct node *pTemp = NULL;
    if(NULL == ppHead2)
        return;
    if(NULL == ppHead1)
    {
        *ppHead1=*ppHead2;
        *ppHead2=NULL;
        return;
    }
    pTemp = *ppHead1;
    while(pTemp->pNext != NULL)
    {
        pTemp=pTemp->pNext;
    }
    pTemp->pNext=*ppHead2;
    *ppHead2=NULL;
}
void ConcatAtPosition(struct node **ppHead1 , struct node **ppHead2 ,int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    
    iCount = CountNode(*ppHead1);
    if(iPos<=0 || iPos>iCount+1)
    {
        printf("\n\tposition is invalid..\n");
        return;
    }
    if(1 == iPos)
    {
        ConcatList(ppHead2,ppHead1);
        *ppHead1=*ppHead2;
        *ppHead2=NULL;
        return;
    }
    iCount=1;
    pTemp1=*ppHead1;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1=pTemp1->pNext;
    }
    pTemp2=*ppHead2;
    while(pTemp2->pNext != NULL)
        pTemp2=pTemp2->pNext;
    pTemp2->pNext=pTemp1->pNext;
    pTemp1->pNext=*ppHead2;
    *ppHead2=NULL;
}
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;
    while(*ppHead != NULL)
    {
        pTemp=*ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
        free(pTemp);
    }
    pTemp=NULL;
}