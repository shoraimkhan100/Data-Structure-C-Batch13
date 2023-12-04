#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **,int);
void Display(struct node *);
int DeleteLast(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    Display(pFirst);
    InsertLast(&pFirst,10);
    Display(pFirst);
    InsertLast(&pFirst,20);
    Display(pFirst);
    InsertLast(&pFirst,30);
    Display(pFirst);

    while(pFirst != NULL)
    {
    iDelData=DeleteLast(&pFirst);
    printf("Proof of deleted data %d\n",iDelData);
    Display(pFirst);
    }
    pFirst = NULL;

    return 0;
}
void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
   
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
void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("link list is empty...\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}   
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;

    pTemp=*ppHead;

    if(NULL == pTemp->pNext)
    {
        iDelData=pTemp->iData;
        free(pTemp);
        
        *ppHead=NULL;
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
    
    pTemp=NULL;
    
    return iDelData;
}