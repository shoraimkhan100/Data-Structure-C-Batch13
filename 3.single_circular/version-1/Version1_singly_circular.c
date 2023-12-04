#include<stdio.h>
#include<malloc.h>
struct node 
{
    int iData;
    struct node *pNext;
};
void InsertFirst(struct node ** , struct node ** , int);
void InsertLast(struct node ** , struct node ** , int);
int DeleteFirst(struct node ** , struct node **);
void Display(struct node * , struct node *);
void DeleteAll(struct node ** ,struct node **);
int DeleteLast(struct node ** , struct node **);
int SearchFirstOccurance(struct node *,struct node * , int);
int SearchLastOccurance(struct node *,struct node * , int);
int SearchAllOccurance(struct node *,struct node * , int);
int CountNode(struct node *,struct node *);
void InsertAtPosition(struct node **,struct node **,int,int);
int DeleteAtPosition(struct node **,struct node **,int);
void Concatlist(struct node ** ,struct node ** , struct node ** ,struct node **);
void ConcatAtPosition(struct node ** ,struct node ** , struct node ** ,struct node **,int);
void PhysicalReverse(struct node ** ,struct node **);
void ReverseDisplay(struct node * ,struct node *);

int main(void)
{
    int iData;
    struct node *pFirst = NULL;
    struct node *pLast1 = NULL;
    struct node *pSecond = NULL;
    struct node *pLast2 = NULL;

    Display(pFirst,pSecond);//list is empty...
    InsertFirst(&pFirst,&pLast1,30);
    InsertFirst(&pFirst,&pLast1,20);
    InsertFirst(&pFirst,&pLast1,10);
    Display(pFirst,pLast1);//10 20 30

    InsertLast(&pFirst,&pLast1,40);
    InsertLast(&pFirst,&pLast1,50);
    InsertLast(&pFirst,&pLast1,60);
    Display(pFirst,pLast1);//10 20 30 40 50 60

    Display(pFirst,pLast1);
    InsertAtPosition(&pFirst,&pLast1,20,4);
    Display(pFirst,pLast1);//10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst,&pLast1);
        if(iData != -1)
            printf("Deleted First Data is : %d\n",iData);//10
    Display(pFirst,pLast1);//20 30 40 50 60

    iData = DeleteLast(&pFirst,&pLast1);
        if(iData != -1)
            printf("Deleted Last Data is : %d\n",iData);//60
    Display(pFirst,pLast1);//20 30 40 50

    iData = DeleteAtPosition(&pFirst,&pLast1,4);
        if(iData != -1)
            printf("Deleted at position is : %d\n",iData);//40

    Display(pFirst,pLast1);//20 30 20 50

    iData = SearchFirstOccurance(pFirst,pLast1,20);
        if(iData != 0)
            printf("First occurrence of %d found at : %d position\n",20,iData);//1
    iData = SearchLastOccurance(pFirst,pLast1,20);
        if(iData != 0)
            printf("Last occurrence of %d found at %d position\n",20,iData);
    iData = SearchAllOccurance(pFirst,pLast1,20); // 2 times
        printf("%d found %d times\n",20,iData); 

    iData = CountNode(pFirst,pLast1);
        printf("Total nodes = %d\n",iData);//4
    
    Display(pFirst,pLast1);//20 30 20 50
    PhysicalReverse(&pFirst,&pLast1);
    Display(pFirst,pLast1);//50 20 30 20
     
    PhysicalReverse(&pFirst,&pLast1);
    Display(pFirst,pLast1);//20 30 20 50

    ReverseDisplay(pFirst,pLast1);//50 20 30 20
    Display(pFirst,pLast1);

    InsertLast(&pSecond,&pLast2,100);
    InsertLast(&pSecond,&pLast2,200);
    InsertLast(&pSecond,&pLast2,300);

    Display(pFirst,pLast1);//20 30 20 50
    Display(pSecond,pLast2);//100 200 300
    Concatlist(&pFirst,&pLast1,&pSecond,&pLast2);
    Display(pFirst,pLast1);//20 30 20 50 100 200 300
    Display(pSecond,pLast2);//list is empty..
    
    
    Display(pFirst,pLast1);//20 30 20 50 100 200 300
    Display(pSecond,pLast2);//1000 2000 3000
    ConcatAtPosition(&pFirst,&pLast1,&pSecond,&pLast2,3);
    Display(pFirst,pLast1);//20 30 20 50 100 200 300 1000 2000 3000
    Display(pSecond,pLast2);//list is empty..
    
    if(pFirst != NULL)
    {
        DeleteAll(&pFirst,&pLast1);
        pFirst=pLast1=NULL;
    }
    if(pSecond != NULL)
    {
        DeleteAll(&pSecond,&pLast2);
        pSecond =pLast2= NULL;
    }
    Display(pFirst,pLast1);
    Display(pSecond,pLast2);
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
int DeleteFirst(struct node **ppHead ,struct node **ppTail)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData=(*ppHead)->iData;
    if(*ppHead == *ppTail)
    {
        (*ppHead)->pNext = NULL;
        free(*ppHead);
        *ppHead = *ppTail = NULL;
        return iDelData;
    }
    *ppHead = (*ppHead)->pNext;
    (*ppTail)->pNext->pNext = NULL;
    free((*ppTail)->pNext);
    (*ppTail)->pNext=*ppHead;
    return iDelData;
}
int DeleteLast(struct node **ppHead , struct node **ppTail)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;
    pTemp = *ppHead;
    while(pTemp->pNext != *ppTail)
        pTemp=pTemp->pNext;
    iDelData = (*ppTail)->iData;
    (*ppTail)->pNext=NULL;
    free(*ppTail);
    if(*ppHead == *ppTail)
    {
        *ppHead = *ppTail = NULL;
    }
    else{
        *ppTail = pTemp;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
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
int SearchLastOccurance(struct node *pHead,struct node *pTail , int iKey)
{
    int iPos = 0;
    int iCount = 0;
    if(NULL == pHead)
        return -1;
    do{
        iPos++;
        if(iKey == pHead->iData)
            iCount = iPos;
        pHead=pHead->pNext;
    }while(pHead != pTail->pNext);
    return iCount;
}
int SearchAllOccurance(struct node *pHead , struct node *pTail ,int iKey)
{
    
    int iCount = 0;
    
    do{
        if(iKey == pHead->iData)
            iCount++;
        pHead=pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCount;
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
int DeleteAtPosition(struct node **ppHead1,struct node **ppHead2,int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    
    iCount =CountNode(*ppHead1,*ppHead2);

    if(iPos <= 0 || iPos>iCount)
    {
        printf("position is invalid\n");
        return -1;
    }
    if(1 == iPos)
       return DeleteFirst(ppHead1,ppHead2);

    if(iPos == iCount+1)
        return DeleteLast(ppHead1,ppHead2);

    pTemp1 = *ppHead1;
    iCount = 1;

    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1= pTemp1->pNext;
    }
    pTemp2=pTemp1->pNext;   
    pTemp1->pNext=pTemp2->pNext;
    iCount = pTemp2->iData;
    free(pTemp2);
    pTemp1=pTemp2=NULL;
    return iCount;
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
void ConcatAtPosition(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2,struct node **ppTail2 , int iPos)
{
    int iCount;
    struct node *pTemp =NULL;
    iCount = CountNode(*ppHead1,*ppTail1);
    if(iPos<=0 || iPos>iCount+1)
    {
        printf("position is INVALID\n");
        return;
    }
    if(NULL == *ppHead2)
        return;
    if(1 == iPos)
    {
        Concatlist(ppHead2,ppTail2,ppHead1,ppTail1);
        *ppHead1=*ppHead2;
        *ppTail1 = *ppTail2;
        return;
    }
    if(iPos == iCount+1)
    {
        Concatlist(ppHead1,ppTail1,ppHead2,ppTail2);
        return;
    }
    pTemp=*ppHead1;
    iCount=1;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    (*ppTail2)->pNext=pTemp->pNext;
    pTemp->pNext=*ppHead2;
    *ppHead2=*ppTail2=NULL;
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