#include<stdio.h>
#define MAX 100

void Display(int Arr[] , int iNo);
void ReArrange(int Arr[] , int iNo , int iSize);
int Del_Node(int Arr[] , int *pSize);
void Build_Heap(int Arr[] , int iSize);
void Heap_Sort(int Arr[] , int iSize);

int main(void)
{
    int Arr[MAX]={0};
    int icounter;
    int iValue;

    printf("\nHow Many Numbers You Want To Sort??\t");
    scanf("%d",&iValue);

    for(icounter=1 ; icounter<=iValue ; icounter++)
    {
        printf("\nEnter %d Element:\t",icounter);
        scanf("%d",&Arr[icounter]);
    }
    printf("\n\nEntered list is :\t");
    Display(Arr,iValue);
    Heap_Sort(Arr,iValue);
    printf("\n\nSorted list is :\t");
    Display(Arr,iValue);

    return 0 ;
}
void Heap_Sort(int Arr[] , int iSize)
{
    int iMax;
    Build_Heap(Arr,iSize);

    printf("\n\nHeap is:\t\t");
    Display(Arr,iSize);
    while (iSize>1)
    {
        iMax = Del_Node(Arr,&iSize);
        Arr[iSize+1]=iMax;
    }
}
void Build_Heap(int Arr[] , int iSize)
{
    int iCounter;
    for(iCounter=iSize/2 ; iCounter>=1 ; iCounter--)
        ReArrange(Arr,iCounter,iSize);
}
int Del_Node(int Arr[] , int *pSize)
{
    int iMax;
    iMax=Arr[1];
    Arr[1]=Arr[*pSize];
    (*pSize)--;
    ReArrange(Arr,1,*pSize);
    return iMax;
}
void ReArrange(int Arr[] , int iNo , int iSize)
{
    int iLeft;
    int iRight;
    int iNum;
    iLeft=2*iNo;
    iRight=iLeft+1;

    iNum=Arr[iNo];
    while(iRight<=iSize)
    {
        if(iNum>=Arr[iLeft] && iNum>=Arr[iRight])
        {
            Arr[iNo]=iNum;
            return;
        }
        else if(Arr[iLeft]>Arr[iRight])
        {
            Arr[iNo]=Arr[iLeft];
            iNo=iLeft;
        }
        else
        {
            Arr[iNo]=Arr[iRight];
            iNo=iRight;
        }
        iLeft=2*iNo;
        iRight=iLeft+1;
    }
    if(iLeft == iSize && iNum<Arr[iLeft])
    {
        Arr[iNo]=Arr[iLeft];
        iNo=iLeft;
    }
    Arr[iNo]=iNum;
}
void Display(int Arr[] , int iNo)
{
    int iCounter;
    for(iCounter=1 ; iCounter<=iNo ; iCounter++)
        printf("%d\t",Arr[iCounter]);
}