#include<stdio.h>
#include<malloc.h>
struct node
{
    int iData;
    struct node *pNext;
};

void Display(struct node *);
void InsertLast(struct node ** , int);
int SearchLast(struct node *,int);
void DeleteAll(struct node **);

int main(void)
{
    int iLast,iPos;
    struct node *pFirst = NULL;

    Display(pFirst);
    InsertLast(&pFirst,10);
    Display(pFirst);
    InsertLast(&pFirst,20);
    Display(pFirst);
    InsertLast(&pFirst,10);
    Display(pFirst);
    InsertLast(&pFirst,30);
    Display(pFirst);
    
    iLast = SearchLast(pFirst,10);
    printf("position of |%d|-> : %d\n",10,iLast);

    iLast = SearchLast(pFirst,20);
    printf("position of |%d|-> : %d\n",20,iLast);
    
    iLast = SearchLast(pFirst,10);
    printf("position of |%d|-> : %d\n",10,iLast);

    iLast = SearchLast(pFirst,30);
    printf("position of |%d|-> : %d\n",30,iLast);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
    Display(pFirst);
    return 0;
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
void InsertLast(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *) malloc(sizeof(struct node));
   
    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pNext=NULL;
    if(NULL == *ppHead)
    {
        *ppHead=pNewNode;
        return;
    }
    pTemp=*ppHead;
    while(pTemp->pNext != NULL)
    {
        pTemp=pTemp->pNext;
    }
    pTemp->pNext=pNewNode;
}
int SearchLast(struct node *pHead , int iKey)
{
    int iPos = 0;
    int iLast = 0;
    
    while(pHead != NULL)
    {
        iPos++;
        if(iKey == pHead->iData)
            iLast=iPos;
        pHead=pHead->pNext;
    }
    return iLast;
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