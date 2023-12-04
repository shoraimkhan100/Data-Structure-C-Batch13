#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData; 
    struct node *pNext;
};

int DeleteLast(struct node**);
void InsertLast(struct node ** , int);
void Display(struct node *);

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
        iDelData=DeleteLast(&pFirst);
        Display(pFirst);
        iDelData=DeleteLast(&pFirst);
        Display(pFirst);
        iDelData=DeleteLast(&pFirst);
        Display(pFirst);
        
        pFirst = NULL;
    }
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
int DeleteLast(struct node **ppHead)
{
    int iDelData;

    struct node *pTemp = NULL;
    if(NULL == *ppHead)
        return -1;
    
    pTemp=*ppHead;
    
    while(pTemp->pNext != NULL)
        pTemp=pTemp->pNext;

    iDelData=pTemp->iData;

    if(pTemp->pPrev != NULL)
    {   
        pTemp->pPrev->pNext=NULL;
        pTemp->pPrev=NULL;
    } 
    else
        *ppHead=NULL;
    free(pTemp);
    pTemp=NULL;

    return iDelData;   
}