#include<stdio.h>
#define MAX 100

int Partition(int Arr[] , int iLow , int iUp);
void Quick(int Arr[] , int iLow , int iUp);

int main(void)
{
    int Arr[MAX]={0};
    int iCounter;
    int iValue;
    
    printf("\nHow Many Number You Want To Sort??\t");
    scanf("%d",&iValue);

    for(iCounter=0 ; iCounter<iValue ; iCounter++)
    {
        printf("\nEnter %d Element:\t",iCounter+1);
        scanf("%d",&Arr[iCounter]);
    }
    
    Quick(Arr,0,iValue-1);
    
    printf("\n\nScorted Element Are:\n\n");
    
    for(iCounter=0; iCounter<iValue ; iCounter++)
        printf("\t%d",Arr[iCounter]);
    return 0;
}
void Quick(int Arr[] , int iLow , int iUp)
{
    int iPivotloc;
    if(iLow>=iUp)
        return;
    iPivotloc=Partition(Arr,iLow,iUp);
    Quick(Arr,iLow,iPivotloc-1);
    Quick(Arr,iPivotloc+1,iUp);
}
int Partition(int Arr[] , int iLow , int iUp)
{
    //int iTemp;
    int iCounter1;
    int iCounter2;
    int iPivot;

    iCounter1=iLow+1;
    iCounter2=iUp;

    iPivot=Arr[iLow];

    while(iCounter1<=iCounter2)
    {
        while((Arr[iCounter1]<iPivot) && (iCounter1<iUp))
            iCounter1++;
        while(Arr[iCounter2]>iPivot)
            iCounter2--;
        /*if(iCounter1<iCounter2)
        {
            iTemp=Arr[iCounter1];
            Arr[iCounter1]=Arr[iCounter2];
            Arr[iCounter2]=iTemp;
            iCounter1++;
            iCounter2--;
        }*/
        if(iCounter1<iCounter2)
        {
            Arr[iCounter1]=Arr[iCounter1]+Arr[iCounter2];
            Arr[iCounter2]=Arr[iCounter1]-Arr[iCounter2];
            Arr[iCounter1]=Arr[iCounter1]-Arr[iCounter2];
            iCounter1++;
            iCounter2--;
        }
        else
            iCounter1++;
    }
    Arr[iLow]=Arr[iCounter2];
    Arr[iCounter2]=iPivot;
    return iCounter2;
}