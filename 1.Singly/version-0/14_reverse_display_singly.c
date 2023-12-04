#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};
void InsertFirst(struct node ** , int);
void Display(struct node*);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;

    Display(pFirst);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,10);
    Display(pFirst);

    ReverseDisplay(pFirst);
    Display(pFirst);

    if(pFirst!=NULL)
    {
        DeleteAll(&pFirst);//i will updata it on delete all code time..
        pFirst=NULL;
    }
    Display(pFirst);
    return 0;
}
void InsertFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode=(struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    if(NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
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
        pHead = pHead->pNext;
    }
        printf("\n");
}
void ReverseDisplay(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("list is empty...\n");
        return;
    }
    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
}
void PhysicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext=pPrev;
        pPrev=pCurrent;
        pCurrent=pNext;
    }
    *ppHead=pPrev;
}
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;
    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp);
    }
    pTemp = NULL; 
}