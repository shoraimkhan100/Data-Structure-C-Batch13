#include<stdio.h>
#include "stack.h"
int g_iTop = -1;
long int g_Stack[STACK_MAX];


void Push(long lSymbol)
{
    if(IsFull())
    {
        printf("Stack is overflow\n");
        return;
    }
    g_Stack[++g_iTop]=lSymbol;
}
int Pop(void)
{
    if(IsEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return g_Stack[g_iTop--];
}
int IsFull(void)
{
    if(g_iTop == STACK_MAX - 1)
        return 1;
    return 0;
}
int IsEmpty(void)
{
    if(g_iTop == -1)
        return 1;
    return 0;
}