#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
    int iHeight;
    char chFlag;
};

void PostOrder(struct node *);
void InsertBst(struct node ** , int);
int Height(struct node *);
int BalanceFactorOfNode(struct node *);
int BalanceChecker(int , int);
void LeftRotaion(struct node **);
void RightRotation(struct node **);
void DeleteAll(struct node **);
int main(void)
{
    struct node *pRoot = NULL;
    InsertBst(&pRoot,50);
    InsertBst(&pRoot,40);
    InsertBst(&pRoot,35);
    InsertBst(&pRoot,58);
    InsertBst(&pRoot,48);
    InsertBst(&pRoot,42);
    InsertBst(&pRoot,60);
    InsertBst(&pRoot,30);
    InsertBst(&pRoot,33);
    InsertBst(&pRoot,25);

    PostOrder(pRoot);

    if(pRoot != NULL)
    {
        DeleteAll(&pRoot);
        pRoot=NULL;
    }
    return 0;
}
void InsertBst(struct node **ppRoot,int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pParent = NULL;
    struct node *pPtr = *ppRoot;
    int iBalanceFactor;
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
    pNewNode->iHeight = 1;

    if(NULL == *ppRoot)
    {   
        pNewNode->chFlag = 'R';
        *ppRoot = pNewNode;
        return;
    }
    if(iNo < (pParent->iData))
    {
        pParent->pLeft=pNewNode;
        pNewNode->chFlag = 'L';
    }
    else if(iNo > (pParent->iData))
    {
        pParent->pRight=pNewNode;
        pNewNode->chFlag = 'r';
    }

    pParent->iHeight = 1 + BalanceChecker(Height(pParent->pLeft) , Height(pParent->pRight));
    iBalanceFactor=BalanceFactorOfNode(*ppRoot);

    //left left rotation
    if(iBalanceFactor > 1 && iNo < (*ppRoot)->pLeft->iData )
        {
            RightRotation(ppRoot);
        }

    //right right rotation
    if(iBalanceFactor < -1 && iNo > (*ppRoot)->pRight->iData)
    {
            LeftRotaion(ppRoot);
    }
    
    //left right rotation
    if(iBalanceFactor > 1 && iNo > (*ppRoot)->pLeft->iData )
    {
        LeftRotaion(&((*ppRoot)->pLeft));
        RightRotation(ppRoot);
    }
    
    
    //right left rotation
    if(iBalanceFactor < -1 && iNo < (*ppRoot)->pRight->iData)
    {
        RightRotation(&(*ppRoot)->pRight);
        LeftRotaion(ppRoot);
    }
}
void PostOrder(struct node *pRoot)
{
    if(NULL == pRoot)
        return;
    PostOrder(pRoot->pLeft);
    PostOrder(pRoot->pRight);
    printf("%d ",pRoot->iData);
}
void LeftRotaion(struct node **ppRoot)
{
    struct node *pRightChild = (*ppRoot)->pRight;
    struct node *pGrandChild = pRightChild->pLeft;

    pRightChild->pLeft=*ppRoot;
    (*ppRoot)->pRight = pGrandChild;

    (*ppRoot)->iHeight = BalanceChecker(Height((*ppRoot)->pLeft),Height((*ppRoot)->pRight)) +1;
    pRightChild->iHeight = BalanceChecker(Height(pRightChild->pRight),Height(pRightChild->pLeft)) + 1;
    *ppRoot=pRightChild;
}
void RightRotation(struct node **ppRoot)
{
    struct node *pLeftChild = (*ppRoot)->pLeft;
    struct node *pGrandChild = pLeftChild->pRight;

    pLeftChild->pRight = *ppRoot;
    (*ppRoot)->pLeft = pGrandChild;

    (*ppRoot)->iHeight = BalanceChecker(Height((*ppRoot)->pLeft),Height((*ppRoot)->pRight)) + 1;
    pLeftChild->iHeight = BalanceChecker(Height(pLeftChild->pLeft),Height(pLeftChild->pRight)) + 1;
    *ppRoot = pLeftChild;
}
int Height(struct node *pRoot)
{
    int iLeftHeight;
    int iRightHeight;

    if(pRoot == NULL)
        return 0;
    iLeftHeight=Height(pRoot->pLeft);
    iRightHeight=Height(pRoot->pRight);

    if(iLeftHeight>iRightHeight)
        return iLeftHeight+1;
    else 
        return iRightHeight+1;
}
int BalanceChecker(int iLeft , int iRight)
{
    if(iLeft>iRight)
        return iLeft;
    return iRight;
}
int BalanceFactorOfNode(struct node *pRoot)
{
    if(NULL == pRoot)
        return 0;
    return Height(pRoot->pLeft) - Height(pRoot->pRight);
}
void DeleteAll(struct node **ppRoot)
{
   if(*ppRoot == NULL)
    return;
    DeleteAll(&((*ppRoot)->pLeft));
    DeleteAll(&((*ppRoot)->pRight));
    free(*ppRoot);
    *ppRoot = NULL;
}
