#include<stdio.h>
#include<malloc.h>
struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node ** , int);
void Display(struct node *);
int DeleteFirst(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,30);
    Display(pFirst);
   
    
    while(pFirst != NULL)
    {
    iDelData=DeleteFirst(&pFirst);
    printf("Proof of deleted data %d\n",iDelData);
    Display(pFirst);
    }
    pFirst=NULL;
    return 0;
}
void InsertFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }

    pNewNode->iData=iNo;
    
    if(NULL == *ppHead)
    {
        pNewNode->pNext=NULL;//first as well as last node..
        *ppHead=pNewNode;//new node become first..
        return;
    }
    pNewNode->pNext=*ppHead;//new node become first..
    *ppHead=pNewNode;//old first node become second..
}
void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\nLIST IS EMPTY\n");
        return;
    }

    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}
int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    
    struct node *pTemp = NULL;
    
    if(NULL == *ppHead)
        return -1;

    pTemp = *ppHead;
    *ppHead = pTemp->pNext;
    iDelData = pTemp->iData;
    
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}