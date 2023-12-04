#include<stdio.h>
#define MAX 100

void Copy(int Arr[] , int iTemp[] , int iLow , int iUp);
void Merge(int Arr[] , int iTemp[] , int iLow , int iUp1 , int iLow2 , int iUp2);
void Merge_Sort(int Arr[] , int iLow , int iUp);

int main(void)
{
    int Arr[MAX]={0};
    int iCounter;
    int iValue;

    printf("\nHow Many Numbers You Want To Sort??\t");
    scanf("%d",&iValue);

    for(iCounter=0 ; iCounter<iValue ; iCounter++)
    {
        printf("\nEnter %d Element:\t",iCounter+1);
        scanf("%d",&Arr[iCounter]);
    }
    Merge_Sort(Arr,0,iValue-1);

    printf("\n\nSorted Elements Are :\n\n");
    for(iCounter=0 ; iCounter<iValue ; iCounter++)
        printf("\t%d",Arr[iCounter]);
    return 0;
}
void Merge_Sort(int Arr[],int iLow , int iUp)
{
    int iMid;
    int iTemp[MAX]={0};

    if(iLow<iUp)
    {
        iMid=(iLow+iUp)/2;
        Merge_Sort(Arr,iLow,iMid);
        Merge_Sort(Arr,iMid+1,iUp);

        Merge(Arr , iTemp , iLow , iMid , iMid+1 , iUp);
        Copy(Arr, iTemp , iLow , iUp);
    }
}
void Merge(int Arr[] , int iTemp[] , int iLow1 , int iUp1 , int iLow2 , int iUp2)
{
    int iCounter1 = iLow1;
    int iCounter2 = iLow2;
    int iLower = iLow1;

    while((iCounter1<=iUp1) && (iCounter2<=iUp2))
    {
        if(Arr[iCounter1]<=Arr[iCounter2])
            iTemp[iLower++]=Arr[iCounter1++];
        else
            iTemp[iLower++]=Arr[iCounter2++];
    }
    while(iCounter1<=iUp1)
        iTemp[iLower++]=Arr[iCounter1++];
    while(iCounter2<=iUp2)
        iTemp[iLower++]=Arr[iCounter2++];
}
void Copy(int Arr[] , int iTemp[] , int iLow , int iUp)
{
    int iCounter;
    for(iCounter=iLow ; iCounter<=iUp ; iCounter++)
        Arr[iCounter]=iTemp[iCounter];
}