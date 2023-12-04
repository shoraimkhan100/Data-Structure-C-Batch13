#include<stdio.h>
#include<malloc.h>
#define MAX 5

int g_iTop = -1;

void Push(int *,int);
void Display(const int *);
int Pop(int *);
int IsEmpty(void);
int IsFull(void);


int main(void)
{
	int PopData;
	int Stack[MAX]={0};
	
		Push(Stack,10);
		printf("g_iTop : %d\n",g_iTop);
		Display(Stack);
		
        Push(Stack,20);
		printf("g_iTop : %d\n",g_iTop);
		Display(Stack);
		
        Push(Stack,30);
		printf("g_iTop : %d\n",g_iTop);
		Display(Stack);
		
		PopData=Pop(Stack);
			printf("Deleted Data %d\n",PopData);
		printf("g_iTop : %d\n",g_iTop);
		Display(Stack);
		
		PopData=Pop(Stack);
			printf("Deleted Data %d\n",PopData);
		printf("g_iTop : %d\n",g_iTop);
		Display(Stack);
		
		PopData=Pop(Stack);
			printf("Deleted Data %d\n",PopData);
		printf("g_iTop : %d\n",g_iTop);
		Display(Stack);
        
		return 0;
}
void Display(const int *pStack)
{
	int iCounter;
	if(IsEmpty())
	{
		printf("stack is empty..\n");
		return;
	}
	for(iCounter=0;iCounter<=g_iTop;iCounter++)
	{
		printf("|%d|->",pStack[iCounter]);
	}
	printf("\n");
}
int IsEmpty(void)
{
	if(g_iTop == -1)
		return 1;
	return 0;
}
int IsFull(void)
{
	if(g_iTop == MAX-1)
		return 1;
	return 0;
}
void Push(int *pStack , int iNo)
{
	if(IsFull())
	{
		printf("Stack is overflow...\n");
		return;
	}
	pStack[++g_iTop]=iNo;
}
int Pop(int *pStack)
{
	if(IsEmpty())
	{
		printf("Stack is Empty..\n");
		return -1;
	}
	return pStack[g_iTop--];
}