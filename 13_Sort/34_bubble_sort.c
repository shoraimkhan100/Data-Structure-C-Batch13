#include<stdio.h>
#define MAX 100

int main(void)
{
    int Arr[MAX]={0};
    int iCounter1;
    int iCounter2;
    int iValue;
    int iTemp;
    int iNoOfSwaps;

    printf("\nHow Many Number You Want To Sort??\t");
    scanf("%d",&iValue);

    for(iCounter1=0 ; iCounter1<iValue ; iCounter1++)
    {
        printf("\nEnter %d Element:\t",iCounter1+1);
        scanf("%d",&Arr[iCounter1]);
    }

    for(iCounter1=0 ; iCounter1<iValue-1 ; iCounter1++)
    {
        iNoOfSwaps=0;
        for(iCounter2=0 ; iCounter2<iValue-1-iCounter1 ; iCounter2++)
        {
            if(Arr[iCounter2] > Arr[iCounter2+1])
            {
                iTemp=Arr[iCounter2];
                Arr[iCounter2]=Arr[iCounter2+1];
                Arr[iCounter2+1]=iTemp;
                ++iNoOfSwaps;
            }
        }
        if(iNoOfSwaps == 0)
            break;
    }
    printf("\n\nSorted Elements Are :\n\n");
    for(iCounter1=0 ; iCounter1<iValue ; iCounter1++)
        printf("\t%d",Arr[iCounter1]);
    return 0;
}