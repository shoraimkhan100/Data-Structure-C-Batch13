#include<stdio.h>
#include<malloc.h>
#define MAX 50
struct node
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};
struct queue
{
    struct node *pData;
    struct queue *pNext;
};

void InsertBST(struct node **,int);
void PreOrder(struct node *);
void InOrder(struct node *);
void PostOrder(struct node *);
void LevelOrderTraversal(struct node *);
void EnQueue(struct queue **,struct node *);
struct node *DeQueue(struct queue **);
int CountNode(struct node *);
int LeafNodeCount(struct node *);
int NonLeafNodeCount(struct node *);
int Height(struct node *);
void DeleteAll(struct node **);
struct node *SearchBST(struct node *,int);
void DeleteBST(struct node ** , int );
int IsQueueFull(struct queue *);
int IsQueueEmpty(struct queue *);

int main(void)
{
    struct node *pPtr = NULL;
    struct node *pRoot = NULL;
    
    InsertBST(&pRoot,35);
    InsertBST(&pRoot,42);
    InsertBST(&pRoot,33);
    InsertBST(&pRoot,25);
    InsertBST(&pRoot,60);
    InsertBST(&pRoot,58);
    InsertBST(&pRoot,50);
    InsertBST(&pRoot,40);
    InsertBST(&pRoot,48);
    InsertBST(&pRoot,30);    

    printf("PreOrder: ");
        PreOrder(pRoot);
    printf("\n");

    printf("InOrder:  ");
    InOrder(pRoot);
    printf("\n");
    
    printf("PostOrder:");
    PostOrder(pRoot);
    printf("\n");

    printf("level order: ");
        LevelOrderTraversal(pRoot);
    printf("\n");

    pPtr = SearchBST(pRoot,58);
    
    if(NULL == pPtr)    
        printf("Data(%d) not Found\n",58);
    else
        printf("Data(%d) Found\n",58);

    pPtr = SearchBST(pRoot,29);
    
    if(NULL == pPtr)
        printf("Data(%d) not Found\n",29);
    else
        printf("Data(%d) Found\n",29);

    printf("Total node Count is :%d\n",CountNode(pRoot));
    printf("Height of tree is :%d\n",Height(pRoot));
    printf("Leaf node Cout is :%d\n",LeafNodeCount(pRoot));
    printf("Non Leaf node Count is :%d\n",NonLeafNodeCount(pRoot));

    DeleteBST(&pRoot,30);
    DeleteBST(&pRoot,33);
    DeleteBST(&pRoot,42);

    printf("level order: ");
        LevelOrderTraversal(pRoot);
    printf("\n");

    if(pRoot != NULL)
    {
        DeleteAll(&pRoot);
        printf("Stack is Empty..\n");
    }
    return 0;
}
void InsertBST(struct node **ppRoot,int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pParent = NULL;
    struct node *pPtr = *ppRoot;

    while(pPtr != NULL)
    {
        pParent = pPtr;
        if(iNo < pPtr->iData)
            pPtr=pPtr->pLeft;
        else if(iNo > pPtr->iData)
            pPtr=pPtr->pRight;
        else
            printf("Data is Duplicating...\n");
    }
    pNewNode=(struct node *) malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pLeft=NULL;
    pNewNode->pRight=NULL;
    if(NULL == *ppRoot)
    {
        *ppRoot = pNewNode;
        return;
    }
    if(iNo < (pParent->iData))
        pParent->pLeft=pNewNode;
    else if(iNo > (pParent->iData))
        pParent->pRight=pNewNode;
}
void PreOrder(struct node *pRoot)
{
    if(NULL == pRoot)
        return;
    printf("%d ",pRoot->iData);
    PreOrder(pRoot->pLeft);
    PreOrder(pRoot->pRight);
}
void InOrder(struct node *pRoot)
{
    if(NULL == pRoot)
        return;
    InOrder(pRoot->pLeft);
    printf("%d ",pRoot->iData);
    InOrder(pRoot->pRight);
}
void PostOrder(struct node *pRoot)
{
    if(NULL == pRoot)
        return;
    PostOrder(pRoot->pLeft);
    PostOrder(pRoot->pRight);
    printf("%d ",pRoot->iData);
}
void LevelOrderTraversal(struct node *pRoot)
{
    struct queue *pQueue = NULL;
    struct node *pPtr = NULL;

    EnQueue(&pQueue,pRoot);
    while((pPtr = DeQueue(&pQueue)) != NULL)
    {
        printf("%d ",pPtr->iData);
        if(pPtr->pLeft != NULL)
            EnQueue(&pQueue,pPtr->pLeft);
        if(pPtr->pRight != NULL)
            EnQueue(&pQueue,pPtr->pRight);
    }
}
void EnQueue(struct queue **ppRoot , struct node *pData)
{
    struct queue *pTemp = NULL;
    struct queue *pNewNode = NULL;

    pNewNode=(struct queue *)malloc(sizeof(struct queue));
    if(NULL == pNewNode)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    pNewNode->pData=pData;
    pNewNode->pNext=NULL;
    if(NULL == *ppRoot)
    {
        *ppRoot=pNewNode;
        return;
    }
    pTemp=*ppRoot;
    while(pTemp->pNext != NULL)
            pTemp = pTemp->pNext;
    pTemp->pNext = pNewNode;

}
struct node *DeQueue(struct queue **ppRoot)
{
    struct queue *pTemp = NULL;
    struct node *pDelData = NULL;
    
