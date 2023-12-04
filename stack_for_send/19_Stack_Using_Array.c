#include<stdio.h>
#include<malloc.h>
#define MAX 5

void Push(int *, int);
int Pop(int *);
int IsFull(void);
int IsEmpty(void);
void Display(const int *);
int g_iTop = -1;

int main(void)
{
    int iPopData;
    int Stack[MAX]={0};
    Push(Stack,30);
    Push(Stack,20);
    Push(Stack,10);
    Display(Stack);
    iPopData=Pop(Stack);
        printf("DELTED DATA %d\n",iPopData);
    Display(Stack);
    return 0;
}
void Push(int *pStack , int iNo)
{
    if(IsFull())
    {
        printf("stack is overflow\n");
        return;
    }
    pStack[++g_iTop]=iNo;
}
int Pop(int *pStack)
{
    int iNo;
    if(IsEmpty())
    {
        printf("stack is empty\n");
        return -1;
    }
    pStack[g_iTop--]=iNo;
}
int IsFull(void)
{
    if(g_iTop == MAX-1)
        return 1;
    return 0;
}
int IsEmpty(void)
{
    if(g_iTop == -1)
        return 1;
    return 0;
}
void Display(const int *pStack)
{
    int iCounter;
    if(IsEmpty())
    {
        printf("list is empty .. \n");
        return;
    }
    for(iCounter=0;iCounter<=g_iTop;iCounter++)
        printf("|%d|->",pStack[iCounter]);
    printf("\n");
}