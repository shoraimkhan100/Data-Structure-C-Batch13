#include<stdio.h>
#include<malloc.h>
#define MAX 50
struct node
{
    char chSign;
    struct node *pNext;
};

char chChecker(char);
int Dover(char *);
void Push(struct node **,char);
char Pop(struct node **);
int IsEmpty(struct node *);
int IsFull(struct node *);
int CountNode(struct node *);

int main(void)
{   
    int iValue;
    char chSymbol[MAX]={'0'};

    printf("Enter The Equation : ");
    scanf("%s",chSymbol);  

    iValue=Dover(chSymbol);
    if(iValue == 1)
        printf("valid\n");
    else 
        printf("inValid\n");
    return 0;
}
char chChecker(char chSymbol)
{
    switch (chSymbol)
    {
    case '(' :
            return ')';
    case '[' :
            return ')';
    case '{' :
            return '}';
    case '<' :
            return '>';
    case ')' : 
            return '(';
    case ']' :
            return '[';
    case '}' :
            return '{';
    case '>' :
            return '<';
    default:
            return '\0';
    }
}
int Dover(char *szString)
{
    int iValue=1;
    char chData;
    char chHolder;
    char chPop;
    int iCounter = 0;
    struct node *pStack = NULL;
    for(iCounter=0; szString[iCounter] != '\0' ; iCounter++)
    {
        chData=szString[iCounter];
        chHolder=chChecker(chData);
        if(chHolder == '\0')
            continue;

        switch(chData)
            {
            case '(':
            case '[':
            case '{':
            case '<':
                Push(&pStack,chData);
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                if(IsEmpty(pStack) || chHolder != pStack->chSign)
                 {
                    iValue=iCounter;
                    return iValue;
                 }
                chPop=Pop(&pStack);
                printf("%c\n",chPop);
                break;
            default:
                    break;
            }
    }
    if(pStack != NULL)
        return 0;
    return iValue;
}
int IsEmpty(struct node *pHead)
{
    if(pHead == NULL)
        return 1;
    return 0;
}
int IsFull(struct node *pHead)
{
    if(MAX == CountNode(pHead))
        return 1;
    return 0;
}
void Push(struct node **ppHead,char chSymbol)
{
    struct node *pNewNode = NULL;
    if(IsFull(*ppHead))
       {
        printf("Stack is overFlow...\n");
        return;
       }
    pNewNode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory Allocation FAILED\n");
        return;
    }
    pNewNode->chSign = chSymbol;
    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;
}
char Pop(struct node **ppHead)
{
    char chPop;
    struct node *pTemp = NULL;
    if(*ppHead == NULL)
        return '\0';
    pTemp=*ppHead;
    *ppHead=pTemp->pNext;
    pTemp->pNext=NULL;
    chPop=pTemp->chSign;
    free(pTemp);
    pTemp=NULL;
    return chPop;
}
int CountNode(struct node *pHead)
{
    int iCounter=0;
    while(pHead != NULL)
    {
        iCounter++;
        pHead=pHead->pNext;
    }
}