    if(IsQueueEmpty(*ppRoot))
        return NULL;
    
    pTemp=*ppRoot;
    pDelData = pTemp->pData;

    *ppRoot=pTemp->pNext;
    pDelData=pTemp->pData;
    pTemp->pNext=NULL;
    free(pTemp);
    pTemp=NULL;
    return pDelData;
}
int CountNode(struct node *pRoot)
{
    static int iCount;
    if(NULL == pRoot)
        return 0;
    iCount++;
    CountNode(pRoot->pLeft);
    CountNode(pRoot->pRight);
    return iCount;
}
int LeafNodeCount(struct node *pRoot)
{
    static int iCount;//because in storage the automatic get 0 not garbage...
    if(NULL == pRoot)
        return 0;
    if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
        iCount++;
    LeafNodeCount(pRoot->pLeft);
    LeafNodeCount(pRoot->pRight);
    return iCount;
}
int NonLeafNodeCount(struct node *pRoot)
{
    static int iCount;
    if(NULL == pRoot)
        return 0;
    if(pRoot->pLeft != NULL || pRoot->pRight != NULL)
        iCount++;
    NonLeafNodeCount(pRoot->pLeft);
    NonLeafNodeCount(pRoot->pRight);
    return iCount;
}
int Height(struct node *pRoot)
{
    int iLeftHeight = 0;
    int iRightHeight = 0;
    
    if(NULL == pRoot)
        return 0;
    else
    {
    iLeftHeight=Height(pRoot->pLeft);
    iRightHeight=Height(pRoot->pRight);
    }
    if(iLeftHeight > iRightHeight)
        return iLeftHeight+1;
    else
        return iRightHeight+1;
}
void DeleteAll(struct node **ppRoot)
{
    if(NULL == *ppRoot)
        return;
    DeleteAll(&((*ppRoot)->pLeft));
    DeleteAll(&((*ppRoot)->pRight));
    free(*ppRoot);
    *ppRoot=NULL;
}
struct node *SearchBST(struct node *pRoot , int iKey)
{
    if(pRoot != NULL)
    {
        if(iKey < pRoot->iData)
            return SearchBST(pRoot->pLeft,iKey);
        else if(iKey > pRoot->iData)
           return SearchBST(pRoot->pRight,iKey);
        else
            return pRoot;
    }
    return NULL;
}
void DeleteBST(struct node **ppRoot , int iNo)
{
    struct node *pPtr = NULL;
    struct node *pChild = NULL;
    struct node *pParent = NULL;
    struct node *pSuccessor = NULL;

    pPtr = *ppRoot;
    //for search the node...
    while(pPtr != NULL)
    {
        if(iNo == pPtr->iData)
            break;
        pParent = pPtr;
        if(iNo < pPtr->iData)
            pPtr = pPtr->pLeft;
        else 
            pPtr = pPtr->pRight;
    }

    if(pPtr->pLeft != NULL && pPtr->pRight != NULL)
    {
        pSuccessor = pPtr->pRight;
        pParent=pPtr;
        
        while(pSuccessor->pLeft != NULL)
        {
                pParent=pSuccessor;
                pSuccessor=pSuccessor->pLeft;
        }  
        pPtr->iData=pSuccessor->iData;
        pPtr=pSuccessor;
    }

    if(pPtr->pLeft != NULL)
        pChild=pPtr->pLeft;
    else if(pPtr->pRight != NULL)
        pChild=pPtr->pRight;
    
    if(pParent == NULL)
        *ppRoot=pChild;
    
    else if(pParent->pLeft == pPtr)
        pParent->pLeft=pChild;
    else if(pParent->pRight == pPtr)
        pParent->pRight=pChild;
    
    
    free(pPtr);
    pPtr=NULL;
}
int IsQueueFull(struct queue *pRoot)
{
    int iCount=0;
    while(pRoot != NULL)
    {
        iCount++;
        pRoot=pRoot->pNext;
    }
    if(iCount>=MAX)
        return 1;
    return 0;
}
int IsQueueEmpty(struct queue *pRoot)
{
    if(NULL == pRoot)
        return 1;
    return 0;
}
