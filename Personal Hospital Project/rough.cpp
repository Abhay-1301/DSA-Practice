#include <bits/stdc++.h>
using namespace std;

int inFibonacci(int x)
{
    int a = 0;
    int b = 1;
    if (x == a || x == b)
    {
        return 1;
    }
    while (b <= x)
    {
        int c = a + b;
        if (c == x)
        {
            return 1;
        }
        a = b;
        b = c;
    }
    return 0;
}

void printFibonacci(int n)
{
    int a = 0;
    int b = 1;

    if (n != 0)
    {
        printf("%d ", a);
    }
    for (int i = 1; i < n; i++)
    {
        printf("%d ", b);
        int c = a + b;
        a = b;
        b = c;
    }
}

void fibonacci(int x, int y)
{
    int a = 0;
    int b = 1;
    if (a >= x && a <= y)
    {
        printf("%d ", a);
    }
    while (!(b > y))
    {
        if (b >= x && b <= y)
        {
            printf("%d ", b);
        }
        int c = a + b;
        a = b;
        b = c;
    }
}

int main()
{

    // int x;
    // int y;
    // scanf("%d", &x);
    // scanf("%d", &y);
    // int m = inFibonacci(x);
    // int n = inFibonacci(y);

    // if (m == 1 && n == 1)
    // {
    //     fibonacci(x, y);
    // }
    // else
    // {
    //     printf("These numbers are not in fibonacci");
    // }
    printFibonacci(1);

    return 0;
}