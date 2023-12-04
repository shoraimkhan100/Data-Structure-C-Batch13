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
int SearchAll(struct node * , int);
void DeleteAll(struct node **);

int main(void)
{
    int iCount=0;
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

    iCount = SearchAll(pFirst,30);
    printf("position of |%d|-> : %d\n",30,iCount);

    iCount = SearchAll(pFirst,20);
    printf("position of |%d|-> : %d\n",20,iCount);

    iCount = SearchAll(pFirst,10);
    printf("position of |%d|-> : %d\n",10,iCount);

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
 
    pNewNode->pNext=NULL;
    pNewNode->iData=iNo;
 
    if(*ppHead == NULL)
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
int SearchAll(struct node *pHead , int iKey)
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
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
    }
    free(pTemp);
    pTemp = NULL; 
}