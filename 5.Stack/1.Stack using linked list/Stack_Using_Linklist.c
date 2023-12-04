#include<stdio.h>
#include<malloc.h>
#define MAX 5 // define only 5 element should be there..

struct node 
{
    int iData;
    struct node *pNext;
};

int Pop(struct node **);//for delete
int IsFull(struct node *);//checking for full
int IsEmpty(struct node *);//checking for empty
void Display(struct node *);//Display
int CountNode(struct node *);//Count of node
void DeleteAll(struct node **);//DeleteAll function for node clear
void Push(struct node ** ,int);//for insert

int main(void)
{
    int iPopData;//print the deleted data
    struct node *pStack =NULL;//Give Address of nodes..
    Push(&pStack,60);
    Push(&pStack,50);
    Push(&pStack,40);
    Push(&pStack,30);
    Push(&pStack,20);
    Push(&pStack,10);
    Display(pStack);
    iPopData=Pop(&pStack);
        printf("DELTED DATA %d\n",iPopData);
    Display(pStack);
    if(pStack != NULL)
    {
        DeleteAll(&pStack);
        pStack=NULL;
    }
    return 0;
}
void Push(struct node **ppHead , int iNo)
{
    int iPop;
    struct node *pNewNode = NULL;
    if(IsFull(*ppHead))
    {
        printf("stack is overflow %d . is not be insert\n",iNo);
        return;
    }
    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("MEMORY allocation FAILED\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;
}
int Pop(struct node **ppHead)
{
    int iPopData;
    struct node *pTemp =NULL;
    if(IsEmpty(*ppHead))
    {
        printf("stack is empty\n");
        return -1;
    }
    pTemp = *ppHead;
    *ppHead=pTemp->pNext;
    pTemp->pNext=NULL;
    iPopData=pTemp->iData;
    free(pTemp);
    pTemp=NULL;
    return iPopData;
}
int IsFull(struct node *pHead)
{
    if(MAX == CountNode(pHead))
        return 1;
    return 0;
}
int IsEmpty(struct node *pHead)
{
    if(NULL == pHead)
        return 1;
    return 0;
}
int CountNode(struct node *pHead)
{
    int iCount = 0;
    while(pHead != NULL)
    {
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