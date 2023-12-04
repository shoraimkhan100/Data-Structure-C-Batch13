#include<stdio.h>
#include<malloc.h>
#define MAX 50

struct node
{
    char chData;
    struct node *pNext;
};

int CountNode(struct node *pHead);
int IsFull(struct node *);
int IsEmpty(struct node *);
char ReturnAction(char );//, char *
void Push(struct node **,char);
char Pop(struct node **);
int Evaluate(char *);

int main(void)
{   
    int iValue;
    char chBracket[MAX]={'0'};
    printf("Enter the equation : ");
    scanf("%s",chBracket);
    iValue=Evaluate(chBracket);
    if(iValue == 0) 
        printf("Equation is valid\n");
    else    
        printf("Equation is not valid\n");
    return 0;
}   
void Push(struct node **ppHead,char chSymbol)
{
    struct node *pNewNode = NULL;
    if(IsFull(*ppHead))
    {
        printf("stack is overflow\n");
        return;
    }
    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("MEMORY allocation FAILED\n");
        return;
    }
    pNewNode->chData = chSymbol;
    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;
}
char Pop(struct node **ppHead)
{   
    char chPopData;
    struct node *pTemp = NULL;
 
    if(IsEmpty(*ppHead))
    {
        printf("stack is empty\n");
        return '\0';
    }
    pTemp = *ppHead;
    *ppHead=pTemp->pNext;
    pTemp->pNext=NULL;
    chPopData=pTemp->chData;
    free(pTemp);
    pTemp=NULL;
    return chPopData;
}
int Evaluate(char* szString)
{
    int iValue=0;
    int iCont;
    char cfData;
    char chHolder;
    struct node *pStack = NULL;

    for(iCont=0;szString[iCont] != '\0';iCont++)
    {
        cfData=szString[iCont];
        chHolder = ReturnAction(cfData);

        switch (cfData)
        {
        case '(':
        case '[':
        case '{':
        case '<':
            Push(&pStack,cfData);
            break;
        case ')':
        case ']' :
        case '}' :
        case '>':
            if(IsEmpty(pStack) || chHolder != pStack->chData)
                {
                    iValue = iCont++;   
                    break;
                }
                    Pop(&pStack);
                    break;
        default:
                break;
        }
    }
    if(pStack != NULL)
    {
        return iValue++;
    }
    return iValue;
}
char ReturnAction(char chEquation)//, char *pReturn
{
    switch(chEquation)
        {
            case '(':
                    return ')';
            case '[':
                    return ']';
            case '<':
                    return '>';
            case '{':
                    return '}'; 
            case ')':
                    return '(';
            case ']':
                    return '[';
            case '>':
                    return '<';
            case '}':
                    return '{';
            default:
                    return '\0';
        }
}
int IsFull(struct node *pHead)
{
    if(CountNode(pHead) == MAX)
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