#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **,int);
void Display(struct node *);
void Concat(struct node **,struct node **);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;
    
    Display(pFirst);
    InsertLast(&pFirst,10);
    Display(pFirst);
    InsertLast(&pFirst,20);
    Display(pFirst);
    InsertLast(&pFirst,30);
    Display(pFirst);
    printf("1.List\n\n");

    InsertLast(&pSecond,40);
    Display(pSecond);
    InsertLast(&pSecond,50);
    Display(pSecond);
    InsertLast(&pSecond,60);
    Display(pSecond);
    printf("2.list\n\n");

    Concat(&pFirst,&pSecond);
    Display(pFirst);
    printf("concat 1 list is linked\n\n");
    Display(pSecond);
    printf("concat list 2 is empty..\n\n");
    
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
void InsertLast(struct node **ppHead , int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
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
        printf("list is empty..\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}
void Concat(struct node **ppHead1 , struct node **ppHead2)
{
    struct node *pTemp = NULL;
    
    if(NULL == *ppHead2) //for 1 and 2 scenario...
        return;

    if(NULL == *ppHead1)//for 3 scenario..
    {
        *ppHead1=*ppHead2;
        *ppHead2=NULL;
        return;
    }

    pTemp = *ppHead1;
    while(pTemp->pNext != NULL)
        pTemp=pTemp->pNext;

    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;
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