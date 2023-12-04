#include<stdio.h>
#include<malloc.h>
struct node
{
    int iData;
    struct node *pNext;
};

void Display(struct node *);
void InsertLast(struct node ** , int);
int SearchAll(struct node *,int);
void DeleteAll(struct node **);

int main(void)
{
    int iCount;
    struct node *pFirst = NULL;

    Display(pFirst);
    InsertLast(&pFirst,10);
    Display(pFirst);
    InsertLast(&pFirst,20);
    Display(pFirst);
    InsertLast(&pFirst,30);
    Display(pFirst);
    InsertLast(&pFirst,30);
    Display(pFirst);
   
    iCount = SearchAll(pFirst,10);
    printf("Count of |%d|-> : %d\n",10,iCount);
    
    iCount = SearchAll(pFirst,20);
    printf("Count of |%d|-> : %d\n",20,iCount);
    
    iCount = SearchAll(pFirst,30);
    printf("Count of |%d|-> : %d\n",30,iCount);

    iCount = SearchAll(pFirst,30);
    printf("Count of |%d|-> : %d\n",30,iCount);
        
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
int SearchAll(struct node *pHead,int iKey)
{
    int iCount = 0;
    
    while(pHead != NULL)
    {
        if(iKey == pHead->iData)
            iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
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