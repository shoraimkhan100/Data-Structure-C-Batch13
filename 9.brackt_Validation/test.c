#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct node
{
    char chData;
    struct node *pNext;
};

int CountNode(struct node *pHead);
int IsFull(struct node *);
int IsEmpty(struct node *);
char ReturnAction(char chEquation);
void Push(struct node **ppHead, char chSymbol);
char Pop(struct node **ppHead);
int Evaluate(char *);

int main(void)
{
    int iValue;
    char chBracket[MAX] = {'0'};
    printf("Enter the equation : ");
    scanf("%s", chBracket);
    iValue = Evaluate(chBracket);
    if (iValue == 0)
        printf("Equation is valid\n");
    else
        printf("Equation is not valid\n");
    return 0;
}

void Push(struct node **ppHead, char chSymbol)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if (NULL == pNewNode)
    {
        printf("MEMORY allocation FAILED\n");
        exit(1);
    }
    pNewNode->chData = chSymbol;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

char Pop(struct node **ppHead)
{
    char chPopData;
    struct node *pTemp = NULL;

    if (IsEmpty(*ppHead))
    {
        printf("stack is empty\n");
        exit(1);
    }
    pTemp = *ppHead;
    *ppHead = pTemp->pNext;
    chPopData = pTemp->chData;
    free(pTemp);
    return chPopData;
}

int Evaluate(char* szString)
{
    int iValue = 0;
    int iCont;
    char cfData;
    struct node *pStack = NULL;

    for (iCont = 0; szString[iCont] != '\0'; iCont++)
    {
        cfData = szString[iCont];

        switch (cfData)
        {
        case '(':
        case '[':
        case '{':
        case '<':
            Push(&pStack, cfData);
            break;
        case ')':
        case ']':
        case '}':
        case '>':
            if (IsEmpty(pStack) || ReturnAction(cfData) != pStack->chData)
            {
                iValue = iCont + 1; // Set iValue to the position of the unmatched bracket
                break;
            }
            Pop(&pStack);
            break;
        default:
            break;
        }
    }

    if (iValue == 0 && !IsEmpty(pStack))
    {
        iValue = iCont + 1; // Set iValue to the position of the unmatched bracket
    }

    while (!IsEmpty(pStack))
    {
        Pop(&pStack);
    }

    return iValue;
}

char ReturnAction(char chEquation)
{
    switch (chEquation)
    {
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    case '>':
        return '<';
    default:
        return '\0';
    }
}

int IsFull(struct node *pHead)
{
    return 0; // Since this is not a fixed-size stack
}

int IsEmpty(struct node *pHead)
{
    return pHead == NULL ? 1 : 0;
}