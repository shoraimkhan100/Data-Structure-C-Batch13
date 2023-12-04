#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData; 
    struct node *pNext;
};

void InsertLast(struct node ** , int);
void Display(struct node *);
void DeleteAll(struct node **);

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

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
    Display(pFirst);
    return 0;
}
void InsertLast(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;
    
    pNewNode=(struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
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
    {
        pTemp=pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
    pNewNode->pPrev=pTemp;

}
void Display(struct node *pHead)
{
    if(pHead == NULL)
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