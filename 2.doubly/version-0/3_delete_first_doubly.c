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
int DeleteFirst(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst =  NULL;

    Display(pFirst);//just for checking...
    InsertFirst(&pFirst,30);
    Display(pFirst);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    InsertFirst(&pFirst,10);
    Display(pFirst);
    
   
    if(NULL != pFirst)
    {  
	iDelData=DeleteFirst(&pFirst);
        printf("Deleted Data : %d\n",iDelData);
	Display(pFirst);
        iDelData=DeleteFirst(&pFirst);
	printf("Deleted Data : %d\n",iDelData);
	Display(pFirst);
    	iDelData=DeleteFirst(&pFirst);
   	printf("Deleted Data : %d\n",iDelData);
	Display(pFirst);
        pFirst=NULL;
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
        pNewNode->pPrev=NULL;
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
int DeleteFirst(struct node **ppHead)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;
    
    iDelData=(*ppHead)->iData;
 
    if(NULL == (*ppHead)->pNext)
    {
        free(*ppHead);
        *ppHead = NULL;
        
        return iDelData;
    }
    (*ppHead)=(*ppHead)->pNext;
    (*ppHead)->pPrev->pNext = NULL;
    free((*ppHead)->pPrev);
    (*ppHead)->pPrev = NULL;
    return iDelData;
}
