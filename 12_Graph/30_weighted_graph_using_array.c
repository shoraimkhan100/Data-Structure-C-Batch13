#include <stdio.h>
#define MAX 10

int main(void)
{
    int Arr[MAX][MAX][MAX]={0};
    int iCounter1;
    int iCounter2;
    int iValue;
    int iAdjacent;
    int iWeight;

    printf("\n\t Enter Number Of Vertices : ");
    scanf("%d",&iValue);

    for(iCounter1 = 0 ; iCounter1 < iValue ; iCounter1++)
    {
        printf("\n\tEnter %d Vertex - ",iCounter1+1);
        scanf("%d",&Arr[iCounter1][0][0]);
    }
    
    for(iCounter1 = 0 ; iCounter1< iValue ; iCounter1++)
    {
        printf("\n\tHow Many Adjacent Vertex For %d : " ,Arr[iCounter1][0][0]);
        scanf("%d",&iAdjacent);

        if(iAdjacent == 0)
            continue;
        for(iCounter2 = 1 ;iCounter2 <= iAdjacent ; iCounter2++)
        {
                printf("\n\tEnter %d Adjacent Vertices For %d= ",iCounter2,Arr[iCounter1][0][0]);
                scanf("%d",&Arr[iCounter1][iCounter2][0]);
                printf("\n\tEnter The Weight of the (%d -> %d)",Arr[iCounter1][0][0] , Arr[iCounter1][iCounter2][0]);
                scanf("%d",&iWeight);
                Arr[iCounter1][iCounter2][1]=iWeight;
        }
    }
    for(iCounter1 =0 ; iCounter1< iValue ; iCounter1++)
    {
        for(iCounter2 = 1 ;Arr[iCounter1][iCounter2][0] != 0 ;iCounter2++)
            printf("%d=>(%d Weight of :%d)-> ",Arr[iCounter1][0][0],Arr[iCounter1][iCounter2][0],Arr[iCounter1][iCounter2][1]);
    printf("\n");
    }
    return 0;
}