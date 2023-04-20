#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        int i = fibonacci(n - 1) + fibonacci(n - 2);
        return i;
    }
}

int main()
{
    int n;
    int output;
    cin >> n;
    output = fibonacci(n - 1);
    cout << output;
    return 0;
}