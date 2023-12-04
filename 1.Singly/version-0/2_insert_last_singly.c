#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **,int);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
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
        free(pFirst);
        pFirst = NULL;
    }
    Display(pFirst);
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
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
        free(pTemp);
    }
    pTemp=NULL;
}