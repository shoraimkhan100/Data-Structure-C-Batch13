#include<stdio.h>
#include<math.h>
#include "stack.h"
#include<stdlib.h>
#define MAX 50


int IsSpace(char);
int IsOperator(char);
long PostfixEvaluation(const char *);
void InfixToPostfix(const char *,char *);

int main(void)
{
    long lResult;
    char szInfix[MAX]={0};
    char szPostfix[MAX]={0};

    printf("Enter arithmetic expression\n");
    gets(szInfix);
    InfixToPostfix(szInfix,szPostfix);
    puts(szPostfix);
    lResult=PostfixEvaluation(szPostfix);
    printf("Result is %ld\n",lResult);
    return 0;
}
void InfixToPostfix(const char *pzInfix,char *pszPostfix)
{
    int iCounter1;
    int iCounter2;
    int iPriority;
    char chSymbol;

    extern int g_iTop;
    extern long int g_Stack[STACK_MAX];
    iCounter2=0;
    for(iCounter1=1;pzInfix[iCounter1] != '\0';iCounter1++)
    {
        chSymbol=pzInfix[iCounter1];
        if(IsSpace(chSymbol))
            continue;
        if((iPriority = IsOperator(chSymbol)) != 0)
        {
            while(!IsEmpty() && IsOperator(g_Stack[g_iTop])>= iPriority)
                pszPostfix[iCounter2++]=Pop();
            Push(chSymbol);
        }
        else
        {
            if(chSymbol == '(')
                Push(chSymbol);
            else   if(chSymbol == ')')
            {
                while(1)
                {
                    chSymbol=Pop();
                        if(chSymbol == '(')
                            break;
                        pszPostfix[iCounter2++]=chSymbol;
                }
            }
            else
            {
                pszPostfix[iCounter2++]='[';
                pszPostfix[iCounter2++] = chSymbol;
                
                while(1)
                {
                    chSymbol=pzInfix[++iCounter1];

                    if(IsSpace(chSymbol))
                        continue;
                    if(chSymbol=='\0' || IsOperator(chSymbol) || chSymbol == ')')
                    {
                        pszPostfix[iCounter2++]=']';
                        break;
                    }
                    pszPostfix[iCounter2++]=chSymbol;
                }
                iCounter1--;
            }
        }
    }
    while(!IsEmpty())
        pszPostfix[iCounter2++]=Pop();
    pszPostfix[iCounter2]='\0';
}
int IsSpace(char chSymbol)
{
    if(chSymbol == ' ' || chSymbol == '\t')
        return 1;
    return 0;
}
int IsOperator(char chSymbol)
{
    switch(chSymbol)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case  '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
long PostfixEvaluation(const char *pszPostfix)
{
    int iCounter1;
    int iCounter2;
    int iOperand1;
    int iOperand2;
    char chSymbol;
    char szTemp[10]={0};
    for(iCounter1 = 0;pszPostfix[iCounter1] != '\0';iCounter1++)
    {
        chSymbol=pszPostfix[iCounter1];
        if(chSymbol == '[')
            {
                iCounter2 = 0;
                while(1)
                {
                    chSymbol=pszPostfix[++iCounter1];
                    if(chSymbol == ']')
                        break;
                    szTemp[iCounter2++]=chSymbol;
                }
                szTemp[iCounter2]='\0';
                Push(atoi(szTemp));//atoi
            }
            else{
                iOperand2 = Pop();
                iOperand1 = Pop();
                switch(chSymbol)
                {
                    case '+':
                        Push(iOperand1 + iOperand2);
                        break;
                    case '-':
                        Push(iOperand1 - iOperand2);
                        break;
                    case '*':
                        Push(iOperand1 * iOperand2);
                        break;
                    case '/':
                        Push(iOperand1 / iOperand2);
                        break;
                    case '%':
                        Push(iOperand1 % iOperand2);
                        break;
                    case '^':
                        Push(iOperand1 ^ iOperand2);
                }
            }
    }
}