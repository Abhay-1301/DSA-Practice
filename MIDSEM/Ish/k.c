#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int a , b , c;
    a = x / 100 ;
    x = x - a*100;
    b = x / 50 ;
    x = x - b*50;
    c = x / 10 ;
    x = x - c*10;
    printf("100 - %d\n",a);
    printf("50 - %d\n",b);
    printf("10 - %d\n",c);

    return 0;
}