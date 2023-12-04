#include <stdio.h>
void function(int *iValue)
{
    printf("%d",*iValue);
}
int main(void)
{
    int iValue;
    printf("Ente the value : ");
    scanf("%d",&iValue);
    function(&iValue);
    return 0;
}