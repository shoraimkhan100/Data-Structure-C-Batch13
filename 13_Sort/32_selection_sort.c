#include<stdio.h>
#define MAX 100

int main(void)
{
    int Arr[MAX]={0};
    int iCounter1;
    int iCounter2;
    int iValue;
    int iMin;

    printf("\nHow Many Number You Want To Sort??\t");
    scanf("%d",&iValue);

    for(iCounter1 = 0 ; iCounter1<iValue ; iCounter1++)
    {
        printf("\nEnter %d Element : \t",iCounter1+1);
        scanf("%d",&Arr[iCounter1]);
    }
    for(iCounter1 = 0 ; iCounter1<iValue-1 ; iCounter1++)
    {
        iMin=iCounter1;
        for(iCounter2 = iCounter1+1 ; iCounter2<iValue ; iCounter2++)
        {
            if(Arr[iMin]>Arr[iCounter2])
                iMin=iCounter2;
        }
        if(iCounter1 != iMin)
        {
            Arr[iCounter1] = Arr[iCounter1] + Arr[iMin];
            Arr[iMin] = Arr[iCounter1] - Arr[iMin];
            Arr[iCounter1] = Arr[iCounter1] - Arr[iMin];
        }
        
    }
    printf("\n\nSorted Elements Are :\n\n");
    for(iCounter1 = 0 ; iCounter1<iValue ; iCounter1++)
        printf("\t%d",Arr[iCounter1]);
    printf("\n");
    return 0;
}