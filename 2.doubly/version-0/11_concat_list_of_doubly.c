#include<stdio.h>
#include<malloc.h>
struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,int);
void Display(struct node *);
void DeleteAll(struct node **);
void Concat(struct node **,struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,10);
    Display(pFirst);

    Display(pSecond);
    InsertFirst(&pSecond,60);
    Display(pSecond);
    InsertFirst(&pSecond,50);
    Display(pSecond);
    InsertFirst(&pSecond,40);
    Display(pSecond);

    Concat(&pFirst,&pSecond);
    Display(pFirst);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
	Display(pFirst);
    return 0;
}
void InsertFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode=(struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    } 
    pNewNode->iData=iNo;
    pNewNode->pPrev=NULL;
        
    if(NULL == *ppHead)
    {
        pNewNode->pNext=NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    (*ppHead)->pPrev=pNewNode;   
    (*ppHead)=pNewNode;
}
void Display(struct node *pHead)
{
    if(NULL==pHead)
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
void Concat(struct node **ppHead1 , struct node **ppHead2)
{
	struct node *pTemp = NULL;
	if(NULL == *ppHead2)
		return;
	if(NULL == *ppHead1)
	{
		*ppHead1=*ppHead2;
		*ppHead2=NULL;
		return;
	}
    pTemp=*ppHead1;
    while(pTemp->pNext != NULL)
        pTemp=pTemp->pNext;
    pTemp->pNext=*ppHead2;
    (*ppHead2)->pPrev=pTemp;
    (*ppHead2)=NULL;	
}