#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n > 1 && arr[1] < arr[0])
    {
        arr[1] = arr[0];
    }
    for (int i = 2; i < n; i++)
    {
        arr[i] = (arr[i - 1]>arr[i - 2] + arr[i])?(arr[i - 1]):(arr[i - 2] + arr[i]);
    }
    cout << arr[n - 1];
    return 0;
}