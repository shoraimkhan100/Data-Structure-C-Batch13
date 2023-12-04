#include<stdio.h>
#define MAX 100

int main(void)
{
    int Arr[MAX]={0};
    int iCounter1;
    int iCounter2;
    int iValue;
    int iHolderArr;
    
    printf("\nHow Many Number You Want To Sort??\t");
    scanf("%d",&iValue);

    for(iCounter1=0 ; iCounter1<iValue ; iCounter1++)
    {
        printf("\nEnter %d Element : \t",iCounter1+1);
        scanf("%d",&Arr[iCounter1]);
    }

    for(iCounter1=1 ; iCounter1<iValue ; iCounter1++)
    {
        iHolderArr=Arr[iCounter1];

        for(iCounter2=iCounter1-1 ; iCounter2>=0 && iHolderArr < Arr[iCounter2] ; iCounter2--)
            Arr[iCounter2+1]=Arr[iCounter2];
        Arr[iCounter2+1]=iHolderArr;
    }
    printf("\n\nSorted elements are :\n\n");
    for(iCounter1=0 ; iCounter1<iValue ; iCounter1++)
        printf("\t%d",Arr[iCounter1]);
    printf("\n");
    return 0;
}