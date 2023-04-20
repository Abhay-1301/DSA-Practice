#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int count = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        if (arr[i] <= arr[k])
        {
            count = count + arr[i];
        }
        else if (arr[i] > arr[k])
        {
            count = count + arr[k];
        }
    }
    for (int i = k + 1; i < n; i++)
    {
        if (arr[i] < arr[k])
        {
            count = count + arr[i];
        }
        else if (arr[i] >= arr[k])
        {
            count = count + arr[k] - 1;
        }
    }
    count = count + arr[k];
    cout << count;

    return 0;
}