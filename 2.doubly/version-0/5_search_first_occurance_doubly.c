#include<stdio.h>
#include<malloc.h>

struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node ** , int);
void Display(struct node *);
int SearchFirstOccurance(struct node * , int);
void DeleteAll(struct node **);

int main(void)
{
    int iPos;
    struct node *pFirst = NULL;

    Display(pFirst);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,10);
    Display(pFirst);

    iPos=SearchFirstOccurance(pFirst,30);
    printf("Position of |%d|-> : %d\n",30,iPos);
    iPos=SearchFirstOccurance(pFirst,20);
    printf("Position of |%d|-> : %d\n",20,iPos);
    iPos=SearchFirstOccurance(pFirst,10);
    printf("Position of |%d|-> : %d\n",10,iPos);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
    return 0;
}
void InsertFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *) malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }

    pNewNode->iData=iNo;
    pNewNode->pPrev=NULL;

    if(*ppHead == NULL)
        pNewNode->pNext=NULL;
    else
        pNewNode->pNext=*ppHead;
   
    *ppHead=pNewNode;
    return;
}
void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("list is empty...\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("\n");
}
int SearchFirstOccurance(struct node *pHead , int iKey)
{
    int iPos = 0;
    while(pHead != NULL)
    {
        iPos++;

        if(iKey == pHead->iData)
            return iPos;

        pHead=pHead->pNext;
    }
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