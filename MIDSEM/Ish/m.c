#include <stdio.h>
int main()
{
    int a, b, c, d, e;
    scanf("%d", &a);
    if (a == 9)
    {
        a = 0;
    }
    else
    {
        a++;
    }
    scanf("%d", &b);
    if (b == 9)
    {
        b = 0;
    }
    else
    {
        b++;
    }
    scanf("%d", &c);
    if (c == 9)
    {
        c = 0;
    }
    else
    {
        c++;
    }
    scanf("%d", &d);
    if (d == 9)
    {
        d = 0;
    }
    else
    {
        d++;
    }
    scanf("%d", &e);
    if (e == 9)
    {
        e = 0;
    }
    else
    {
        e++;
    }
    printf("%d %d %d %d %d", a, b, c, d, e);
    return 0;
}