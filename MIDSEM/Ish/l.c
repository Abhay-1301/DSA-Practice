#include <stdio.h>
int main()
{
    float Total_SP,Profit;
    scanf("%f" , &Total_SP);
    scanf("%f" , &Profit);
    float cp;
    cp =(Total_SP - Profit)/15 ;
    printf("%.6f",cp);
    return 0;
}