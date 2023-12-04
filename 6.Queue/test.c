#include <stdio.h>
#include <stdlib.h> // Include <stdlib.h> for malloc
#define MAX 5

void EnQueueFront(int *, int);
int DeQueueFront(int *);

void EnQueueAtRear(int *, int);
int DeQueueAtRear(int *);

void Display(const int *);

int IsQueueFull(void);
int IsQueueEmpty(void);

int g_iFront = 0;
int g_iRear = -1;

int main(void)
{
    int iDelData;
    int Queue[MAX] = {0};
    EnQueueAtRear(Queue, 10);
    EnQueueAtRear(Queue, 20);
    EnQueueAtRear(Queue, 30);
    Display(Queue);

    iDelData = DeQueueFront(Queue);
    printf("Deleted Data is %d\n", iDelData);
    Display(Queue);

    EnQueueFront(Queue, 40); // Changed 10 to 40 for testing
    EnQueueFront(Queue, 50); // Changed 20 to 50 for testing
    EnQueueFront(Queue, 60); // Changed 30 to 60 for testing
    iDelData = DeQueueFront(Queue);
    printf("Deleted Data is %d\n", iDelData);
    Display(Queue);

    return 0;
}

void EnQueueAtRear(int *pQueue, int iNo)
{
    if (IsQueueFull())
    {
        printf("Queue is overflow..\n");
        return;
    }
    if (g_iRear == MAX - 1)
        g_iRear = -1;
    pQueue[++g_iRear] = iNo;
}

int DeQueueAtRear(int *pQueue)
{
    int iDelData;
    if (IsQueueEmpty())
    {
        printf("Queue is Empty..\n");
        return -1;
    }
    iDelData = pQueue[g_iFront];
    if (g_iFront == g_iRear)
    {
        g_iFront = 0;
        g_iRear = -1;
    }
    else if (g_iFront == MAX - 1)
        g_iFront = 0;
    else
        g_iFront++;
    return iDelData;
}

int DeQueueFront(int *pQueue)
{
    int iDelData;
    if (IsQueueEmpty())
    {
        printf("Queue is empty..\n");
        return -1;
    }
    iDelData = pQueue[g_iFront++];
    if (g_iFront == g_iRear + 1)
    {
        g_iFront = 0;
        g_iRear = -1;
    }
    else if (g_iFront == MAX - 1)
        g_iFront = 0;
    return iDelData;
}

void EnQueueFront(int *pQueue, int iNo)
{
    if (IsQueueFull())
    {
        printf("Queue is overflow..\n");
        return;
    }
    if (g_iFront == 0 && g_iRear == -1)
    {
        g_iFront = g_iRear = MAX - 1;
    }
    else if (g_iFront == 0)
        g_iFront = MAX - 1;
    else
        --g_iFront;
    pQueue[g_iFront] = iNo;
}

void Display(const int *pQueue)
{
    int iCounter = g_iFront;
    if (IsQueueEmpty())
    {
        printf("Queue is empty..\n");
        return;
    }
    if (g_iRear <= g_iFront)
    {
        for (; iCounter < MAX; iCounter++)
            printf("|%d|->", pQueue[iCounter]);
        return;
    }
    else
    {
        for (; iCounter <= g_iRear; iCounter++)
            printf("|%d|->", pQueue[iCounter]);
    }
    printf("\n");
}

int IsQueueFull(void)
{
    if ((g_iRear == 0 && g_iFront == MAX - 1) || (g_iFront == g_iRear + 1))
        return 1;
    return 0;
}

int IsQueueEmpty(void)
{
    if (g_iRear == -1)
        return 1;
    return 0;
}
