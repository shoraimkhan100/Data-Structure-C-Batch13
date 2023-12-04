#include <stdio.h>
#include <malloc.h>

struct edge;
struct vertex
{
    struct edge *pAdjEdge;
    int iData;
    struct vertex *pNextVertex;
};
struct edge
{
    struct vertex *pAdjVertex;
    struct edge *pNextEdge;
};
void InsertVertex(struct vertex ** , int);
void InsertAdjacent(struct vertex ** , struct edge *);

int main(void)
{
    struct vertex *pStack = NULL;
    int iCounter1;
    int iCounter2;
    int iVertex;
    int iValue;
    int iAdjacent;
    struct vertex *pTemp = NULL;

    printf("Enter Number Of  Vertex : ");
    scanf("%d",&iVertex);

    for(iCounter1 = 0 ; iCounter1 < iVertex ; iCounter1++)
    {
        printf("Enter the Vertex Value : ");
        scanf("%d",&iValue);
        InsertVertex(&pStack,iValue);
    }
    pTemp=pStack;
    while(pTemp != NULL)
    {
        printf("How Many Adjacent for %d : ",pTemp->iData);
        scanf("%d",&iAdjacent);
        for(iCounter1=0 ; iCounter1<iAdjacent && iAdjacent != 0; iCounter1++)
        {
            printf("Enter the %d - Adjacent Value : ",iCounter1+1);
            scanf("%d",&iValue);
            InsertAdjacent(&pTemp,iValue);
        }
        pTemp=pTemp->pNextVertex;
    }
 //   Display(pStack);

    free(pTemp);
    return 0;
}
void InsertVertex(struct vertex **ppHead , int iValue)
{
    struct vertex *pTemp = *ppHead;
    struct vertex *pNewNode = NULL;
    pNewNode =(struct vertex *)malloc(sizeof(struct vertex));
    if(pNewNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    pNewNode->iData = iValue;
    pNewNode->pAdjEdge = NULL;
    pNewNode->pNextVertex = NULL;    
    
    if(NULL == *ppHead)
    {
        *ppHead = pNewNode;
        return;
    }   
        while(pTemp->pNextVertex != NULL)
        {
            pTemp=pTemp->pNextVertex;
        }
    pTemp->pNextVertex = pNewNode;
}
void InsertAdjacent(struct vertex **ppVertex , struct edge *pTemp)
{
    struct edge *pNewNode = NULL;
    //struct edge *pTemp = NULL;
    pNewNode=(struct edge *)malloc(sizeof(struct edge));
    
    if(NULL == pNewNode)
    {
        printf("Memory Allocation FAILED\n");
        return;
    }
    /*pTemp = *ppVertex;
    while( pTemp->pAdjVertex != (&iAdjacent) && pTemp->pNextEdge != NULL)
    {
        pTemp=pTemp->pNextEdge;
    }
    pNewNode->pAdjVertex = *ppVertex;
    pNewNode->pNextEdge = (*ppVertex)->pAdjEdge;
    (*ppVertex)->pAdjEdge = pNewNode;*/
        
        pNewNode->pAdjVertex = pTemp;
        pNewNode->pNextEdge = (*ppVertex)->pAdjEdge;
        (*ppVertex)->pAdjEdge = pNewNode;

    
}
